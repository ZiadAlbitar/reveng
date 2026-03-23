
// C:\Users\lukli307\Documents\MicroLab PC\MicroLab PC\MLInstrumentConfig.dll
// MLInstrumentConfig, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
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
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Windows.Forms;
using System.Xml;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyTitle("MLInstrumentConfig")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("")]
[assembly: AssemblyProduct("MLInstrumentConfig")]
[assembly: AssemblyCopyright("Copyright ©  2015")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: Guid("3208aac8-73b2-486d-87b3-f6779900d73a")]
[assembly: AssemblyFileVersion("1.0.0.0")]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("1.0.0.0")]
namespace MLInstrumentConfig;

public class ComboboxItem
{
	public string Text { get; set; }

	public int Value { get; set; }

	public ComboboxItem(string strText, int nValue)
	{
		Text = strText;
		Value = nValue;
	}

	public override string ToString()
	{
		return Text;
	}
}
public class AccessoryName
{
	public string Text { get; set; }

	public int SampleTechType { get; set; }

	public int SubCode1 { get; set; }

	public int SubCode2 { get; set; }

	public int SubCode3 { get; set; }

	public int Gain { get; set; }

	public int Energy { get; set; }

	public string SerialNumber { get; set; }

	public bool IsPrimary { get; set; }

	public bool AllowPrimary { get; set; }

	public AccessoryName(string strName, int nSampleTechType, int nSubCode1, int nSubCode2, int nSubCode3, bool bAllowPrimary)
	{
		Text = strName;
		SampleTechType = nSampleTechType;
		SubCode1 = nSubCode1;
		SubCode2 = nSubCode2;
		SubCode3 = nSubCode3;
		Gain = 0;
		Energy = 0;
		SerialNumber = "";
		IsPrimary = false;
		AllowPrimary = bAllowPrimary;
	}

	public override string ToString()
	{
		if (Text.Length > 0)
		{
			return Text;
		}
		return base.ToString();
	}
}
public class InstrumentInfo
{
	public AccessoryName primary_accessory;

	public AccessoryName[] accessories;

	public int Instrument { get; set; }

	public int Laser_Type { get; set; }

	public int IR_Source_Type { get; set; }

	public int Detector_Location { get; set; }

	public int Detector { get; set; }

	public int Optics { get; set; }

	public int AccessoryChangeType { get; set; }

	public InstrumentInfo()
	{
		Initialize();
	}

	private void Initialize()
	{
		Instrument = -1;
		Laser_Type = -1;
		IR_Source_Type = -1;
		Detector = -1;
		Detector_Location = -1;
		Optics = -1;
		primary_accessory = null;
		accessories = null;
	}
}
public class InstrumentConfig : Form
{
	private InstrumentXMLParser m_InstrumentXMLParser;

	private bool m_bAllowMultipleAccessories;

	private AccessoryName m_PrimaryAccessory;

	private InstrumentInfo m_InstrumentInformation;

	private InstrumentInfo m_inputInformation;

	private int m_AccessoryChangeType;

	private IContainer components;

	private Button btnMakePrimary;

	private Label lblAvailableAccessories;

	private Label lblIncludedAccessories;

	private Button btnExclude;

	private Button btnInclude;

	private ListBox lbInclude;

	private ListBox lbExclude;

	private GroupBox gbPrimaryAccessory;

	private Label lblPrimaryAccessory;

	private ComboBox cbOptics;

	private Label lblOptics;

	private ComboBox cbDetector;

	private Label lblDetector;

	private ComboBox cbDetectorLocation;

	private Label lblDetectorLocation;

	private ComboBox cbIRSourceType;

	private Label lblIRSourceType;

	private ComboBox cbLaserType;

	private Label lblLaserType;

	private ComboBox cbInstrument;

	private Label lblInstrument;

	private Button btnOK;

	private Button btnClose;

	public InstrumentInfo InstrumentInformation => m_InstrumentInformation;

	public InstrumentConfig(ref InstrumentXMLParser instrumentXMLParser, InstrumentInfo info, bool bAllowMultipleAccessories)
	{
		InitializeComponent();
		m_InstrumentXMLParser = instrumentXMLParser;
		m_bAllowMultipleAccessories = bAllowMultipleAccessories;
		m_PrimaryAccessory = null;
		m_inputInformation = info;
		m_InstrumentInformation = new InstrumentInfo();
	}

	private void btnClose_Click(object sender, EventArgs e)
	{
		base.DialogResult = DialogResult.Cancel;
		Close();
	}

	private void btnOK_Click(object sender, EventArgs e)
	{
		if (cbInstrument.Items[cbInstrument.SelectedIndex] is ComboboxItem)
		{
			m_InstrumentInformation.Instrument = ((ComboboxItem)cbInstrument.Items[cbInstrument.SelectedIndex]).Value;
			m_InstrumentInformation.Laser_Type = ((ComboboxItem)cbLaserType.Items[cbLaserType.SelectedIndex]).Value;
			m_InstrumentInformation.IR_Source_Type = ((ComboboxItem)cbIRSourceType.Items[cbIRSourceType.SelectedIndex]).Value;
			m_InstrumentInformation.Detector_Location = ((ComboboxItem)cbDetectorLocation.Items[cbDetectorLocation.SelectedIndex]).Value;
			m_InstrumentInformation.Detector = ((ComboboxItem)cbDetector.Items[cbDetector.SelectedIndex]).Value;
			m_InstrumentInformation.Optics = ((ComboboxItem)cbOptics.Items[cbOptics.SelectedIndex]).Value;
			m_InstrumentInformation.AccessoryChangeType = m_AccessoryChangeType;
			if (lbInclude.Items.Count > 0)
			{
				m_InstrumentInformation.accessories = new AccessoryName[lbInclude.Items.Count];
				ListBox.ObjectCollection items = lbInclude.Items;
				object[] accessories = m_InstrumentInformation.accessories;
				items.CopyTo(accessories, 0);
				m_InstrumentInformation.primary_accessory = m_PrimaryAccessory;
				if (m_InstrumentInformation.primary_accessory != null)
				{
					m_InstrumentInformation.primary_accessory.IsPrimary = true;
				}
			}
			else
			{
				m_InstrumentInformation.primary_accessory = null;
			}
		}
		if (m_InstrumentInformation.primary_accessory == null)
		{
			if (DialogResult.Yes == MessageBox.Show(InstrumentDataResource.ContinueNoPrimary, InstrumentDataResource.ContinueTitle, MessageBoxButtons.YesNo))
			{
				base.DialogResult = DialogResult.OK;
				Close();
			}
		}
		else
		{
			base.DialogResult = DialogResult.OK;
			Close();
		}
	}

	private void SetDefaultComboBoxItem(ref ComboBox cb, int nValue)
	{
		bool flag = false;
		if (nValue >= 0)
		{
			for (int i = 0; i < cb.Items.Count; i++)
			{
				if (cb.Items[i] is ComboboxItem && ((ComboboxItem)cb.Items[i]).Value == nValue)
				{
					cb.SelectedIndex = i;
					flag = true;
					break;
				}
			}
		}
		if (!flag && cb.Items.Count > 0)
		{
			cb.SelectedIndex = 0;
		}
	}

	private int GetAccessoryIndexFromListBox(AccessoryName curAccessory, ref ListBox lb)
	{
		int result = -1;
		for (int i = 0; i < lb.Items.Count; i++)
		{
			if (!(lb.Items[i] is AccessoryName) || curAccessory == null || curAccessory.SampleTechType <= 0 || curAccessory.SampleTechType != ((AccessoryName)lb.Items[i]).SampleTechType)
			{
				continue;
			}
			if (curAccessory.SubCode1 <= 0)
			{
				if (((AccessoryName)lb.Items[i]).SubCode1 <= 0)
				{
					result = i;
				}
				break;
			}
			if (curAccessory.SubCode1 != ((AccessoryName)lb.Items[i]).SubCode1)
			{
				continue;
			}
			if (curAccessory.SubCode2 <= 0)
			{
				if (((AccessoryName)lb.Items[i]).SubCode2 <= 0)
				{
					result = i;
				}
				break;
			}
			if (curAccessory.SubCode2 != ((AccessoryName)lb.Items[i]).SubCode2)
			{
				continue;
			}
			if (curAccessory.SubCode3 <= 0)
			{
				if (((AccessoryName)lb.Items[i]).SubCode3 <= 0)
				{
					result = i;
				}
				break;
			}
			if (curAccessory.SubCode3 == ((AccessoryName)lb.Items[i]).SubCode3)
			{
				result = i;
				break;
			}
		}
		return result;
	}

	private void SetPrimaryAccessory(AccessoryName curAccessory)
	{
		int accessoryIndexFromListBox = GetAccessoryIndexFromListBox(curAccessory, ref lbInclude);
		if (accessoryIndexFromListBox >= 0)
		{
			lbInclude.SelectedIndex = accessoryIndexFromListBox;
			if (lbInclude.SelectedItem is AccessoryName && ((AccessoryName)lbInclude.SelectedItem).AllowPrimary)
			{
				MakePrimary();
				btnMakePrimary.Text = InstrumentDataResource.RemovePrimary;
			}
		}
	}

	private void AddInputAccessories(AccessoryName curAccessory)
	{
		int accessoryIndexFromListBox = GetAccessoryIndexFromListBox(curAccessory, ref lbExclude);
		if (accessoryIndexFromListBox >= 0)
		{
			lbInclude.Items.Add(lbExclude.Items[accessoryIndexFromListBox]);
			lbExclude.Items.Remove(lbExclude.Items[accessoryIndexFromListBox]);
		}
	}

