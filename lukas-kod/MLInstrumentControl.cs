
// C:\Users\lukli307\Documents\MicroLab PC\MicroLab PC\MLInstrumentControl.dll
// MLInstrumentControl, Version=5.8.2648.0, Culture=neutral, PublicKeyToken=null
// Global type: <Module>
// Architecture: x86
// Runtime: v4.0.30319
// Hash algorithm: SHA1

using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Threading;
using System.Windows;
using System.Windows.Interop;
using System.Windows.Threading;
using CommonShared;
using MicroLabData;
using MicroLabData.SystemLog;
using MicroLabPC;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyTitle("MLInstrumentControl")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("Agilent Technologies")]
[assembly: AssemblyProduct("MLInstrumentControl")]
[assembly: AssemblyCopyright("Copyright © 2016 Agilent Technologies")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: Guid("04fe001d-adda-42e2-873a-16d5791e4218")]
[assembly: AssemblyFileVersion("5.8.2648.0")]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("5.8.2648.0")]
namespace MLInstrumentControl;

public class DataPoint : INotifyPropertyChanged
{
	public delegate void voiddelegate();

	private double _x;

	private double _y;

	private Dispatcher _dispatcher;

	public double X
	{
		get
		{
			return _x;
		}
		set
		{
			_x = value;
		}
	}

	public double Y
	{
		get
		{
			return _y;
		}
		set
		{
			_y = value;
		}
	}

	public Brush MarkerBrush
	{
		get
		{
			return Brushes.Red;
		}
		set
		{
		}
	}

	public event PropertyChangedEventHandler PropertyChanged;

	public DataPoint(double x, double y)
	{
		X = x;
		Y = y;
	}

	public DataPoint(Dispatcher dispatcher)
	{
		_dispatcher = dispatcher;
	}

	public void Update()
	{
		if (this.PropertyChanged != null)
		{
			if (_dispatcher != null)
			{
				_dispatcher.Invoke(new voiddelegate(UpdateInvoke));
				return;
			}
			this.PropertyChanged(this, new PropertyChangedEventArgs("MarkerBrush"));
			this.PropertyChanged(this, new PropertyChangedEventArgs("X"));
			this.PropertyChanged(this, new PropertyChangedEventArgs("Y"));
		}
	}

	private void UpdateInvoke()
	{
		this.PropertyChanged(this, new PropertyChangedEventArgs("MarkerBrush"));
		this.PropertyChanged(this, new PropertyChangedEventArgs("X"));
		this.PropertyChanged(this, new PropertyChangedEventArgs("Y"));
	}

	public void UpdateLiveDataY()
	{
		if (this.PropertyChanged != null && _dispatcher != null)
		{
			_dispatcher.Invoke(new voiddelegate(UpdateLiveDataYInvoke));
		}
	}

	private void UpdateLiveDataYInvoke()
	{
		this.PropertyChanged(this, new PropertyChangedEventArgs("Y"));
	}
}
public interface IInstrumentEventDelegate
{
	void CleanCheckComplete(bool passed);

	void BackgroundComplete(bool passed);

	void RunAborted();

	void UpdateData(DataPoint dp);

	void UpdateAllData(DataPoint[] allData);

	void SampleCollectComplete();

	void Button1Pressed();

	void Button2Pressed();

	void InvalidMethod();
}
public class InstrumentControl : INotifyPropertyChanged
{
	public enum ConnectionState
	{
		NotConnected = 1,
		Connected = 2,
		ShuttingDown = 4096,
		ShutDown = 8192,
		ConnectionLost = 256,
		Unknown = 1,
		NoInstrumentControl = int.MaxValue
	}

	public enum enumInstrumentState
	{
		Unknown = 0,
		NotConnected = 0,
		Ready = 1,
		LowEnergy = 2
	}

	public enum enumRunMode
	{
		Unknown = 0,
		None = 0,
		SampleCollect = 1
	}

	public enum enumRunState
	{
		Ready = 0,
		Unknown = 0,
		CleanCheck = 1,
		BackgroundCheck = 2,
		LiveSignal = 4,
		CollectSample = 8
	}

	private delegate void CallBackDelegate();

	private BackgroundWorker _backgroundWorker;

	private const int SYSSTAT_UNCONNECTED = 1;

	private const int SYSSTAT_CONNECTED = 2;

	private const int SYSSTAT_CONNECTIONLOST = 256;

	private const int SYSSTAT_SHUTTINGDOWN = 4096;

	private const int SYSSTAT_SHUTDOWN = 8192;

	private const int SYSSTAT_SAMPTECH_CHANGED = 32768;

	private const int SYSSTAT_NOCONTROL = int.MaxValue;

	private double _progress;

	private MLDiag _currentStatus;

	private MLVersion _currentVersion;

	private MLSoftwareVersion _currentSoftwareVersion;

	private Stack<Exception> _exceptionList;

	private DataCurve _cleanSBCurve = new DataCurve();

	private DataCurve _cleanAbsCurve = new DataCurve();

	private MLResults _results;

	private string _progressText;

	private enumRunMode _runMode;

	private enumRunState _runState;

	private MLSettings _settings;

	public const int POLLING_TIME_DISCONNECTED = 500;

	public const int POLLING_TIME_CONNECTED = 500;

	public const int POLLING_TIMER_RUNNING = 250;

	public const int POLLING_TIME_CHECKINGSTATUS = 200;

	private static readonly object threadSynch = new object();

	protected int m_nCurrentUnits;

	protected int m_nTotalUnits;

	private IInstrumentEventDelegate _eventDelegate;

	private ConnectionState _instrumentState = ConnectionState.NotConnected;

	private DispatcherTimer _pollingTimer;

	private Dispatcher _mainDispatcher;

	private string m_SoftwareVersion = "";

	protected MLOPERATIONTYPE m_eOperationType;

	protected string _cleanFile;

	protected MLClean _clean;

	protected MLMethod _activeMethod;

	private bool _firstBackground = true;

	private DateTime _lastBackgroundRunTime;

	private int _liveSize;

	private int _handbackSize;

	private const int _DesiredLiveRes = 16;

	private double[] _liveFullData;

	private DataPoint[] _liveHandbackData;

	public static double RangeMaxFromWN => 4000.0;

	public static double RangeMaxToWN => 650.0;

	public int CurrentUnits
	{
		get
		{
			return m_nCurrentUnits;
		}
		set
		{
			m_nCurrentUnits = value;
		}
	}