	public void LoadInstrumentData()
	{
		int num = -1;
		int nValue = -1;
		int nValue2 = -1;
		int nValue3 = -1;
		int nValue4 = -1;
		int nValue5 = -1;
		bool flag = false;
		foreach (int key in m_InstrumentXMLParser.Instruments.Keys)
		{
			if (m_InstrumentXMLParser.Instruments[key].Valid)
			{
				cbInstrument.Items.Add(new ComboboxItem(m_InstrumentXMLParser.Instruments[key].DisplayName, key));
			}
		}
		if (m_InstrumentInformation != null)
		{
			num = m_inputInformation.Instrument;
			nValue = m_inputInformation.Detector;
			nValue2 = m_inputInformation.Detector_Location;
			nValue3 = m_inputInformation.IR_Source_Type;
			nValue4 = m_inputInformation.Laser_Type;
			nValue5 = m_inputInformation.Optics;
		}
		SetDefaultComboBoxItem(ref cbInstrument, num);
		SetDefaultComboBoxItem(ref cbDetector, nValue);
		SetDefaultComboBoxItem(ref cbDetectorLocation, nValue2);
		SetDefaultComboBoxItem(ref cbIRSourceType, nValue3);
		SetDefaultComboBoxItem(ref cbLaserType, nValue4);
		SetDefaultComboBoxItem(ref cbOptics, nValue5);
		if (m_InstrumentXMLParser.Instruments.ContainsKey(num) && m_InstrumentXMLParser.Instruments[num].AccessoryChangeType.Contains(1))
		{
			flag = true;
		}
		cbInstrument_SelectedIndexChanged(this, new EventArgs());
		lbInclude.Items.Clear();
		if (m_bAllowMultipleAccessories || !flag)
		{
			if (m_inputInformation.accessories != null)
			{
				AccessoryName[] accessories = m_inputInformation.accessories;
				foreach (AccessoryName curAccessory in accessories)
				{
					AddInputAccessories(curAccessory);
				}
			}
		}
		else if (m_inputInformation.primary_accessory != null)
		{
			AddInputAccessories(m_inputInformation.primary_accessory);
		}
		SetPrimaryAccessory(m_inputInformation.primary_accessory);
	}

	private void InstrumentConfig_Load(object sender, EventArgs e)
	{
		lblPrimaryAccessory.Text = "";
		btnMakePrimary.Enabled = false;
		if (m_bAllowMultipleAccessories)
		{
			Text = InstrumentDataResource.SelectInstAccessoryConfig;
			cbInstrument.Enabled = false;
			cbLaserType.Enabled = false;
			cbDetector.Enabled = false;
			cbDetectorLocation.Enabled = false;
			cbIRSourceType.Enabled = false;
			cbOptics.Enabled = false;
			cbLaserType.Visible = false;
			cbDetector.Visible = false;
			cbDetectorLocation.Visible = false;
			cbIRSourceType.Visible = false;
			cbOptics.Visible = false;
			lblDetector.Visible = false;
			lblDetectorLocation.Visible = false;
			lblIRSourceType.Visible = false;
			lblLaserType.Visible = false;
			lblOptics.Visible = false;
		}
		else
		{
			Text = InstrumentDataResource.SelectInstConfig;
			cbInstrument.Enabled = true;
			cbLaserType.Enabled = true;
			cbDetector.Enabled = true;
			cbDetectorLocation.Enabled = true;
			cbIRSourceType.Enabled = true;
			cbOptics.Enabled = true;
			cbLaserType.Visible = true;
			cbDetector.Visible = true;
			cbDetectorLocation.Visible = true;
			cbIRSourceType.Visible = true;
			cbOptics.Visible = true;
			lblDetector.Visible = true;
			lblDetectorLocation.Visible = true;
			lblIRSourceType.Visible = true;
			lblLaserType.Visible = true;
			lblOptics.Visible = true;
		}
		LoadInstrumentData();
		cbInstrument.SelectedIndexChanged += cbInstrument_SelectedIndexChanged;
	}

	private void LoadInstrumentComboBox<T>(List<int> curList, ref ComboBox cb, Dictionary<int, T> dictID) where T : InstrumentDefinitions
	{
		ComboboxItem comboboxItem = null;
		if (cb.SelectedItem is ComboboxItem)
		{
			comboboxItem = (ComboboxItem)cb.SelectedItem;
		}
		cb.Items.Clear();
		foreach (int cur in curList)
		{
			if (comboboxItem != null && comboboxItem.Text == dictID[cur].DisplayName)
			{
				cb.Items.Add(comboboxItem);
			}
			else
			{
				cb.Items.Add(new ComboboxItem(dictID[cur].DisplayName, cur));
			}
		}
		if (comboboxItem != null && cb.Items.Contains(comboboxItem))
		{
			cb.SelectedItem = comboboxItem;
		}
		else if (cb.Items.Count > 0)
		{
			cb.SelectedIndex = 0;
		}
	}

	private void cbInstrument_SelectedIndexChanged(object sender, EventArgs e)
	{
		if (cbInstrument.SelectedIndex >= 0 && cbInstrument.Items[cbInstrument.SelectedIndex] is ComboboxItem)
		{
			ComboboxItem comboboxItem = (ComboboxItem)cbInstrument.Items[cbInstrument.SelectedIndex];
			LoadInstrumentComboBox(m_InstrumentXMLParser.Instruments[comboboxItem.Value].LaserType, ref cbLaserType, m_InstrumentXMLParser.LaserTypes);
			LoadInstrumentComboBox(m_InstrumentXMLParser.Instruments[comboboxItem.Value].IRSourceType, ref cbIRSourceType, m_InstrumentXMLParser.IRSourceTypes);
			LoadInstrumentComboBox(m_InstrumentXMLParser.Instruments[comboboxItem.Value].Optics, ref cbOptics, m_InstrumentXMLParser.Optics);
			LoadInstrumentComboBox(m_InstrumentXMLParser.Instruments[comboboxItem.Value].DetectorLocation, ref cbDetectorLocation, m_InstrumentXMLParser.DetectorLocations);
			LoadInstrumentComboBox(m_InstrumentXMLParser.Instruments[comboboxItem.Value].Detector, ref cbDetector, m_InstrumentXMLParser.Detectors);
			if (m_InstrumentXMLParser.Instruments[comboboxItem.Value].AccessoryChangeType.Count > 0)
			{
				m_AccessoryChangeType = m_InstrumentXMLParser.Instruments[comboboxItem.Value].AccessoryChangeType[0];
			}
			LoadAccessories();
			if (!m_bAllowMultipleAccessories || m_InstrumentXMLParser.Instruments[comboboxItem.Value].AccessoryChangeType.Contains(1))
			{
				lbExclude.SelectionMode = SelectionMode.One;
				lbInclude.SelectionMode = SelectionMode.One;
			}
			else
			{
				lbExclude.SelectionMode = SelectionMode.MultiExtended;
				lbInclude.SelectionMode = SelectionMode.MultiExtended;
			}
		}
	}

	private void LoadAccessories()
	{
		lbExclude.Items.Clear();
		lbInclude.Items.Clear();
		if (cbInstrument.SelectedIndex < 0)
		{
			return;
		}
		ComboboxItem comboboxItem = (ComboboxItem)cbInstrument.Items[cbInstrument.SelectedIndex];
		foreach (AccessoryName accessory in m_InstrumentXMLParser.Instruments[comboboxItem.Value].AccessoryList)
		{
			lbExclude.Items.Add(accessory);
		}
	}

	private void CheckMakePrimary()
	{
		if (lbInclude.SelectedItems == null || lbInclude.SelectedItems.Count != 1)
		{
			btnMakePrimary.Enabled = false;
			if (lbInclude.Items.Count <= 0)
			{
				MakePrimary();
			}
		}
		else
		{
			btnMakePrimary.Enabled = true;
		}
	}

	private void MakePrimary()
	{
		if (lbInclude.SelectedItem is AccessoryName)
		{
			AccessoryName accessoryName = (AccessoryName)lbInclude.SelectedItem;
			if (accessoryName.AllowPrimary)
			{
				lblPrimaryAccessory.Text = accessoryName.Text;
				m_PrimaryAccessory = accessoryName;
				btnMakePrimary.Text = InstrumentDataResource.RemovePrimary;
			}
		}
		else
		{
			lblPrimaryAccessory.Text = "";
			m_PrimaryAccessory = null;
		}
	}

	private void btnInclude_Click(object sender, EventArgs e)
	{
		ListBox.SelectedObjectCollection selectedItems = lbExclude.SelectedItems;
		if (lbInclude.SelectionMode == SelectionMode.One)
		{
			if (lbInclude.Items.Count > 0)
			{
				foreach (object item in lbInclude.Items)
				{
					lbExclude.Items.Add(item);
				}
				lbInclude.Items.Clear();
			}
			foreach (object item2 in selectedItems)
			{
				lbInclude.Items.Add(item2);
			}
			while (lbExclude.SelectedItems.Count > 0)
			{
				lbExclude.Items.Remove(lbExclude.SelectedItems[0]);
			}
		}
		else
		{
			foreach (object item3 in selectedItems)
			{
				lbInclude.Items.Add(item3);
			}
			while (lbExclude.SelectedItems.Count > 0)
			{
				lbExclude.Items.Remove(lbExclude.SelectedItems[0]);
			}
		}
		if (lbInclude.Items.Count == 1)
		{
			lbInclude.SelectedIndex = 0;
		}
		else if (lbInclude.SelectedItem == null && lbInclude.Items.Count > 0)
		{
			lbInclude.SelectedIndex = 0;
		}
	}

	private void btnExclude_Click(object sender, EventArgs e)
	{
		bool flag = false;
		foreach (object selectedItem in lbInclude.SelectedItems)
		{
			lbExclude.Items.Add(selectedItem);
		}
		while (lbInclude.SelectedItems.Count > 0)
		{
			if (m_PrimaryAccessory == lbInclude.SelectedItems[0])
			{
				flag = true;
			}
			lbInclude.Items.Remove(lbInclude.SelectedItems[0]);
		}
		if (lbInclude.Items.Count == 1)
		{
			lbInclude.SelectedIndex = 0;
		}
		if (flag)
		{
			btnMakePrimary.Text = InstrumentDataResource.MakePrimary;
			lblPrimaryAccessory.Text = "";
			m_PrimaryAccessory = null;
		}
	}

	private void btnMakePrimary_Click(object sender, EventArgs e)
	{
		if (btnMakePrimary.Text == InstrumentDataResource.MakePrimary)
		{
			MakePrimary();
			return;
		}
		btnMakePrimary.Text = InstrumentDataResource.MakePrimary;
		lblPrimaryAccessory.Text = "";
		m_PrimaryAccessory = null;
	}