	public int TotalUnits
	{
		get
		{
			return m_nTotalUnits;
		}
		set
		{
			m_nTotalUnits = value;
		}
	}

	public string SoftwareVersion
	{
		get
		{
			return m_SoftwareVersion;
		}
		set
		{
			m_SoftwareVersion = value;
		}
	}

	public MLOPERATIONTYPE OperationType
	{
		get
		{
			return m_eOperationType;
		}
		set
		{
			m_eOperationType = value;
		}
	}

	public IInstrumentEventDelegate EventDelegate
	{
		get
		{
			return _eventDelegate;
		}
		set
		{
			_eventDelegate = value;
		}
	}

	protected MLClean Clean
	{
		get
		{
			return _clean;
		}
		set
		{
			_clean = value;
		}
	}

	public MLMethod ActiveMethod
	{
		get
		{
			return _activeMethod;
		}
		set
		{
			if (_activeMethod == null || value == null || _activeMethod.MethodName != value.MethodName || _activeMethod.BkgScans != value.BkgScans || _activeMethod.Resolution != value.Resolution || _activeMethod.BkgCheckEverySample != value.BkgCheckEverySample)
			{
				_firstBackground = true;
			}
			_activeMethod = value;
			RaisePropertyChanged("ActiveMethod");
		}
	}

	public MLResults CurrentSample => _results;

	public enumInstrumentState State
	{
		get
		{
			enumInstrumentState enumInstrumentState = enumInstrumentState.Unknown;
			if (!Connected)
			{
				enumInstrumentState = enumInstrumentState.Unknown;
			}
			else if (_settings != null)
			{
				enumInstrumentState = enumInstrumentState.Ready;
				if (_currentStatus.InstrumentDiag.nEnergyStatus < _settings.EnergyMinMarginal)
				{
					enumInstrumentState |= enumInstrumentState.LowEnergy;
				}
				else if (_currentStatus.InstrumentDiag.nEnergyStatus < _settings.EnergyMin)
				{
					enumInstrumentState |= enumInstrumentState.LowEnergy;
				}
			}
			return enumInstrumentState;
		}
	}

	public double Progress
	{
		get
		{
			return _progress * 100.0;
		}
		set
		{
			_progress = value * 100.0;
		}
	}

	public string ProgressText
	{
		get
		{
			return _progressText;
		}
		set
		{
			_progressText = value;
			RaisePropertyChanged("ProgressText");
		}
	}

	public bool Connected => _instrumentState == ConnectionState.Connected;

	public bool LowEnergy => (State & enumInstrumentState.LowEnergy) == enumInstrumentState.LowEnergy;

	public bool HasInstrumentControl => _instrumentState != ConnectionState.NoInstrumentControl;

	public Visibility InstrumentControlVisibility
	{
		get
		{
			if (_instrumentState == ConnectionState.NoInstrumentControl)
			{
				return Visibility.Hidden;
			}
			return Visibility.Visible;
		}
	}

	public ConnectionState InstrumentState
	{
		get
		{
			return _instrumentState;
		}
		set
		{
			_instrumentState = value;
			RaisePropertyChanged("Connected");
		}
	}

	public enumRunMode RunMode => _runMode;

	public enumRunState RunState
	{
		get
		{
			return _runState;
		}
		set
		{
			_runState = value;
			if (_runState == enumRunState.CleanCheck)
			{
				ProgressText = TextStrings.PerformCleanCheck;
			}
			else if (_runState == enumRunState.BackgroundCheck)
			{
				ProgressText = TextStrings.CollectBackground;
			}
			else if (_runState == enumRunState.CollectSample)
			{
				ProgressText = TextStrings.CollectSample;
			}
		}
	}

	public Exception LastError => _exceptionList.Peek();

	public MLVersion CurrentVersion => _currentVersion;

	public event PropertyChangedEventHandler PropertyChanged;

	public void LoadAssemblyVersion()
	{
		string fullName = Assembly.GetExecutingAssembly().FullName;
		int num = fullName.IndexOf("Version");
		if (num >= 0)
		{
			fullName = fullName.Substring(num + 8);
			num = fullName.IndexOf(",");
			if (num >= 0)
			{
				fullName = fullName.Substring(0, num);
			}
		}
		else
		{
			fullName = "0.0.0.0";
		}
		SoftwareVersion = fullName;
	}

	public InstrumentControl()
	{
		_currentSoftwareVersion = new MLSoftwareVersion(SoftwareVersion);
		string fullName = Assembly.GetExecutingAssembly().FullName;
		fullName = fullName.Substring(0, fullName.LastIndexOf('\\') + 1);
		fullName += "MLQuant_HasControl.INI";
		_currentStatus = new MLDiag();
		_results = new MLResults();
		OperationType = MLOPERATIONTYPE.eMLNone;
		if (File.Exists(fullName))
		{
			InstrumentInvoke.HasControl = true;
			_pollingTimer = new DispatcherTimer();
			_pollingTimer.Interval = new TimeSpan(0, 0, 0, 0, 250);
			_pollingTimer.Tick += _pollingTimer_Tick;
			_exceptionList = new Stack<Exception>();
			_mainDispatcher = Dispatcher.CurrentDispatcher;
			_backgroundWorker = new BackgroundWorker();
			_backgroundWorker.DoWork += Run;
			_pollingTimer.Start();
		}
		else
		{
			InstrumentInvoke.HasControl = false;
			_instrumentState = ConnectionState.NoInstrumentControl;
			_pollingTimer = null;
			_backgroundWorker = null;
			_exceptionList = null;
			_mainDispatcher = null;
		}
	}