	private void lbInclude_SelectedValueChanged(object sender, EventArgs e)
	{
		bool flag = false;
		if (lbInclude.SelectedItem is AccessoryName)
		{
			AccessoryName accessoryName = (AccessoryName)lbInclude.SelectedItem;
			btnMakePrimary.Enabled = accessoryName.AllowPrimary;
			if (m_PrimaryAccessory == accessoryName)
			{
				flag = true;
			}
		}
		else
		{
			btnMakePrimary.Enabled = false;
		}
		if (!flag)
		{
			if (btnMakePrimary.Text != InstrumentDataResource.MakePrimary)
			{
				btnMakePrimary.Text = InstrumentDataResource.MakePrimary;
			}
		}
		else
		{
			btnMakePrimary.Text = InstrumentDataResource.RemovePrimary;
		}
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	private void InitializeComponent()
	{
		this.btnMakePrimary = new System.Windows.Forms.Button();
		this.lblAvailableAccessories = new System.Windows.Forms.Label();
		this.lblIncludedAccessories = new System.Windows.Forms.Label();
		this.btnExclude = new System.Windows.Forms.Button();
		this.btnInclude = new System.Windows.Forms.Button();
		this.lbInclude = new System.Windows.Forms.ListBox();
		this.lbExclude = new System.Windows.Forms.ListBox();
		this.gbPrimaryAccessory = new System.Windows.Forms.GroupBox();
		this.lblPrimaryAccessory = new System.Windows.Forms.Label();
		this.cbOptics = new System.Windows.Forms.ComboBox();
		this.lblOptics = new System.Windows.Forms.Label();
		this.cbDetector = new System.Windows.Forms.ComboBox();
		this.lblDetector = new System.Windows.Forms.Label();
		this.cbDetectorLocation = new System.Windows.Forms.ComboBox();
		this.lblDetectorLocation = new System.Windows.Forms.Label();
		this.cbIRSourceType = new System.Windows.Forms.ComboBox();
		this.lblIRSourceType = new System.Windows.Forms.Label();
		this.cbLaserType = new System.Windows.Forms.ComboBox();
		this.lblLaserType = new System.Windows.Forms.Label();
		this.cbInstrument = new System.Windows.Forms.ComboBox();
		this.lblInstrument = new System.Windows.Forms.Label();
		this.btnOK = new System.Windows.Forms.Button();
		this.btnClose = new System.Windows.Forms.Button();
		this.gbPrimaryAccessory.SuspendLayout();
		base.SuspendLayout();
		this.btnMakePrimary.ImeMode = System.Windows.Forms.ImeMode.NoControl;
		this.btnMakePrimary.Location = new System.Drawing.Point(468, 361);
		this.btnMakePrimary.Name = "btnMakePrimary";
		this.btnMakePrimary.Size = new System.Drawing.Size(128, 23);
		this.btnMakePrimary.TabIndex = 57;
		this.btnMakePrimary.Text = "Make Primary";
		this.btnMakePrimary.UseVisualStyleBackColor = true;
		this.btnMakePrimary.Click += new System.EventHandler(btnMakePrimary_Click);
		this.lblAvailableAccessories.AutoSize = true;
		this.lblAvailableAccessories.ImeMode = System.Windows.Forms.ImeMode.NoControl;
		this.lblAvailableAccessories.Location = new System.Drawing.Point(14, 192);
		this.lblAvailableAccessories.Name = "lblAvailableAccessories";
		this.lblAvailableAccessories.Size = new System.Drawing.Size(113, 13);
		this.lblAvailableAccessories.TabIndex = 56;
		this.lblAvailableAccessories.Text = "Available Accessories:";
		this.lblIncludedAccessories.AutoSize = true;
		this.lblIncludedAccessories.ImeMode = System.Windows.Forms.ImeMode.NoControl;
		this.lblIncludedAccessories.Location = new System.Drawing.Point(337, 192);
		this.lblIncludedAccessories.Name = "lblIncludedAccessories";
		this.lblIncludedAccessories.Size = new System.Drawing.Size(121, 13);
		this.lblIncludedAccessories.TabIndex = 55;
		this.lblIncludedAccessories.Text = "Purchased Accessories:";
		this.btnExclude.Font = new System.Drawing.Font("Arial", 8.25f);
		this.btnExclude.ImeMode = System.Windows.Forms.ImeMode.NoControl;
		this.btnExclude.Location = new System.Drawing.Point(276, 268);
		this.btnExclude.Name = "btnExclude";
		this.btnExclude.Size = new System.Drawing.Size(28, 23);
		this.btnExclude.TabIndex = 54;
		this.btnExclude.Text = "◄";
		this.btnExclude.UseVisualStyleBackColor = true;
		this.btnExclude.Click += new System.EventHandler(btnExclude_Click);
		this.btnInclude.Font = new System.Drawing.Font("Arial", 8.25f);
		this.btnInclude.ImeMode = System.Windows.Forms.ImeMode.NoControl;
		this.btnInclude.Location = new System.Drawing.Point(306, 268);
		this.btnInclude.Name = "btnInclude";
		this.btnInclude.Size = new System.Drawing.Size(28, 23);
		this.btnInclude.TabIndex = 53;
		this.btnInclude.Text = "►";
		this.btnInclude.UseVisualStyleBackColor = true;
		this.btnInclude.Click += new System.EventHandler(btnInclude_Click);
		this.lbInclude.FormattingEnabled = true;
		this.lbInclude.Location = new System.Drawing.Point(340, 208);
		this.lbInclude.Name = "lbInclude";
		this.lbInclude.SelectionMode = System.Windows.Forms.SelectionMode.MultiExtended;
		this.lbInclude.Size = new System.Drawing.Size(256, 147);
		this.lbInclude.Sorted = true;
		this.lbInclude.TabIndex = 52;
		this.lbInclude.SelectedValueChanged += new System.EventHandler(lbInclude_SelectedValueChanged);
		this.lbExclude.FormattingEnabled = true;
		this.lbExclude.Location = new System.Drawing.Point(14, 208);
		this.lbExclude.Name = "lbExclude";
		this.lbExclude.SelectionMode = System.Windows.Forms.SelectionMode.MultiExtended;
		this.lbExclude.Size = new System.Drawing.Size(256, 147);
		this.lbExclude.Sorted = true;
		this.lbExclude.TabIndex = 51;
		this.gbPrimaryAccessory.Controls.Add(this.lblPrimaryAccessory);
		this.gbPrimaryAccessory.Location = new System.Drawing.Point(340, 108);
		this.gbPrimaryAccessory.Name = "gbPrimaryAccessory";
		this.gbPrimaryAccessory.Size = new System.Drawing.Size(256, 59);
		this.gbPrimaryAccessory.TabIndex = 50;
		this.gbPrimaryAccessory.TabStop = false;
		this.gbPrimaryAccessory.Text = "Primary Accessory";
		this.lblPrimaryAccessory.AutoSize = true;
		this.lblPrimaryAccessory.ImeMode = System.Windows.Forms.ImeMode.NoControl;
		this.lblPrimaryAccessory.Location = new System.Drawing.Point(6, 25);
		this.lblPrimaryAccessory.Name = "lblPrimaryAccessory";
		this.lblPrimaryAccessory.Size = new System.Drawing.Size(90, 13);
		this.lblPrimaryAccessory.TabIndex = 20;
		this.lblPrimaryAccessory.Text = "PrimaryAccessory";
		this.cbOptics.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
		this.cbOptics.FormattingEnabled = true;
		this.cbOptics.Location = new System.Drawing.Point(113, 146);
		this.cbOptics.Name = "cbOptics";
		this.cbOptics.Size = new System.Drawing.Size(112, 21);
		this.cbOptics.TabIndex = 49;
		this.lblOptics.AutoSize = true;
		this.lblOptics.ImeMode = System.Windows.Forms.ImeMode.NoControl;
		this.lblOptics.Location = new System.Drawing.Point(11, 149);
		this.lblOptics.Name = "lblOptics";
		this.lblOptics.Size = new System.Drawing.Size(40, 13);
		this.lblOptics.TabIndex = 48;
		this.lblOptics.Text = "Optics:";
		this.cbDetector.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
		this.cbDetector.FormattingEnabled = true;
		this.cbDetector.Location = new System.Drawing.Point(113, 119);
		this.cbDetector.Name = "cbDetector";
		this.cbDetector.Size = new System.Drawing.Size(112, 21);
		this.cbDetector.TabIndex = 47;
		this.lblDetector.AutoSize = true;
		this.lblDetector.ImeMode = System.Windows.Forms.ImeMode.NoControl;
		this.lblDetector.Location = new System.Drawing.Point(11, 122);
		this.lblDetector.Name = "lblDetector";
		this.lblDetector.Size = new System.Drawing.Size(51, 13);
		this.lblDetector.TabIndex = 46;
		this.lblDetector.Text = "Detector:";
		this.cbDetectorLocation.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
		this.cbDetectorLocation.FormattingEnabled = true;
		this.cbDetectorLocation.Location = new System.Drawing.Point(113, 92);
		this.cbDetectorLocation.Name = "cbDetectorLocation";
		this.cbDetectorLocation.Size = new System.Drawing.Size(112, 21);
		this.cbDetectorLocation.TabIndex = 45;
		this.lblDetectorLocation.AutoSize = true;
		this.lblDetectorLocation.ImeMode = System.Windows.Forms.ImeMode.NoControl;
		this.lblDetectorLocation.Location = new System.Drawing.Point(11, 95);
		this.lblDetectorLocation.Name = "lblDetectorLocation";
		this.lblDetectorLocation.Size = new System.Drawing.Size(95, 13);
		this.lblDetectorLocation.TabIndex = 44;
		this.lblDetectorLocation.Text = "Detector Location:";
		this.cbIRSourceType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
		this.cbIRSourceType.FormattingEnabled = true;
		this.cbIRSourceType.Location = new System.Drawing.Point(113, 65);
		this.cbIRSourceType.Name = "cbIRSourceType";
		this.cbIRSourceType.Size = new System.Drawing.Size(112, 21);
		this.cbIRSourceType.TabIndex = 43;
		this.lblIRSourceType.AutoSize = true;
		this.lblIRSourceType.ImeMode = System.Windows.Forms.ImeMode.NoControl;
		this.lblIRSourceType.Location = new System.Drawing.Point(11, 68);
		this.lblIRSourceType.Name = "lblIRSourceType";
		this.lblIRSourceType.Size = new System.Drawing.Size(85, 13);
		this.lblIRSourceType.TabIndex = 42;
		this.lblIRSourceType.Text = "IR Source Type:";
		this.cbLaserType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
		this.cbLaserType.FormattingEnabled = true;
		this.cbLaserType.Location = new System.Drawing.Point(113, 38);
		this.cbLaserType.Name = "cbLaserType";
		this.cbLaserType.Size = new System.Drawing.Size(112, 21);
		this.cbLaserType.TabIndex = 41;
		this.lblLaserType.AutoSize = true;
		this.lblLaserType.ImeMode = System.Windows.Forms.ImeMode.NoControl;
		this.lblLaserType.Location = new System.Drawing.Point(11, 41);
		this.lblLaserType.Name = "lblLaserType";
		this.lblLaserType.Size = new System.Drawing.Size(63, 13);
		this.lblLaserType.TabIndex = 40;
		this.lblLaserType.Text = "Laser Type:";
		this.cbInstrument.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
		this.cbInstrument.FormattingEnabled = true;
		this.cbInstrument.Location = new System.Drawing.Point(113, 11);
		this.cbInstrument.Name = "cbInstrument";
		this.cbInstrument.Size = new System.Drawing.Size(112, 21);
		this.cbInstrument.TabIndex = 39;
		this.cbInstrument.SelectedIndexChanged += new System.EventHandler(cbInstrument_SelectedIndexChanged);
		this.lblInstrument.AutoSize = true;
		this.lblInstrument.ImeMode = System.Windows.Forms.ImeMode.NoControl;
		this.lblInstrument.Location = new System.Drawing.Point(11, 14);
		this.lblInstrument.Name = "lblInstrument";
		this.lblInstrument.Size = new System.Drawing.Size(59, 13);
		this.lblInstrument.TabIndex = 38;
		this.lblInstrument.Text = "Instrument:";
		this.btnOK.ImeMode = System.Windows.Forms.ImeMode.NoControl;
		this.btnOK.Location = new System.Drawing.Point(521, 8);
		this.btnOK.Name = "btnOK";
		this.btnOK.Size = new System.Drawing.Size(75, 21);
		this.btnOK.TabIndex = 58;
		this.btnOK.Text = "OK";
		this.btnOK.UseVisualStyleBackColor = true;
		this.btnOK.Click += new System.EventHandler(btnOK_Click);
		this.btnClose.ImeMode = System.Windows.Forms.ImeMode.NoControl;
		this.btnClose.Location = new System.Drawing.Point(521, 37);
		this.btnClose.Name = "btnClose";
		this.btnClose.Size = new System.Drawing.Size(75, 21);
		this.btnClose.TabIndex = 37;
		this.btnClose.Text = "Cancel";
		this.btnClose.UseVisualStyleBackColor = true;
		this.btnClose.Click += new System.EventHandler(btnClose_Click);
		base.AutoScaleDimensions = new System.Drawing.SizeF(6f, 13f);
		base.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
		base.ClientSize = new System.Drawing.Size(608, 391);
		base.Controls.Add(this.btnMakePrimary);
		base.Controls.Add(this.lblAvailableAccessories);
		base.Controls.Add(this.lblIncludedAccessories);
		base.Controls.Add(this.btnExclude);
		base.Controls.Add(this.btnInclude);
		base.Controls.Add(this.lbInclude);
		base.Controls.Add(this.lbExclude);
		base.Controls.Add(this.gbPrimaryAccessory);
		base.Controls.Add(this.cbOptics);
		base.Controls.Add(this.lblOptics);
		base.Controls.Add(this.cbDetector);
		base.Controls.Add(this.lblDetector);
		base.Controls.Add(this.cbDetectorLocation);
		base.Controls.Add(this.lblDetectorLocation);
		base.Controls.Add(this.cbIRSourceType);
		base.Controls.Add(this.lblIRSourceType);
		base.Controls.Add(this.cbLaserType);
		base.Controls.Add(this.lblLaserType);
		base.Controls.Add(this.cbInstrument);
		base.Controls.Add(this.lblInstrument);
		base.Controls.Add(this.btnOK);
		base.Controls.Add(this.btnClose);
		base.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
		base.MaximizeBox = false;
		base.Name = "InstrumentConfig";
		base.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
		this.Text = "InstrumentConfig";
		base.Load += new System.EventHandler(InstrumentConfig_Load);
		this.gbPrimaryAccessory.ResumeLayout(false);
		this.gbPrimaryAccessory.PerformLayout();
		base.ResumeLayout(false);
		base.PerformLayout();
	}
}
public class InstrumentData
{
	private InstrumentConfig m_InstrumentConfigForm;