	private void _pollingTimer_Tick(object sender, EventArgs e)
	{
		if (!Connected)
		{
			return;
		}
		bool flag = false;
		lock (threadSynch)
		{
			Console.WriteLine("Polling ProgressState...");
			MLProgress mLProgress = CheckProgress();
			FTIR_STATE state = mLProgress.m_progress.state;
			string[] obj = new string[5] { "CheckProgressStruct - State = ", null, null, null, null };
			int num = (int)state;
			obj[1] = num.ToString();
			obj[2] = " (";
			obj[3] = state.ToString();
			obj[4] = ")";
			Console.WriteLine(string.Concat(obj));
			m_nCurrentUnits = mLProgress.m_progress.currentUnits;
			m_nTotalUnits = mLProgress.m_progress.totalUnits;
			if (state != FTIR_STATE.FTIR_Collecting && state != FTIR_STATE.FTIR_Transmitting && state != FTIR_STATE.FTIR_Init)
			{
				switch (OperationType)
				{
				case MLOPERATIONTYPE.eMLRunCleanOperation:
				case MLOPERATIONTYPE.eMLRunBkgdOperation:
				case MLOPERATIONTYPE.eMLRunSpectrumOperation:
					_pollingTimer.Stop();
					OperationType = MLOPERATIONTYPE.eMLNone;
					flag = true;
					Console.WriteLine("PollingTimer Stopped - (Operation switched to None) from State = " + state);
					break;
				case MLOPERATIONTYPE.eMLInvalidOperation:
				case MLOPERATIONTYPE.eMLNone:
					_pollingTimer.Stop();
					Console.WriteLine("PollingTimer Stoppedfrom State = " + state);
					break;
				case (MLOPERATIONTYPE)0:
					break;
				}
			}
		}
		if (flag)
		{
			RaisePropertyChanged("Progress");
		}
	}

	public void LoadClean(string fileName)
	{
		_cleanFile = fileName;
		Clean = MLClean.LoadFile(fileName);
	}

	public void Abort()
	{
		if (HasInstrumentControl)
		{
			InstrumentInvoke.KillCollection();
			RunState = enumRunState.Ready;
			if (EventDelegate != null)
			{
				EventDelegate.RunAborted();
			}
		}
	}

	public void Deinitialize()
	{
		if (HasInstrumentControl)
		{
			InstrumentInvoke.Deinit();
		}
	}

	public bool BackgroundRequired()
	{
		bool flag = false;
		if (ActiveMethod != null)
		{
			flag = ActiveMethod.BkgCheckEverySample || _firstBackground;
			if (!flag && (DateTime.Now - _lastBackgroundRunTime).TotalMinutes > ActiveMethod.BkgValidMinutes)
			{
				flag = true;
			}
		}
		return flag;
	}

	private void RaisePropertyChanged(string propertyName)
	{
		if (this.PropertyChanged != null)
		{
			this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
		}
	}

	public void Start()
	{
		if (_backgroundWorker != null && HasInstrumentControl)
		{
			_backgroundWorker.RunWorkerAsync();
		}
	}

	public void Stop()
	{
		if (_backgroundWorker != null && HasInstrumentControl)
		{
			_backgroundWorker.CancelAsync();
		}
	}

	private void Run(object sender, DoWorkEventArgs e)
	{
		try
		{
			while (!_backgroundWorker.CancellationPending)
			{
				Console.WriteLine("Run() WhileLoop...");
				if (_instrumentState == ConnectionState.NotConnected || _instrumentState == ConnectionState.NotConnected)
				{
					lock (threadSynch)
					{
						Connect();
					}
					Console.WriteLine("Run() Sleep Not Connected...(" + 500 + ")");
					Thread.Sleep(500);
					if (_instrumentState == ConnectionState.NotConnected || _instrumentState == ConnectionState.NotConnected)
					{
						break;
					}
				}
				else
				{
					if (_instrumentState != ConnectionState.Connected)
					{
						continue;
					}
					bool flag = true;
					lock (threadSynch)
					{
						flag = _pollingTimer.IsEnabled;
					}
					if (!flag)
					{
						if (RunState == enumRunState.LiveSignal)
						{
							GetLiveSignal();
							Console.WriteLine("Run() Sleep LiveSignal...");
							Thread.Sleep(200);
							continue;
						}
						Console.WriteLine("Run() Status..." + RunState);
						CheckStatus();
						if (RunState == enumRunState.CleanCheck || RunState == enumRunState.BackgroundCheck || RunState == enumRunState.CollectSample)
						{
							if (RunState == enumRunState.CleanCheck)
							{
								CheckCleanProgress();
							}
							else if (RunState == enumRunState.BackgroundCheck)
							{
								CheckBackgroundProgress();
							}
							else if (RunState == enumRunState.CollectSample)
							{
								CheckSampleProgress();
							}
						}
						Thread.Sleep(200);
					}
					else
					{
						Console.WriteLine("Run() Sleep Instrument Polling running...(" + 500 + ")");
						Thread.Sleep(500);
					}
				}
			}
		}
		catch
		{
			Console.WriteLine("Run() Exception occurred in processing the Connection/Progress Status Updates");
			Console.WriteLine("Run() Instrument Control is exiting 'Run' thread without further updates");
		}
	}

	private void GetLiveSignal()
	{
		if (_liveSize <= 0 || _liveFullData == null)
		{
			return;
		}
		double actualFrom = 0.0;
		double actualTo = 0.0;
		int actualRes = 0;
		Console.WriteLine("*** GetLiveSignal ...");
		if (InstrumentInvoke.GetLiveSpectrum(ActiveMethod.FromRange, ActiveMethod.ToRange, ActiveMethod.Resolution, ActiveMethod.XType, ActiveMethod.YType, _liveFullData, _liveSize, ref actualFrom, ref actualTo, ref actualRes) > 0 && _handbackSize > 0)
		{
			int num = 16 / ActiveMethod.Resolution;
			if (num <= 0)
			{
				num = 1;
			}
			for (int i = 0; i < _handbackSize; i++)
			{
				_liveHandbackData[i].Y = _liveFullData[i * num];
			}
			if (EventDelegate != null)
			{
				EventDelegate.UpdateAllData(_liveHandbackData);
			}
		}
		else
		{
			Console.WriteLine("*** GetLiveSignal ... ERROR");
		}
	}

	private MLProgress CheckProgress()
	{
		MLProgress pProgress = new MLProgress();
		pProgress.m_progress.state = FTIR_STATE.FTIR_Init;
		if (InstrumentInvoke.CheckProgressStruct(ref pProgress) > 0)
		{
			int num = pProgress.m_progress.currentUnits;
			int totalUnits = pProgress.m_progress.totalUnits;
			Console.WriteLine("CheckProgress() State = " + pProgress.m_progress.state);
			if (pProgress.m_progress.state == FTIR_STATE.FTIR_DataReady)
			{
				num = totalUnits;
			}
			Console.WriteLine("Progress is " + num + " of " + totalUnits);
			_progress = (double)num / (double)totalUnits;
			if (pProgress.m_progress.recentRejected > 0 && pProgress.m_progress.rejectReason != 65552)
			{
				Console.WriteLine("REJECTEDSCANS! " + pProgress.m_progress.recentRejected + " (Total=" + pProgress.m_progress.numRejectsSame + "), Reason = " + pProgress.m_progress.rejectReason);
			}
			RaisePropertyChanged("Progress");
			RaisePropertyChanged("ProgressTitle");
		}
		else
		{
			pProgress.m_progress.state = FTIR_STATE.FTIR_Error;
		}
		return pProgress;
	}

	private bool CheckUntilNoLongerDataReady()
	{
		bool flag = false;
		int num = 100;
		FTIR_STATE state;
		do
		{
			state = CheckProgress().m_progress.state;
			if (state == FTIR_STATE.FTIR_DataReady)
			{
				Thread.Sleep(1);
			}
			else
			{
				flag = true;
			}
			num--;
		}
		while (state == FTIR_STATE.FTIR_DataReady && num > 0);
		if (flag)
		{
			Console.WriteLine("Saw transition away from DataReady - maxtries = " + (100 - num));
		}
		else
		{
			Console.WriteLine("xxxxxxxxxxxx FAILED transition away from DataReady - state = " + state);
		}
		return flag;
	}

	private bool CheckUntilCollecting()
	{
		bool flag = false;
		int num = 100;
		FTIR_STATE state;
		do
		{
			state = CheckProgress().m_progress.state;
			if (state != FTIR_STATE.FTIR_Collecting)
			{
				Thread.Sleep(1);
			}
			else
			{
				flag = true;
			}
			num--;
		}
		while (state != FTIR_STATE.FTIR_Collecting && num > 0);
		if (flag)
		{
			Console.WriteLine("Saw transition to Collecting - maxtries = " + (100 - num));
		}
		else
		{
			Console.WriteLine("xxxxxxxxxxxx FAILED transition to Collecting - state = " + state);
		}
		return flag;
	}

	private void CheckSampleProgress()
	{
		Console.WriteLine("CheckSampleProgress()");
		FTIR_STATE state = CheckProgress().m_progress.state;
		try
		{
			if (state != FTIR_STATE.FTIR_DataReady)
			{
				return;
			}
			Console.WriteLine("Seeing DataReady state");
			int spectrumSize = InstrumentInvoke.GetSpectrumSize();
			if (spectrumSize > 0)
			{
				double[] array = new double[spectrumSize];
				double actualFrom = 0.0;
				double actualTo = 0.0;
				int actualRes = 0;
				int spectrum = InstrumentInvoke.GetSpectrum(array, spectrumSize, ref actualFrom, ref actualTo, ref actualRes);
				Console.WriteLine("Got Spectrum (ret = " + spectrum + ") : " + spectrum + " Points, from " + actualFrom + " to " + actualTo);
				if (_results.SampleCurves == null)
				{
					_results.SampleCurves = new MLResults.DataCurveID[1];
					_results.SampleCurves[0] = new MLResults.DataCurveID();
				}
				_results.SampleCurves[0].SetData(actualFrom, actualTo, array, spectrum, ActiveMethod.XType, ActiveMethod.YType);
				_results.SampleCurves[0].timePoint = DateTime.Now;
				_results.SampleCurves[0].curveType = CURVE_DATA_TYPE.CDT_SPECTRUMDATA;
				OperationType = MLOPERATIONTYPE.eMLNone;
				RunState = enumRunState.Ready;
				array = null;
				CheckUntilNoLongerDataReady();
				if (EventDelegate != null)
				{
					EventDelegate.SampleCollectComplete();
					Console.WriteLine("Called EventDelegate for SampleCollectComplete");
				}
				else
				{
					Console.WriteLine("Failed to Call EventDelegate for SampleCollectComplete (was null)");
				}
			}
			else
			{
				Console.WriteLine("Failed GetSpectrumSize (siz = " + spectrumSize + ")");
			}
		}
		catch (Exception ex)
		{
			RaiseError(ex);
		}
	}

	private void CheckBackgroundProgress()
	{
		Console.WriteLine("CheckBackgroundProgress()");
		FTIR_STATE state = CheckProgress().m_progress.state;
		try
		{
			if (state != FTIR_STATE.FTIR_DataReady)
			{
				return;
			}
			int singleBeamSize = InstrumentInvoke.GetSingleBeamSize();
			Console.WriteLine("Checked Single Beam Size = " + singleBeamSize);
			if (singleBeamSize > 0)
			{
				double[] array = new double[singleBeamSize];
				double actualFrom = 0.0;
				double actualTo = 0.0;
				int actualRes = 0;
				int singleBeam = InstrumentInvoke.GetSingleBeam(array, singleBeamSize, ref actualFrom, ref actualTo, ref actualRes);
				Console.WriteLine("Got Single Beam (ret = " + singleBeam + ") = From " + actualFrom + " To " + actualTo + " at Res " + actualRes);
				if (_results.RefCurves == null)
				{
					_results.RefCurves = new MLResults.DataCurveID[1];
					_results.RefCurves[0] = new MLResults.DataCurveID();
				}
				_results.RefCurves[0].SetData(actualFrom, actualTo, array, singleBeam, ActiveMethod.XType, DATAYTYPE.YT_ARB);
				_results.RefCurves[0].timePoint = DateTime.Now;
				_results.RefCurves[0].curveType = CURVE_DATA_TYPE.CDT_BKGREFDATA;
				_firstBackground = false;
				_lastBackgroundRunTime = _results.RefCurves[0].timePoint;
				OperationType = MLOPERATIONTYPE.eMLNone;
				RunState = enumRunState.Ready;
				array = null;
				CheckUntilNoLongerDataReady();
			}
			if (EventDelegate != null)
			{
				EventDelegate.BackgroundComplete(singleBeamSize > 0);
				Console.WriteLine("Called EventDelegate for BackgroundComplete");
			}
			else
			{
				Console.WriteLine("Failed to Call EventDelegate for BackgroundComplete (was null)");
			}
		}
		catch (Exception ex)
		{
			RaiseError(ex);
		}
	}