	private InstrumentXMLParser m_InstrumentXMLParser;

	public string Unknown => InstrumentDataResource.Unknown;

	public string GetInstrumentName(int nVal)
	{
		string result = InstrumentDataResource.Unknown;
		if (m_InstrumentXMLParser != null)
		{
			result = m_InstrumentXMLParser.GetInstrumentName(nVal);
		}
		return result;
	}

	public string GetAtrTypeName(int nVal)
	{
		string result = InstrumentDataResource.Unknown;
		if (m_InstrumentXMLParser != null)
		{
			result = m_InstrumentXMLParser.GetAtrTypeName(nVal);
		}
		return result;
	}

	public string GetAccessoryName(int nSampleTech, int nSubCode1, int nSubCode2, int nSubCode3)
	{
		string result = InstrumentDataResource.Unknown;
		if (m_InstrumentXMLParser != null)
		{
			result = m_InstrumentXMLParser.GetAccessoryName(nSampleTech, nSubCode1, nSubCode2, nSubCode3);
		}
		return result;
	}

	public DialogResult DisplayInstrumentConfigForm(ref InstrumentInfo info, bool bAllowMultipleAccessories)
	{
		m_InstrumentConfigForm = new InstrumentConfig(ref m_InstrumentXMLParser, info, bAllowMultipleAccessories);
		DialogResult num = m_InstrumentConfigForm.ShowDialog();
		if (num == DialogResult.OK)
		{
			info = m_InstrumentConfigForm.InstrumentInformation;
		}
		return num;
	}

	public bool LoadData(string strDataFile)
	{
		m_InstrumentXMLParser = new InstrumentXMLParser();
		if (!m_InstrumentXMLParser.LoadData(strDataFile))
		{
			return false;
		}
		return true;
	}
}
public enum SubCode
{
	None,
	SampleTechMajor,
	SubCode1,
	SubCode2,
	SubCode3,
	OpticsType,
	DetectorType,
	DetLocation,
	LaserTypeEx,
	IrSourceType
}
public enum SubCode1
{
	None,
	AtrType,
	TransType,
	ReflType,
	GasCellType,
	MicroType,
	FiberType,
	MiscType
}
public enum SubCode2
{
	None,
	AtrMaterial,
	ReflAngle
}
public enum SubCode3
{
	None,
	AtrPress,
	ReflScreen
}
public abstract class InstrumentDefinitions
{
	protected string m_strDisplayName;

	protected SubCode m_SubCode;

	public string DisplayName => m_strDisplayName;

	public SubCode SubCode => m_SubCode;

	public InstrumentDefinitions()
	{
		m_strDisplayName = "";
		m_SubCode = SubCode.None;
	}

	public InstrumentDefinitions(string strSubCode, string strDispName)
	{
		SetDefaultData(strDispName, strSubCode, null, out var _);
	}

	protected void LoadSubCode(string strSubCode)
	{
		m_SubCode = SubCode.None;
		if (strSubCode == null)
		{
			return;
		}
		foreach (SubCode value in Enum.GetValues(typeof(SubCode)))
		{
			if (strSubCode.ToString().ToLower() == value.ToString().ToLower())
			{
				m_SubCode = value;
				break;
			}
		}
	}

	public virtual bool SetDefaultData(string strDisplayName, string strSubCode, string[] strParams, out bool bValid)
	{
		bValid = true;
		m_strDisplayName = strDisplayName;
		LoadSubCode(strSubCode);
		return true;
	}
}
public abstract class InstrumentDefinitionsWithValid : InstrumentDefinitions
{
	protected bool m_bValid;

	public bool Valid => m_bValid;

	public InstrumentDefinitionsWithValid()
	{
		m_bValid = true;
	}

	public override bool SetDefaultData(string strDisplayName, string strSubCode, string[] strParams, out bool bValid)
	{
		bValid = true;
		if (strParams == null || strParams.Length != 1)
		{
			return false;
		}
		m_strDisplayName = strDisplayName;
		LoadSubCode(strSubCode);
		if (strParams[0] != null && !bool.TryParse(strParams[0], out m_bValid))
		{
			m_bValid = true;
		}
		bValid = m_bValid;
		return true;
	}
}
public class AtrType : InstrumentDefinitions
{
}
public class AtrMaterial : InstrumentDefinitions
{
}
public class AtrPress : InstrumentDefinitions
{
}
public class ReflAngle : InstrumentDefinitions
{
}
public class AccessoryChangeType : InstrumentDefinitions
{
}
public class DetectorLocation : InstrumentDefinitions
{
}
public class IRSourceType : InstrumentDefinitions
{
}
public class TransType : InstrumentDefinitions
{
	private string m_strInternalName;

	public string InternalName => m_strInternalName;

	public override bool SetDefaultData(string strDisplayName, string strSubCode, string[] strParams, out bool bValid)
	{
		bValid = true;
		if (strParams == null || strParams.Length != 1)
		{
			return false;
		}
		m_strDisplayName = strDisplayName;
		LoadSubCode(strSubCode);
		m_strInternalName = strParams[0];
		return true;
	}
}
public class LaserType : InstrumentDefinitions
{
	private int m_nLaserType;

	public int LaserTypeValue => m_nLaserType;

	public override bool SetDefaultData(string strDisplayName, string strSubCode, string[] strParams, out bool bValid)
	{
		bValid = true;
		if (strParams == null || strParams.Length != 1)
		{
			return false;
		}
		m_strDisplayName = strDisplayName;
		LoadSubCode(strSubCode);
		if (strParams[0] != null && !int.TryParse(strParams[0], out m_nLaserType))
		{
			m_nLaserType = 0;
		}
		return true;
	}
}
public class SampleTechType : InstrumentDefinitionsWithValid
{
	public SubCode1 SubCode1 { get; set; }

	public SubCode2 SubCode2 { get; set; }

	public SubCode3 SubCode3 { get; set; }

	public override bool SetDefaultData(string strDisplayName, string strSubCode, string[] strParams, out bool bValid)
	{
		bValid = true;
		if (strParams == null || strParams.Length != 4)
		{
			return false;
		}
		m_strDisplayName = strDisplayName;
		LoadSubCode(strSubCode);
		m_bValid = true;
		SubCode1 = SubCode1.None;
		SubCode2 = SubCode2.None;
		SubCode3 = SubCode3.None;
		if (strParams[0] != null)
		{
			foreach (SubCode1 value in Enum.GetValues(typeof(SubCode1)))
			{
				if (strParams[0].ToString().ToLower() == value.ToString().ToLower())
				{
					SubCode1 = value;
					break;
				}
			}
		}
		if (strParams[1] != null)
		{
			foreach (SubCode2 value2 in Enum.GetValues(typeof(SubCode2)))
			{
				if (strParams[1].ToString().ToLower() == value2.ToString().ToLower())
				{
					SubCode2 = value2;
					break;
				}
			}
		}
		if (strParams[2] != null)
		{
			foreach (SubCode3 value3 in Enum.GetValues(typeof(SubCode3)))
			{
				if (strParams[2].ToString().ToLower() == value3.ToString().ToLower())
				{
					SubCode3 = value3;
					break;
				}
			}
		}
		if (strParams[3] != null && !bool.TryParse(strParams[3], out m_bValid))
		{
			m_bValid = true;
		}
		bValid = m_bValid;
		return true;
	}
}
public class ReflType : InstrumentDefinitionsWithValid
{
}
public class ReflScreen : InstrumentDefinitionsWithValid
{
}
public class GasCellType : InstrumentDefinitionsWithValid
{
}
public class MicroType : InstrumentDefinitionsWithValid
{
}
public class FiberType : InstrumentDefinitionsWithValid
{
}
public class MiscType : InstrumentDefinitionsWithValid
{
}
public class Optics : InstrumentDefinitionsWithValid
{
}
public class Detector : InstrumentDefinitionsWithValid
{
}
public class Instrument
{
	public const int SINGLE_NO_CHANGE = 1;

	public string DisplayName { get; set; }

	public string InternalName { get; set; }

	public int InstrumentType { get; set; }

	public bool Valid { get; set; }

	public List<int> LaserType { get; private set; }

	public List<int> IRSourceType { get; private set; }

	public List<int> DetectorLocation { get; private set; }

	public List<int> Detector { get; private set; }

	public List<int> Optics { get; private set; }

	public List<int> AccessoryChangeType { get; private set; }

	public List<AccessoryName> AccessoryList { get; private set; }

	public Instrument()
	{
		DisplayName = InstrumentDataResource.Unknown;
		InternalName = "";
		InstrumentType = -1;
		Valid = true;
		LaserType = new List<int>();
		IRSourceType = new List<int>();
		DetectorLocation = new List<int>();
		Detector = new List<int>();
		Optics = new List<int>();
		AccessoryChangeType = new List<int>();
		AccessoryList = new List<AccessoryName>();
	}
}
public class InstrumentXMLParser
{
	private XmlDocument m_xmlDoc;

	private Dictionary<int, SampleTechType> m_dictionarySampleTechType;

	private Dictionary<int, AtrType> m_dictionaryAtrType;

	private Dictionary<int, AtrMaterial> m_dictionaryAtrMaterial;

	private Dictionary<int, AtrPress> m_dictionaryAtrPress;

	private Dictionary<int, TransType> m_dictionaryTransType;

	private Dictionary<int, ReflType> m_dictionaryReflType;

	private Dictionary<int, ReflAngle> m_dictionaryReflAngle;

	private Dictionary<int, ReflScreen> m_dictionaryReflScreen;

	private Dictionary<int, AccessoryChangeType> m_dictionaryAccessoryChangeType;

	private Dictionary<int, GasCellType> m_dictionaryGasCellType;

	private Dictionary<int, MicroType> m_dictionaryMicroType;

	private Dictionary<int, FiberType> m_dictionaryFiberType;

	private Dictionary<int, MiscType> m_dictionaryMiscType;

	private Dictionary<int, Optics> m_dictionaryOptics;

	private Dictionary<int, Detector> m_dictionaryDetector;

	private Dictionary<int, DetectorLocation> m_dictionaryDetectorLocation;

	private Dictionary<int, LaserType> m_dictionaryLaserType;

	private Dictionary<int, IRSourceType> m_dictionaryIRSourceType;

	private Dictionary<int, Instrument> m_dictionaryInstrument;

	private const string STR_DISPLAYNAME = "DisplayName";

	private const string STR_INTERNALNAME = "InternalName";

	private const string STR_VALID = "Valid";

	private const string STR_SUBCODE = "SubCode";

	private const string STR_SUBCODE1 = "SubCode1";

	private const string STR_SUBCODE2 = "SubCode2";

	private const string STR_SUBCODE3 = "SubCode3";

	private const string STR_LASERTYPE = "LaserType";

	private const string STR_INSTTYPE = "InstType";

	private const string STR_INSTRUMENTCONFIG = "InstrumentConfigs";

	private const string STR_INSTRUMENTSUBNODE = "./Instrument";

	private const string STR_ACCESSORYSUBNODE = "./Accessory";

	private const string STR_SUBTYPE = "./SubType";

	private const string STR_ALL = "All";

	private const string STR_INSTRUMENTNODE = "Instrument";

	private const string STR_INSTRUMENTCONFIGNODES = "InstrumentConfigNodes";

	private const string STR_ACCESSORYNODE = "Accessory";

	private const string STR_SAMPLETECHTYPE = "SampleTechType";

	private const string STR_SUBTYPENODE = "SubType";

	private const string STR_ALLOWPRIMARY = "AllowPrimary";

	public Dictionary<int, Instrument> Instruments => m_dictionaryInstrument;

	public Dictionary<int, LaserType> LaserTypes => m_dictionaryLaserType;

	public Dictionary<int, IRSourceType> IRSourceTypes => m_dictionaryIRSourceType;

	public Dictionary<int, Optics> Optics => m_dictionaryOptics;

	public Dictionary<int, DetectorLocation> DetectorLocations => m_dictionaryDetectorLocation;

	public Dictionary<int, Detector> Detectors => m_dictionaryDetector;

	public Dictionary<int, AccessoryChangeType> AccessoryChangeTypes => m_dictionaryAccessoryChangeType;

	public Dictionary<int, SampleTechType> SampleTechTypes => m_dictionarySampleTechType;

	public bool LoadData(string strDataFile)
	{
		if (!CheckFileExist(strDataFile))
		{
			return false;
		}
		if (!LoadXMLDoc(strDataFile))
		{
			return false;
		}
		m_dictionarySampleTechType = new Dictionary<int, SampleTechType>();
		m_dictionaryAtrType = new Dictionary<int, AtrType>();
		m_dictionaryAtrMaterial = new Dictionary<int, AtrMaterial>();
		m_dictionaryAtrPress = new Dictionary<int, AtrPress>();
		m_dictionaryTransType = new Dictionary<int, TransType>();
		m_dictionaryReflType = new Dictionary<int, ReflType>();
		m_dictionaryReflAngle = new Dictionary<int, ReflAngle>();
		m_dictionaryReflScreen = new Dictionary<int, ReflScreen>();
		m_dictionaryAccessoryChangeType = new Dictionary<int, AccessoryChangeType>();
		m_dictionaryGasCellType = new Dictionary<int, GasCellType>();
		m_dictionaryMicroType = new Dictionary<int, MicroType>();
		m_dictionaryFiberType = new Dictionary<int, FiberType>();
		m_dictionaryMiscType = new Dictionary<int, MiscType>();
		m_dictionaryOptics = new Dictionary<int, Optics>();
		m_dictionaryDetector = new Dictionary<int, Detector>();
		m_dictionaryDetectorLocation = new Dictionary<int, DetectorLocation>();
		m_dictionaryLaserType = new Dictionary<int, LaserType>();
		m_dictionaryIRSourceType = new Dictionary<int, IRSourceType>();
		m_dictionaryInstrument = new Dictionary<int, Instrument>();
		if (!ParseXMLDoc())
		{
			return false;
		}
		return true;
	}

	private bool CheckFileExist(string strDoc)
	{
		if (!File.Exists(strDoc))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.MissingDataFile, strDoc), InstrumentDataResource.Error, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		return true;
	}