	private void CheckCleanProgress()
	{
		Console.WriteLine("CheckCleanProgress()");
		FTIR_STATE state = CheckProgress().m_progress.state;
		try
		{
			if (state != FTIR_STATE.FTIR_DataReady)
			{
				return;
			}
			bool flag = false;
			int cleanSize = InstrumentInvoke.GetCleanSize();
			if (cleanSize <= 0)
			{
				return;
			}
			double[] array = new double[cleanSize];
			double actualFrom = 0.0;
			double actualTo = 0.0;
			int actualRes = 0;
			int clean = InstrumentInvoke.GetClean(array, cleanSize, ref actualFrom, ref actualTo, ref actualRes);
			if (clean <= 0)
			{
				throw new Exception(string.Format(TextStrings.GetCleanError, clean));
			}
			_cleanSBCurve.SetData(actualFrom, actualTo, array, cleanSize, ActiveMethod.XType, DATAYTYPE.YT_ARB);
			if (!Clean.DoesBkgdSBExist() || Clean.Resolution != 4 || Clean.LaserWN != _currentVersion.m_version.dLaserWN || Clean.BkgdSB.FirstX != actualFrom || Clean.BkgdSB.LastX != actualTo)
			{
				flag = true;
				Clean.BkgdSB = new DataCurve(_cleanSBCurve);
				Clean.LaserWN = _currentVersion.InstrumentVersion.dLaserWN;
				Clean.Resolution = 4;
				if (_cleanFile != null)
				{
					Clean.WriteToFile(_cleanFile, null);
				}
			}
			else
			{
				double[] array2 = new double[_cleanSBCurve.NumPoints];
				InstrumentInvoke.GetRatioSpectrum(Clean.BkgdSB.YData, _cleanSBCurve.YData, array2, _cleanSBCurve.NumPoints, DATAYTYPE.YT_Abs);
				_cleanAbsCurve.SetData(_cleanSBCurve.FirstX, _cleanSBCurve.LastX, array2, _cleanSBCurve.NumPoints, _cleanSBCurve.DataXType, DATAYTYPE.YT_Abs);
				int num = DLSAlg.DLSAlg_dSGDerivative(_cleanAbsCurve.YData, _cleanAbsCurve.NumPoints, 15, 2, array2);
				double num2 = 0.0;
				if (num != 0)
				{
					for (int i = 0; i < _cleanAbsCurve.NumPoints; i++)
					{
						array2[i] = 0.0 - array2[i];
					}
					DataCurve dataCurve = new DataCurve(_cleanAbsCurve.FirstX, _cleanAbsCurve.LastX, array2, _cleanAbsCurve.NumPoints, _cleanAbsCurve.DataXType, _cleanAbsCurve.DataYType);
					num2 = dataCurve.SubCurve(4000.0, 2400.0).MaxY;
					DataCurve dataCurve2 = dataCurve.SubCurve(2000.0, 700.0);
					if (dataCurve2.MaxY > num2)
					{
						num2 = dataCurve2.MaxY;
					}
				}
				else
				{
					num2 = ActiveMethod.CleanThreshold + 1.0;
				}
				if (num2 < ActiveMethod.CleanThreshold)
				{
					flag = true;
				}
				if (flag)
				{
					Clean.BkgdSB = new DataCurve(_cleanSBCurve);
					Clean.LaserWN = _currentVersion.InstrumentVersion.dLaserWN;
					Clean.Resolution = 4;
					if (_cleanFile != null)
					{
						Clean.WriteToFile(_cleanFile, null);
					}
				}
			}
			RunState = enumRunState.Ready;
			array = null;
			CheckUntilNoLongerDataReady();
			if (EventDelegate != null)
			{
				EventDelegate.CleanCheckComplete(flag);
			}
		}
		catch (Exception ex)
		{
			RaiseError(ex);
		}
	}

	private void CheckStatus()
	{
		try
		{
			if (!Connected)
			{
				return;
			}
			_runMode = enumRunMode.SampleCollect;
			enumInstrumentState state = State;
			InstrumentInvoke.GetStatusEx(ref _currentStatus);
			enumInstrumentState state2 = State;
			if (state2 != state)
			{
				RaisePropertyChanged("State");
				if ((state2 & enumInstrumentState.LowEnergy) != (state & enumInstrumentState.LowEnergy))
				{
					RaisePropertyChanged("LowEnergy");
				}
			}
		}
		catch (Exception item)
		{
			_exceptionList.Push(item);
		}
	}

	public DataPoint[] StartLiveSignal(Dispatcher mainDispatcher)
	{
		DataPoint[] array = null;
		try
		{
			RunState = enumRunState.LiveSignal;
			if (_liveSize == 0)
			{
				double actualFrom = 0.0;
				double actualTo = 0.0;
				int actualRes = 0;
				Console.WriteLine("*** Starting LiveSignal with resolution " + ActiveMethod.Resolution);
				_liveSize = InstrumentInvoke.GetLiveSpectrum(ActiveMethod.FromRange, ActiveMethod.ToRange, ActiveMethod.Resolution, ActiveMethod.XType, ActiveMethod.YType, null, 0, ref actualFrom, ref actualTo, ref actualRes);
				if (_liveSize > 0)
				{
					int num = 16 / ActiveMethod.Resolution;
					if (num <= 0)
					{
						num = 1;
					}
					_liveFullData = new double[_liveSize];
					_handbackSize = _liveSize / num;
					array = new DataPoint[_handbackSize];
					for (int i = 0; i < _handbackSize; i++)
					{
						double num2 = (ActiveMethod.ToRange - ActiveMethod.FromRange) / ((double)_liveSize - 1.0);
						num2 *= (double)num;
						array[i] = new DataPoint(mainDispatcher);
						array[i].Y = 0.0;
						array[i].X = ActiveMethod.FromRange + num2 * (double)i;
					}
				}
				else
				{
					Console.WriteLine("*** Starting LiveSignal ... ERROR");
				}
			}
			_liveHandbackData = array;
		}
		catch (Exception ex)
		{
			RaiseError(ex);
		}
		return array;
	}

	public void StopLiveSignal()
	{
		try
		{
			RunState = enumRunState.Ready;
			_liveSize = 0;
			_handbackSize = 0;
			_liveFullData = null;
		}
		catch (Exception ex)
		{
			RaiseError(ex);
		}
	}