	private bool LoadXMLDoc(string strDoc)
	{
		m_xmlDoc = new XmlDocument();
		try
		{
			m_xmlDoc.Load(strDoc);
		}
		catch (Exception ex)
		{
			MessageBox.Show(ex.Message, InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		return true;
	}

	private bool ParseXMLDoc()
	{
		if (!LoadInstrumentConfigNode(ref m_dictionarySampleTechType, new string[4] { "SubCode1", "SubCode2", "SubCode3", "Valid" }))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(SampleTechType).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryAtrType))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(AtrType).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryAtrMaterial))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(AtrMaterial).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryAtrPress))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(AtrPress).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryTransType, new string[1] { "InternalName" }))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(TransType).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryReflType, new string[1] { "Valid" }))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(ReflType).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryReflAngle))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(ReflAngle).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryReflScreen, new string[1] { "Valid" }))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(ReflScreen).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryAccessoryChangeType))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(AccessoryChangeType).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryGasCellType, new string[1] { "Valid" }))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(GasCellType).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryMicroType, new string[1] { "Valid" }))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(MicroType).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryFiberType, new string[1] { "Valid" }))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(FiberType).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryMiscType, new string[1] { "Valid" }))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(MiscType).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryOptics, new string[1] { "Valid" }))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(Optics).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryDetector, new string[1] { "Valid" }))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(Detector).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryDetectorLocation))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(DetectorLocation).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryLaserType, new string[1] { "LaserType" }))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(LaserType).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentConfigNode(ref m_dictionaryIRSourceType))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(IRSourceType).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		if (!LoadInstrumentData(ref m_xmlDoc))
		{
			MessageBox.Show(string.Format(InstrumentDataResource.InvalidXMLInfo, typeof(Instrument).Name.ToString()), InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return false;
		}
		return true;
	}

	private bool LoadInstrumentData(ref XmlDocument xmlDoc)
	{
		XmlNodeList elementsByTagName = xmlDoc.GetElementsByTagName("InstrumentConfigs");
		for (int i = 0; i < elementsByTagName.Count; i++)
		{
			XmlNodeList xmlNodeList = elementsByTagName[i].SelectNodes("./Instrument");
			for (int j = 0; j < xmlNodeList.Count; j++)
			{
				XmlNode curNode = xmlNodeList[j];
				if (!LoadInstrumentAttributes(ref curNode, out var instrument, bAddInstrument: true))
				{
					return false;
				}
				if (!LoadInstrumentAccessories(ref curNode, ref instrument))
				{
					return false;
				}
			}
		}
		return true;
	}

	private bool GetXMLStringData(ref XmlNode curNode, string strName, out string strData)
	{
		strData = "";
		XmlAttribute xmlAttribute = curNode.Attributes[strName];
		if (xmlAttribute != null)
		{
			strData = xmlAttribute.Value;
			return true;
		}
		return false;
	}

	private void AddListData<T>(string strValue, List<int> m_list, ref Dictionary<int, T> dictID) where T : InstrumentDefinitions
	{
		int result = -1;
		if (strValue.ToLower() == "All".ToLower())
		{
			foreach (int key in dictID.Keys)
			{
				m_list.Add(key);
			}
			return;
		}
		int.TryParse(strValue, out result);
		m_list.Add(result);
	}

	private bool LoadInstrumentAccessories(ref XmlNode curNode, ref Instrument instrument)
	{
		XmlNodeList xmlNodeList = curNode.SelectNodes("./Accessory");
		instrument.AccessoryList.Clear();
		for (int i = 0; i < xmlNodeList.Count; i++)
		{
			XmlNode curNode2 = xmlNodeList[i];
			if (curNode2.Attributes == null)
			{
				continue;
			}
			XmlAttribute xmlAttribute = curNode2.Attributes[typeof(SampleTechType).Name.ToString()];
			if (xmlAttribute != null)
			{
				if (!int.TryParse(xmlAttribute.Value, out var result))
				{
					return false;
				}
				if (!m_dictionarySampleTechType.ContainsKey(result))
				{
					return false;
				}
				SampleTechType stt = m_dictionarySampleTechType[result];
				if (0 >= LoadSubType(ref curNode2, stt, 1, ref instrument, result, -1, -1))
				{
					return false;
				}
			}
		}
		return true;
	}

	public string GetSubCode1Text(SubCode1 subCode, int nValue)
	{
		string text = "";
		switch (subCode)
		{
		case SubCode1.AtrType:
			if (m_dictionaryAtrType.ContainsKey(nValue))
			{
				text = m_dictionaryAtrType[nValue].DisplayName;
			}
			break;
		case SubCode1.FiberType:
			if (m_dictionaryFiberType.ContainsKey(nValue))
			{
				text = m_dictionaryFiberType[nValue].DisplayName;
			}
			break;
		case SubCode1.GasCellType:
			if (m_dictionaryGasCellType.ContainsKey(nValue))
			{
				text = m_dictionaryGasCellType[nValue].DisplayName;
			}
			break;
		case SubCode1.MicroType:
			if (m_dictionaryMicroType.ContainsKey(nValue))
			{
				text = m_dictionaryMicroType[nValue].DisplayName;
			}
			break;
		case SubCode1.MiscType:
			if (m_dictionaryMiscType.ContainsKey(nValue))
			{
				text = m_dictionaryMiscType[nValue].DisplayName;
			}
			break;
		case SubCode1.ReflType:
			if (m_dictionaryReflType.ContainsKey(nValue))
			{
				text = m_dictionaryReflType[nValue].DisplayName;
			}
			break;
		case SubCode1.TransType:
			if (m_dictionaryTransType.ContainsKey(nValue))
			{
				text = m_dictionaryTransType[nValue].DisplayName;
			}
			break;
		}
		if (text.ToLower() == InstrumentDataResource.None.ToLower() || text.ToLower() == InstrumentDataResource.Undefined.ToLower())
		{
			text = "";
		}
		return text;
	}

	private void GetSubCode1All(SubCode1 subCode, out List<int> subCodeValues)
	{
		subCodeValues = new List<int>();
		switch (subCode)
		{
		case SubCode1.AtrType:
			subCodeValues = m_dictionaryAtrType.Keys.ToList();
			break;
		case SubCode1.FiberType:
			subCodeValues = m_dictionaryFiberType.Keys.ToList();
			break;
		case SubCode1.GasCellType:
			subCodeValues = m_dictionaryGasCellType.Keys.ToList();
			break;
		case SubCode1.MicroType:
			subCodeValues = m_dictionaryMicroType.Keys.ToList();
			break;
		case SubCode1.MiscType:
			subCodeValues = m_dictionaryMiscType.Keys.ToList();
			break;
		case SubCode1.ReflType:
			subCodeValues = m_dictionaryReflType.Keys.ToList();
			break;
		case SubCode1.TransType:
			subCodeValues = m_dictionaryTransType.Keys.ToList();
			break;
		}
	}

	public string GetSubCode2Text(SubCode2 subCode, int nValue)
	{
		string text = "";
		switch (subCode)
		{
		case SubCode2.AtrMaterial:
			if (m_dictionaryAtrMaterial.ContainsKey(nValue))
			{
				text = m_dictionaryAtrMaterial[nValue].DisplayName;
			}
			break;
		case SubCode2.ReflAngle:
			if (m_dictionaryReflAngle.ContainsKey(nValue))
			{
				text = m_dictionaryReflAngle[nValue].DisplayName;
			}
			break;
		}
		if (text.ToLower() == InstrumentDataResource.None.ToLower() || text.ToLower() == InstrumentDataResource.Undefined.ToLower())
		{
			text = "";
		}
		return text;
	}

	private void GetSubCode2All(SubCode2 subCode, out List<int> subCodeValues)
	{
		subCodeValues = new List<int>();
		switch (subCode)
		{
		case SubCode2.AtrMaterial:
			subCodeValues = m_dictionaryAtrMaterial.Keys.ToList();
			break;
		case SubCode2.ReflAngle:
			subCodeValues = m_dictionaryReflAngle.Keys.ToList();
			break;
		}
	}

	public string GetSubCode3Text(SubCode3 subCode, int nValue)
	{
		string text = "";
		switch (subCode)
		{
		case SubCode3.AtrPress:
			if (m_dictionaryAtrPress.ContainsKey(nValue))
			{
				text = m_dictionaryAtrPress[nValue].DisplayName;
			}
			break;
		case SubCode3.ReflScreen:
			if (m_dictionaryReflScreen.ContainsKey(nValue))
			{
				text = m_dictionaryReflScreen[nValue].DisplayName;
			}
			break;
		}
		if (text.ToLower() == InstrumentDataResource.None.ToLower() || text.ToLower() == InstrumentDataResource.Undefined.ToLower())
		{
			text = "";
		}
		return text;
	}

	private void GetSubCode3All(SubCode3 subCode, out List<int> subCodeValues)
	{
		subCodeValues = new List<int>();
		switch (subCode)
		{
		case SubCode3.AtrPress:
			subCodeValues = m_dictionaryAtrPress.Keys.ToList();
			break;
		case SubCode3.ReflScreen:
			subCodeValues = m_dictionaryReflScreen.Keys.ToList();
			break;
		}
	}

	private bool GetPrimaryAttribute(ref XmlNode subTypeNode)
	{
		bool result = false;
		XmlAttribute xmlAttribute = subTypeNode.Attributes["AllowPrimary"];
		if (xmlAttribute != null)
		{
			bool.TryParse(xmlAttribute.Value, out result);
		}
		return result;
	}

	private int LoadSubType(ref XmlNode curNode, SampleTechType stt, int nDepth, ref Instrument instrument, int nAccessoryType, int nSubCode1, int nSubCode2)
	{
		int num = 0;
		XmlNodeList xmlNodeList = curNode.SelectNodes("./SubType");
		for (int i = 0; i < xmlNodeList.Count; i++)
		{
			XmlNode curNode2 = xmlNodeList[i];
			if (curNode2.Attributes == null)
			{
				continue;
			}
			int result;
			switch (nDepth)
			{
			case 1:
			{
				string value = curNode2.Attributes[stt.SubCode1.ToString()].Value;
				if (value.ToLower() == "All".ToLower())
				{
					GetSubCode1All(stt.SubCode1, out var subCodeValues2);
					foreach (int item7 in subCodeValues2)
					{
						num = LoadSubType(ref curNode2, stt, nDepth + 1, ref instrument, nAccessoryType, item7, -1);
						if (num == 0)
						{
							string[] array3 = new string[4] { "", "", "", "" };
							array3[0] = m_dictionarySampleTechType[nAccessoryType].DisplayName;
							array3[1] = GetSubCode1Text(stt.SubCode1, item7);
							string strName2 = array3[0] + " " + array3[1] + " " + array3[2] + " " + array3[3];
							bool primaryAttribute2 = GetPrimaryAttribute(ref curNode2);
							AccessoryName item3 = new AccessoryName(strName2, nAccessoryType, item7, -1, -1, primaryAttribute2);
							instrument.AccessoryList.Add(item3);
							num = 1;
						}
					}
				}
				else if (int.TryParse(value, out result))
				{
					num = LoadSubType(ref curNode2, stt, nDepth + 1, ref instrument, nAccessoryType, result, -1);
					if (num == 0)
					{
						string[] array4 = new string[4] { "", "", "", "" };
						array4[0] = m_dictionarySampleTechType[nAccessoryType].DisplayName;
						array4[1] = GetSubCode1Text(stt.SubCode1, result);
						AccessoryName item4 = new AccessoryName(array4[0] + " " + array4[1] + " " + array4[2] + " " + array4[3], bAllowPrimary: GetPrimaryAttribute(ref curNode2), nSampleTechType: nAccessoryType, nSubCode1: result, nSubCode2: -1, nSubCode3: -1);
						instrument.AccessoryList.Add(item4);
						num = 1;
					}
				}
				break;
			}
			case 2:
			{
				string value = curNode2.Attributes[stt.SubCode2.ToString()].Value;
				if (value.ToLower() == "All".ToLower())
				{
					GetSubCode2All(stt.SubCode2, out var subCodeValues3);
					foreach (int item8 in subCodeValues3)
					{
						num = LoadSubType(ref curNode2, stt, nDepth + 1, ref instrument, nAccessoryType, nSubCode1, item8);
						if (num == 0)
						{
							string[] array5 = new string[4] { "", "", "", "" };
							array5[0] = m_dictionarySampleTechType[nAccessoryType].DisplayName;
							array5[1] = GetSubCode1Text(stt.SubCode1, nSubCode1);
							array5[2] = GetSubCode2Text(stt.SubCode2, item8);
							string strName3 = array5[0] + " " + array5[1] + " " + array5[2] + " " + array5[3];
							bool primaryAttribute3 = GetPrimaryAttribute(ref curNode2);
							AccessoryName item5 = new AccessoryName(strName3, nAccessoryType, nSubCode1, item8, -1, primaryAttribute3);
							instrument.AccessoryList.Add(item5);
							num = 1;
						}
					}
				}
				else if (int.TryParse(value, out result))
				{
					num = LoadSubType(ref curNode2, stt, nDepth + 1, ref instrument, nAccessoryType, nSubCode1, result);
					if (num == 0)
					{
						string[] array6 = new string[4] { "", "", "", "" };
						array6[0] = m_dictionarySampleTechType[nAccessoryType].DisplayName;
						array6[1] = GetSubCode1Text(stt.SubCode1, nSubCode1);
						array6[2] = GetSubCode2Text(stt.SubCode2, result);
						AccessoryName item6 = new AccessoryName(array6[0] + " " + array6[1] + " " + array6[2] + " " + array6[3], bAllowPrimary: GetPrimaryAttribute(ref curNode2), nSampleTechType: nAccessoryType, nSubCode1: nSubCode1, nSubCode2: result, nSubCode3: -1);
						instrument.AccessoryList.Add(item6);
						num = 1;
					}
				}
				break;
			}
			case 3:
			{
				string value = curNode2.Attributes[stt.SubCode3.ToString()].Value;
				if (value.ToLower() == "All".ToLower())
				{
					GetSubCode3All(stt.SubCode3, out var subCodeValues);
					foreach (int item9 in subCodeValues)
					{
						string[] array = new string[4] { "", "", "", "" };
						array[0] = m_dictionarySampleTechType[nAccessoryType].DisplayName;
						array[1] = GetSubCode1Text(stt.SubCode1, nSubCode1);
						array[2] = GetSubCode2Text(stt.SubCode2, nSubCode2);
						array[3] = GetSubCode3Text(stt.SubCode3, item9);
						string strName = array[0] + " " + array[1] + " " + array[2] + " " + array[3];
						bool primaryAttribute = GetPrimaryAttribute(ref curNode2);
						AccessoryName item = new AccessoryName(strName, nAccessoryType, nSubCode1, nSubCode2, item9, primaryAttribute);
						instrument.AccessoryList.Add(item);
						num = 1;
					}
				}
				else if (int.TryParse(value, out result))
				{
					string[] array2 = new string[4] { "", "", "", "" };
					array2[0] = m_dictionarySampleTechType[nAccessoryType].DisplayName;
					array2[1] = GetSubCode1Text(stt.SubCode1, nSubCode1);
					array2[2] = GetSubCode2Text(stt.SubCode2, nSubCode2);
					array2[3] = GetSubCode3Text(stt.SubCode3, result);
					AccessoryName item2 = new AccessoryName(array2[0] + " " + array2[1] + " " + array2[2] + " " + array2[3], bAllowPrimary: GetPrimaryAttribute(ref curNode2), nSampleTechType: nAccessoryType, nSubCode1: nSubCode1, nSubCode2: nSubCode2, nSubCode3: result);
					instrument.AccessoryList.Add(item2);
					num = 1;
				}
				break;
			}
			}
		}
		return num;
	}

	private bool LoadInstrumentAttributes(ref XmlNode curNode, out Instrument instrument, bool bAddInstrument)
	{
		int result = -1;
		bool result2 = true;
		instrument = new Instrument();
		if (curNode.Attributes != null)
		{
			if (GetXMLStringData(ref curNode, "DisplayName", out var strData))
			{
				instrument.DisplayName = strData;
			}
			if (GetXMLStringData(ref curNode, "InternalName", out var strData2))
			{
				instrument.InternalName = strData2;
			}
			if (GetXMLStringData(ref curNode, typeof(LaserType).Name.ToString(), out var strData3))
			{
				AddListData(strData3, instrument.LaserType, ref m_dictionaryLaserType);
			}
			if (GetXMLStringData(ref curNode, typeof(IRSourceType).Name.ToString(), out var strData4))
			{
				AddListData(strData4, instrument.IRSourceType, ref m_dictionaryIRSourceType);
			}
			if (GetXMLStringData(ref curNode, typeof(DetectorLocation).Name.ToString(), out var strData5))
			{
				AddListData(strData5, instrument.DetectorLocation, ref m_dictionaryDetectorLocation);
			}
			if (GetXMLStringData(ref curNode, typeof(Detector).Name.ToString(), out var strData6))
			{
				AddListData(strData6, instrument.Detector, ref m_dictionaryDetector);
			}
			if (GetXMLStringData(ref curNode, typeof(Optics).Name.ToString(), out var strData7))
			{
				AddListData(strData7, instrument.Optics, ref m_dictionaryOptics);
			}
			if (GetXMLStringData(ref curNode, typeof(AccessoryChangeType).Name.ToString(), out var strData8))
			{
				AddListData(strData8, instrument.AccessoryChangeType, ref m_dictionaryAccessoryChangeType);
			}
			if (GetXMLStringData(ref curNode, "InstType", out var strData9))
			{
				int.TryParse(strData9, out result);
				instrument.InstrumentType = result;
			}
			if (GetXMLStringData(ref curNode, "Valid", out var strData10) && bool.TryParse(strData10, out result2))
			{
				instrument.Valid = result2;
			}
		}
		if (bAddInstrument)
		{
			if (result <= 0 || m_dictionaryInstrument.ContainsKey(result))
			{
				return false;
			}
			m_dictionaryInstrument.Add(result, instrument);
		}
		return true;
	}

	private bool LoadInstrumentConfigNode<T>(ref Dictionary<int, T> dictID) where T : InstrumentDefinitions
	{
		return LoadInstrumentConfigNode(ref dictID, null);
	}

	private bool LoadInstrumentConfigNode<T>(ref Dictionary<int, T> dictID, string[] strParams) where T : InstrumentDefinitions
	{
		string name = typeof(T).Name.ToString();
		string strSubCode = "";
		if (strParams != null && strParams.Length == 0)
		{
			return false;
		}
		XmlNodeList elementsByTagName = m_xmlDoc.GetElementsByTagName(name);
		for (int i = 0; i < elementsByTagName.Count; i++)
		{
			XmlNode xmlNode = elementsByTagName[i];
			if (xmlNode.Attributes != null)
			{
				XmlAttribute xmlAttribute = xmlNode.Attributes["SubCode"];
				if (xmlAttribute != null)
				{
					strSubCode = xmlAttribute.Value;
				}
			}
			foreach (XmlNode childNode in xmlNode.ChildNodes)
			{
				string strDisplayName = "";
				string[] array = null;
				if (strParams != null)
				{
					array = new string[strParams.Length];
				}
				if (childNode.Attributes != null)
				{
					XmlAttribute xmlAttribute2 = childNode.Attributes["DisplayName"];
					if (xmlAttribute2 != null)
					{
						strDisplayName = xmlAttribute2.Value;
					}
					if (strParams != null)
					{
						for (int j = 0; j < strParams.Length; j++)
						{
							XmlAttribute xmlAttribute3 = childNode.Attributes[strParams[j]];
							if (xmlAttribute3 != null)
							{
								array[j] = xmlAttribute3.Value;
							}
						}
					}
				}
				int.TryParse(childNode.InnerText, out var result);
				T val = (T)Activator.CreateInstance(typeof(T));
				if (!val.SetDefaultData(strDisplayName, strSubCode, array, out var bValid))
				{
					return false;
				}
				if (bValid)
				{
					if (dictID.ContainsKey(result))
					{
						return false;
					}
					dictID.Add(result, val);
				}
			}
		}
		return true;
	}

	public void ReadXMLDataFile(string strFile, ref Dictionary<ComboboxItem, AccessoryName[]> InstrumentList)
	{
		XmlDocument xmlDocument = new XmlDocument();
		try
		{
			xmlDocument.Load(strFile);
			XmlNodeList elementsByTagName = xmlDocument.GetElementsByTagName("InstrumentConfigs");
			for (int i = 0; i < elementsByTagName.Count; i++)
			{
				XmlNodeList xmlNodeList = elementsByTagName[i].SelectNodes("./Instrument");
				for (int j = 0; j < xmlNodeList.Count; j++)
				{
					bool flag = true;
					XmlNode curNode = xmlNodeList[j];
					if (!LoadInstrumentAttributes(ref curNode, out var instrument, bAddInstrument: false))
					{
						flag = false;
					}
					if (!LoadInstrumentAccessories(ref curNode, ref instrument))
					{
						flag = false;
					}
					if (!flag)
					{
						continue;
					}
					foreach (ComboboxItem key in InstrumentList.Keys)
					{
						if (key.Value != instrument.InstrumentType)
						{
							continue;
						}
						List<AccessoryName> list = new List<AccessoryName>();
						if (m_dictionaryInstrument.ContainsKey(instrument.InstrumentType) && instrument.AccessoryList != null && instrument.AccessoryList.Count > 0 && m_dictionaryInstrument[instrument.InstrumentType].AccessoryList != null && m_dictionaryInstrument[instrument.InstrumentType].AccessoryList.Count > 0)
						{
							foreach (AccessoryName accessory in m_dictionaryInstrument[instrument.InstrumentType].AccessoryList)
							{
								foreach (AccessoryName accessory2 in instrument.AccessoryList)
								{
									if (accessory.SampleTechType == accessory2.SampleTechType && accessory.SubCode1 == accessory2.SubCode1 && accessory.SubCode2 == accessory2.SubCode2 && accessory.SubCode3 == accessory2.SubCode3)
									{
										list.Add(accessory);
										break;
									}
								}
							}
						}
						if (list.Count > 0)
						{
							InstrumentList[key] = new AccessoryName[list.Count];
							list.ToArray().CopyTo(InstrumentList[key], 0);
						}
						break;
					}
				}
			}
		}
		catch (Exception ex)
		{
			MessageBox.Show(ex.Message, InstrumentDataResource.DataFileParseError, MessageBoxButtons.OK, MessageBoxIcon.Hand);
		}
	}

	public void WriteXMLDataFile(string strFile, Dictionary<ComboboxItem, AccessoryName[]> InstrumentList)
	{
		try
		{
			XmlDocument doc = new XmlDocument();
			XmlDeclaration newChild = doc.CreateXmlDeclaration("1.0", "UTF-8", null);
			XmlElement documentElement = doc.DocumentElement;
			doc.InsertBefore(newChild, documentElement);
			XmlElement xmlElement = doc.CreateElement(string.Empty, "InstrumentConfigNodes", string.Empty);
			doc.AppendChild(xmlElement);
			AddAccessoryNode(ref doc, xmlElement, "SampleTechType");
			AddAccessoryNode(ref doc, xmlElement, "AtrType");
			AddAccessoryNode(ref doc, xmlElement, "AtrMaterial");
			AddAccessoryNode(ref doc, xmlElement, "AtrPress");
			AddAccessoryNode(ref doc, xmlElement, "TransType");
			AddAccessoryNode(ref doc, xmlElement, "ReflType");
			AddAccessoryNode(ref doc, xmlElement, "ReflAngle");
			AddAccessoryNode(ref doc, xmlElement, "ReflScreen");
			AddAccessoryNode(ref doc, xmlElement, "AccessoryChangeType");
			AddAccessoryNode(ref doc, xmlElement, "GasCellType");
			AddAccessoryNode(ref doc, xmlElement, "MicroType");
			AddAccessoryNode(ref doc, xmlElement, "FiberType");
			AddAccessoryNode(ref doc, xmlElement, "MiscType");
			AddAccessoryNode(ref doc, xmlElement, "Optics");
			AddAccessoryNode(ref doc, xmlElement, "Detector");
			AddAccessoryNode(ref doc, xmlElement, "DetectorLocation");
			AddAccessoryNode(ref doc, xmlElement, "LaserType");
			AddAccessoryNode(ref doc, xmlElement, "IRSourceType");
			XmlElement xmlElement2 = doc.CreateElement(string.Empty, "InstrumentConfigs", string.Empty);
			xmlElement.AppendChild(xmlElement2);
			XmlNodeList elementsByTagName = m_xmlDoc.GetElementsByTagName("InstrumentConfigs");
			XmlNodeList xmlNodeList = null;
			for (int i = 0; i < elementsByTagName.Count; i++)
			{
				xmlNodeList = elementsByTagName[i].SelectNodes("./Instrument");
			}
			if (xmlNodeList != null)
			{
				foreach (ComboboxItem key in InstrumentList.Keys)
				{
					AccessoryName[] curAccessories = InstrumentList[key];
					AddInstrumentNode(ref doc, xmlNodeList, xmlElement2, key, curAccessories);
				}
			}
			doc.Save(strFile);
		}
		catch (Exception ex)
		{
			MessageBox.Show(ex.Message, InstrumentDataResource.Error, MessageBoxButtons.OK, MessageBoxIcon.Hand);
		}
	}

	private void AddAccessoryNode(ref XmlDocument doc, XmlElement parent, string strName)
	{
		XmlNodeList elementsByTagName = m_xmlDoc.GetElementsByTagName(strName);
		for (int i = 0; i < elementsByTagName.Count; i++)
		{
			XmlNode node = elementsByTagName[i];
			XmlNode newChild = doc.ImportNode(node, deep: true);
			parent.AppendChild(newChild);
		}
	}

	private void AddInstrumentNode(ref XmlDocument doc, XmlNodeList instrumentList, XmlElement parent, ComboboxItem item, AccessoryName[] curAccessories)
	{
		for (int i = 0; i < instrumentList.Count; i++)
		{
			XmlNode curNode = instrumentList[i];
			if (!LoadInstrumentAttributes(ref curNode, out var _, bAddInstrument: false) || curNode.Attributes == null || !GetXMLStringData(ref curNode, "InstType", out var strData))
			{
				continue;
			}
			int.TryParse(strData, out var result);
			if (result != item.Value)
			{
				continue;
			}
			XmlNode xmlNode = doc.ImportNode(curNode, deep: false);
			parent.AppendChild(xmlNode);
			if (curAccessories == null)
			{
				continue;
			}
			Dictionary<int, Dictionary<int, Dictionary<int, List<int>>>> dictionary = new Dictionary<int, Dictionary<int, Dictionary<int, List<int>>>>();
			for (int j = 0; j < curAccessories.Length; j++)
			{
				if (curAccessories[j].SampleTechType < 0)
				{
					continue;
				}
				if (!dictionary.ContainsKey(curAccessories[j].SampleTechType))
				{
					dictionary.Add(curAccessories[j].SampleTechType, new Dictionary<int, Dictionary<int, List<int>>>());
				}
				if (curAccessories[j].SubCode1 < 0)
				{
					continue;
				}
				if (!dictionary[curAccessories[j].SampleTechType].ContainsKey(curAccessories[j].SubCode1))
				{
					dictionary[curAccessories[j].SampleTechType].Add(curAccessories[j].SubCode1, new Dictionary<int, List<int>>());
				}
				if (curAccessories[j].SubCode2 >= 0)
				{
					if (!dictionary[curAccessories[j].SampleTechType][curAccessories[j].SubCode1].ContainsKey(curAccessories[j].SubCode2))
					{
						dictionary[curAccessories[j].SampleTechType][curAccessories[j].SubCode1].Add(curAccessories[j].SubCode2, new List<int>());
					}
					if (curAccessories[j].SubCode3 >= 0 && !dictionary[curAccessories[j].SampleTechType][curAccessories[j].SubCode1][curAccessories[j].SubCode2].Contains(curAccessories[j].SubCode3))
					{
						dictionary[curAccessories[j].SampleTechType][curAccessories[j].SubCode1][curAccessories[j].SubCode2].Add(curAccessories[j].SubCode3);
					}
				}
			}
			foreach (int key in dictionary.Keys)
			{
				SampleTechType sampleTechType = m_dictionarySampleTechType[key];
				if (!m_dictionarySampleTechType.ContainsKey(key))
				{
					continue;
				}
				XmlElement xmlElement = doc.CreateElement(string.Empty, "Accessory", string.Empty);
				XmlAttribute xmlAttribute = doc.CreateAttribute(string.Empty, "SampleTechType", string.Empty);
				xmlAttribute.Value = key.ToString();
				xmlElement.Attributes.Append(xmlAttribute);
				xmlNode.AppendChild(xmlElement);
				foreach (int key2 in dictionary[key].Keys)
				{
					XmlElement xmlElement2 = doc.CreateElement(string.Empty, "SubType", string.Empty);
					XmlAttribute xmlAttribute2 = doc.CreateAttribute(string.Empty, sampleTechType.SubCode1.ToString(), string.Empty);
					xmlAttribute2.Value = key2.ToString();
					xmlElement2.Attributes.Append(xmlAttribute2);
					xmlElement.AppendChild(xmlElement2);
					foreach (int key3 in dictionary[key][key2].Keys)
					{
						XmlElement xmlElement3 = doc.CreateElement(string.Empty, "SubType", string.Empty);
						XmlAttribute xmlAttribute3 = doc.CreateAttribute(string.Empty, sampleTechType.SubCode2.ToString(), string.Empty);
						xmlAttribute3.Value = key3.ToString();
						xmlElement3.Attributes.Append(xmlAttribute3);
						xmlElement2.AppendChild(xmlElement3);
						foreach (int item2 in dictionary[key][key2][key3])
						{
							XmlElement xmlElement4 = doc.CreateElement(string.Empty, "SubType", string.Empty);
							XmlAttribute xmlAttribute4 = doc.CreateAttribute(string.Empty, sampleTechType.SubCode3.ToString(), string.Empty);
							xmlAttribute4.Value = item2.ToString();
							xmlElement4.Attributes.Append(xmlAttribute4);
							xmlElement3.AppendChild(xmlElement4);
						}
					}
				}
			}
		}
	}

	public string GetInstrumentName(int nVal)
	{
		string unknown = InstrumentDataResource.Unknown;
		if (m_dictionaryInstrument != null && m_dictionaryInstrument.ContainsKey(nVal))
		{
			return Instruments[nVal].DisplayName;
		}
		return unknown;
	}

	public string GetAtrTypeName(int nVal)
	{
		string unknown = InstrumentDataResource.Unknown;
		if (m_dictionaryAtrType != null && m_dictionaryAtrType.ContainsKey(nVal))
		{
			return m_dictionaryAtrType[nVal].DisplayName;
		}
		return unknown;
	}

	public string GetAccessoryName(int nSampleTech, int nSubCode1, int nSubCode2, int nSubCode3)
	{
		string text = InstrumentDataResource.Unknown;
		string text2 = "";
		string[] array = new string[3] { "", "", "" };
		if (m_dictionarySampleTechType != null && m_dictionarySampleTechType.ContainsKey(nSampleTech))
		{
			text2 = m_dictionarySampleTechType[nSampleTech].DisplayName;
			array[0] = GetSubCode1Text(m_dictionarySampleTechType[nSampleTech].SubCode1, nSubCode1);
			array[1] = GetSubCode2Text(m_dictionarySampleTechType[nSampleTech].SubCode2, nSubCode2);
			array[2] = GetSubCode3Text(m_dictionarySampleTechType[nSampleTech].SubCode3, nSubCode3);
		}
		if (text2.Length > 0)
		{
			text = text2;
			for (int i = 0; i < 3 && array[i].Length > 0; i++)
			{
				text = text + " " + array[i];
			}
		}
		return text;
	}
}
[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "4.0.0.0")]
[DebuggerNonUserCode]
[CompilerGenerated]
internal class InstrumentDataResource
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
				resourceMan = new ResourceManager("MLInstrumentConfig.InstrumentDataResource", typeof(InstrumentDataResource).Assembly);
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

	internal static string ContinueNoPrimary => ResourceManager.GetString("ContinueNoPrimary", resourceCulture);

	internal static string ContinueTitle => ResourceManager.GetString("ContinueTitle", resourceCulture);

	internal static string DataFileParseError => ResourceManager.GetString("DataFileParseError", resourceCulture);

	internal static string Error => ResourceManager.GetString("Error", resourceCulture);

	internal static string InvalidXMLInfo => ResourceManager.GetString("InvalidXMLInfo", resourceCulture);

	internal static string MakePrimary => ResourceManager.GetString("MakePrimary", resourceCulture);

	internal static string MissingDataFile => ResourceManager.GetString("MissingDataFile", resourceCulture);

	internal static string None => ResourceManager.GetString("None", resourceCulture);

	internal static string RemovePrimary => ResourceManager.GetString("RemovePrimary", resourceCulture);

	internal static string SelectInstAccessoryConfig => ResourceManager.GetString("SelectInstAccessoryConfig", resourceCulture);

	internal static string SelectInstConfig => ResourceManager.GetString("SelectInstConfig", resourceCulture);

	internal static string SelectPrimaryAccessory => ResourceManager.GetString("SelectPrimaryAccessory", resourceCulture);

	internal static string Undefined => ResourceManager.GetString("Undefined", resourceCulture);

	internal static string Unknown => ResourceManager.GetString("Unknown", resourceCulture);

	internal InstrumentDataResource()
	{
	}
}