	public void RunSample()
	{
		if (Connected && RunState == enumRunState.Ready && ActiveMethod != null)
		{
			if ((State & enumInstrumentState.LowEnergy) == enumInstrumentState.LowEnergy)
			{
				return;
			}
			try
			{
				_progress = 0.0;
				_pollingTimer.Stop();
				RaisePropertyChanged("Progress");
				_results.DiagInfo = new MLDiag();
				_results.DiagInfo = _currentStatus;
				_results.VersionInfo = new MLVersion();
				_results.VersionInfo = _currentVersion;
				_results.DiagInfoLimits = new MLDiagLimits();
				_results.SetSoftwareVersionInfo(_currentSoftwareVersion);
				Console.WriteLine("*** Running Sample with " + ActiveMethod.SampleScans + " Scans");
				if (InstrumentInvoke.StartSpectrum(ActiveMethod.SampleScans, ActiveMethod.FromRange, ActiveMethod.ToRange, ActiveMethod.Resolution, ActiveMethod.XType, ActiveMethod.YType, bAutoSetUnknown: true) > 0)
				{
					CheckUntilCollecting();
					RunState = enumRunState.CollectSample;
					OperationType = MLOPERATIONTYPE.eMLRunSpectrumOperation;
					_pollingTimer.Start();
					SystemLogFactory.SystemLog.AddSysLogEntry(SysLogType.DataCollectStarted, MLConfig.CurrentConfig.CurrentUser, ActiveMethod.MethodFullPath);
				}
				else
				{
					Console.WriteLine("!!! Failed to StartSpectrum!");
				}
				return;
			}
			catch (Exception ex)
			{
				RaiseError(ex);
				return;
			}
		}
		Console.WriteLine("Trying to run sample - Instrument Not Connected or Not Ready");
	}

	public void RunBackground()
	{
		if (Connected && RunState == enumRunState.Ready && ActiveMethod != null)
		{
			if ((State & enumInstrumentState.LowEnergy) == enumInstrumentState.LowEnergy)
			{
				return;
			}
			try
			{
				_progress = 0.0;
				_pollingTimer.Stop();
				RaisePropertyChanged("Progress");
				Console.WriteLine("*** Running Background with " + ActiveMethod.BkgScans + " Scans");
				if (InstrumentInvoke.StartSingleBeam(ActiveMethod.BkgScans, ActiveMethod.FromRange, ActiveMethod.ToRange, ActiveMethod.Resolution, bAutoSetBkg: true, bAutoSetClean: false) > 0)
				{
					CheckUntilCollecting();
					OperationType = MLOPERATIONTYPE.eMLRunBkgdOperation;
					RunState = enumRunState.BackgroundCheck;
					_pollingTimer.Start();
				}
				else
				{
					Console.WriteLine("!!! Failed to StartSingleBeam background!");
				}
				return;
			}
			catch (Exception ex)
			{
				RaiseError(ex);
				return;
			}
		}
		Console.WriteLine("Trying to run background - Instrument Not Connected or Not Ready");
	}

	public void RunClean()
	{
		if (Connected && RunState == enumRunState.Ready && ActiveMethod != null)
		{
			if ((State & enumInstrumentState.LowEnergy) == enumInstrumentState.LowEnergy)
			{
				return;
			}
			try
			{
				_progress = 0.0;
				_pollingTimer.Stop();
				RaisePropertyChanged("Progress");
				Console.WriteLine("*** Running Clean with " + ActiveMethod.NumCleanScans + " Scans");
				Console.WriteLine("*** (ActiveMethod Clean Check = " + ActiveMethod.bCleanCheck + ")");
				if (InstrumentInvoke.StartSingleBeam(ActiveMethod.NumCleanScans, 4000.0, 650.0, 4, bAutoSetBkg: false, bAutoSetClean: true) > 0)
				{
					CheckUntilCollecting();
					RunState = enumRunState.CleanCheck;
					OperationType = MLOPERATIONTYPE.eMLRunCleanOperation;
					_pollingTimer.Start();
				}
				else
				{
					Console.WriteLine("!!! Failed to StartSingleBeam clean!");
				}
				return;
			}
			catch (Exception ex)
			{
				RaiseError(ex);
				return;
			}
		}
		Console.WriteLine("Trying to run clean check - Instrument Not Connected or Not Ready");
	}

	private void RaiseError(Exception ex)
	{
		_exceptionList.Push(ex);
		RaisePropertyChanged("LastError");
	}

	public void Connect()
	{
		if (!HasInstrumentControl)
		{
			if (InstrumentInvoke.InitializationCheck() >= 0)
			{
				InstrumentState = ConnectionState.Connected;
				_currentVersion = new MLVersion();
				InstrumentInvoke.GetVersionEx(_currentVersion);
				_settings = new MLSettings((ML_INSTRUMENT_TYPE)_currentVersion.InstrumentVersion.instrType);
				CheckStatus();
				_mainDispatcher.BeginInvoke(new CallBackDelegate(InitializeStatusCallBacks), null);
			}
			else
			{
				InstrumentState = ConnectionState.NotConnected;
			}
		}
	}

	private void InitializeStatusCallBacks()
	{
		RegisterForStatusAndButtonUpdates();
		if (Application.Current != null && Application.Current.MainWindow != null)
		{
			((HwndSource)PresentationSource.FromVisual(Application.Current.MainWindow)).AddHook(HandleMessages);
		}
	}

	private IntPtr HandleMessages(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
	{
		if (msg == InstrumentInvoke.StatusMessageID)
		{
			InstrumentState = (ConnectionState)(int)wParam;
			Console.WriteLine("Connection Changed: " + _instrumentState);
		}
		else if (msg == InstrumentInvoke.Button1MessageID)
		{
			if (EventDelegate != null)
			{
				Console.WriteLine("**** Calling Button1Pressed()");
				EventDelegate.Button1Pressed();
			}
		}
		else if (msg == InstrumentInvoke.Button2MessageID && EventDelegate != null)
		{
			Console.WriteLine("**** Calling Button2Pressed()");
			EventDelegate.Button2Pressed();
		}
		return IntPtr.Zero;
	}

	private void RegisterForStatusAndButtonUpdates()
	{
		InstrumentInvoke.RegisterStatus();
		InstrumentInvoke.RegisterButton1();
		InstrumentInvoke.RegisterButton2();
	}

	private int Init()
	{
		int result = 0;
		if (!HasInstrumentControl)
		{
			result = InstrumentInvoke.InitializationCheck();
		}
		return result;
	}
}
internal class InstrumentInvoke
{
	public class InstrumentFailedException : Exception
	{
		public int nInitCode;

		public InstrumentFailedException(int code)
		{
			nInitCode = code;
		}
	}

	private static int m_Button1MessageID;

	private static int m_Button2MessageID;

	private static int m_StatusMessageID;

	public const double MLInstrumentRangeMaxFrom = 4000.0;

	public const double MLInstrumentRangeMaxTo = 650.0;

	public const int MLCleanRes = 4;

	protected static bool m_bHasControl;

	protected static bool m_bInitialized;

	protected static bool m_bInitExceptionMessageError;

	protected static bool m_binitializing;

	public static int StatusMessageID => m_StatusMessageID;

	public static int Button1MessageID => m_Button1MessageID;

	public static int Button2MessageID => m_Button2MessageID;

	public static bool HasControl
	{
		get
		{
			return m_bHasControl;
		}
		set
		{
			m_bHasControl = value;
		}
	}

	public static bool Initialized
	{
		get
		{
			return m_bInitialized;
		}
		set
		{
			m_bInitialized = value;
		}
	}

	public static bool initializing
	{
		get
		{
			return m_binitializing;
		}
		set
		{
			m_binitializing = value;
		}
	}

	public static int InitializationCheck()
	{
		int num = 0;
		if (HasControl)
		{
			bool flag = false;
			while (!Initialized && !flag)
			{
				if (!initializing && !Initialized)
				{
					initializing = true;
					num = Init();
					if (num == 0)
					{
						Initialized = true;
						initializing = false;
					}
					else
					{
						Deinit();
						flag = true;
						initializing = false;
					}
				}
			}
		}
		return num;
	}

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_GetVersion(ref int fwRev, ref int dllRev, ref int spareRev);

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_GetInstrumentInfo(ref MLInstrInfo pInstrInfo);

	public static int GetVersionEx(MLVersion vInfo)
	{
		InitializationCheck();
		int num = -8;
		if (HasControl)
		{
			num = 0;
			bool flag = false;
			try
			{
				num = new ExFunctionInvoke().GetVersionEx(ref vInfo.m_version);
				MLInstrInfo pInstrInfo = new MLInstrInfo
				{
					nVersion = 101
				};
				num = FTIRInst_GetInstrumentInfo(ref pInstrInfo);
				if (num == 0)
				{
					vInfo.InstrumentInformation = pInstrInfo;
				}
				flag = true;
			}
			catch
			{
			}
			if (!flag)
			{
				num = FTIRInst_GetVersion(ref vInfo.m_version.fwRev, ref vInfo.m_version.dllRev, ref vInfo.m_version.spareRev);
				vInfo.m_version.dLaserWN = 7633.0;
				vInfo.m_version.instrType = 0;
				vInfo.m_version.sampleTechType = 1;
				vInfo.m_version.atrType = 1;
				vInfo.m_version.dBasePathLength = 0.1;
				vInfo.m_version.dAdjustPathLength = 0.0;
			}
		}
		return num;
	}

	public static int CheckProgressStruct(ref MLProgress pProgress)
	{
		InitializationCheck();
		if (HasControl)
		{
			return FTIRInst_CheckProgressStruct(ref pProgress.m_progress);
		}
		return -8;
	}

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_CheckProgressStruct(ref _progress pProgress);

	public static int GetSingleBeamSize()
	{
		double actualFrom = 0.0;
		double actualTo = 0.0;
		int actualRes = 0;
		InitializationCheck();
		if (HasControl)
		{
			Console.WriteLine("*** GetSingleBeamSize() called");
			return FTIRInst_dptrGetSingleBeam(null, 0, ref actualFrom, ref actualTo, ref actualRes);
		}
		return -8;
	}

	public static int GetSingleBeam(double[] array, int size, ref double actualFrom, ref double actualTo, ref int actualRes)
	{
		InitializationCheck();
		if (HasControl)
		{
			Console.WriteLine("*** GetSingleBeam() called");
			return FTIRInst_dptrGetSingleBeam(array, size, ref actualFrom, ref actualTo, ref actualRes);
		}
		return -8;
	}

	public static int GetRatioSpectrum(double[] bkgarray, double[] smparray, double[] outarray, int size, DATAYTYPE ytype)
	{
		InitializationCheck();
		if (HasControl)
		{
			return FTIRInst_dptrGetRatioSpectrum(bkgarray, smparray, outarray, size, ytype);
		}
		return -8;
	}

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_dptrGetRatioSpectrum(double[] bkgarray, double[] smparray, double[] outarray, int size, DATAYTYPE ytype);

	public static int GetCleanSize()
	{
		double actualFrom = 0.0;
		double actualTo = 0.0;
		int actualRes = 0;
		return GetClean(null, 0, ref actualFrom, ref actualTo, ref actualRes);
	}

	public static int GetClean(double[] array, int size, ref double actualFrom, ref double actualTo, ref int actualRes)
	{
		InitializationCheck();
		if (HasControl)
		{
			try
			{
				Console.WriteLine("*** GetClean() tried");
				return FTIRInst_dptrGetClean(array, size, ref actualFrom, ref actualTo, ref actualRes);
			}
			catch
			{
				Console.WriteLine("*** GetSingleBeam() called (inside GetClean)");
				return FTIRInst_dptrGetSingleBeam(array, size, ref actualFrom, ref actualTo, ref actualRes);
			}
		}
		return -8;
	}

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_dptrGetClean(double[] array, int size, ref double actualFrom, ref double actualTo, ref int actualRes);

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_dptrGetSingleBeam(double[] array, int size, ref double actualFrom, ref double actualTo, ref int actualRes);

	public static int GetLiveSpectrum(double from, double to, int res, DATAXTYPE xtype, DATAYTYPE ytype, double[] array, int size, ref double actualFrom, ref double actualTo, ref int actualRes)
	{
		InitializationCheck();
		if (HasControl)
		{
			return FTIRInst_dptrGetLiveSpectrum(ref from, ref to, res, xtype, ytype, array, size, ref actualFrom, ref actualTo, ref actualRes);
		}
		return -8;
	}

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_dptrGetLiveSpectrum(ref double from, ref double to, int res, DATAXTYPE xtype, DATAYTYPE ytype, double[] array, int size, ref double actualFrom, ref double actualTo, ref int actualRes);

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_dptrGetSpectrum(double[] array, int size, ref double actualFrom, ref double actualTo, ref int actualRes);

	public static int GetSpectrumSize()
	{
		double actualFrom = 0.0;
		double actualTo = 0.0;
		int actualRes = 0;
		InitializationCheck();
		if (HasControl)
		{
			Console.WriteLine("*** GetSpectrumSize() called");
			return FTIRInst_dptrGetSpectrum(null, 0, ref actualFrom, ref actualTo, ref actualRes);
		}
		return -8;
	}

	public static int KillCollection()
	{
		InitializationCheck();
		if (HasControl)
		{
			return FTIRInst_KillCollection();
		}
		return -8;
	}

	[DllImport("FTIRInst.dll", SetLastError = true)]
	private static extern int FTIRInst_KillCollection();

	public static int Init()
	{
		int result = -3;
		if (HasControl)
		{
			try
			{
				Console.WriteLine("Init...");
				result = ((!m_bInitExceptionMessageError) ? FTIRInst_Init() : (-3));
				Console.WriteLine("...(" + result + ")");
			}
			catch
			{
				if (!m_bInitExceptionMessageError)
				{
					Console.WriteLine("ERROR: Instrument Control interface DLL (FTIRInst.DLL) cannot load.\nThere was a problem trying to load the instrument interface component.\nThe instrument cannot communicate unless the instrument driver has been properly installed.");
				}
				m_bInitExceptionMessageError = true;
			}
		}
		else
		{
			result = -8;
		}
		return result;
	}

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode, SetLastError = true)]
	private static extern int FTIRInst_Init();

	public static int Deinit()
	{
		if (HasControl)
		{
			try
			{
				return FTIRInst_Deinit();
			}
			catch
			{
				return -201;
			}
		}
		return -8;
	}

	[DllImport("FTIRInst.dll", CharSet = CharSet.Unicode, SetLastError = true)]
	private static extern int FTIRInst_Deinit();

	public static int GetStatusEx(ref MLDiag dStatus)
	{
		InitializationCheck();
		int result = 0;
		if (HasControl)
		{
			try
			{
				result = new ExFunctionInvoke().GetStatusEx(ref dStatus.m_diag);
			}
			catch
			{
			}
		}
		else
		{
			result = -8;
		}
		return result;
	}

	public static int RegisterStatus()
	{
		if (HasControl)
		{
			try
			{
				return FTIRInst_RegisterStatus(new WindowInteropHelper(Application.Current.MainWindow).Handle, ref m_StatusMessageID);
			}
			catch (Exception)
			{
				return 0;
			}
		}
		return -8;
	}

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_RegisterStatus(IntPtr whandle, ref int wm_MessageID);

	public static int RegisterButton1()
	{
		if (HasControl)
		{
			try
			{
				return FTIRInst_RegisterButton1(new WindowInteropHelper(Application.Current.MainWindow).Handle, ref m_Button1MessageID);
			}
			catch
			{
				return 0;
			}
		}
		return -8;
	}

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_RegisterButton1(IntPtr whandle, ref int m_A2);

	public static int RegisterButton2()
	{
		if (HasControl)
		{
			try
			{
				return FTIRInst_RegisterButton2(new WindowInteropHelper(Application.Current.MainWindow).Handle, ref m_Button2MessageID);
			}
			catch
			{
				return 0;
			}
		}
		return -8;
	}

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_RegisterButton2(IntPtr whandle, ref int wm_MessageID);

	public static int StartSingleBeam(int numScans, double from, double to, int res, bool bAutoSetBkg, bool bAutoSetClean)
	{
		InitializationCheck();
		Console.WriteLine("*** StartSingleBeam() called");
		return FTIRInst_dptrStartSingleBeam(numScans, ref from, ref to, res, bAutoSetBkg ? 1 : 0, bAutoSetClean ? 1 : 0);
	}

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_dptrStartSingleBeam(int numScans, ref double from, ref double to, int res, int bAutoSetBkg, int bAutoSetClean);

	public static int GetSpectrum(double[] array, int size, ref double actualFrom, ref double actualTo, ref int actualRes)
	{
		InitializationCheck();
		Console.WriteLine("*** GetSpectrum() called");
		return FTIRInst_dptrGetSpectrum(array, size, ref actualFrom, ref actualTo, ref actualRes);
	}

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_dptrStartSpectrum(int numScans, ref double from, ref double to, int res, DATAXTYPE xtype, DATAYTYPE ytype, int bAutoSetUnknown);

	public static int StartSpectrum(int numScans, double from, double to, int res, DATAXTYPE xtype, DATAYTYPE ytype, bool bAutoSetUnknown)
	{
		InitializationCheck();
		Console.WriteLine("*** StartSpectrum() called");
		return FTIRInst_dptrStartSpectrum(numScans, ref from, ref to, res, xtype, ytype, bAutoSetUnknown ? 1 : 0);
	}
}
public class ExFunctionInvoke
{
	public int GetVersionEx(ref _instrumentMLVersionEx _vInfo)
	{
		return FTIRInst_GetVersionEx(ref _vInfo);
	}

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_GetVersionEx(ref _instrumentMLVersionEx _vInfo);

	public int GetStatusEx(ref _instrumentMLDiag _dStatus)
	{
		return FTIRInst_GetStatusEx(ref _dStatus);
	}

	[DllImport("FTIRInst.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
	private static extern int FTIRInst_GetStatusEx(ref _instrumentMLDiag _dStatus);
}
[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "4.0.0.0")]
[DebuggerNonUserCode]
[CompilerGenerated]
internal class TextStrings
{
	private static ResourceManager resourceMan;

	private static CultureInfo resourceCulture;

	[EditorBrowsable(EditorBrowsableState.Advanced)]
	internal static ResourceManager ResourceManager
	{
		get
		{
			if (resourceMan == null)
			{
				resourceMan = new ResourceManager("MLInstrumentControl.TextStrings", typeof(TextStrings).Assembly);
			}
			return resourceMan;
		}
	}

	[EditorBrowsable(EditorBrowsableState.Advanced)]
	internal static CultureInfo Culture
	{
		get
		{
			return resourceCulture;
		}
		set
		{
			resourceCulture = value;
		}
	}

	internal static string CollectBackground => ResourceManager.GetString("CollectBackground", resourceCulture);

	internal static string CollectSample => ResourceManager.GetString("CollectSample", resourceCulture);

	internal static string GetCleanError => ResourceManager.GetString("GetCleanError", resourceCulture);

	internal static string PerformCleanCheck => ResourceManager.GetString("PerformCleanCheck", resourceCulture);

	internal TextStrings()
	{
	}
}
