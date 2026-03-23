; shrunk from mInstUsb.dll.c.txt
strings:
  S1="Error: UsbConn::Lock() Failed\\n"
  S2="vector<T> too long"
  S3="deque<T> too long"
  S4="Unknown exception"
  S5="KERNEL32.DLL"
  S6="EncodePointer"
  S7="DecodePointer"
  S8="FlsAlloc"
  S9="FlsGetValue"
  S10="FlsSetValue"
  S11="FlsFree"
  S12="Runtime Error!\\n\\nProgram: "
  S13="<program name unknown>"
  S14="..."
  S15="\\n\\n"
  S16="Microsoft Visual C++ Runtime Library"
  S17=""
  S18="mscoree.dll"
  S19="CorExitProcess"
  S20="USER32.DLL"
  S21="MessageBoxA"
  S22="GetActiveWindow"
  S23="GetLastActivePopup"
  S24="GetUserObjectInformationA"
  S25="GetProcessWindowStation"
  S26="CONOUT$"
  S27="string too long"
  S28="invalid string position"
  S29="bad exception"
  S30="mInstWire64 can\\'t get mutex\\n"
  S31="mInstWire64SharedDataMutex"
  S32="\\\\"
  S33="Error in mInstWire64::connect %d (0x%x)\\n"
  S34="mInstWire32 can\\'t get mutex\\n"
  S35="Warning: mInstWire32 disconnect still had mutex locked\\n"
  S36="Error in mInstWire32::connect %d (0x%x)\\n"
  S37="mInstWinUsb can\\'t get mutex\\n"
  S38="Warning: mInstWinUsb disconnect still had mutex locked\\n"
  S39="TopScan"
  S40="WinUsbNotify"
  S41="ClosePort() manually terminated HeartbeatThread\\n"
  S42="ClosePort() manually terminated StatusThread"
  S43="HeartbeatThread: Starting\\n"
  S44="StartHeartbeatThread(): Could not create HeartbeatThread"
  S45="StartHeartbeatThread(): HeartbeatThread already running!"
  S46="StatusThread started\\n"
  S47="StartStatusThread(): Could not create StatusThread"
  S48="StartStatusThread(): StatusThread already running!"
f FUN_10001030(1):
  c:exception
  cf:
    *(undefined ***)param_1 = std::bad_alloc::vftable;
    exception::~exception();
    return;

f FUN_10001050(2):
  c:FUN_10001030,FUN_10008417
  g:FUN_10001030,FUN_10008417
  cf:
    FUN_10001030();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(exception *)this;

f FUN_10001080(2):
  cf:
    return param_2;

f FUN_10001090(2):
  cf:
    return;

f FUN_100010a0(3):
  c:_memcmp
  cf:
    _memcmp();
    return;

f FID_conflict__Move_s(4):
  c:_memcpy_s
  cf:
    _memcpy_s();
    return param_1;

f FID_conflict__Move_s(4):
  c:_memmove_s
  cf:
    _memmove_s();
    return param_1;

f FUN_10001120(2):
  cf:
    *(undefined4 *)this = param_1;
    return(undefined4 *)this;

f FUN_10001140(1):
  cf:
    return *param_1;

f FUN_10001150(0):
  cf:
    return;

f FUN_10001160(1):
  cf:
    return param_1;

f FUN_10001180(2):
  cf:
    *(undefined4 *)this = *param_1;
    return;

f FUN_100011a0(1):
  c:FUN_10001140
  g:FUN_10001140
  cf:
    if(*param_1 == 0){
    else{
    local_c = FUN_10001140();
    return local_c;

f FUN_100011d0(2):
  cf:
    return *this == *param_1;

f FUN_100011f0(1):
  cf:
    return *param_1 != 0;

f FID_conflict_runtime_error(2):
  c:FUN_1000688a,FUN_100019b0
  k:0xc
  cf:
    FUN_1000688a();
    *(undefined ***)this = std::logic_error::vftable;
    FUN_100019b0(0xc);
    return(undefined4 *)this;

f FID_conflict__logic_error(1):
  c:exception
  k:0xc
  cf:
    *(undefined ***)param_1 = std::logic_error::vftable;
    std::basic_string<>::~basic_string<>((basic_string<> *)(param_1 + 0xc));
    exception::~exception();
    return;

f what(1):
  c:FUN_10001a50
  k:0xc
  cf:
    FUN_10001a50(0xc);
    return;

f FUN_100012d0(2):
  c:FID_conflict__logic_error,FUN_10008417
  g:FUN_10008417
  cf:
    FID_conflict__logic_error();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(exception *)this;

f FID_conflict_length_error(2):
  c:FID_conflict_runtime_error
  cf:
    FID_conflict_runtime_error();
    *(undefined ***)this = std::length_error::vftable;
    return(undefined4 *)this;

f FUN_10001330(1):
  c:FID_conflict__logic_error
  cf:
    *(undefined ***)param_1 = std::length_error::vftable;
    FID_conflict__logic_error();
    return;

f FUN_10001350(2):
  c:FUN_10001330,FUN_10008417
  g:FUN_10001330,FUN_10008417
  cf:
    FUN_10001330();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(exception *)this;

f FID_conflict_runtime_error(2):
  c:exception,FUN_100019b0
  k:0xc
  cf:
    std::exception::exception();
    *(undefined ***)this = std::logic_error::vftable;
    FUN_100019b0(0xc,0xc);
    return(exception *)this;

f FID_conflict__vector_deleting_destructor_(2):
  c:DTaskBase,FUN_10008417,_eh_vector_destructor_iterator_,FUN_1000837a
  g:FUN_10008417
  k:0x40
  cf:
    if((param_1 & 2)== 0){
    DTaskBase::~DTaskBase();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    else{
    _eh_vector_destructor_iterator_(0x40);
    if((param_1 & 1)!= 0){
    FUN_1000837a();
    this =(void *)((int)this + -4);
    return(DTaskBase *)this;

f FUN_10001620(1):
  c:DMutex
  k:0x19,0x1a,0x1b,0xb
  cf:
    DMutex::DMutex();
    *(undefined1 *)(param_1 + 6)= 0;
    *(undefined1 *)((int)param_1 + 0x19)= 1;
    *(undefined1 *)((int)param_1 + 0x1a)= 0;
    *(undefined1 *)((int)param_1 + 0x1b)= 1;
    *(undefined1 *)(param_1 + 0xb)= 0;
    return param_1;

f FUN_100016c0(1):
  c:DMutex
  cf:
    DMutex::~DMutex();
    return;

f FUN_100016e0(4):
  c:FUN_100017b0,FUN_10001790,FUN_10018df0,FUN_10018b70
  g:FUN_10001790
  k:0xc,0x10,0x19
  cf:
    *(undefined4 *)((int)this + 8)= param_1;
    *(undefined4 *)((int)this + 0xc)= param_2;
    *(undefined4 *)((int)this + 0x10)= 1;
    if(param_3 == '\0'){
    FUN_100017b0();
    else{
    FUN_10001790();
    if(*(char *)((int)this + 0x19)!= '\0'){
    FUN_10018df0();
    FUN_10018b70();
    return;

f FUN_10001740(2):
  k:0xc
  cf:
    *(undefined4 *)((int)this + 0xc)= param_1;
    return;

f FUN_10001760(1):
  c:FUN_10018350,FUN_100182b0
  g:FUN_10018350
  k:0x10
  cf:
    FUN_10018350();
    FUN_100182b0();
    *(undefined4 *)(param_1 + 0x10)= 0;
    return;

f FUN_10001790(1):
  k:0x1b
  cf:
    *(undefined1 *)(param_1 + 0x1b)= 1;
    return;

f FUN_100017b0(1):
  k:0x1b
  cf:
    *(undefined1 *)(param_1 + 0x1b)= 0;
    return;

f FUN_100017d0(2):
  k:0x1c
  cf:
    *(undefined4 *)((int)this + 0x1c)= param_1;
    return;

f FUN_100017f0(1):
  k:0x10
  cf:
    return *(undefined4 *)(param_1 + 0x10);

f FUN_10001810(1):
  c:Lock,OutputDebugStringA
  cf:
    lVar1 = DMutex::Lock();
    if(lVar1 != 0){
    OutputDebugStringA(S1);
    return;

f FUN_10001840(1):
  c:Unlock
  cf:
    DMutex::Unlock();
    return;

f FUN_10001860(2):
  c:FUN_100016c0,FUN_10008417
  g:FUN_10008417
  cf:
    FUN_100016c0();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(undefined4 *)this;

f FUN_10001890(1):
  cf:
    std::basic_string<>::basic_string<>((basic_string<> *)(param_1 + 8));
    return param_1;

f FUN_100018b0(1):
  cf:
    std::basic_string<>::~basic_string<>((basic_string<> *)(param_1 + 8));
    return;

f FUN_100018d0(2):
  c:DMutex,FUN_10008417
  g:FUN_10008417
  cf:
    DMutex::~DMutex();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(DMutex *)this;

f FUN_10001900(2):
  c:FUN_100019b0
  cf:
    *(undefined4 *)this = *param_1;
    *(undefined4 *)((int)this + 4)= param_1[1];
    FUN_100019b0();
    return(undefined4 *)this;

f FUN_100019b0(2):
  c:FUN_10001f10,FUN_10001e70,assign
  k:0xffffffff
  cf:
    FUN_10001f10();
    FUN_10001e70();
    std::basic_string<>::assign(0xffffffff);
    return(basic_string<> *)this;

f FUN_10001a10(2):
  c:FID_conflict_assign
  cf:
    FID_conflict_assign();
    return;

f FUN_10001a50(1):
  c:_Myptr
  cf:
    std::basic_string<>::_Myptr();
    return;

f FUN_10001ac0(1):
  c:FUN_10003cc0,FUN_10002090
  g:FUN_10002090
  k:0xffffffe0
  cf:
    allocator<>(&stack0xffffffe0);
    FUN_10003cc0();
    FUN_10002090();
    return param_1;

f FUN_10001b30(1):
  c:FUN_10002110,FUN_10003a70
  g:FUN_10002110
  cf:
    FUN_10002110();
    FUN_10003a70();
    return;

f FUN_10001b50(1):
  k:0x10,0xc,0x24
  cf:
    return(*(int *)(param_1 + 0x10)- *(int *)(param_1 + 0xc))/ 0x24;

f FUN_10001b70(2):
  c:FUN_10001b50,FUN_100082e9
  k:0x24,0xc
  cf:
    uVar1 = FUN_10001b50();
    if(uVar1 <= param_1){
    FUN_100082e9();
    return param_1 * 0x24 + *(int *)((int)this + 0xc);

f FUN_10001ba0(2):
  c:FUN_10001b50,FUN_10001f30,FUN_10002190,FUN_10003d30,FUN_10001f70
  g:FUN_10002190
  k:0x10
  cf:
    uVar1 = FUN_10001b50();
    uVar2 = FUN_10001f30();
    if(uVar1 < uVar2){
    iVar3 = FUN_10002190(0x10);
    *(int *)((int)this + 0x10)= iVar3;
    else{
    puVar4 =(undefined4 *)FUN_10003d30();
    FUN_10001f70();
    return;

f FUN_10001c20(1):
  c:FUN_10003d30,FUN_10003ad0,FUN_10001ff0
  cf:
    puVar1 =(undefined4 *)FUN_10003d30();
    puVar1 =(undefined4 *)FUN_10003ad0();
    FUN_10001ff0();
    return;

f FUN_10001c80(1):
  c:FUN_10002250,FUN_10003a70
  g:FUN_10002250
  cf:
    FUN_10002250();
    FUN_10003a70();
    return;

f FID_conflict_assign(2):
  c:assign
  k:0xffffffff
  cf:
    std::basic_string<>::assign(0xffffffff);
    return;

f FUN_10001dc0(5):
  c:FUN_100114f5,_Myptr,FUN_100010a0
  k:0x14
  cf:
    if(*(uint *)((int)this + 0x14)< param_1){
    FUN_100114f5();
    if(*(int *)((int)this + 0x14)- param_1 < param_2){
    param_2 = *(int *)((int)this + 0x14)- param_1;
    if(param_2 < param_4){
    else{
    pcVar1 = std::basic_string<>::_Myptr();
    local_14 = FUN_100010a0();
    if(local_14 == 0){
    if(param_2 < param_4){
    else{
    local_18 =(uint)(param_2 != param_4);
    return local_14;

f FUN_10001e70(3):
  c:FUN_10004e70,_Eos
  k:0xf,0x18,0x10
  cf:
    if((param_1 != '\0')&&(0xf < *(uint *)((int)this + 0x18))){
    pcVar1 = *(char **)((int)this + 4);
    if(param_2 != 0){
    std::_Traits_helper::copy_s<>((char *)((int)this + 4),0x10,pcVar1,param_2);
    FUN_10004e70();
    *(undefined4 *)((int)this + 0x18)= 0xf;
    std::basic_string<>::_Eos();
    return;

f FUN_10001f10(2):
  cf:
    std::allocator<char>::allocator<char>((allocator<char> *)this,param_1);
    return(allocator<char> *)this;

f FUN_10001f30(1):
  k:0xc,0x14,0x24
  cf:
    if(*(int *)(param_1 + 0xc)== 0){
    else{
    local_c =(*(int *)(param_1 + 0x14)- *(int *)(param_1 + 0xc))/ 0x24;
    return local_c;

f FUN_10001f70(5):
  c:FUN_10001b50,FUN_10003ad0,FUN_10002a60,FUN_10002550,FUN_10002a20
  g:FUN_10002550
  cf:
    iVar1 = FUN_10001b50();
    if(iVar1 == 0){
    else{
    piVar2 =(int *)FUN_10003ad0();
    local_20 = FUN_10002a60();
    FUN_10002550();
    this_00 = FUN_10003ad0();
    FUN_10002a20();
    return param_1;

f FUN_10001ff0(6):
  c:FUN_10004e50,FUN_10004e90,FUN_10002520
  g:FUN_10002520
  k:0x10
  cf:
    FUN_10004e50();
    bVar1 = FUN_10004e90();
    if(bVar1){
    *(undefined4 *)((int)this + 0x10),local_8);
    FUN_10002520(0x10);
    *(void **)((int)this + 0x10)= pvVar2;
    return param_1;

f FUN_10002090(2):
  c:FUN_10002500,FID_conflict__Xinvarg,FUN_100029d0,CONCAT31
  g:FUN_10002500,CONCAT31
  k:0xc,0x10,0x14,0xffffff00,0x24
  cf:
    *(undefined4 *)((int)this + 0xc)= 0;
    *(undefined4 *)((int)this + 0x10)= 0;
    *(undefined4 *)((int)this + 0x14)= 0;
    if(param_1 == 0){
    uVar1 =(uint)this & 0xffffff00;
    else{
    uVar1 = FUN_10002500();
    if(uVar1 < param_1){
    this =(void *)FID_conflict__Xinvarg();
    else{
    uVar2 = FUN_100029d0();
    *(undefined4 *)((int)this + 0xc)= uVar2;
    *(undefined4 *)((int)this + 0x10)= *(undefined4 *)((int)this + 0xc);
    *(uint *)((int)this + 0x14)= param_1 * 0x24 + *(int *)((int)this + 0xc);
    uVar1 = CONCAT31();
    return uVar1;

f FUN_10002110(1):
  c:FUN_10002520,FUN_10004e70
  g:FUN_10002520
  k:0xc,0x10,0x14
  cf:
    if(*(int *)((int)param_1 + 0xc)!= 0){
    FUN_10002520(0xc,0x10);
    FUN_10004e70(0xc);
    *(undefined4 *)((int)param_1 + 0xc)= 0;
    *(undefined4 *)((int)param_1 + 0x10)= 0;
    *(undefined4 *)((int)param_1 + 0x14)= 0;
    return;

f FUN_10002190(4):
  c:FUN_10002f10
  k:0x24
  cf:
    FUN_10002f10();
    return param_2 * 0x24 + param_1;

f FUN_100021d0(2):
  c:FUN_100061a0,FID_conflict__Xinvarg,FUN_10002ce0,CONCAT31
  g:CONCAT31
  k:0xc,0x10,0x14,0xffffff00
  cf:
    *(undefined4 *)((int)this + 0xc)= 0;
    *(undefined4 *)((int)this + 0x10)= 0;
    *(undefined4 *)((int)this + 0x14)= 0;
    if(param_1 == 0){
    uVar1 =(uint)this & 0xffffff00;
    else{
    uVar1 = FUN_100061a0();
    if(uVar1 < param_1){
    this =(void *)FID_conflict__Xinvarg();
    else{
    uVar2 = FUN_10002ce0();
    *(undefined4 *)((int)this + 0xc)= uVar2;
    *(undefined4 *)((int)this + 0x10)= *(undefined4 *)((int)this + 0xc);
    *(uint *)((int)this + 0x14)= *(int *)((int)this + 0xc)+ param_1 * 4;
    uVar1 = CONCAT31();
    return uVar1;

f FUN_10002250(1):
  c:FUN_100029f0,FUN_10004e70
  k:0xc,0x10,0x14
  cf:
    if(*(int *)((int)param_1 + 0xc)!= 0){
    FUN_100029f0(0xc,0x10);
    FUN_10004e70(0xc);
    *(undefined4 *)((int)param_1 + 0xc)= 0;
    *(undefined4 *)((int)param_1 + 0x10)= 0;
    *(undefined4 *)((int)param_1 + 0x14)= 0;
    return;

f if(1):
  c:_Eos
  cf:
    basic_string<>::_Eos();

f FUN_10002500(0):
  c:max_size
  cf:
    max_size();
    return;

f FUN_10002520(3):
  c:FUN_10002f90
  cf:
    FUN_10002f90();
    return;

f FUN_10002550(5):
  c:FUN_10001f30,FUN_10001b50,FUN_10002500,FID_conflict__Xinvarg,FUN_100029d0,FUN_10002190,do_is,FUN_10002725,FUN_10001900,CONCAT31,FUN_1000285b,FUN_10003030,FUN_10003000,FUN_100018b0,__security_check_cookie
  g:DAT_10020030,FUN_10002500,FUN_10002190,FUN_10002725,FUN_10001900,CONCAT31,FUN_10003030,FUN_10003000
  k:0xfffffffc,0xc,0x24,0x10
  cf:
    uStack_8c = DAT_10020030 ^(uint)&stack0xfffffffc;
    local_14 =(undefined1 *)&uStack_8c;
    local_18 = FUN_10001f30();
    if(param_3 != 0){
    iVar1 = FUN_10001b50();
    iVar2 = FUN_10002500();
    if((uint)(iVar2 - iVar1)< param_3){
    FID_conflict__Xinvarg();
    else{
    iVar1 = FUN_10001b50();
    if(local_18 < iVar1 + param_3){
    iVar1 = FUN_10002500();
    if(iVar1 - uVar4 < local_18){
    else{
    local_7c =(local_18 >> 1)+ local_18;
    iVar1 = FUN_10001b50();
    if(local_18 < iVar1 + param_3){
    iVar1 = FUN_10001b50();
    local_20 = FUN_100029d0();
    local_1c =(param_2 - *(int *)((int)this + 0xc))/ 0x24;
    FUN_10002190(0x24);
    do_is(this,*(undefined4 *)((int)this + 0xc),param_2,local_20);
    do_is(this,param_2,*(undefined4 *)((int)this + 0x10),(local_1c + param_3)* 0x24 + local_20)
    FUN_10002725();
    return;
    if((uint)((*(int *)((int)this + 0x10)- param_2)/ 0x24)< param_3){
    FUN_10001900();
    do_is(this,param_2,*(undefined4 *)((int)this + 0x10),param_3 * 0x24 + param_2);
    local_8 = CONCAT31();
    param_3 -(*(int *)((int)this + 0x10)- param_2)/ 0x24,local_4c);
    FUN_1000285b();
    return;
    FUN_10001900();
    local_50 = *(int *)((int)this + 0x10);
    uVar3 = do_is(0x24,0x10);
    *(undefined4 *)((int)this + 0x10)= uVar3;
    FUN_10003030();
    FUN_10003000(0x24);
    FUN_100018b0();
    __security_check_cookie(0xfffffffc);
    return;

f Catch_All_100026b6(0):
  c:FUN_10004e70,__CxxThrowException_8
  k:0x20,0x18,0x24,0x1c,0x10,0x0,0xffffffff,0x1000272c
  cf:
    if(1 < *(int *)(unaff_EBP + -0x20)){
    (void *)(*(int *)(unaff_EBP + -0x18)* 0x24 + *(int *)(unaff_EBP + -0x1c)));
    if(0 < *(int *)(unaff_EBP + -0x20)){
    *(int *)(unaff_EBP + 0x10)* 0x24));
    FUN_10004e70(0x1c);
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    return 0x1000272c;

f FUN_10002725(0):
  c:FUN_10001b50,FUN_10004e70,__security_check_cookie
  k:0xffffffff,0x74,0x10,0xc,0x14,0x24,0x1c
  cf:
    *(undefined4 *)(unaff_EBP - 4)= 0xffffffff;
    iVar1 = FUN_10001b50(0x74);
    *(int *)(unaff_EBP + 0x10)= iVar1 + *(int *)(unaff_EBP + 0x10);
    if(*(int *)(*(int *)(unaff_EBP - 0x74)+ 0xc)!= 0){
    *(void **)(*(int *)(unaff_EBP - 0x74)+ 0x10));
    FUN_10004e70(0x74);
    *(int *)(unaff_EBP - 0x14)* 0x24 + *(int *)(unaff_EBP - 0x1c);
    *(int *)(unaff_EBP + 0x10)* 0x24 + *(int *)(unaff_EBP - 0x1c);
    *(undefined4 *)(*(int *)(unaff_EBP - 0x74)+ 0xc)= *(undefined4 *)(unaff_EBP - 0x1c);
    ExceptionList = *(void **)(unaff_EBP - 0xc);
    __security_check_cookie(0x24);
    return;

f Catch_All_10002826(0):
  c:__CxxThrowException_8
  k:0x74,0x10,0x0,0x10002862
  cf:
    *(int *)(*(int *)(unaff_EBP + -0x74)+ 0x10)));
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 2;
    return 0x10002862;

f FUN_1000285b(0):
  c:FUN_100018b0,__security_check_cookie
  k:0x10,0x24,0x74,0x48,0xffffffff,0xc
  cf:
    *(undefined4 *)(unaff_EBP - 4)= 2;
    *(int *)(unaff_EBP + 0x10)* 0x24 + *(int *)(*(int *)(unaff_EBP - 0x74)+ 0x10);
    (undefined4 *)(unaff_EBP - 0x48));
    *(undefined4 *)(unaff_EBP - 4)= 0xffffffff;
    FUN_100018b0(0x48);
    ExceptionList = *(void **)(unaff_EBP - 0xc);
    __security_check_cookie(0x24);
    return;

f FID_conflict__Xinvarg(0):
  c:FID_conflict_length_error,__CxxThrowException_8
  cf:
    basic_string<>(local_54,S2);
    FID_conflict_length_error();
    __CxxThrowException_8();
    std::basic_string<>::~basic_string<>((basic_string<> *)local_54);
    return;

f FUN_100029d0(1):
  c:FUN_100030a0
  cf:
    FUN_100030a0();
    return;

f FUN_100029f0(3):
  c:FUN_100030f0
  cf:
    FUN_100030f0();
    return;

f FUN_10002a20(3):
  c:FUN_10002d60
  cf:
    local_8 = *(undefined4 *)((int)this + 4);
    puVar2 =(undefined4 *)FUN_10002d60();
    return param_1;

f FUN_10002a60(2):
  c:FUN_100011f0,FUN_100011d0,FUN_100082e9
  k:0x24
  cf:
    bVar1 = FUN_100011f0();
    if((!bVar1)||(bVar1 = FUN_100011d0(this,param_1),!bVar1)){
    FUN_100082e9();
    return(*(int *)((int)this + 4)- param_1[1])/ 0x24;

f FID_conflict_invalid_argument(2):
  c:FID_conflict_runtime_error
  cf:
    FID_conflict_runtime_error();
    *(undefined ***)this = std::length_error::vftable;
    return(undefined4 *)this;

f FID_conflict_max_size(1):
  c:max_size
  cf:
    uVar1 = std::allocator<char>::max_size();
    if(uVar1 < 2){
    else{
    return local_10;

f FUN_10002b20(2):
  c:FID_conflict_max_size,elif,allocate,FUN_10002c35
  k:0x18
  cf:
    uVar1 = FID_conflict_max_size();
    if(uVar1 < local_1c){
    elif(local_1c / 3 < *(uint *)((int)this + 0x18)>> 1){
    uVar1 = *(uint *)((int)this + 0x18);
    iVar2 = FID_conflict_max_size();
    if(*(uint *)((int)this + 0x18)<= iVar2 -(uVar1 >> 1)){
    local_1c =(*(uint *)((int)this + 0x18)>> 1)+ *(int *)((int)this + 0x18);
    std::allocator<char>::allocate();
    FUN_10002c35();
    return;

f Catch_All_10002bd8(0):
  c:FUN_10002c21
  g:BADSPACEBASE
  k:0x10,0x00000010,0x18,0x1c,0x24,0x14
  cf:
    *(BADSPACEBASE **)(unaff_EBP + -0x10)= register0x00000010;
    *(undefined4 *)(unaff_EBP + -0x18)= *(undefined4 *)(unaff_EBP + 8);
    *(undefined1 *)(unaff_EBP + -4)= 2;
    (*(allocator<char> **)(unaff_EBP + -0x1c),*(int *)(unaff_EBP + -0x18)+ 1);
    *(char **)(unaff_EBP + -0x24)= pcVar1;
    *(undefined4 *)(unaff_EBP + -0x14)= *(undefined4 *)(unaff_EBP + -0x24);
    FUN_10002c21();
    return;

f Catch_All_10002bff(0):
  c:FUN_10001e70,__CxxThrowException_8
  k:0x1c,0x0,0x10002c28
  cf:
    FUN_10001e70(0x1c);
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 1;
    return 0x10002c28;

f FUN_10002c21(0):
  k:0x10002c3c
  cf:
    *(undefined4 *)(unaff_EBP + -4)= 1;
    return 0x10002c3c;

f FUN_10002c35(0):
  c:_Myptr,FUN_10001e70,_Eos
  k:0xffffffff,0xc,0x1c,0x14,0x18
  cf:
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    if(*(int *)(unaff_EBP + 0xc)!= 0){
    uVar2 = *(uint *)(unaff_EBP + 0xc);
    pcVar1 = std::basic_string<>::_Myptr(0x1c);
    (*(char **)(unaff_EBP + -0x14),*(int *)(unaff_EBP + -0x18)+ 1,pcVar1,uVar2);
    FUN_10001e70(0x1c);
    *(undefined4 *)(*(int *)(unaff_EBP + -0x1c)+ 4)= *(undefined4 *)(unaff_EBP + -0x14);
    *(undefined4 *)(*(int *)(unaff_EBP + -0x1c)+ 0x18)= *(undefined4 *)(unaff_EBP + -0x18);
    std::basic_string<>::_Eos(0x1c,0xc);
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return;

f FID_conflict__Inside(2):
  c:_Myptr,CONCAT31
  g:CONCAT31
  k:0x0,0x14,0xffffff00
  cf:
    if((param_1 !=(char *)0x0)&&
    pcVar1 = std::basic_string<>::_Myptr();
    in_EAX = pcVar1 + *(int *)((int)this + 0x14);
    if(param_1 < in_EAX){
    return CONCAT31((int3)((uint)in_EAX >> 8),1);
    return(uint)in_EAX & 0xffffff00;

f FUN_10002ce0(1):
  c:FUN_10003130
  g:FUN_10003130
  cf:
    FUN_10003130();
    return;

f max_size(0):
  k:0x71c71c7
  cf:
    return 0x71c71c7;

f max_size(0):
  k:0x3fffffff
  cf:
    return 0x3fffffff;

f FUN_10002d60(2):
  c:FUN_10002df0
  cf:
    FUN_10002df0();
    return this;

f FUN_10002d80(1):
  c:FUN_10004360
  g:FUN_10004360
  cf:
    FUN_10004360();
    return param_1;

f FUN_10002df0(2):
  c:FUN_100011f0,FUN_100082e9,FUN_100011a0
  k:0x10,0x24
  cf:
    bVar2 = FUN_100011f0();
    if(!bVar2){
    FUN_100082e9();
    iVar1 = *(int *)((int)this + 4);
    iVar3 = FUN_100011a0();
    if((*(uint *)(iVar3 + 0x10)<(uint)(param_1 * 0x24 + iVar1))||
    FUN_100082e9();
    *(int *)((int)this + 4)= param_1 * 0x24 + *(int *)((int)this + 4);
    return(int *)this;

f FUN_10002ea0(4):
  c:CONCAT12,FUN_10006800,FUN_10004620,FUN_10003220
  g:CONCAT12,FUN_10006800,FUN_10004620,FUN_10003220
  cf:
    uStack_8 =(uint)param_1;
    uVar1 = _Char_traits_cat<>(&param_4);
    uStack_8._0_3_ = CONCAT12();
    FUN_10006800();
    puVar2 =(undefined4 *)FUN_10004620();
    puVar3 =(undefined4 *)FUN_10004620();
    FUN_10003220();
    return;

f FUN_10002f10(4):
  c:FUN_10003280
  g:FUN_10003280
  cf:
    _Char_traits_cat<>(&param_1);
    FUN_10003280();
    return;

f FUN_10002f90(3):
  cf:
    _Char_traits_cat<>(&param_1);
    _Destroy_range<>(param_1,param_2);
    return;

f do_is(4):
  c:FUN_10003390
  g:FUN_10003390
  cf:
    FUN_10003390();
    return;

f FUN_10003000(3):
  c:FUN_10004620
  g:FUN_10004620
  cf:
    pvVar1 =(void *)FUN_10004620();
    pvVar2 =(void *)FUN_10004620();
    _Destroy_range<>(pvVar2,pvVar1,puVar3);
    return;

f FUN_10003030(4):
  c:CONCAT12,FUN_10006800,FUN_10004620,FUN_10003410
  g:CONCAT12,FUN_10006800,FUN_10004620,FUN_10003410
  cf:
    uStack_8 =(uint)param_1;
    uVar1 = _Char_traits_cat<>(&param_4);
    uStack_8._0_3_ = CONCAT12();
    puVar2 =(undefined1 *)FUN_10006800();
    puVar3 =(undefined4 *)FUN_10004620();
    puVar4 =(undefined4 *)FUN_10004620();
    FUN_10003410();
    return;

f FUN_100030a0(1):
  c:elif,bad_alloc,__CxxThrowException_8,operator_new
  k:0xffffffff,0x24,0x0
  cf:
    if(param_1 == 0){
    elif((uint)(0xffffffff /(ulonglong)param_1)< 0x24){
    std::bad_alloc::bad_alloc(0x0);
    __CxxThrowException_8();
    operator_new(0x24);
    return;

f FUN_100030f0(3):
  c:FUN_10005dd0
  cf:
    _Char_traits_cat<>(&param_1);
    FUN_10005dd0();
    return;

f FUN_10003130(1):
  c:elif,bad_alloc,__CxxThrowException_8,operator_new
  k:0xffffffff,0x0
  cf:
    if(param_1 == 0){
    elif((uint)(0xffffffff /(ulonglong)param_1)< 4){
    std::bad_alloc::bad_alloc(0x0);
    __CxxThrowException_8();
    operator_new();
    return;

f FUN_100031d0(2):
  c:exception
  cf:
    std::exception::exception();
    *(undefined ***)this = std::bad_alloc::vftable;
    return(exception *)this;

f FUN_10003220(3):
  c:FUN_10004620,FUN_100034f0
  g:FUN_10004620
  k:0x24
  cf:
    iVar1 =(((int)param_2 -(int)param_1)/ 0x24)* 0x24 + param_3;
    pvVar2 =(void *)FUN_10004620();
    FUN_100034f0();
    return iVar1;

f FUN_10003280(3):
  c:FUN_100034a0,FUN_1000331c
  cf:
    for(;param_2 != 0;param_2 = param_2 + -1){
    FUN_100034a0();
    FUN_1000331c();
    return;

f Catch_All_100032e5(0):
  c:FUN_100034c0,FUN_100032e7,__CxxThrowException_8
  k:0x14,0x0,0xffffffff,0x10003323
  cf:
    if(*(int *)(unaff_EBP + -0x14)!= *(int *)(unaff_EBP + 8)){
    FUN_100034c0(0x14);
    uVar1 = FUN_100032e7();
    return uVar1;
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    return 0x10003323;

f FUN_100032e7(0):
  c:FUN_100034c0,FUN_100032e7,__CxxThrowException_8
  k:0x14,0x24,0x0,0xffffffff,0x10003323
  cf:
    *(int *)(unaff_EBP + -0x14)= *(int *)(unaff_EBP + -0x14)+ 0x24;
    if(*(int *)(unaff_EBP + -0x14)!= *(int *)(unaff_EBP + 8)){
    FUN_100034c0(0x14);
    uVar1 = FUN_100032e7();
    return uVar1;
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    return 0x10003323;

f FUN_100032f0(0):
  c:FUN_100034c0,FUN_100032e7,__CxxThrowException_8
  k:0x14,0x0,0xffffffff,0x10003323
  cf:
    if(*(int *)(unaff_EBP + -0x14)!= *(int *)(unaff_EBP + 8)){
    FUN_100034c0(0x14);
    uVar1 = FUN_100032e7();
    return uVar1;
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    return 0x10003323;

f FUN_1000331c(0):
  k:0xffffffff,0xc
  cf:
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return;

f FUN_10003390(4):
  c:FUN_10004620,FUN_10003530
  g:FUN_10004620,FUN_10003530
  cf:
    _Char_traits_cat<>(&param_3);
    uVar1 = FUN_10004620();
    uVar2 = FUN_10004620();
    FUN_10003530();
    return;

f FUN_10003410(4):
  c:FUN_10003550
  g:FUN_10003550
  cf:
    _Char_traits_cat<>(&param_3);
    FUN_10003550();
    return;

f FUN_10003460(2):
  c:FUN_10001a10
  cf:
    *(undefined4 *)this = *param_1;
    *(undefined4 *)((int)this + 4)= param_1[1];
    FUN_10001a10();
    return(undefined4 *)this;

f FUN_100034a0(2):
  c:FUN_100035b0
  cf:
    FUN_100035b0();
    return;

f FUN_100034c0(1):
  c:FUN_10003630
  g:FUN_10003630
  cf:
    FUN_10003630();
    return;

f FUN_100034e0(1):
  cf:
    return *param_1;

f FUN_100034f0(3):
  c:FUN_10003460
  g:FUN_10003460
  k:0x24
  cf:
    for(;param_1 != param_2;param_1 = param_1 + 9){
    FUN_10003460();
    param_3 =(void *)((int)param_3 + 0x24);
    return param_3;

f FUN_10003530(4):
  c:FUN_10003670
  g:FUN_10003670
  cf:
    FUN_10003670();
    return;

f FUN_10003550(3):
  c:FUN_10004620,FUN_100036d0
  g:FUN_10004620
  k:0x24
  cf:
    iVar2 = param_3 +(((int)param_2 -(int)param_1)/ 0x24)* -0x24;
    pvVar1 =(void *)FUN_10004620();
    FUN_100036d0();
    return iVar2;

f FUN_100035b0(2):
  c:FUN_10001080,FUN_10001900
  g:FUN_10001080,FUN_10001900
  k:0x24,0x0
  cf:
    this =(void *)FUN_10001080(0x24);
    if(this !=(void *)0x0){
    FUN_10001900();
    return;

f FUN_10003630(1):
  c:FUN_10003640
  g:FUN_10003640
  cf:
    FUN_10003640();
    return;

f FUN_10003640(2):
  c:FUN_100018b0,FUN_10008417
  g:FUN_10008417
  cf:
    FUN_100018b0();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return this;

f FUN_10003670(4):
  c:FUN_10004620,FUN_10003700
  g:FUN_10004620,FUN_10003700
  cf:
    _Char_traits_cat<>(&param_3);
    puVar1 =(undefined4 *)FUN_10004620();
    puVar2 =(undefined4 *)FUN_10004620();
    FUN_10003700();
    return;

f FUN_100036d0(3):
  c:FUN_10003460
  g:FUN_10003460
  k:0x24
  cf:
    while(param_1 != param_2){
    param_3 =(void *)((int)param_3 + -0x24);
    FUN_10003460();
    return param_3;

f FUN_10003700(3):
  c:FUN_100034a0,FUN_1000379e
  cf:
    for(;param_1 != param_2;param_1 = param_1 + 9){
    FUN_100034a0();
    FUN_1000379e();
    return;

f Catch_All_10003767(0):
  c:FUN_100034c0,FUN_10003769,__CxxThrowException_8
  g:FUN_10003769
  k:0x14,0x10,0x0,0xffffffff,0x100037a5
  cf:
    if(*(int *)(unaff_EBP + -0x14)!= *(int *)(unaff_EBP + 0x10)){
    FUN_100034c0(0x14);
    uVar1 = FUN_10003769();
    return uVar1;
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    return 0x100037a5;

f FUN_10003769(0):
  c:FUN_100034c0,FUN_10003769,__CxxThrowException_8
  g:FUN_10003769
  k:0x14,0x24,0x10,0x0,0xffffffff,0x100037a5
  cf:
    *(int *)(unaff_EBP + -0x14)= *(int *)(unaff_EBP + -0x14)+ 0x24;
    if(*(int *)(unaff_EBP + -0x14)!= *(int *)(unaff_EBP + 0x10)){
    FUN_100034c0(0x14);
    uVar1 = FUN_10003769();
    return uVar1;
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    return 0x100037a5;

f FUN_10003772(0):
  c:FUN_100034c0,FUN_10003769,__CxxThrowException_8
  g:FUN_10003769
  k:0x14,0x10,0x0,0xffffffff,0x100037a5
  cf:
    if(*(int *)(unaff_EBP + -0x14)!= *(int *)(unaff_EBP + 0x10)){
    FUN_100034c0(0x14);
    uVar1 = FUN_10003769();
    return uVar1;
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    return 0x100037a5;

f FUN_1000379e(0):
  k:0xffffffff,0xc,0x10
  cf:
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return *(undefined4 *)(unaff_EBP + 0x10);

f previous_character(2):
  c:__mbsicmp
  cf:
    __mbsicmp();
    return;

f FUN_100037e0(1):
  cf:
    return param_1;

f FUN_10003800(1):
  cf:
    return;

f FUN_10003820(1):
  c:CONCAT13,CONCAT12,CONCAT11
  g:CONCAT13,CONCAT12,CONCAT11
  cf:
    return CONCAT13((undefined1)param_1,CONCAT12(param_1._1_1_,CONCAT11(param_1._2_1_,param_1._3_1_)))

f FUN_10003860(1):
  c:CONCAT22,CONCAT11
  g:CONCAT22,CONCAT11
  k:0x10
  cf:
    return CONCAT22((short)((uint)&param_1 >> 0x10),CONCAT11((undefined1)param_1,param_1._1_1_));

f FUN_10003890(2):
  c:FUN_10003800,FUN_10008417
  g:FUN_10003800,FUN_10008417
  cf:
    FUN_10003800();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(undefined4 *)this;

f FUN_100038c0(1):
  k:0x57c
  cf:
    return *(undefined4 *)(param_1 + 0x57c);

f FUN_100038e0(2):
  c:FUN_10016310,FUN_10008417
  g:FUN_10016310,FUN_10008417
  cf:
    FUN_10016310();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(undefined4 *)this;

f FUN_10003910(1):
  c:FUN_10003cc0,FUN_10003b80
  k:0xffffffe0
  cf:
    allocator<>(&stack0xffffffe0);
    FUN_10003cc0();
    FUN_10003b80();
    return param_1;

f FUN_10003980(1):
  c:FUN_10003c00,FUN_10003a70
  cf:
    FUN_10003c00();
    FUN_10003a70();
    return;

f FUN_100039a0(1):
  k:0x10,0xc,0x1c
  cf:
    return(*(int *)(param_1 + 0x10)- *(int *)(param_1 + 0xc))/ 0x1c;

f FUN_100039c0(2):
  c:FUN_100039a0,FUN_100082e9
  k:0x1c,0xc
  cf:
    uVar1 = FUN_100039a0();
    if(uVar1 <= param_1){
    FUN_100082e9();
    return param_1 * 0x1c + *(int *)((int)this + 0xc);

f FUN_100039f0(2):
  c:FUN_100039a0,FUN_10003a90,FUN_10003c80,FUN_10003d30,FUN_10003b00
  k:0x10
  cf:
    uVar1 = FUN_100039a0();
    uVar2 = FUN_10003a90();
    if(uVar1 < uVar2){
    iVar3 = FUN_10003c80(0x10);
    *(int *)((int)this + 0x10)= iVar3;
    else{
    puVar4 =(undefined4 *)FUN_10003d30();
    FUN_10003b00();
    return;

f FUN_10003a70(1):
  c:FUN_10003d00
  cf:
    FUN_10003d00();
    return;

f FUN_10003a90(1):
  k:0xc,0x14,0x1c
  cf:
    if(*(int *)(param_1 + 0xc)== 0){
    else{
    local_c =(*(int *)(param_1 + 0x14)- *(int *)(param_1 + 0xc))/ 0x1c;
    return local_c;

f FUN_10003ad0(2):
  k:0xc
  cf:
    _Vector_iterator<>(param_1,*(uint *)((int)this + 0xc),(undefined4 *)this);
    return param_1;

f FUN_10003b00(5):
  c:FUN_100039a0,FUN_10003ad0,FUN_100042c0,FUN_10003db0,FUN_10004280
  g:FUN_10004280
  cf:
    iVar1 = FUN_100039a0();
    if(iVar1 == 0){
    else{
    piVar2 =(int *)FUN_10003ad0();
    local_20 = FUN_100042c0();
    FUN_10003db0();
    this_00 = FUN_10003ad0();
    FUN_10004280();
    return param_1;

f FUN_10003b80(2):
  c:FUN_10003d60,FID_conflict__Xinvarg,FUN_10004260,CONCAT31
  g:FUN_10004260,CONCAT31
  k:0xc,0x10,0x14,0xffffff00,0x1c
  cf:
    *(undefined4 *)((int)this + 0xc)= 0;
    *(undefined4 *)((int)this + 0x10)= 0;
    *(undefined4 *)((int)this + 0x14)= 0;
    if(param_1 == 0){
    uVar1 =(uint)this & 0xffffff00;
    else{
    uVar1 = FUN_10003d60();
    if(uVar1 < param_1){
    this =(void *)FID_conflict__Xinvarg();
    else{
    uVar2 = FUN_10004260();
    *(undefined4 *)((int)this + 0xc)= uVar2;
    *(undefined4 *)((int)this + 0x10)= *(undefined4 *)((int)this + 0xc);
    *(uint *)((int)this + 0x14)= param_1 * 0x1c + *(int *)((int)this + 0xc);
    uVar1 = CONCAT31();
    return uVar1;

f FUN_10003c00(1):
  c:FUN_10003d80,FUN_10004e70
  k:0xc,0x10,0x14
  cf:
    if(*(int *)((int)param_1 + 0xc)!= 0){
    FUN_10003d80(0xc,0x10);
    FUN_10004e70(0xc);
    *(undefined4 *)((int)param_1 + 0xc)= 0;
    *(undefined4 *)((int)param_1 + 0x10)= 0;
    *(undefined4 *)((int)param_1 + 0x14)= 0;
    return;

f FUN_10003c80(4):
  c:FUN_10004400
  g:FUN_10004400
  k:0x1c
  cf:
    FUN_10004400();
    return param_2 * 0x1c + param_1;

f FUN_10003cc0(1):
  c:FUN_100041b0
  k:0xfffffff0,0x00000004
  cf:
    ((allocator<char> *)&stack0xfffffff0,(allocator<char> *)&stack0x00000004);
    FUN_100041b0();
    ((allocator<char> *)(param_1 + 2),(allocator<char> *)&stack0x00000004);
    return param_1;

f FUN_10003d00(1):
  c:FUN_10004e70,FUN_10001150
  g:FUN_10001150
  cf:
    FUN_10004e70();
    FUN_10001150();
    return;

f FUN_10003d30(2):
  k:0x10
  cf:
    _Vector_iterator<>(param_1,*(uint *)((int)this + 0x10),(undefined4 *)this);
    return param_1;

f FUN_10003d60(0):
  c:max_size
  cf:
    max_size();
    return;

f FUN_10003d80(3):
  c:FUN_10004450
  g:FUN_10004450
  cf:
    FUN_10004450();
    return;

f FUN_10003db0(5):
  c:FUN_10003a90,FUN_100039a0,FUN_10003d60,FID_conflict__Xinvarg,FUN_10004260,FUN_10003c80,do_is,FUN_10003f85,FUN_100019b0,CONCAT31,FUN_100040bb,FUN_100044f0,FUN_100044c0,__security_check_cookie
  g:DAT_10020030,FUN_10004260,CONCAT31
  k:0xfffffffc,0xc,0x1c,0x10
  cf:
    uStack_7c = DAT_10020030 ^(uint)&stack0xfffffffc;
    local_14 =(undefined1 *)&uStack_7c;
    local_18 = FUN_10003a90();
    if(param_3 != 0){
    iVar1 = FUN_100039a0();
    iVar2 = FUN_10003d60();
    if((uint)(iVar2 - iVar1)< param_3){
    FID_conflict__Xinvarg();
    else{
    iVar1 = FUN_100039a0();
    if(local_18 < iVar1 + param_3){
    iVar1 = FUN_10003d60();
    if(iVar1 - uVar4 < local_18){
    else{
    local_6c =(local_18 >> 1)+ local_18;
    iVar1 = FUN_100039a0();
    if(local_18 < iVar1 + param_3){
    iVar1 = FUN_100039a0();
    local_20 =(void *)FUN_10004260();
    local_1c =(param_2 - *(int *)((int)this + 0xc))/ 0x1c;
    FUN_10003c80(0x1c);
    do_is(this,*(undefined4 *)((int)this + 0xc),param_2,local_20);
    do_is(this,param_2,*(undefined4 *)((int)this + 0x10),
    (void *)((local_1c + param_3)* 0x1c +(int)local_20));
    FUN_10003f85();
    return;
    if((uint)((*(int *)((int)this + 0x10)- param_2)/ 0x1c)< param_3){
    FUN_100019b0();
    do_is(this,param_2,*(undefined4 *)((int)this + 0x10),(void *)(param_3 * 0x1c + param_2));
    local_8 = CONCAT31();
    param_3 -(*(int *)((int)this + 0x10)- param_2)/ 0x1c,local_44);
    FUN_100040bb();
    return;
    FUN_100019b0();
    local_48 = *(int *)((int)this + 0x10);
    uVar3 = do_is(0x1c,0x10);
    *(undefined4 *)((int)this + 0x10)= uVar3;
    FUN_100044f0();
    FUN_100044c0(0x1c);
    std::basic_string<>::~basic_string<>(local_64);
    __security_check_cookie(0xfffffffc);
    return;

f Catch_All_10003f16(0):
  c:FUN_10004e70,__CxxThrowException_8
  k:0x20,0x18,0x1c,0x10,0x0,0xffffffff,0x10003f8c
  cf:
    if(1 < *(int *)(unaff_EBP + -0x20)){
    (void *)(*(int *)(unaff_EBP + -0x18)* 0x1c + *(int *)(unaff_EBP + -0x1c)));
    if(0 < *(int *)(unaff_EBP + -0x20)){
    *(int *)(unaff_EBP + 0x10)* 0x1c));
    FUN_10004e70(0x1c);
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    return 0x10003f8c;

f FUN_10003f85(0):
  c:FUN_100039a0,FUN_10004e70,__security_check_cookie
  k:0xffffffff,0x10,0xc,0x14,0x1c,0x24,100
  cf:
    *(undefined4 *)(unaff_EBP - 4)= 0xffffffff;
    iVar1 = FUN_100039a0(100);
    *(int *)(unaff_EBP + 0x10)= iVar1 + *(int *)(unaff_EBP + 0x10);
    if(*(int *)(*(int *)(unaff_EBP - 100)+ 0xc)!= 0){
    *(void **)(*(int *)(unaff_EBP - 100)+ 0x10));
    FUN_10004e70(0xc);
    *(int *)(unaff_EBP - 0x14)* 0x1c + *(int *)(unaff_EBP - 0x1c);
    *(int *)(unaff_EBP + 0x10)* 0x1c + *(int *)(unaff_EBP - 0x1c);
    *(undefined4 *)(*(int *)(unaff_EBP - 100)+ 0xc)= *(undefined4 *)(unaff_EBP - 0x1c);
    ExceptionList = *(void **)(unaff_EBP - 0xc);
    __security_check_cookie(0x24);
    return;

f Catch_All_10004086(0):
  c:__CxxThrowException_8
  k:0x10,0x0,0x100040c2,100
  cf:
    *(int *)(*(int *)(unaff_EBP + -100)+ 0x10)));
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 2;
    return 0x100040c2;

f FUN_100040bb(0):
  c:__security_check_cookie
  k:0x10,0x1c,0x40,0xffffffff,0xc,0x24,100
  cf:
    *(undefined4 *)(unaff_EBP - 4)= 2;
    *(int *)(unaff_EBP + 0x10)* 0x1c + *(int *)(*(int *)(unaff_EBP - 100)+ 0x10);
    (basic_string<> *)(unaff_EBP - 0x40));
    *(undefined4 *)(unaff_EBP - 4)= 0xffffffff;
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP - 0x40));
    ExceptionList = *(void **)(unaff_EBP - 0xc);
    __security_check_cookie(0x24);
    return;

f FUN_100041b0(1):
  c:FUN_10002ce0,FUN_10001080,FUN_10001120
  g:FUN_10001080,FUN_10001120
  k:0x00000004,0x0
  cf:
    allocator<>(param_1);
    ((allocator<char> *)(param_1 + 1),(allocator<char> *)&stack0x00000004);
    uVar1 = FUN_10002ce0();
    this =(void *)FUN_10001080();
    if(this ==(void *)0x0){
    local_24 =(undefined4 *)0x0;
    else{
    local_24 = FUN_10001120();
    return param_1;

f FUN_10004260(1):
  c:FUN_10004560
  g:FUN_10004560
  cf:
    FUN_10004560();
    return;

f FUN_10004280(3):
  c:FUN_10004340
  g:FUN_10004340
  cf:
    local_8 = *(undefined4 *)((int)this + 4);
    puVar2 =(undefined4 *)FUN_10004340();
    return param_1;

f FUN_100042c0(2):
  c:FUN_100011f0,FUN_100011d0,FUN_100082e9
  k:0x1c
  cf:
    bVar1 = FUN_100011f0();
    if((!bVar1)||(bVar1 = FUN_100011d0(this,param_1),!bVar1)){
    FUN_100082e9();
    return(*(int *)((int)this + 4)- param_1[1])/ 0x1c;

f max_size(0):
  k:0x9249249
  cf:
    return 0x9249249;

f FUN_10004340(2):
  c:FUN_10004380
  g:FUN_10004380
  cf:
    FUN_10004380();
    return this;

f FUN_10004360(1):
  c:FUN_10001160
  g:FUN_10001160
  cf:
    FUN_10001160();
    return param_1;

f FUN_10004380(2):
  c:FUN_100011f0,FUN_100082e9,FUN_100011a0
  k:0x10,0x1c
  cf:
    bVar2 = FUN_100011f0();
    if(!bVar2){
    FUN_100082e9();
    iVar1 = *(int *)((int)this + 4);
    iVar3 = FUN_100011a0();
    if((*(uint *)(iVar3 + 0x10)<(uint)(param_1 * 0x1c + iVar1))||
    FUN_100082e9();
    *(int *)((int)this + 4)= param_1 * 0x1c + *(int *)((int)this + 4);
    return(int *)this;

f FUN_10004400(4):
  c:FUN_10004640
  g:FUN_10004640
  cf:
    _Char_traits_cat<>(&param_1);
    FUN_10004640();
    return;

f FUN_10004450(3):
  cf:
    _Char_traits_cat<>(&param_1);
    _Destroy_range<>(param_1,param_2);
    return;

f do_is(4):
  c:FUN_10004730
  g:FUN_10004730
  cf:
    FUN_10004730();
    return;

f FUN_100044c0(3):
  c:FUN_10004620
  g:FUN_10004620
  cf:
    pvVar1 =(void *)FUN_10004620();
    pvVar2 =(void *)FUN_10004620();
    _Destroy_range<>(pvVar2,pvVar1,pbVar3);
    return;

f FUN_100044f0(4):
  c:CONCAT12,FUN_10006800,FUN_10004620,FUN_100047b0
  g:CONCAT12,FUN_10006800,FUN_10004620
  cf:
    uStack_8 =(uint)param_1;
    uVar1 = _Char_traits_cat<>(&param_4);
    uStack_8._0_3_ = CONCAT12();
    pbVar2 =(byte *)FUN_10006800();
    uVar5 =(uint)*pbVar2;
    pbVar3 =(basic_string<> *)FUN_10004620();
    pbVar4 =(basic_string<> *)FUN_10004620();
    FUN_100047b0();
    return;

f FUN_10004560(1):
  c:elif,bad_alloc,__CxxThrowException_8,operator_new
  k:0xffffffff,0x1c,0x0
  cf:
    if(param_1 == 0){
    elif((uint)(0xffffffff /(ulonglong)param_1)< 0x1c){
    std::bad_alloc::bad_alloc(0x0);
    __CxxThrowException_8();
    operator_new(0x1c);
    return;

f FUN_100045b0(4):
  c:CONCAT12,FUN_10006800,FUN_10004620,FUN_10005130
  g:CONCAT12,FUN_10006800,FUN_10004620,FUN_10005130
  cf:
    uStack_8 =(uint)param_1;
    uVar1 = _Char_traits_cat<>(&param_4);
    uStack_8._0_3_ = CONCAT12();
    puVar2 =(undefined1 *)FUN_10006800();
    iVar3 = FUN_10004620();
    pvVar4 =(void *)FUN_10004620();
    FUN_10005130();
    return;

f FUN_10004620(1):
  c:FUN_100034e0
  cf:
    FUN_100034e0();
    return;

f FUN_10004640(3):
  c:FUN_10004840,FUN_100046dc
  g:FUN_10004840
  cf:
    for(;param_2 != 0;param_2 = param_2 + -1){
    FUN_10004840();
    FUN_100046dc();
    return;

f Catch_All_100046a5(0):
  c:FUN_10004860,FUN_100046a7,__CxxThrowException_8
  g:FUN_10004860
  k:0x14,0x0,0xffffffff,0x100046e3
  cf:
    if(*(int *)(unaff_EBP + -0x14)!= *(int *)(unaff_EBP + 8)){
    FUN_10004860(0x14);
    uVar1 = FUN_100046a7();
    return uVar1;
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    return 0x100046e3;

f FUN_100046a7(0):
  c:FUN_10004860,FUN_100046a7,__CxxThrowException_8
  g:FUN_10004860
  k:0x14,0x1c,0x0,0xffffffff,0x100046e3
  cf:
    *(int *)(unaff_EBP + -0x14)= *(int *)(unaff_EBP + -0x14)+ 0x1c;
    if(*(int *)(unaff_EBP + -0x14)!= *(int *)(unaff_EBP + 8)){
    FUN_10004860(0x14);
    uVar1 = FUN_100046a7();
    return uVar1;
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    return 0x100046e3;

f FUN_100046b0(0):
  c:FUN_10004860,FUN_100046a7,__CxxThrowException_8
  g:FUN_10004860
  k:0x14,0x0,0xffffffff,0x100046e3
  cf:
    if(*(int *)(unaff_EBP + -0x14)!= *(int *)(unaff_EBP + 8)){
    FUN_10004860(0x14);
    uVar1 = FUN_100046a7();
    return uVar1;
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    return 0x100046e3;

f FUN_100046dc(0):
  k:0xffffffff,0xc
  cf:
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return;

f FUN_10004730(4):
  c:FUN_10004620,FUN_10004880
  g:FUN_10004620,FUN_10004880
  cf:
    _Char_traits_cat<>(&param_3);
    pbVar1 =(basic_string<> *)FUN_10004620();
    pbVar2 =(basic_string<> *)FUN_10004620();
    FUN_10004880();
    return;

f FUN_100047b0(5):
  c:FUN_10004620,FUN_10004980
  g:FUN_10004620,FUN_10004980
  k:0x1c
  cf:
    iVar2 = param_3 +(((int)param_2 -(int)param_1)/ 0x1c)* -0x1c;
    pvVar1 =(void *)FUN_10004620();
    FUN_10004980();
    return iVar2;

f FUN_10004810(3):
  cf:
    for(;param_1 != param_2;param_1 = param_1 + 1){
    return;

f FUN_10004840(2):
  c:FUN_100049c0
  cf:
    FUN_100049c0();
    return;

f FUN_10004860(1):
  c:FUN_10004a40
  cf:
    FUN_10004a40();
    return;

f FUN_10004880(3):
  c:FUN_10004840,FUN_1000493f
  g:DAT_10020030,FUN_10004840
  k:0xfffffffc,0x1c
  cf:
    uStack_4c = DAT_10020030 ^(uint)&stack0xfffffffc;
    local_14 =(undefined1 *)&uStack_4c;
    std::basic_string<>::basic_string<>(local_38);
    for(;param_1 != param_2;param_1 = param_1 + 0x1c){
    FUN_10004840();
    iter_swap<>(param_3,param_1);
    param_3 =(void *)((int)param_3 + 0x1c);
    FUN_1000493f();
    return;

f Catch_All_10004908(0):
  c:FUN_10004860,FUN_1000490a,__CxxThrowException_8
  g:FUN_10004860
  k:0x14,0x10,0x0,0x10004946
  cf:
    if(*(int *)(unaff_EBP + -0x14)!= *(int *)(unaff_EBP + 0x10)){
    FUN_10004860(0x14);
    uVar1 = FUN_1000490a();
    return uVar1;
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0;
    return 0x10004946;

f FUN_1000490a(0):
  c:FUN_10004860,FUN_1000490a,__CxxThrowException_8
  g:FUN_10004860
  k:0x14,0x1c,0x10,0x0,0x10004946
  cf:
    *(int *)(unaff_EBP + -0x14)= *(int *)(unaff_EBP + -0x14)+ 0x1c;
    if(*(int *)(unaff_EBP + -0x14)!= *(int *)(unaff_EBP + 0x10)){
    FUN_10004860(0x14);
    uVar1 = FUN_1000490a();
    return uVar1;
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0;
    return 0x10004946;

f FUN_10004913(0):
  c:FUN_10004860,FUN_1000490a,__CxxThrowException_8
  g:FUN_10004860
  k:0x14,0x10,0x0,0x10004946
  cf:
    if(*(int *)(unaff_EBP + -0x14)!= *(int *)(unaff_EBP + 0x10)){
    FUN_10004860(0x14);
    uVar1 = FUN_1000490a();
    return uVar1;
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0;
    return 0x10004946;

f FUN_1000493f(0):
  c:__security_check_cookie
  k:0x38,0x10,0xffffffff,0x34,0xc,0x18
  cf:
    *(undefined4 *)(unaff_EBP - 4)= 0;
    *(undefined4 *)(unaff_EBP - 0x38)= *(undefined4 *)(unaff_EBP + 0x10);
    *(undefined4 *)(unaff_EBP - 4)= 0xffffffff;
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP - 0x34));
    ExceptionList = *(void **)(unaff_EBP - 0xc);
    __security_check_cookie(0x18);
    return;

f FUN_10004980(3):
  k:0x1c
  cf:
    while(param_1 != param_2){
    param_3 =(void *)((int)param_3 + -0x1c);
    iter_swap<>(param_3,param_2);
    return param_3;

f FUN_100049c0(2):
  c:FUN_10001080,FUN_100019b0
  g:FUN_10001080
  k:0x1c,0x0
  cf:
    this =(void *)FUN_10001080(0x1c);
    if(this !=(void *)0x0){
    FUN_100019b0();
    return;

f FUN_10004a40(1):
  c:FUN_10004a50
  cf:
    FUN_10004a50();
    return;

f FUN_10004a50(2):
  c:FUN_10008417
  g:FUN_10008417
  cf:
    std::basic_string<>::~basic_string<>((basic_string<> *)this);
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(basic_string<> *)this;

f FUN_10004ac0(2):
  c:FUN_10004c10,FUN_100019b0,FUN_10001a10,__security_check_cookie
  g:DAT_10020030
  k:0xfffffffc,0xc,0x10,0x14,0x18
  cf:
    local_18 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if((basic_string<> *)this != param_1){
    cVar1 = FUN_10004c10();
    if(cVar1 == '\0'){
    FUN_100019b0();
    FUN_10001a10();
    std::basic_string<>::~basic_string<>(local_48);
    else{
    local_28 = *(undefined4 *)((int)this + 4);
    local_24 = *(undefined4 *)((int)this + 8);
    local_20 = *(undefined4 *)((int)this + 0xc);
    local_1c = *(undefined4 *)((int)this + 0x10);
    *(undefined4 *)((int)this + 4)= *(undefined4 *)(param_1 + 4);
    *(undefined4 *)((int)this + 8)= *(undefined4 *)(param_1 + 8);
    *(undefined4 *)((int)this + 0xc)= *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)((int)this + 0x10)= *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 4)= local_28;
    *(undefined4 *)(param_1 + 8)= local_24;
    *(undefined4 *)(param_1 + 0xc)= local_20;
    *(undefined4 *)(param_1 + 0x10)= local_1c;
    local_14 = *(undefined4 *)((int)this + 0x14);
    *(undefined4 *)((int)this + 0x14)= *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x14)= local_14;
    local_2c = *(undefined4 *)((int)this + 0x18);
    *(undefined4 *)((int)this + 0x18)= *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x18)= local_2c;
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10004c10(0):
  cf:
    return 1;

f FUN_10004c20(1):
  k:0x458
  cf:
    return *(undefined4 *)(param_1 + 0x458);

f FUN_10004c40(2):
  c:FUN_10015a40,FUN_10008417
  g:FUN_10008417
  cf:
    FUN_10015a40();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(undefined4 *)this;

f FUN_10004c70(1):
  k:0x178
  cf:
    return *(undefined4 *)(param_1 + 0x178);

f FUN_10004c90(2):
  c:FUN_10014440,FUN_10008417
  g:FUN_10014440,FUN_10008417
  cf:
    FUN_10014440();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(undefined4 *)this;

f FUN_10004ce0(1):
  k:0x10,0xc
  cf:
    return *(int *)(param_1 + 0x10)- *(int *)(param_1 + 0xc)>> 2;

f FUN_10004d30(4):
  c:FUN_10004fe0
  cf:
    FUN_10004fe0();
    return param_1 + param_2 * 4;

f FUN_10004e50(4):
  cf:
    _Vector_iterator<>(param_1,param_3,(undefined4 *)this);
    return param_1;

f FUN_10004e70(1):
  c:FUN_10008417
  g:FUN_10008417
  cf:
    FUN_10008417();
    return;

f FUN_10004e90(2):
  c:FUN_10004f90
  k:0xff
  cf:
    uVar1 = FUN_10004f90();
    return(bool)('\x01' -((uVar1 & 0xff)!= 0));

f FUN_10004f90(2):
  c:FUN_100011f0,FUN_100011d0,FUN_100082e9,CONCAT31
  g:CONCAT31
  cf:
    bVar1 = FUN_100011f0();
    if((!bVar1)||(bVar1 = FUN_100011d0(this,param_1),!bVar1)){
    FUN_100082e9();
    return CONCAT31((int3)((uint)*(int *)((int)this + 4)>> 8),*(int *)((int)this + 4)== param_1[1]);

f FUN_10004fe0(4):
  c:FUN_10005db0
  cf:
    _Char_traits_cat<>(&param_1);
    FUN_10005db0();
    return;

f do_is(4):
  c:FUN_100050e0
  cf:
    FUN_100050e0();
    return;

f FUN_10005060(3):
  c:FUN_10004620,FUN_10004810
  g:FUN_10004620,FUN_10004810
  cf:
    puVar1 =(undefined4 *)FUN_10004620();
    puVar2 =(undefined4 *)FUN_10004620();
    FUN_10004810();
    return;

f FUN_10005090(3):
  c:_memmove_s
  cf:
    iVar1 = param_2 -(int)param_1 >> 2;
    if(0 < iVar1){
    _memmove_s();
    return(void *)((int)param_3 + iVar1 * 4);

f FUN_100050e0(4):
  c:FUN_10004620,FUN_10005180
  g:FUN_10004620,FUN_10005180
  cf:
    _Char_traits_cat<>(&param_3);
    uVar1 = FUN_10004620();
    uVar2 = FUN_10004620();
    FUN_10005180();
    return;

f FUN_10005130(4):
  c:FUN_100067b0
  cf:
    _Char_traits_cat<>(&param_3);
    FUN_100067b0();
    return;

f FUN_10005180(4):
  c:FUN_10005cc0
  cf:
    FUN_10005cc0();
    return;

f FUN_100051a0(5):
  c:operator_new,FUN_10005230
  g:FUN_10005230
  k:0x1c,0x0
  cf:
    this = operator_new(0x1c);
    if(this ==(void *)0x0){
    local_10 =(undefined4 *)0x0;
    else{
    local_10 = FUN_10005230();
    return local_10;

f PostNcDestroy(1):
  k:0x0
  cf:
    if(param_1 !=(int *)0x0){
    (**(code **)(*param_1 + 4))(1);
    return;

f FUN_10005230(6):
  k:0xc,0x10,0x14
  cf:
    *(undefined ***)this = DMsg::vftable;
    *(uint *)((int)this + 4)=(uint)param_1;
    *(undefined4 *)((int)this + 8)= param_2;
    *(undefined4 *)((int)this + 0xc)= param_3;
    *(undefined4 *)((int)this + 0x10)= param_4;
    *(undefined4 *)((int)this + 0x14)= param_5;
    return(undefined4 *)this;

f FUN_10005280(1):
  cf:
    return;

f FUN_100052a0(2):
  c:FUN_10005280,FUN_10008417
  g:FUN_10005280,FUN_10008417
  cf:
    FUN_10005280();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(undefined4 *)this;

f FUN_100052d0(2):
  c:FUN_10012bf0,FUN_10008417
  g:FUN_10008417
  cf:
    FUN_10012bf0();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(undefined4 *)this;

f FUN_10005300(2):
  c:DQueue,FUN_10008417
  g:FUN_10008417
  cf:
    DQueue::~DQueue();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(DQueue *)this;

f FUN_10005330(0):
  c:FUN_100059c0
  cf:
    allocator<>(auStack_10);
    FUN_100059c0();
    return local_c;

f FUN_10005380(1):
  c:FUN_10005900,FUN_10005680
  g:FUN_10005900,FUN_10005680
  cf:
    FUN_10005900();
    FUN_10005680();
    return;

f FUN_100053a0(1):
  k:0x1c
  cf:
    return *(int *)(param_1 + 0x1c)== 0;

f FUN_100053c0(1):
  c:FUN_100056a0,FUN_10005a40
  cf:
    piVar1 =(int *)FUN_100056a0();
    FUN_10005a40();
    return;

f FUN_100053e0(2):
  c:FUN_100056d0,FUN_10002ce0,FUN_10005a00
  k:0x18,0x14,0x10,0x1c
  cf:
    if((*(uint *)((int)this + 0x18)% 4 == 0)&&
    FUN_100056d0();
    if(*(int *)((int)this + 0x18)== 0){
    local_14 = *(int *)((int)this + 0x14)<< 2;
    else{
    local_14 = *(int *)((int)this + 0x18);
    if(*(int *)(*(int *)((int)this + 0x10)+ uVar1 * 4)== 0){
    uVar2 = FUN_10002ce0();
    *(undefined4 *)(*(int *)((int)this + 0x10)+ uVar1 * 4)= uVar2;
    FUN_10005a00(0x10);
    *(uint *)((int)this + 0x18)= uVar3;
    *(int *)((int)this + 0x1c)= *(int *)((int)this + 0x1c)+ 1;
    return;

f FUN_100054d0(1):
  c:FUN_100053a0
  k:0x18,0x14,0x1c
  cf:
    bVar1 = FUN_100053a0();
    if(!bVar1){
    (*(uint *)(param_1 + 0x18)% 4)* 4));
    *(int *)(param_1 + 0x18)= *(int *)(param_1 + 0x18)+ 1;
    if((uint)(*(int *)(param_1 + 0x14)<< 2)<= *(uint *)(param_1 + 0x18)){
    *(undefined4 *)(param_1 + 0x18)= 0;
    *(int *)(param_1 + 0x1c)= *(int *)(param_1 + 0x1c)+ -1;
    if(*(int *)(param_1 + 0x1c)== 0){
    *(undefined4 *)(param_1 + 0x18)= 0;
    return;

f FUN_10005580(2):
  c:FUN_100056d0,FUN_10002ce0,FUN_10005a00
  k:0x18,0x1c,0x14,0x10
  cf:
    if(((uint)(*(int *)((int)this + 0x18)+ *(int *)((int)this + 0x1c))% 4 == 0)&&
    FUN_100056d0();
    uVar1 = *(int *)((int)this + 0x18)+ *(int *)((int)this + 0x1c);
    if(*(uint *)((int)this + 0x14)<= local_c){
    local_c = local_c - *(int *)((int)this + 0x14);
    if(*(int *)(*(int *)((int)this + 0x10)+ local_c * 4)== 0){
    uVar2 = FUN_10002ce0();
    *(undefined4 *)(*(int *)((int)this + 0x10)+ local_c * 4)= uVar2;
    FUN_10005a00(0x10);
    *(int *)((int)this + 0x1c)= *(int *)((int)this + 0x1c)+ 1;
    return;

f FUN_10005660(1):
  c:FUN_10005900
  g:FUN_10005900
  cf:
    FUN_10005900();
    return;

f FUN_10005680(1):
  c:FUN_10003a70
  cf:
    FUN_10003a70();
    return;

f FUN_100056a0(2):
  k:0x18
  cf:
    _Vector_iterator<>(param_1,*(uint *)((int)this + 0x18),(undefined4 *)this);
    return param_1;

f FUN_100056d0(2):
  c:FUN_10005a60,FID_conflict__Xinvarg,FUN_10002ce0,FUN_10004fe0,FUN_10004e70
  k:0x14,0x18,0x10
  cf:
    uVar1 = FUN_10005a60();
    if((uVar1 >> 2)- *(int *)((int)this + 0x14)< param_1){
    FID_conflict__Xinvarg();
    local_c = *(uint *)((int)this + 0x14)>> 1;
    if(local_c < 8){
    if(param_1 < local_c){
    uVar1 = FUN_10005a60();
    if(*(uint *)((int)this + 0x14)<=(uVar1 >> 2)- local_c){
    local_8 = *(uint *)((int)this + 0x18)>> 2;
    local_14 =(void *)FUN_10002ce0(0x14);
    local_10 =(void *)((int)local_14 + local_8 * 4);
    local_10,(int)this + 8);
    if(param_1 < local_8){
    ,(int)this + 8);
    FUN_10004fe0();
    else{
    FUN_10004fe0();
    *(int *)((int)this + 0x10)+ *(int *)((int)this + 0x14)* 4,(int)this + 8);
    if(*(int *)((int)this + 0x10)!= 0){
    FUN_10004e70(0x10);
    *(void **)((int)this + 0x10)= local_14;
    *(uint *)((int)this + 0x14)= *(int *)((int)this + 0x14)+ param_1;
    return;

f FUN_10005900(1):
  c:FUN_100053a0,FUN_10005a80,FUN_10004e70
  k:0x14,0x10
  cf:
    while(true){
    bVar1 = FUN_100053a0();
    if(bVar1)break;
    FUN_10005a80();
    local_8 = *(int *)(param_1 + 0x14);
    while(local_8 != 0){
    if(*(int *)(*(int *)(param_1 + 0x10)+ local_8 * 4)!= 0){
    FUN_10004e70(0x10);
    (_Container_proxy *)(*(int *)(param_1 + 0x10)+ local_8 * 4));
    if(*(int *)(param_1 + 0x10)!= 0){
    FUN_10004e70(0x10);
    *(undefined4 *)(param_1 + 0x14)= 0;
    *(undefined4 *)(param_1 + 0x10)= 0;
    return;

f FUN_100059c0(1):
  c:FUN_10003cc0
  k:0xfffffff0,0x00000004
  cf:
    ((allocator<char> *)&stack0xfffffff0,(allocator<char> *)&stack0x00000004);
    FUN_10003cc0();
    ((allocator<char> *)(param_1 + 3),(allocator<char> *)&stack0x00000004);
    return param_1;

f FUN_10005a00(2):
  c:FUN_10005d20
  cf:
    FUN_10005d20();
    return;

f FUN_10005a40(1):
  c:FUN_10005bc0
  cf:
    FUN_10005bc0();
    return;

f FUN_10005a60(0):
  c:max_size
  cf:
    max_size();
    return;

f FUN_10005a80(1):
  c:FUN_100053a0
  k:0x1c,0x18,0x14,0x10
  cf:
    bVar2 = FUN_100053a0();
    if(!bVar2){
    uVar1 = *(int *)(param_1 + 0x1c)+ -1 + *(int *)(param_1 + 0x18);
    if(*(uint *)(param_1 + 0x14)<= local_c){
    local_c = local_c - *(int *)(param_1 + 0x14);
    (*(int *)(*(int *)(param_1 + 0x10)+ local_c * 4)+(uVar1 % 4)* 4));
    *(int *)(param_1 + 0x1c)= *(int *)(param_1 + 0x1c)+ -1;
    if(*(int *)(param_1 + 0x1c)== 0){
    *(undefined4 *)(param_1 + 0x18)= 0;
    return;

f FID_conflict__Xinvarg(0):
  c:FID_conflict_length_error,__CxxThrowException_8
  cf:
    basic_string<>(local_54,S3);
    FID_conflict_length_error();
    __CxxThrowException_8();
    std::basic_string<>::~basic_string<>((basic_string<> *)local_54);
    return;

f FUN_10005bc0(1):
  c:FUN_100011f0,FUN_100082e9,FUN_100011a0
  k:0x18,0x1c,0x14,0x10
  cf:
    local_8 =(uint)param_1[1] >> 2;
    bVar2 = FUN_100011f0();
    if(!bVar2){
    FUN_100082e9();
    iVar3 = FUN_100011a0();
    iVar4 = FUN_100011a0();
    if((uint)(*(int *)(iVar3 + 0x18)+ *(int *)(iVar4 + 0x1c))<=(uint)param_1[1]){
    FUN_100082e9();
    iVar3 = FUN_100011a0();
    if(*(uint *)(iVar3 + 0x14)<= local_8){
    iVar3 = FUN_100011a0();
    local_8 = local_8 - *(int *)(iVar3 + 0x14);
    iVar3 = FUN_100011a0();
    return *(int *)(*(int *)(iVar3 + 0x10)+ local_8 * 4)+(uVar1 & 3)* 4;

f FUN_10005c60(3):
  c:FUN_10002d80,FUN_100082e9,FUN_10001180
  g:FUN_10001180
  k:0x0
  cf:
    FUN_10002d80();
    if(((param_2 ==(undefined4 *)0x0)||(param_1 <(uint)param_2[6]))||
    FUN_100082e9();
    FUN_10001180();
    *(uint *)((int)this + 4)= param_1;
    return(undefined4 *)this;

f FUN_10005cc0(4):
  c:FUN_10004620,FUN_10005d60
  g:FUN_10004620
  cf:
    _Char_traits_cat<>(&param_3);
    iVar1 = FUN_10004620();
    pvVar2 =(void *)FUN_10004620();
    FUN_10005d60();
    return;

f FUN_10005d20(2):
  c:FUN_10001080
  g:FUN_10001080
  k:0x0
  cf:
    puVar1 =(undefined4 *)FUN_10001080();
    if(puVar1 !=(undefined4 *)0x0){
    return;

f FUN_10005d60(3):
  c:_memmove_s
  cf:
    iVar1 = param_2 -(int)param_1 >> 2;
    if(iVar1 != 0){
    _memmove_s();
    return(void *)((int)param_3 + iVar1 * 4);

f FUN_10005db0(3):
  c:FUN_10005de0
  cf:
    FUN_10005de0();
    return;

f FUN_10005dd0(0):
  cf:
    return;

f FUN_10005de0(4):
  c:FUN_10006800,FUN_10005e20
  g:FUN_10006800
  cf:
    uStack_8 =(uint)param_1;
    FUN_10006800();
    FUN_10005e20();
    return;

f FUN_10005e20(3):
  c:FUN_10004620,FUN_10005e60
  g:FUN_10004620
  cf:
    puVar1 =(undefined4 *)FUN_10004620();
    FUN_10005e60();
    return;

f FUN_10005e60(3):
  cf:
    for(;param_2 != 0;param_2 = param_2 + -1){
    return;

f FUN_10005e90(2):
  c:FUN_10012770,FUN_10008417
  g:FUN_10012770,FUN_10008417
  cf:
    FUN_10012770();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(basic_string<> *)this;

f FUN_10005ec0(1):
  c:FUN_10003cc0,FUN_100021d0
  k:0xffffffe0
  cf:
    allocator<>(&stack0xffffffe0);
    FUN_10003cc0();
    FUN_100021d0();
    return param_1;

f FUN_10005f30(2):
  c:FUN_10004ce0,FUN_100082e9
  k:0xc
  cf:
    uVar1 = FUN_10004ce0();
    if(uVar1 <= param_1){
    FUN_100082e9();
    return *(int *)((int)this + 0xc)+ param_1 * 4;

f FUN_10005f60(2):
  c:FUN_10004ce0,FUN_10006040,FUN_10004d30,FUN_10003d30,FUN_10006080
  g:FUN_10006040,FUN_10006080
  k:0x10
  cf:
    uVar1 = FUN_10004ce0();
    uVar2 = FUN_10006040();
    if(uVar1 < uVar2){
    iVar3 = FUN_10004d30(0x10);
    *(int *)((int)this + 0x10)= iVar3;
    else{
    puVar4 =(undefined4 *)FUN_10003d30();
    FUN_10006080();
    return;

f FUN_10005fe0(1):
  c:FUN_10003d30,FUN_10003ad0,FUN_10006100
  g:FUN_10006100
  cf:
    puVar1 =(undefined4 *)FUN_10003d30();
    puVar1 =(undefined4 *)FUN_10003ad0();
    FUN_10006100();
    return;

f FUN_10006040(1):
  k:0xc,0x14
  cf:
    if(*(int *)(param_1 + 0xc)== 0){
    else{
    local_c = *(int *)(param_1 + 0x14)- *(int *)(param_1 + 0xc)>> 2;
    return local_c;

f FUN_10006080(5):
  c:FUN_10004ce0,FUN_10003ad0,FUN_100065d0,FUN_100061c0,FUN_10006590
  g:FUN_10006590
  cf:
    iVar1 = FUN_10004ce0();
    if(iVar1 == 0){
    else{
    piVar2 =(int *)FUN_10003ad0();
    local_20 = FUN_100065d0();
    FUN_100061c0();
    this_00 = FUN_10003ad0();
    FUN_10006590();
    return param_1;

f FUN_10006100(6):
  c:FUN_10004e50,FUN_10004e90,FUN_100029f0
  k:0x10
  cf:
    FUN_10004e50();
    bVar1 = FUN_10004e90();
    if(bVar1){
    *(undefined4 *)((int)this + 0x10),local_8);
    FUN_100029f0(0x10);
    *(undefined4 *)((int)this + 0x10)= uVar2;
    return param_1;

f FUN_100061a0(0):
  c:max_size
  cf:
    max_size();
    return;

f FUN_100061c0(5):
  c:FUN_10006040,FUN_100061a0,FUN_10004ce0,FID_conflict__Xinvarg,FUN_10002ce0,FUN_10004d30,do_is,FUN_10006389,FUN_100064a8,FUN_100045b0,FUN_10005060
  g:DAT_10020030,FUN_10006040,FUN_10006389,FUN_10005060
  k:0xfffffffc,0xc,0x10
  cf:
    uStack_48 = DAT_10020030 ^(uint)&stack0xfffffffc;
    local_14 =(undefined1 *)&uStack_48;
    local_18 = FUN_10006040();
    if(param_3 != 0){
    iVar1 = FUN_100061a0();
    iVar2 = FUN_10004ce0();
    if((uint)(iVar1 - iVar2)< param_3){
    FID_conflict__Xinvarg();
    else{
    iVar1 = FUN_10004ce0();
    if(local_18 < iVar1 + param_3){
    iVar1 = FUN_100061a0();
    if(iVar1 -(local_18 >> 1)< local_18){
    else{
    local_38 =(local_18 >> 1)+ local_18;
    iVar1 = FUN_10004ce0();
    if(local_18 < iVar1 + param_3){
    iVar1 = FUN_10004ce0();
    local_20 =(void *)FUN_10002ce0();
    local_1c = param_2 - *(int *)((int)this + 0xc)>> 2;
    FUN_10004d30();
    do_is(this,*(undefined4 *)((int)this + 0xc),param_2,local_20);
    do_is(this,param_2,*(undefined4 *)((int)this + 0x10),
    (void *)((int)local_20 +(local_1c + param_3)* 4));
    FUN_10006389();
    return;
    if((uint)(*(int *)((int)this + 0x10)- param_2 >> 2)< param_3){
    do_is(this,param_2,*(undefined4 *)((int)this + 0x10),(void *)(param_2 + param_3 * 4));
    param_3 -(*(int *)((int)this + 0x10)- param_2 >> 2),&local_28);
    FUN_100064a8();
    return;
    local_2c = *(int *)((int)this + 0x10);
    uVar3 = do_is(0x10);
    *(undefined4 *)((int)this + 0x10)= uVar3;
    FUN_100045b0();
    FUN_10005060();
    return;

f Catch_All_1000631c(0):
  c:FUN_10004e70,__CxxThrowException_8
  k:0x20,0x1c,0x18,0x10,0x0,0xffffffff,0x10006390
  cf:
    if(1 < *(int *)(unaff_EBP + -0x20)){
    *(int *)(unaff_EBP + -0x1c)+ *(int *)(unaff_EBP + -0x18)* 4);
    if(0 < *(int *)(unaff_EBP + -0x20)){
    *(int *)(unaff_EBP + 0x10)* 4);
    FUN_10004e70(0x1c);
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    return 0x10006390;

f FUN_10006389(0):
  c:FUN_10004ce0,FUN_10004e70
  k:0xffffffff,0x30,0x10,0xc,0x1c,0x14
  cf:
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    iVar1 = FUN_10004ce0(0x30);
    *(int *)(unaff_EBP + 0x10)= iVar1 + *(int *)(unaff_EBP + 0x10);
    if(*(int *)(*(int *)(unaff_EBP + -0x30)+ 0xc)!= 0){
    *(undefined4 *)(*(int *)(unaff_EBP + -0x30)+ 0x10));
    FUN_10004e70(0x30);
    *(int *)(unaff_EBP + -0x1c)+ *(int *)(unaff_EBP + -0x14)* 4;
    *(int *)(unaff_EBP + -0x1c)+ *(int *)(unaff_EBP + 0x10)* 4;
    *(undefined4 *)(*(int *)(unaff_EBP + -0x30)+ 0xc)= *(undefined4 *)(unaff_EBP + -0x1c);
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return;

f Catch_All_10006473(0):
  c:__CxxThrowException_8
  k:0x30,0x10,0x0,0xffffffff,0x100064af
  cf:
    *(int *)(*(int *)(unaff_EBP + -0x30)+ 0x10)+ *(int *)(unaff_EBP + 0x10)* 4);
    __CxxThrowException_8(0x0);
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    return 0x100064af;

f FUN_100064a8(0):
  k:0xffffffff,0x30,0x10,0x24,0xc
  cf:
    *(undefined4 *)(unaff_EBP + -4)= 0xffffffff;
    *(int *)(*(int *)(unaff_EBP + -0x30)+ 0x10)+ *(int *)(unaff_EBP + 0x10)* 4;
    (undefined4 *)(unaff_EBP + -0x24));
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return;

f FUN_10006590(3):
  c:FUN_10006620
  g:FUN_10006620
  cf:
    local_8 = *(undefined4 *)((int)this + 4);
    puVar2 =(undefined4 *)FUN_10006620();
    return param_1;

f FUN_100065d0(2):
  c:FUN_100011f0,FUN_100011d0,FUN_100082e9
  cf:
    bVar1 = FUN_100011f0();
    if((!bVar1)||(bVar1 = FUN_100011d0(this,param_1),!bVar1)){
    FUN_100082e9();
    return *(int *)((int)this + 4)- param_1[1] >> 2;

f FUN_10006620(2):
  c:FUN_100066a0
  cf:
    FUN_100066a0();
    return this;

f FUN_10006640(3):
  c:FUN_10002d80,FUN_100082e9,FUN_10001180
  g:FUN_10001180
  k:0x0
  cf:
    FUN_10002d80();
    if(((param_2 ==(undefined4 *)0x0)||(param_1 <(uint)param_2[3]))||
    FUN_100082e9();
    FUN_10001180();
    *(uint *)((int)this + 4)= param_1;
    return(undefined4 *)this;

f FUN_100066a0(2):
  c:FUN_100011f0,FUN_100082e9,FUN_100011a0
  k:0x10
  cf:
    bVar2 = FUN_100011f0();
    if(!bVar2){
    FUN_100082e9();
    iVar1 = *(int *)((int)this + 4);
    iVar3 = FUN_100011a0();
    if((*(uint *)(iVar3 + 0x10)<(uint)(iVar1 + param_1 * 4))||
    FUN_100082e9();
    *(int *)((int)this + 4)= *(int *)((int)this + 4)+ param_1 * 4;
    return(int *)this;

f FUN_10006720(4):
  c:CONCAT12,FUN_10006800,FUN_10004620,FUN_10005090
  g:CONCAT12,FUN_10006800,FUN_10004620,FUN_10005090
  cf:
    uStack_8 =(uint)param_1;
    uVar1 = _Char_traits_cat<>(&param_4);
    uStack_8._0_3_ = CONCAT12();
    FUN_10006800();
    iVar2 = FUN_10004620();
    pvVar3 =(void *)FUN_10004620();
    FUN_10005090();
    return;

f FUN_100067b0(3):
  c:_memmove_s
  cf:
    iVar1 = param_2 -(int)param_1 >> 2;
    _Dst =(void *)(param_3 + iVar1 * -4);
    if(0 < iVar1){
    _memmove_s();
    return _Dst;

f FUN_10006800(1):
  cf:
    return param_1;

f Process32First(0):
  c:Process32First
  cf:
    Process32First();
    return;

f Process32Next(0):
  c:Process32Next
  cf:
    Process32Next();
    return;

f CreateToolhelp32Snapshot(0):
  c:CreateToolhelp32Snapshot
  cf:
    CreateToolhelp32Snapshot();
    return;

f __security_check_cookie(1):
  c:___report_gsfailure
  g:DAT_10020030
  cf:
    if(param_1 == DAT_10020030){
    return;
    ___report_gsfailure();

f _memmove_s(4):
  c:__errno,_memmove,__invalid_parameter
  g:LAB_10006884
  k:0x0
  cf:
    if(_MaxCount == 0){
    else{
    if((_Dst ==(void *)0x0)||(_Src ==(void *)0x0)){
    piVar1 = __errno();
    else{
    if(_MaxCount <= _DstSize){
    _memmove();
    goto LAB_10006884;
    piVar1 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    return eVar2;

f FUN_1000688a(1):
  cf:
    return;

f FUN_1000697e(1):
  k:0x0
  cf:
    pcVar1 = *(char **)(param_1 + 4);
    if(pcVar1 ==(char *)0x0){
    return pcVar1;

f FUN_1000698b(2):
  c:exception,FUN_10008417
  g:FUN_10008417
  cf:
    exception::~exception();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(exception *)this;

f FUN_100069ac(1):
  c:operator_new
  cf:
    operator_new();
    return;

f _memcmp(3):
  k:0x1f,0x20,0xb,0xc,0xd,0xe,0xf,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0xff
  cf:
    if(_Size == 0){
    return 0;
    if(_Size == 1){
    uVar2 =(uint)*_Buf1;
    uVar3 =(uint)*_Buf2;
    if(uVar2 == uVar3){
    return 0;
    return(uint)(0 <(int)(uVar2 - uVar3))* 2 + -1;
    if(_Size == 2){
    uVar2 =(uint)*_Buf1;
    uVar3 =(uint)*_Buf2;
    if((uVar2 != uVar3)&&
    return iVar1;
    uVar2 =(uint)*(byte *)((int)_Buf1 + 1);
    uVar3 =(uint)*(byte *)((int)_Buf2 + 1);
    goto LAB_10007f10;
    if(_Size == 3){
    uVar2 =(uint)*_Buf1;
    uVar3 =(uint)*_Buf2;
    if((uVar2 != uVar3)&&
    return iVar1;
    uVar2 =(uint)*(byte *)((int)_Buf1 + 1);
    uVar3 =(uint)*(byte *)((int)_Buf2 + 1);
    if((uVar2 != uVar3)&&
    return iVar1;
    uVar2 =(uint)*(byte *)((int)_Buf1 + 2);
    uVar3 =(uint)*(byte *)((int)_Buf2 + 2);
    goto LAB_10007f10;
    if(_Size == 4){
    uVar2 =(uint)*_Buf1;
    uVar3 =(uint)*_Buf2;
    if((uVar2 != uVar3)&&
    return iVar1;
    uVar2 =(uint)*(byte *)((int)_Buf1 + 1);
    uVar3 =(uint)*(byte *)((int)_Buf2 + 1);
    if((uVar2 != uVar3)&&
    return iVar1;
    uVar2 =(uint)*(byte *)((int)_Buf1 + 2);
    uVar3 =(uint)*(byte *)((int)_Buf2 + 2);
    if((uVar2 != uVar3)&&
    return iVar1;
    uVar2 =(uint)*(byte *)((int)_Buf1 + 3);
    uVar3 =(uint)*(byte *)((int)_Buf2 + 3);
    goto LAB_10007f10;
    for(;0x1f < _Size;_Size = _Size - 0x20){
    if(*_Buf1 == *_Buf2){
    else{
    uVar3 =(uint)*_Buf1;
    uVar2 =(uint)*_Buf2;
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 1);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 1);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 2);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 2);
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 + 3)-(uint)*(byte *)((int)_Buf2 + 3);
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    if(*(int *)((int)_Buf1 + 4)== *(int *)((int)_Buf2 + 4)){
    else{
    uVar3 =(uint)*(byte *)((int)_Buf1 + 4);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 4);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 5);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 5);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 6);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 6);
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 + 7)-(uint)*(byte *)((int)_Buf2 + 7);
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    if(*(int *)((int)_Buf1 + 8)== *(int *)((int)_Buf2 + 8)){
    else{
    uVar3 =(uint)*(byte *)((int)_Buf1 + 8);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 8);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 9);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 9);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 10);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 10);
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 + 0xb)-(uint)*(byte *)((int)_Buf2 + 0xb);
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    if(*(int *)((int)_Buf1 + 0xc)== *(int *)((int)_Buf2 + 0xc)){
    else{
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0xc);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0xc);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0xd);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0xd);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0xe);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0xe);
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 + 0xf)-(uint)*(byte *)((int)_Buf2 + 0xf);
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    if(*(int *)((int)_Buf1 + 0x10)== *(int *)((int)_Buf2 + 0x10)){
    else{
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0x10);
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0x10);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0x11);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0x11);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0x12);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0x12);
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 + 0x13)-(uint)*(byte *)((int)_Buf2 + 0x13);
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    if(*(int *)((int)_Buf1 + 0x14)== *(int *)((int)_Buf2 + 0x14)){
    else{
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0x14);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0x14);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0x15);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0x15);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0x16);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0x16);
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 + 0x17)-(uint)*(byte *)((int)_Buf2 + 0x17);
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    if(*(int *)((int)_Buf1 + 0x18)== *(int *)((int)_Buf2 + 0x18)){
    else{
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0x18);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0x18);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0x19);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0x19);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0x1a);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0x1a);
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 + 0x1b)-(uint)*(byte *)((int)_Buf2 + 0x1b);
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    if(*(int *)((int)_Buf1 + 0x1c)== *(int *)((int)_Buf2 + 0x1c)){
    else{
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0x1c);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0x1c);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0x1d);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0x1d);
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 + 0x1e);
    uVar2 =(uint)*(byte *)((int)_Buf2 + 0x1e);
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 + 0x1f)-(uint)*(byte *)((int)_Buf2 + 0x1f);
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    _Buf1 =(void *)((int)_Buf1 + 0x20);
    _Buf2 =(void *)((int)_Buf2 + 0x20);
    switch(_Size){
    default:
    goto switchD_10006e7e_caseD_0;
    case 1:
    goto switchD_10006e7e_caseD_1;
    case 2:
    goto switchD_10006e7e_caseD_2;
    case 3:
    goto switchD_10006e7e_caseD_3;
    case 4:
    goto switchD_10006e7e_caseD_4;
    case 5:
    goto switchD_10006e7e_caseD_5;
    case 6:
    goto switchD_10006e7e_caseD_6;
    case 7:
    goto switchD_10006e7e_caseD_7;
    case 8:
    goto switchD_10006e7e_caseD_8;
    case 9:
    goto switchD_10006e7e_caseD_9;
    case 10:
    goto switchD_10006e7e_caseD_a;
    case 0xb:
    goto switchD_10006e7e_caseD_b;
    case 0xc:
    goto switchD_10006e7e_caseD_c;
    case 0xd:
    goto switchD_10006e7e_caseD_d;
    case 0xe:
    goto switchD_10006e7e_caseD_e;
    case 0xf:
    goto switchD_10006e7e_caseD_f;
    case 0x10:
    goto switchD_10006e7e_caseD_10;
    case 0x11:
    goto switchD_10006e7e_caseD_11;
    case 0x12:
    goto switchD_10006e7e_caseD_12;
    case 0x13:
    goto switchD_10006e7e_caseD_13;
    case 0x14:
    goto switchD_10006e7e_caseD_14;
    case 0x15:
    goto switchD_10006e7e_caseD_15;
    case 0x16:
    goto switchD_10006e7e_caseD_16;
    case 0x17:
    goto switchD_10006e7e_caseD_17;
    case 0x18:
    goto switchD_10006e7e_caseD_18;
    case 0x1a:
    goto switchD_10006e7e_caseD_1a;
    case 0x1b:
    goto switchD_10006e7e_caseD_1b;
    case 0x1c:
    if(*(uint *)((int)_Buf1 +(_Size - 0x1c))== *(uint *)((int)_Buf2 +(_Size - 0x1c))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x1c))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1c));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x1b));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1b));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x1a));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1a));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0x19));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_18:
    if(*(uint *)((int)_Buf1 +(_Size - 0x18))== *(uint *)((int)_Buf2 +(_Size - 0x18))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x18))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x18));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x17));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x17));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x16));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x16));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0x15));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_14:
    if(*(uint *)((int)_Buf1 +(_Size - 0x14))== *(uint *)((int)_Buf2 +(_Size - 0x14))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x14))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x14));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x13));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x13));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x12));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x12));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0x11));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_10:
    if(*(uint *)((int)_Buf1 +(_Size - 0x10))== *(uint *)((int)_Buf2 +(_Size - 0x10))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x10))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x10));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0xf));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xf));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0xe));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xe));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0xd));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_c:
    if(*(int *)((int)_Buf1 +(_Size - 0xc))== *(int *)((int)_Buf2 +(_Size - 0xc))){
    else{
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xc));
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0xc));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0xb));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xb));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 10));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 10));
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 +(_Size - 9))-(uint)*(byte *)((int)_Buf2 +(_Size - 9));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_8:
    if(*(uint *)((int)_Buf1 +(_Size - 8))== *(uint *)((int)_Buf2 +(_Size - 8))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 8))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 8));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 7));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 7));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 6));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 6));
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 +(_Size - 5))-(uint)*(byte *)((int)_Buf2 +(_Size - 5));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 == 0){
    switchD_10006e7e_caseD_4:
    if(*(uint *)((int)_Buf1 +(_Size - 4))== *(uint *)((int)_Buf2 +(_Size - 4))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 4))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 4));
    if((uVar3 == uVar2)||
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 3));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 3));
    if((uVar3 == uVar2)||
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 2));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 2));
    if(((uVar3 == uVar2)||
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 == 0){
    switchD_10006e7e_caseD_0:
    return iVar1;
    case 0x1d:
    if(*(uint *)((int)_Buf1 +(_Size - 0x1d))== *(uint *)((int)_Buf2 +(_Size - 0x1d))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x1d))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1d));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x1c));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1c));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x1b));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1b));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0x1a));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    case 0x19:
    if(*(uint *)((int)_Buf1 +(_Size - 0x19))== *(uint *)((int)_Buf2 +(_Size - 0x19))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x19))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x19));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x18));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x18));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x17));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x17));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0x16));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_15:
    if(*(uint *)((int)_Buf1 +(_Size - 0x15))== *(uint *)((int)_Buf2 +(_Size - 0x15))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x15))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x15));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x14));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x14));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x13));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x13));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0x12));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_11:
    if(*(uint *)((int)_Buf1 +(_Size - 0x11))== *(uint *)((int)_Buf2 +(_Size - 0x11))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x11))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x11));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x10));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x10));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0xf));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xf));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0xe));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_d:
    if(*(uint *)((int)_Buf1 +(_Size - 0xd))== *(uint *)((int)_Buf2 +(_Size - 0xd))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0xd))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xd));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0xc));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xc));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0xb));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xb));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 10));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_9:
    if(*(int *)((int)_Buf1 +(_Size - 9))== *(int *)((int)_Buf2 +(_Size - 9))){
    else{
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 9));
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 9));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 8));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 8));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 7));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 7));
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 +(_Size - 6))-(uint)*(byte *)((int)_Buf2 +(_Size - 6));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_5:
    if(*(uint *)((int)_Buf1 +(_Size - 5))== *(uint *)((int)_Buf2 +(_Size - 5))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 5))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 5));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 4));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 4));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 3));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 3));
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 +(_Size - 2))-(uint)*(byte *)((int)_Buf2 +(_Size - 2));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_1:
    if((uint)*(byte *)((int)_Buf1 +(_Size - 1))==(uint)*(byte *)((int)_Buf2 +(_Size - 1))){
    return 0;
    return(uint)(0 <(int)((uint)*(byte *)((int)_Buf1 +(_Size - 1))-
    (uint)*(byte *)((int)_Buf2 +(_Size - 1))))* 2 + -1;
    case 0x1e:
    if(*(uint *)((int)_Buf1 +(_Size - 0x1e))== *(uint *)((int)_Buf2 +(_Size - 0x1e))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x1e))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1e));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x1d));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1d));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x1c));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1c));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0x1b));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_1a:
    if(*(uint *)((int)_Buf1 +(_Size - 0x1a))== *(uint *)((int)_Buf2 +(_Size - 0x1a))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x1a))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1a));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x19));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x19));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x18));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x18));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0x17));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_16:
    if(*(uint *)((int)_Buf1 +(_Size - 0x16))== *(uint *)((int)_Buf2 +(_Size - 0x16))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x16))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x16));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x15));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x15));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x14));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x14));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0x13));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_12:
    if(*(uint *)((int)_Buf1 +(_Size - 0x12))== *(uint *)((int)_Buf2 +(_Size - 0x12))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x12))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x12));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x11));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x11));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x10));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x10));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0xf));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_e:
    if(*(uint *)((int)_Buf1 +(_Size - 0xe))== *(uint *)((int)_Buf2 +(_Size - 0xe))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0xe))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xe));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0xd));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xd));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0xc));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xc));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0xb));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_a:
    if(*(int *)((int)_Buf1 +(_Size - 10))== *(int *)((int)_Buf2 +(_Size - 10))){
    else{
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 10));
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 10));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 9));
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 9));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 8));
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 8));
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 +(_Size - 7))-(uint)*(byte *)((int)_Buf2 +(_Size - 7));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_6:
    if(*(uint *)((int)_Buf1 +(_Size - 6))== *(uint *)((int)_Buf2 +(_Size - 6))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 6))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 6));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 5));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 5));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 4));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 4));
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 +(_Size - 3))-(uint)*(byte *)((int)_Buf2 +(_Size - 3));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_2:
    if(*(short *)((int)_Buf1 +(_Size - 2))!= *(short *)((int)_Buf2 +(_Size - 2))){
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 2));
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 2));
    if((uVar3 != uVar2)&&
    return iVar1;
    goto switchD_10006e7e_caseD_1;
    goto switchD_10006e7e_caseD_0;
    case 0x1f:
    if(*(int *)((int)_Buf1 +(_Size - 0x1f))== *(int *)((int)_Buf2 +(_Size - 0x1f))){
    else{
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1f));
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x1f));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x1e));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1e));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x1d));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1d));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0x1c));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_1b:
    if(*(uint *)((int)_Buf1 +(_Size - 0x1b))== *(uint *)((int)_Buf2 +(_Size - 0x1b))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x1b))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1b));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x1a));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x1a));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x19));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x19));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0x18));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_17:
    if(*(uint *)((int)_Buf1 +(_Size - 0x17))== *(uint *)((int)_Buf2 +(_Size - 0x17))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x17))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x17));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x16));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x16));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x15));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x15));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0x14));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_13:
    if(*(uint *)((int)_Buf1 +(_Size - 0x13))== *(uint *)((int)_Buf2 +(_Size - 0x13))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0x13))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x13));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x12));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x12));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0x11));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0x11));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0x10));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_f:
    if(*(int *)((int)_Buf1 +(_Size - 0xf))== *(int *)((int)_Buf2 +(_Size - 0xf))){
    else{
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xf));
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0xf));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0xe));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xe));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 0xd));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xd));
    if((uVar3 != uVar2)&&
    return iVar1;
    (uint)*(byte *)((int)_Buf2 +(_Size - 0xc));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_b:
    if(*(uint *)((int)_Buf1 +(_Size - 0xb))== *(uint *)((int)_Buf2 +(_Size - 0xb))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 0xb))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 0xb));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 10));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 10));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 9));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 9));
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 +(_Size - 8))-(uint)*(byte *)((int)_Buf2 +(_Size - 8));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_7:
    if(*(uint *)((int)_Buf1 +(_Size - 7))== *(uint *)((int)_Buf2 +(_Size - 7))){
    else{
    uVar3 = *(uint *)((int)_Buf1 +(_Size - 7))& 0xff;
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 7));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 6));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 6));
    if((uVar3 != uVar2)&&
    return iVar1;
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 5));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 5));
    if((uVar3 != uVar2)&&
    return iVar1;
    iVar1 =(uint)*(byte *)((int)_Buf1 +(_Size - 4))-(uint)*(byte *)((int)_Buf2 +(_Size - 4));
    if(iVar1 != 0){
    iVar1 =(uint)(0 < iVar1)* 2 + -1;
    if(iVar1 != 0){
    return iVar1;
    switchD_10006e7e_caseD_3:
    uVar3 =(uint)*(byte *)((int)_Buf1 +(_Size - 3));
    uVar2 =(uint)*(byte *)((int)_Buf2 +(_Size - 3));
    if((uVar3 != uVar2)&&
    return iVar1;
    goto LAB_10007a64;

f _strlen(1):
  k:0xffffffff,0x7efefeff,0x81010100,0xff0000,0xff000000
  cf:
    uVar1 =(uint)_Str & 3;
    puVar2 =(uint *)_Str;
    while(uVar1 != 0){
    puVar2 =(uint *)((int)puVar2 + 1);
    if((char)uVar1 == '\0')goto LAB_100080a3;
    uVar1 =(uint)puVar2 & 3;
    do{
    }while(((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff)& 0x81010100)== 0);
    if((char)uVar1 == '\0'){
    return(int)puVar3 -(int)_Str;
    if((char)(uVar1 >> 8)== '\0'){
    return(size_t)((int)puVar3 +(1 -(int)_Str));
    if((uVar1 & 0xff0000)== 0){
    return(size_t)((int)puVar3 +(2 -(int)_Str));
    }while((uVar1 & 0xff000000)!= 0);
    return(size_t)((int)puVar2 +(-1 -(int)_Str));

f __ArrayUnwind(4):
  cf:
    while(true){
    if(param_3 < 0)break;
    (*param_4)(in_stack_ffffffc8);
    return;

f _eh_vector_destructor_iterator_(4):
  c:FUN_10008174
  g:FUN_10008174
  cf:
    while(true){
    if(param_3 < 0)break;
    (*param_4)(in_stack_ffffffd0);
    FUN_10008174();
    return;

f FUN_10008174(0):
  k:0x1c,0x14
  cf:
    if(*(int *)(unaff_EBP + -0x1c)== 0){
    *(_func_void_void_ptr **)(unaff_EBP + 0x14));
    return;

f FUN_1000818c(1):
  cf:
    return;

f __invoke_watson(5):
  c:_memset,IsDebuggerPresent,SetUnhandledExceptionFilter,UnhandledExceptionFilter,FUN_10009bac,GetCurrentProcess,TerminateProcess,__security_check_cookie
  g:DAT_10020030,PCONTEXT
  k:0xfffffffc,0x4c,0x0
  cf:
    uVar1 = DAT_10020030 ^(uint)&stack0xfffffffc;
    _memset(0x4c);
    local_2dc.ContextRecord =(PCONTEXT)&local_2d4;
    BVar2 = IsDebuggerPresent();
    SetUnhandledExceptionFilter(0x0);
    LVar3 = UnhandledExceptionFilter();
    if((LVar3 == 0)&&(BVar2 == 0)){
    FUN_10009bac();
    hProcess = GetCurrentProcess();
    TerminateProcess();
    __security_check_cookie(0xfffffffc);
    return;

f __invalid_parameter(5):
  c:__decode_pointer,FUN_10009bac,__invoke_watson
  g:UNRECOVERED_JUMPTABLE,DAT_10021140
  k:0x0
  cf:
    UNRECOVERED_JUMPTABLE =(code *)__decode_pointer(DAT_10021140);
    if(UNRECOVERED_JUMPTABLE !=(code *)0x0){
    (*UNRECOVERED_JUMPTABLE)();
    return;
    FUN_10009bac();
    __invoke_watson();

f FUN_100082e9(0):
  c:__invalid_parameter
  k:0x0
  cf:
    __invalid_parameter(0x0,0x0,0x0);
    return;

f _memset(3):
  c:undefined1,__VEC_memzero
  k:0xff
  cf:
    undefined1(*pauVar2)[16];
    if(_Size == 0){
    return _Dst;
    if((((char)_Val == '\0')&&(0xff < _Size))&&(DAT_10022d98 != 0)){
    pauVar2 = __VEC_memzero();
    return pauVar2;
    puVar5 =(uint *)_Dst;
    if(3 < _Size){
    uVar3 = -(int)_Dst & 3;
    if(uVar3 != 0){
    do{
    *(char *)puVar5 =(char)_Val;
    puVar5 =(uint *)((int)puVar5 + 1);
    }while(uVar3 != 0);
    if(uVar3 != 0){
    for(;uVar3 != 0;uVar3 = uVar3 - 1){
    if(_Size == 0){
    return _Dst;
    do{
    *(char *)puVar5 =(char)uVar1;
    puVar5 =(uint *)((int)puVar5 + 1);
    }while(_Size != 0);
    return _Dst;

f FUN_1000837a(1):
  c:FUN_10008417
  g:FUN_10008417
  cf:
    FUN_10008417();
    return;

f _strcpy_s(3):
  c:__errno,__invalid_parameter
  k:0x0
  cf:
    if((_Dst !=(char *)0x0)&&(_SizeInBytes != 0)){
    if(_Src !=(char *)0x0){
    do{
    if(cVar1 == '\0')break;
    }while(_SizeInBytes != 0);
    if(_SizeInBytes != 0){
    return 0;
    piVar2 = __errno();
    goto LAB_100083a7;
    piVar2 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    return eVar4;

f __purecall(0):
  c:__decode_pointer,__NMSG_WRITE,__set_abort_behavior,_abort
  k:0x0,0x19
  cf:
    pcVar1 =(code *)__decode_pointer();
    if(pcVar1 !=(code *)0x0){
    (*pcVar1)();
    __NMSG_WRITE(0x19);
    __set_abort_behavior();
    _abort();

f FUN_10008417(1):
  c:_free
  cf:
    _free();
    return;

f _memcpy_s(4):
  c:__errno,_memcpy,_memset,__invalid_parameter
  g:LAB_10008432
  k:0x0,0x16
  cf:
    if(_MaxCount == 0){
    else{
    if(_Dst ==(void *)0x0){
    piVar2 = __errno();
    else{
    if((_Src !=(void *)0x0)&&(_MaxCount <= _DstSize)){
    _memcpy();
    goto LAB_10008432;
    _memset();
    if(_Src ==(void *)0x0)goto LAB_1000843b;
    if(_MaxCount <= _DstSize){
    return 0x16;
    piVar2 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    return eVar1;

f operator_new(1):
  c:_malloc,__callnewh,bad_alloc,_atexit,FUN_100031d0,__CxxThrowException_8,swi
  k:0x0
  cf:
    do{
    pvVar3 = _malloc();
    if(pvVar3 !=(void *)0x0){
    return pvVar3;
    iVar2 = __callnewh();
    }while(iVar2 != 0);
    if((_DAT_10021150 & 1)== 0){
    std::bad_alloc::bad_alloc();
    _atexit();
    FUN_100031d0();
    __CxxThrowException_8();
    pcVar1 =(code *)swi();
    pvVar3 =(void *)(*pcVar1)();
    return pvVar3;

f _memcpy(3):
  c:__VEC_memcpy
  k:0xff,0xf
  cf:
    if((_Src < _Dst)&&(_Dst <(void *)(_Size +(int)_Src))){
    puVar1 =(undefined4 *)((_Size - 4)+(int)_Src);
    puVar4 =(undefined4 *)((_Size - 4)+(int)_Dst);
    if(((uint)puVar4 & 3)== 0){
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_10008753_caseD_2;
    case 3:
    goto switchD_10008753_caseD_3;
    goto switchD_10008753_caseD_1;
    else{
    switch(_Size){
    case 0:
    goto switchD_10008753_caseD_0;
    case 1:
    goto switchD_10008753_caseD_1;
    case 2:
    goto switchD_10008753_caseD_2;
    case 3:
    goto switchD_10008753_caseD_3;
    default:
    uVar2 = _Size -((uint)puVar4 & 3);
    switch((uint)puVar4 & 3){
    case 1:
    *(undefined1 *)((int)puVar4 + 3)= *(undefined1 *)((int)puVar1 + 3);
    puVar1 =(undefined4 *)((int)puVar1 + -1);
    puVar4 =(undefined4 *)((int)puVar4 - 1);
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_10008753_caseD_2;
    case 3:
    goto switchD_10008753_caseD_3;
    goto switchD_10008753_caseD_1;
    break;
    case 2:
    *(undefined1 *)((int)puVar4 + 3)= *(undefined1 *)((int)puVar1 + 3);
    *(undefined1 *)((int)puVar4 + 2)= *(undefined1 *)((int)puVar1 + 2);
    puVar1 =(undefined4 *)((int)puVar1 + -2);
    puVar4 =(undefined4 *)((int)puVar4 - 2);
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_10008753_caseD_2;
    case 3:
    goto switchD_10008753_caseD_3;
    goto switchD_10008753_caseD_1;
    break;
    case 3:
    *(undefined1 *)((int)puVar4 + 3)= *(undefined1 *)((int)puVar1 + 3);
    *(undefined1 *)((int)puVar4 + 2)= *(undefined1 *)((int)puVar1 + 2);
    *(undefined1 *)((int)puVar4 + 1)= *(undefined1 *)((int)puVar1 + 1);
    puVar1 =(undefined4 *)((int)puVar1 + -3);
    puVar4 =(undefined4 *)((int)puVar4 - 3);
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_10008753_caseD_2;
    case 3:
    goto switchD_10008753_caseD_3;
    goto switchD_10008753_caseD_1;
    switch(uVar2){
    case 7:
    case 6:
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    switch(uVar3){
    case 1:
    switchD_10008753_caseD_1:
    *(undefined1 *)((int)puVar4 + 3)= *(undefined1 *)((int)puVar1 + 3);
    return _Dst;
    case 2:
    switchD_10008753_caseD_2:
    *(undefined1 *)((int)puVar4 + 3)= *(undefined1 *)((int)puVar1 + 3);
    *(undefined1 *)((int)puVar4 + 2)= *(undefined1 *)((int)puVar1 + 2);
    return _Dst;
    case 3:
    switchD_10008753_caseD_3:
    *(undefined1 *)((int)puVar4 + 3)= *(undefined1 *)((int)puVar1 + 3);
    *(undefined1 *)((int)puVar4 + 2)= *(undefined1 *)((int)puVar1 + 2);
    *(undefined1 *)((int)puVar4 + 1)= *(undefined1 *)((int)puVar1 + 1);
    return _Dst;
    switchD_10008753_caseD_0:
    return _Dst;
    if(((0xff < _Size)&&(DAT_10022d98 != 0))&&(((uint)_Dst & 0xf)==((uint)_Src & 0xf))){
    puVar1 = __VEC_memcpy();
    return puVar1;
    puVar1 =(undefined4 *)_Dst;
    if(((uint)_Dst & 3)== 0){
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    _Src =(undefined4 *)((int)_Src + 4);
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_100085cc_caseD_2;
    case 3:
    goto switchD_100085cc_caseD_3;
    goto switchD_100085cc_caseD_1;
    else{
    switch(_Size){
    case 0:
    goto switchD_100085cc_caseD_0;
    case 1:
    goto switchD_100085cc_caseD_1;
    case 2:
    goto switchD_100085cc_caseD_2;
    case 3:
    goto switchD_100085cc_caseD_3;
    default:
    uVar2 =(_Size - 4)+((uint)_Dst & 3);
    switch((uint)_Dst & 3){
    case 1:
    *(undefined1 *)_Dst = *_Src;
    *(undefined1 *)((int)_Dst + 1)= *(undefined1 *)((int)_Src + 1);
    *(undefined1 *)((int)_Dst + 2)= *(undefined1 *)((int)_Src + 2);
    _Src =(void *)((int)_Src + 3);
    puVar1 =(undefined4 *)((int)_Dst + 3);
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    _Src =(undefined4 *)((int)_Src + 4);
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_100085cc_caseD_2;
    case 3:
    goto switchD_100085cc_caseD_3;
    goto switchD_100085cc_caseD_1;
    break;
    case 2:
    *(undefined1 *)_Dst = *_Src;
    *(undefined1 *)((int)_Dst + 1)= *(undefined1 *)((int)_Src + 1);
    _Src =(void *)((int)_Src + 2);
    puVar1 =(undefined4 *)((int)_Dst + 2);
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    _Src =(undefined4 *)((int)_Src + 4);
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_100085cc_caseD_2;
    case 3:
    goto switchD_100085cc_caseD_3;
    goto switchD_100085cc_caseD_1;
    break;
    case 3:
    *(undefined1 *)_Dst = *_Src;
    _Src =(void *)((int)_Src + 1);
    puVar1 =(undefined4 *)((int)_Dst + 1);
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    _Src =(undefined4 *)((int)_Src + 4);
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_100085cc_caseD_2;
    case 3:
    goto switchD_100085cc_caseD_3;
    goto switchD_100085cc_caseD_1;
    switch(uVar2){
    case 7:
    puVar1[uVar2 - 7] = *(undefined4 *)((int)_Src +(uVar2 - 7)* 4);
    case 6:
    puVar1[uVar2 - 6] = *(undefined4 *)((int)_Src +(uVar2 - 6)* 4);
    case 5:
    puVar1[uVar2 - 5] = *(undefined4 *)((int)_Src +(uVar2 - 5)* 4);
    case 4:
    puVar1[uVar2 - 4] = *(undefined4 *)((int)_Src +(uVar2 - 4)* 4);
    case 3:
    puVar1[uVar2 - 3] = *(undefined4 *)((int)_Src +(uVar2 - 3)* 4);
    case 2:
    puVar1[uVar2 - 2] = *(undefined4 *)((int)_Src +(uVar2 - 2)* 4);
    case 1:
    puVar1[uVar2 - 1] = *(undefined4 *)((int)_Src +(uVar2 - 1)* 4);
    _Src =(void *)((int)_Src + uVar2 * 4);
    switch(uVar3){
    case 1:
    switchD_100085cc_caseD_1:
    *(undefined1 *)puVar1 = *_Src;
    return _Dst;
    case 2:
    switchD_100085cc_caseD_2:
    *(undefined1 *)puVar1 = *_Src;
    *(undefined1 *)((int)puVar1 + 1)= *(undefined1 *)((int)_Src + 1);
    return _Dst;
    case 3:
    switchD_100085cc_caseD_3:
    *(undefined1 *)puVar1 = *_Src;
    *(undefined1 *)((int)puVar1 + 1)= *(undefined1 *)((int)_Src + 1);
    *(undefined1 *)((int)puVar1 + 2)= *(undefined1 *)((int)_Src + 2);
    return _Dst;
    switchD_100085cc_caseD_0:
    return _Dst;

f __mbsicmp_l(3):
  c:_LocaleUpdate,__errno,__invalid_parameter,elif,__stricmp_l
  g:LPSTR
  k:0x0,0x70,0xfffffffd,0x10,0x100,0x7fffffff
  cf:
    _LocaleUpdate::_LocaleUpdate();
    if(_Str1 ==(uchar *)0x0){
    piVar4 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    if(local_c != '\0'){
    *(uint *)(local_10 + 0x70)= *(uint *)(local_10 + 0x70)& 0xfffffffd;
    elif(_Str2 ==(uchar *)0x0){
    piVar4 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    if(local_c != '\0'){
    *(uint *)(local_10 + 0x70)= *(uint *)(local_10 + 0x70)& 0xfffffffd;
    else{
    if((local_18.mbcinfo)->ismbcodepage == 0){
    iVar5 = __stricmp_l();
    if(local_c != '\0'){
    *(uint *)(local_10 + 0x70)= *(uint *)(local_10 + 0x70)& 0xfffffffd;
    else{
    do{
    if((ptVar6->mbctype[bVar1 + 5] & 4)== 0){
    if((ptVar6->mbctype[bVar1 + 5] & 0x10)== 0){
    uVar2 =(ushort)bVar1;
    else{
    uVar2 =(ushort)ptVar6->mbcasemap[bVar1 + 4];
    elif(*pbVar7 == 0){
    else{
    (LPSTR)&local_8,2,ptVar6->mbcodepage,1);
    if(iVar5 == 1){
    uVar2 =(ushort)local_8;
    else{
    if(iVar5 != 2)goto LAB_10008b3a;
    uVar2 =(ushort)local_8 * 0x100 +(ushort)local_7;
    if((ptVar6->mbctype[bVar1 + 5] & 4)== 0){
    if((ptVar6->mbctype[bVar1 + 5] & 0x10)== 0){
    uVar3 =(ushort)bVar1;
    else{
    uVar3 =(ushort)ptVar6->mbcasemap[bVar1 + 4];
    elif(*pbVar7 == 0){
    else{
    (LPSTR)&local_8,2,ptVar6->mbcodepage,1);
    if(iVar5 == 1){
    uVar3 =(ushort)local_8;
    else{
    if(iVar5 != 2){
    piVar4 = __errno();
    if(local_c != '\0'){
    *(uint *)(local_10 + 0x70)= *(uint *)(local_10 + 0x70)& 0xfffffffd;
    return 0x7fffffff;
    uVar3 =(ushort)local_8 * 0x100 +(ushort)local_7;
    if(uVar3 != uVar2){
    iVar5 =(-(uint)(uVar3 < uVar2)& 2)- 1;
    if(local_c == '\0'){
    return iVar5;
    *(uint *)(local_10 + 0x70)= *(uint *)(local_10 + 0x70)& 0xfffffffd;
    return iVar5;
    }while(uVar2 != 0);
    if(local_c != '\0'){
    *(uint *)(local_10 + 0x70)= *(uint *)(local_10 + 0x70)& 0xfffffffd;
    return iVar5;

f if(1):

f if(1):

f __mbsicmp(2):
  c:__mbsicmp_l
  k:0x0
  cf:
    iVar1 = __mbsicmp_l(0x0);
    return iVar1;

f __onexit_nolock(1):
  c:__decode_pointer,__msize,__realloc_crt,__encode_pointer
  k:0x800,0x10,0x0
  cf:
    _Memory =(int *)__decode_pointer();
    piVar1 =(int *)__decode_pointer();
    if((piVar1 < _Memory)||(iVar5 =(int)piVar1 -(int)_Memory,iVar5 + 4U < 4)){
    return 0;
    sVar2 = __msize();
    if(sVar2 < iVar5 + 4U){
    if(sVar2 < 0x800){
    if((sVar3 + sVar2 < sVar2)||
    if(sVar2 + 0x10 < sVar2){
    return 0;
    pvVar4 = __realloc_crt(0x10);
    if(pvVar4 ==(void *)0x0){
    return 0;
    piVar1 =(int *)((int)pvVar4 +(iVar5 >> 2)* 4);
    DAT_10022d88 = __encode_pointer();
    iVar5 = __encode_pointer();
    DAT_10022d84 = __encode_pointer();
    return param_1;

f __onexit(1):
  c:FUN_1000bb45,__onexit_nolock,FUN_10008cba
  cf:
    FUN_1000bb45();
    p_Var1 =(_onexit_t)__onexit_nolock();
    FUN_10008cba();
    return p_Var1;

f FUN_10008cba(0):
  c:FUN_1000bb4e
  cf:
    FUN_1000bb4e();
    return;

f _atexit(1):
  c:__onexit
  k:0x0
  cf:
    p_Var1 = __onexit();
    return(p_Var1 !=(_onexit_t)0x0)- 1;

f __endthreadex(1):
  c:__IsNonwritableInCurrentImage,__getptd_noexit,__freeptd,ExitThread
  k:0x0
  cf:
    if(DAT_10022da4 !=(code *)0x0){
    BVar1 = __IsNonwritableInCurrentImage();
    if(BVar1 != 0){
    (*DAT_10022da4)();
    _Ptd = __getptd_noexit();
    if(_Ptd !=(_ptiddata)0x0){
    __freeptd();
    ExitThread();

f __callthreadstartex(0):
  c:__getptd,__endthreadex,__XcptFilter
  cf:
    p_Var1 = __getptd();
    _Retval =(*(code *)p_Var1->_initaddr)(p_Var1->_initarg);
    __endthreadex();
    __XcptFilter();
    return;

f __threadstartex_4(1):
  c:___set_flsgetvalue,FUN_10009cc4,___fls_getvalue_4,___fls_setvalue_8,GetLastError,ExitThread,GetCurrentThreadId,__freefls_4,__IsNonwritableInCurrentImage,__callthreadstartex,swi
  k:0x54,0x15,0x58,0x16,0x0
  cf:
    ___set_flsgetvalue();
    uVar2 = FUN_10009cc4();
    iVar3 = ___fls_getvalue_4();
    if(iVar3 == 0){
    uVar2 = FUN_10009cc4();
    iVar3 = ___fls_setvalue_8();
    if(iVar3 == 0){
    DVar4 = GetLastError();
    ExitThread();
    DVar4 = GetCurrentThreadId();
    else{
    *(DWORD *)(iVar3 + 0x54)= param_1[0x15];
    *(DWORD *)(iVar3 + 0x58)= param_1[0x16];
    *(DWORD *)(iVar3 + 4)= param_1[1];
    __freefls_4();
    if(DAT_10022da8 !=(code *)0x0){
    BVar5 = __IsNonwritableInCurrentImage();
    if(BVar5 != 0){
    (*DAT_10022da8)();
    __callthreadstartex();
    pcVar1 =(code *)swi();
    (*pcVar1)();
    return;

f __beginthreadex(6):
  c:__errno,__invalid_parameter,___set_flsgetvalue,__calloc_crt,__getptd,__initptd,GetLastError,_free,__dosmaperr
  g:LPDWORD,HANDLE
  k:0x0,0x214
  cf:
    if(_StartAddress ==(_StartAddress *)0x0){
    piVar2 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    else{
    ___set_flsgetvalue();
    _Ptd =(_ptiddata)__calloc_crt(0x214);
    if(_Ptd !=(_ptiddata)0x0){
    p_Var3 = __getptd();
    __initptd();
    lpThreadId =(_StartAddress **)_ThrdAddr;
    if(_ThrdAddr ==(uint *)0x0){
    _InitFlag,(LPDWORD)lpThreadId);
    if(pvVar4 !=(HANDLE)0x0){
    return(uintptr_t)pvVar4;
    local_8 = GetLastError();
    _free();
    if(local_8 != 0){
    __dosmaperr();
    return 0;

f _sprintf(3):
  c:__errno,__invalid_parameter,__output_l,__flsbuf
  k:0x0,0x0000000c
  cf:
    if((_Format ==(char *)0x0)||(_Dest ==(char *)0x0)){
    piVar1 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    else{
    iVar2 = __output_l(0x0,0x0000000c);
    if(local_24._cnt < 0){
    __flsbuf();
    else{
    return iVar2;

f _strncpy(3):
  g:LAB_10009019
  k:0x10008f5c,0xffffffff,0x7efefeff,0x81010100,0x10009015,0xff0000,0xff000000
  cf:
    if(_Count == 0){
    return _Dest;
    puVar5 =(uint *)_Dest;
    if(((uint)_Source & 3)!= 0){
    while(true){
    uVar4 = *(uint *)_Source;
    _Source =(char *)((int)_Source + 1);
    *(char *)puVar5 =(char)uVar4;
    puVar5 =(uint *)((int)puVar5 + 1);
    if(_Count == 0){
    return _Dest;
    if((char)uVar4 == '\0')break;
    if(((uint)_Source & 3)== 0){
    goto joined_r0x10008f5c;
    do{
    if(((uint)puVar5 & 3)== 0){
    if(uVar4 == 0)goto LAB_10008fa3;
    goto LAB_10009019;
    *(char *)puVar5 = '\0';
    puVar5 =(uint *)((int)puVar5 + 1);
    }while(_Count != 0);
    return _Dest;
    if(uVar4 != 0){
    do{
    uVar1 = *(uint *)_Source;
    uVar2 = *(uint *)_Source;
    _Source =(char *)((int)_Source + 4);
    if(((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff)& 0x81010100)!= 0){
    if((char)uVar2 == '\0'){
    while(true){
    if(uVar4 == 0)break;
    if(_Count != 0)goto LAB_10008fa3;
    return _Dest;
    if((char)(uVar2 >> 8)== '\0'){
    goto joined_r0x10009015;
    if((uVar2 & 0xff0000)== 0){
    goto joined_r0x10009015;
    if((uVar2 & 0xff000000)== 0){
    goto joined_r0x10009015;
    }while(uVar4 != 0);
    if(_Count == 0){
    return _Dest;
    do{
    cVar3 =(char)*(uint *)_Source;
    _Source =(char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 =(uint *)((int)puVar5 + 1);
    if(cVar3 == '\0'){
    while(_Count = _Count - 1,_Count != 0){
    *(char *)puVar5 = cVar3;
    puVar5 =(uint *)((int)puVar5 + 1);
    return _Dest;
    }while(_Count != 0);
    return _Dest;

f __CRT_INIT_12(3):
  c:__heap_init,__mtinit,__RTC_Initialize,GetCommandLineA,___crtGetEnvironmentStringsA,__ioinit,__setargv,__setenvp,__ioterm,__mtterm,__heap_term,elif,__cexit,__freeptd,___set_flsgetvalue,__calloc_crt,__decode_pointer,__initptd,GetCurrentThreadId,_free
  g:DAT_10021158,DAT_10021154,DAT_10021840,DAT_10021498
  k:0x0,0x214
  cf:
    if(param_2 == 1){
    iVar1 = __heap_init();
    if(iVar1 != 0){
    iVar1 = __mtinit();
    if(iVar1 != 0){
    __RTC_Initialize();
    DAT_10022da0 = GetCommandLineA();
    DAT_10021158 = ___crtGetEnvironmentStringsA();
    iVar1 = __ioinit();
    if(-1 < iVar1){
    iVar1 = __setargv();
    if(((-1 < iVar1)&&(iVar1 = __setenvp(),-1 < iVar1))&&
    return 1;
    __ioterm();
    __mtterm();
    __heap_term();
    elif(param_2 == 0){
    if(0 < DAT_10021154){
    if(DAT_10021840 == 0){
    __cexit();
    if(param_3 == 0){
    __ioterm();
    __mtterm();
    __heap_term();
    return 1;
    else{
    if(param_2 != 2){
    if(param_2 != 3){
    return 1;
    __freeptd(0x0);
    return 1;
    ___set_flsgetvalue();
    _Ptd =(_ptiddata)__calloc_crt(0x214);
    if(_Ptd !=(_ptiddata)0x0){
    pcVar2 =(code *)__decode_pointer(DAT_10021498);
    iVar1 =(*pcVar2)(uVar4,p_Var5);
    if(iVar1 != 0){
    __initptd(0x0);
    DVar3 = GetCurrentThreadId();
    return 1;
    _free();
    return 0;

f if(1):
  c:__cexit,__ioterm,__mtterm,__heap_term
  g:DAT_10021154,DAT_10021840
  cf:
    if(0 < DAT_10021154){
    if(DAT_10021840 == 0){
    __cexit();
    if(param_3 == 0){
    __ioterm();
    __mtterm();
    __heap_term();
    return 1;

f ___DllMainCRTStartup(3):
  c:FUN_10017b10,__CRT_INIT_12
  g:DAT_10021154
  cf:
    if(((param_2 == 0)&&(DAT_10021154 == 0))||
    else{
    local_20 = FUN_10017b10();
    if((param_2 == 1)&&(local_20 == 0)){
    FUN_10017b10();
    __CRT_INIT_12();
    if(((param_2 == 0)||(param_2 == 3))&&
    return local_20;

f entry(3):
  c:___security_init_cookie,___DllMainCRTStartup
  cf:
    if(param_2 == 1){
    ___security_init_cookie();
    ___DllMainCRTStartup();
    return;

f ___report_gsfailure(0):
  c:IsDebuggerPresent,FUN_10009bac,SetUnhandledExceptionFilter,UnhandledExceptionFilter,GetCurrentProcess,TerminateProcess
  k:0x100000,0x80000,0x40000,0x0
  cf:
    (uint)(in_VIP & 1)* 0x100000 |(uint)(in_VIF & 1)* 0x80000 |(uint)(in_AC & 1)* 0x40000;
    DAT_100211b8 = IsDebuggerPresent();
    FUN_10009bac();
    SetUnhandledExceptionFilter(0x0);
    UnhandledExceptionFilter();
    if(DAT_100211b8 == 0){
    FUN_10009bac();
    hProcess = GetCurrentProcess();
    TerminateProcess();
    return;

f _memmove(3):
  c:__VEC_memcpy
  k:0xff,0xf
  cf:
    if((_Src < _Dst)&&(_Dst <(void *)(_Size +(int)_Src))){
    puVar1 =(undefined4 *)((_Size - 4)+(int)_Src);
    puVar4 =(undefined4 *)((_Size - 4)+(int)_Dst);
    if(((uint)puVar4 & 3)== 0){
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_10009573_caseD_2;
    case 3:
    goto switchD_10009573_caseD_3;
    goto switchD_10009573_caseD_1;
    else{
    switch(_Size){
    case 0:
    goto switchD_10009573_caseD_0;
    case 1:
    goto switchD_10009573_caseD_1;
    case 2:
    goto switchD_10009573_caseD_2;
    case 3:
    goto switchD_10009573_caseD_3;
    default:
    uVar2 = _Size -((uint)puVar4 & 3);
    switch((uint)puVar4 & 3){
    case 1:
    *(undefined1 *)((int)puVar4 + 3)= *(undefined1 *)((int)puVar1 + 3);
    puVar1 =(undefined4 *)((int)puVar1 + -1);
    puVar4 =(undefined4 *)((int)puVar4 - 1);
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_10009573_caseD_2;
    case 3:
    goto switchD_10009573_caseD_3;
    goto switchD_10009573_caseD_1;
    break;
    case 2:
    *(undefined1 *)((int)puVar4 + 3)= *(undefined1 *)((int)puVar1 + 3);
    *(undefined1 *)((int)puVar4 + 2)= *(undefined1 *)((int)puVar1 + 2);
    puVar1 =(undefined4 *)((int)puVar1 + -2);
    puVar4 =(undefined4 *)((int)puVar4 - 2);
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_10009573_caseD_2;
    case 3:
    goto switchD_10009573_caseD_3;
    goto switchD_10009573_caseD_1;
    break;
    case 3:
    *(undefined1 *)((int)puVar4 + 3)= *(undefined1 *)((int)puVar1 + 3);
    *(undefined1 *)((int)puVar4 + 2)= *(undefined1 *)((int)puVar1 + 2);
    *(undefined1 *)((int)puVar4 + 1)= *(undefined1 *)((int)puVar1 + 1);
    puVar1 =(undefined4 *)((int)puVar1 + -3);
    puVar4 =(undefined4 *)((int)puVar4 - 3);
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_10009573_caseD_2;
    case 3:
    goto switchD_10009573_caseD_3;
    goto switchD_10009573_caseD_1;
    switch(uVar2){
    case 7:
    case 6:
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    switch(uVar3){
    case 1:
    switchD_10009573_caseD_1:
    *(undefined1 *)((int)puVar4 + 3)= *(undefined1 *)((int)puVar1 + 3);
    return _Dst;
    case 2:
    switchD_10009573_caseD_2:
    *(undefined1 *)((int)puVar4 + 3)= *(undefined1 *)((int)puVar1 + 3);
    *(undefined1 *)((int)puVar4 + 2)= *(undefined1 *)((int)puVar1 + 2);
    return _Dst;
    case 3:
    switchD_10009573_caseD_3:
    *(undefined1 *)((int)puVar4 + 3)= *(undefined1 *)((int)puVar1 + 3);
    *(undefined1 *)((int)puVar4 + 2)= *(undefined1 *)((int)puVar1 + 2);
    *(undefined1 *)((int)puVar4 + 1)= *(undefined1 *)((int)puVar1 + 1);
    return _Dst;
    switchD_10009573_caseD_0:
    return _Dst;
    if(((0xff < _Size)&&(DAT_10022d98 != 0))&&(((uint)_Dst & 0xf)==((uint)_Src & 0xf))){
    puVar1 = __VEC_memcpy();
    return puVar1;
    puVar1 =(undefined4 *)_Dst;
    if(((uint)_Dst & 3)== 0){
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    _Src =(undefined4 *)((int)_Src + 4);
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_100093ec_caseD_2;
    case 3:
    goto switchD_100093ec_caseD_3;
    goto switchD_100093ec_caseD_1;
    else{
    switch(_Size){
    case 0:
    goto switchD_100093ec_caseD_0;
    case 1:
    goto switchD_100093ec_caseD_1;
    case 2:
    goto switchD_100093ec_caseD_2;
    case 3:
    goto switchD_100093ec_caseD_3;
    default:
    uVar2 =(_Size - 4)+((uint)_Dst & 3);
    switch((uint)_Dst & 3){
    case 1:
    *(undefined1 *)_Dst = *_Src;
    *(undefined1 *)((int)_Dst + 1)= *(undefined1 *)((int)_Src + 1);
    *(undefined1 *)((int)_Dst + 2)= *(undefined1 *)((int)_Src + 2);
    _Src =(void *)((int)_Src + 3);
    puVar1 =(undefined4 *)((int)_Dst + 3);
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    _Src =(undefined4 *)((int)_Src + 4);
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_100093ec_caseD_2;
    case 3:
    goto switchD_100093ec_caseD_3;
    goto switchD_100093ec_caseD_1;
    break;
    case 2:
    *(undefined1 *)_Dst = *_Src;
    *(undefined1 *)((int)_Dst + 1)= *(undefined1 *)((int)_Src + 1);
    _Src =(void *)((int)_Src + 2);
    puVar1 =(undefined4 *)((int)_Dst + 2);
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    _Src =(undefined4 *)((int)_Src + 4);
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_100093ec_caseD_2;
    case 3:
    goto switchD_100093ec_caseD_3;
    goto switchD_100093ec_caseD_1;
    break;
    case 3:
    *(undefined1 *)_Dst = *_Src;
    _Src =(void *)((int)_Src + 1);
    puVar1 =(undefined4 *)((int)_Dst + 1);
    if(7 < uVar2){
    for(;uVar2 != 0;uVar2 = uVar2 - 1){
    _Src =(undefined4 *)((int)_Src + 4);
    switch(uVar3){
    case 0:
    return _Dst;
    case 2:
    goto switchD_100093ec_caseD_2;
    case 3:
    goto switchD_100093ec_caseD_3;
    goto switchD_100093ec_caseD_1;
    switch(uVar2){
    case 7:
    puVar1[uVar2 - 7] = *(undefined4 *)((int)_Src +(uVar2 - 7)* 4);
    case 6:
    puVar1[uVar2 - 6] = *(undefined4 *)((int)_Src +(uVar2 - 6)* 4);
    case 5:
    puVar1[uVar2 - 5] = *(undefined4 *)((int)_Src +(uVar2 - 5)* 4);
    case 4:
    puVar1[uVar2 - 4] = *(undefined4 *)((int)_Src +(uVar2 - 4)* 4);
    case 3:
    puVar1[uVar2 - 3] = *(undefined4 *)((int)_Src +(uVar2 - 3)* 4);
    case 2:
    puVar1[uVar2 - 2] = *(undefined4 *)((int)_Src +(uVar2 - 2)* 4);
    case 1:
    puVar1[uVar2 - 1] = *(undefined4 *)((int)_Src +(uVar2 - 1)* 4);
    _Src =(void *)((int)_Src + uVar2 * 4);
    switch(uVar3){
    case 1:
    switchD_100093ec_caseD_1:
    *(undefined1 *)puVar1 = *_Src;
    return _Dst;
    case 2:
    switchD_100093ec_caseD_2:
    *(undefined1 *)puVar1 = *_Src;
    *(undefined1 *)((int)puVar1 + 1)= *(undefined1 *)((int)_Src + 1);
    return _Dst;
    case 3:
    switchD_100093ec_caseD_3:
    *(undefined1 *)puVar1 = *_Src;
    *(undefined1 *)((int)puVar1 + 1)= *(undefined1 *)((int)_Src + 1);
    *(undefined1 *)((int)puVar1 + 2)= *(undefined1 *)((int)_Src + 2);
    return _Dst;
    switchD_100093ec_caseD_0:
    return _Dst;

f __get_errno_from_oserr(1):
  g:DAT_10020040
  k:0x10020044,0x2d,0x13,0x12,0xd,0xe,0xbc
  cf:
    do{
    if(param_1 ==(&DAT_10020040)[uVar1 * 2]){
    return *(int *)(uVar1 * 8 + 0x10020044);
    }while(uVar1 < 0x2d);
    if(param_1 - 0x13 < 0x12){
    return 0xd;
    return(-(uint)(0xe < param_1 - 0xbc)& 0xe)+ 8;

f __errno(0):
  c:__getptd_noexit
  k:0x0
  cf:
    p_Var1 = __getptd_noexit();
    if(p_Var1 ==(_ptiddata)0x0){
    return(int *)&DAT_100201a8;
    return &p_Var1->_terrno;

f ___doserrno(0):
  c:__getptd_noexit
  k:0x0
  cf:
    p_Var1 = __getptd_noexit();
    if(p_Var1 ==(_ptiddata)0x0){
    return(ulong *)&DAT_100201ac;
    return &p_Var1->_tdoserrno;

f __dosmaperr(1):
  c:___doserrno,__get_errno_from_oserr,__errno
  cf:
    puVar1 = ___doserrno();
    iVar2 = __get_errno_from_oserr();
    piVar3 = __errno();
    return;

f _V6_HeapAlloc(1):
  c:__lock,___sbh_alloc_block,FUN_100097c6
  k:0x0
  cf:
    local_20 =(int *)0x0;
    if(param_1 <= DAT_10022c4c){
    __lock();
    local_20 = ___sbh_alloc_block();
    FUN_100097c6();
    return local_20;

f FUN_100097c6(0):
  c:FUN_1000d764
  cf:
    FUN_1000d764();
    return;

f _malloc(1):
  c:__FF_MSGBANNER,__NMSG_WRITE,___crtExitProcess,HeapAlloc,elif,_V6_HeapAlloc,__errno,__callnewh
  g:DAT_10021954,HANDLE
  k:0xffffffe1,0x0,0x1e,0xff
  cf:
    if(_Size < 0xffffffe1){
    do{
    if(DAT_10021954 ==(HANDLE)0x0){
    __FF_MSGBANNER();
    __NMSG_WRITE(0x1e);
    ___crtExitProcess(0xff);
    if(DAT_10022c5c == 1){
    if(_Size == 0){
    piVar1 =(int *)HeapAlloc(DAT_10021954);
    elif((DAT_10022c5c != 3)||(piVar1 = _V6_HeapAlloc((uint *)_Size),piVar1 ==(int *)0x0))
    if(_Size == 0){
    goto LAB_1000983e;
    if(piVar1 !=(int *)0x0){
    return piVar1;
    if(DAT_10021aac == 0){
    piVar1 = __errno();
    break;
    iVar2 = __callnewh();
    }while(iVar2 != 0);
    piVar1 = __errno();
    else{
    __callnewh();
    piVar1 = __errno();
    return(void *)0x0;

f _free(1):
  c:__lock,___sbh_find_block,___sbh_free_block,FUN_100098ef,HeapFree,__errno,GetLastError,__get_errno_from_oserr
  g:DAT_10021954
  k:0x0
  cf:
    if(_Memory !=(void *)0x0){
    if(DAT_10022c5c == 3){
    __lock();
    puVar1 =(uint *)___sbh_find_block();
    if(puVar1 !=(uint *)0x0){
    ___sbh_free_block();
    FUN_100098ef();
    if(puVar1 !=(uint *)0x0){
    return;
    BVar2 = HeapFree(DAT_10021954);
    if(BVar2 == 0){
    piVar3 = __errno();
    DVar4 = GetLastError();
    iVar5 = __get_errno_from_oserr();
    return;

f FUN_100098ef(0):
  c:FUN_1000d764
  cf:
    FUN_1000d764();
    return;

f terminate(0):
  c:__getptd,_abort
  k:0x0
  cf:
    p_Var1 = __getptd();
    if((code *)p_Var1->_terminate !=(code *)0x0){
    (*(code *)p_Var1->_terminate)();
    _abort();

f FUN_10009960(0):
  c:__getptd,terminate
  k:0x0
  cf:
    p_Var1 = __getptd();
    if((code *)p_Var1->_unexpected !=(code *)0x0){
    (*(code *)p_Var1->_unexpected)();
    terminate();
    return;

f _inconsistency(0):
  c:__decode_pointer,terminate,swi
  k:0x0
  cf:
    pcVar1 =(code *)__decode_pointer();
    if(pcVar1 !=(code *)0x0){
    (*pcVar1)();
    terminate();
    pcVar1 =(code *)swi();
    (*pcVar1)();
    return;

f __initp_eh_hooks(0):
  c:__encode_pointer
  k:0x10009927
  cf:
    DAT_1002148c = __encode_pointer(0x10009927);
    return;

f __SEH_prolog4(2):
  g:DAT_10020030
  k:0x10,0xc
  cf:
    *(undefined4 *)((int)auStack_1c + iVar1 + 0x10)= unaff_EBX;
    *(undefined4 *)((int)auStack_1c + iVar1 + 0xc)= unaff_ESI;
    *(undefined4 *)((int)auStack_1c + iVar1 + 8)= unaff_EDI;
    *(uint *)((int)auStack_1c + iVar1 + 4)= DAT_10020030 ^(uint)&param_2;
    *(undefined4 *)((int)auStack_1c + iVar1)= unaff_retaddr;
    return;

f __SEH_epilog4(0):
  cf:
    ExceptionList =(void *)unaff_EBP[-4];
    return;

f __except_handler4(3):
  c:__security_check_cookie,_EH4_CallFilterFunc,___DestructExceptionObject,_EH4_GlobalUnwind,_EH4_LocalUnwind,_EH4_TransferToHandler
  g:DAT_10020030
  k:0x10,0x66,0xc,0xfffffffe,0x0,0x1f928c9d
  cf:
    piVar5 =(int *)(*(uint *)((int)param_2 + 8)^ DAT_10020030);
    iVar1 =(int)param_2 + 0x10;
    if(*piVar5 != -2){
    __security_check_cookie();
    if((*(byte *)(param_1 + 1)& 0x66)== 0){
    *(int ***)((int)param_2 + -4)= &local_1c;
    pvVar4 = *(PVOID *)((int)param_2 + 0xc);
    if(pvVar4 ==(PVOID)0xfffffffe){
    return local_10;
    do{
    local_14 =(uint *)(piVar5 +(int)pvVar4 * 3 + 4);
    local_c =(PVOID)*local_14;
    if((undefined *)piVar5[(int)pvVar4 * 3 + 5] !=(undefined *)0x0){
    iVar2 = _EH4_CallFilterFunc();
    if(iVar2 < 0){
    goto LAB_10009ac8;
    if(0 < iVar2){
    if((*param_1 == -0x1f928c9d)&&
    ___DestructExceptionObject();
    _EH4_GlobalUnwind();
    if(*(PVOID *)((int)param_2 + 0xc)!= pvVar4){
    _EH4_LocalUnwind(&DAT_10020030);
    *(PVOID *)((int)param_2 + 0xc)= local_c;
    if(*piVar5 != -2){
    __security_check_cookie();
    _EH4_TransferToHandler();
    goto LAB_10009b8c;
    }while(local_c !=(PVOID)0xfffffffe);
    if(local_5 == '\0'){
    return local_10;
    else{
    if(*(int *)((int)pvVar4 + 0xc)== -2){
    return local_10;
    _EH4_LocalUnwind(0xfffffffe,&DAT_10020030);
    if(*piVar5 != -2){
    __security_check_cookie();
    return local_10;

f FUN_10009bac(0):
  cf:
    return;

f __encode_pointer(1):
  c:TlsGetValue,GetModuleHandleW,GetProcAddress
  g:LPVOID,FARPROC,LS5,HMODULE
  k:0x0,0x1f8
  cf:
    pvVar1 = TlsGetValue();
    if((pvVar1 !=(LPVOID)0x0)&&(DAT_100201b0 != -1)){
    pcVar2 =(code *)TlsGetValue();
    iVar3 =(*pcVar2)(iVar3);
    if(iVar3 != 0){
    pFVar4 = *(FARPROC *)(iVar3 + 0x1f8);
    goto LAB_10009c14;
    hModule = GetModuleHandleW(LS5);
    if((hModule ==(HMODULE)0x0)&&
    return param_1;
    pFVar4 = GetProcAddress(S6);
    if(pFVar4 !=(FARPROC)0x0){
    param_1 =(*pFVar4)(param_1);
    return param_1;

f __encoded_null(0):
  c:__encode_pointer
  cf:
    __encode_pointer();
    return;

f __decode_pointer(1):
  c:TlsGetValue,GetModuleHandleW,GetProcAddress
  g:LPVOID,FARPROC,LS5,HMODULE
  k:0x0,0x1fc
  cf:
    pvVar1 = TlsGetValue();
    if((pvVar1 !=(LPVOID)0x0)&&(DAT_100201b0 != -1)){
    pcVar2 =(code *)TlsGetValue();
    iVar3 =(*pcVar2)(iVar3);
    if(iVar3 != 0){
    pFVar4 = *(FARPROC *)(iVar3 + 0x1fc);
    goto LAB_10009c8f;
    hModule = GetModuleHandleW(LS5);
    if((hModule ==(HMODULE)0x0)&&
    return param_1;
    pFVar4 = GetProcAddress(S7);
    if(pFVar4 !=(FARPROC)0x0){
    param_1 =(*pFVar4)(param_1);
    return param_1;

f ___fls_getvalue_4(1):
  c:TlsGetValue
  cf:
    pcVar1 =(code *)TlsGetValue();
    (*pcVar1)(param_1);
    return;

f FUN_10009cc4(0):
  cf:
    return DAT_100201b0;

f ___set_flsgetvalue(0):
  c:TlsGetValue,__decode_pointer,TlsSetValue
  g:LPVOID,DAT_10021494
  k:0x0
  cf:
    lpTlsValue = TlsGetValue();
    if(lpTlsValue ==(LPVOID)0x0){
    lpTlsValue =(LPVOID)__decode_pointer(DAT_10021494);
    TlsSetValue();
    return lpTlsValue;

f ___fls_setvalue_8(2):
  c:__decode_pointer
  g:DAT_10021498
  cf:
    pcVar1 =(code *)__decode_pointer(DAT_10021498);
    (*pcVar1)(param_1,param_2);
    return;

f __mtterm(0):
  c:__decode_pointer,TlsFree,__mtdeletelocks
  k:0xffffffff
  cf:
    if(DAT_100201b0 != -1){
    pcVar1 =(code *)__decode_pointer();
    (*pcVar1)(iVar2);
    if(DAT_100201b4 != 0xffffffff){
    TlsFree();
    __mtdeletelocks();
    return;

f __initptd(2):
  c:GetModuleHandleW,__crt_waiting_on_module_handle,GetProcAddress,__lock,InterlockedIncrement,FUN_10009e2d,___addlocaleref,FUN_10009e36
  g:LS5,HMODULE,FARPROC,DAT_10020280,PTR_DAT_10020888
  k:0x0,0x1d,0x1f,0x43,0x93,0xd,0xc
  cf:
    hModule = GetModuleHandleW(LS5);
    if(hModule ==(HMODULE)0x0){
    hModule =(HMODULE)__crt_waiting_on_module_handle(LS5);
    if(hModule !=(HMODULE)0x0){
    pFVar1 = GetProcAddress(S6);
    *(FARPROC *)((_Ptd->_setloc_data)._cacheout + 0x1d)= pFVar1;
    pFVar1 = GetProcAddress(S7);
    *(FARPROC *)((_Ptd->_setloc_data)._cacheout + 0x1f)= pFVar1;
    *(undefined1 *)((_Ptd->_setloc_data)._cachein + 8)= 0x43;
    *(undefined1 *)((int)(_Ptd->_setloc_data)._cachein + 0x93)= 0x43;
    _Ptd->ptmbcinfo =(pthreadmbcinfo)&DAT_10020280;
    __lock(0xd);
    InterlockedIncrement();
    FUN_10009e2d();
    __lock(0xc);
    if(_Locale ==(pthreadlocinfo)0x0){
    _Ptd->ptlocinfo =(pthreadlocinfo)PTR_DAT_10020888;
    ___addlocaleref();
    FUN_10009e36();
    return;

f FUN_10009e2d(0):
  c:FUN_1000d764
  k:0xd
  cf:
    FUN_1000d764(0xd);
    return;

f FUN_10009e36(0):
  c:FUN_1000d764
  k:0xc
  cf:
    FUN_1000d764(0xc);
    return;

f __getptd_noexit(0):
  c:GetLastError,___set_flsgetvalue,__calloc_crt,__decode_pointer,_free,__initptd,GetCurrentThreadId,SetLastError
  g:DAT_10021498
  k:0x0,0x214
  cf:
    dwErrCode = GetLastError();
    pcVar1 =(code *)___set_flsgetvalue();
    _Ptd =(_ptiddata)(*pcVar1)(uVar4);
    if(_Ptd ==(_ptiddata)0x0){
    _Ptd =(_ptiddata)__calloc_crt(0x214);
    if(_Ptd !=(_ptiddata)0x0){
    pcVar1 =(code *)__decode_pointer(DAT_10021498);
    iVar2 =(*pcVar1)(uVar4,p_Var5);
    if(iVar2 == 0){
    _free();
    _Ptd =(_ptiddata)0x0;
    else{
    __initptd(0x0);
    DVar3 = GetCurrentThreadId();
    SetLastError();
    return _Ptd;

f __getptd(0):
  c:__getptd_noexit,__amsg_exit
  k:0x0,0x10
  cf:
    p_Var1 = __getptd_noexit();
    if(p_Var1 ==(_ptiddata)0x0){
    __amsg_exit(0x10);
    return p_Var1;

f __freefls_4(1):
  c:_free,__lock,InterlockedDecrement,FUN_10009fec,___removelocaleref,___freetlocinfo,FUN_10009ff8
  g:LONG,DAT_10020280,PTR_DAT_10020888
  k:0x0,0x24,0x2c,0x34,0x3c,0x40,0x44,0x48,0x5c,0xd,0x68,0xc,0x6c
  cf:
    if(param_1 !=(void *)0x0){
    if(*(void **)((int)param_1 + 0x24)!=(void *)0x0){
    _free(0x24);
    if(*(void **)((int)param_1 + 0x2c)!=(void *)0x0){
    _free(0x2c);
    if(*(void **)((int)param_1 + 0x34)!=(void *)0x0){
    _free(0x34);
    if(*(void **)((int)param_1 + 0x3c)!=(void *)0x0){
    _free(0x3c);
    if(*(void **)((int)param_1 + 0x40)!=(void *)0x0){
    _free(0x40);
    if(*(void **)((int)param_1 + 0x44)!=(void *)0x0){
    _free(0x44);
    if(*(void **)((int)param_1 + 0x48)!=(void *)0x0){
    _free(0x48);
    if(*(undefined **)((int)param_1 + 0x5c)!= &DAT_1001a998){
    _free(0x5c);
    __lock(0xd);
    pLVar1 = *(LONG **)((int)param_1 + 0x68);
    if(pLVar1 !=(LONG *)0x0){
    LVar2 = InterlockedDecrement();
    if((LVar2 == 0)&&(pLVar1 !=(LONG *)&DAT_10020280)){
    _free();
    FUN_10009fec();
    __lock(0xc);
    pLVar1 = *(LONG **)((int)param_1 + 0x6c);
    if(pLVar1 !=(LONG *)0x0){
    ___removelocaleref();
    if(((pLVar1 !=(LONG *)PTR_DAT_10020888)&&(pLVar1 !=(LONG *)&DAT_100207b0))&&
    ___freetlocinfo();
    FUN_10009ff8();
    _free();
    return;

f FUN_10009fec(0):
  c:FUN_1000d764
  k:0xd
  cf:
    FUN_1000d764(0xd);
    return;

f FUN_10009ff8(0):
  c:FUN_1000d764
  k:0xc
  cf:
    FUN_1000d764(0xc);
    return;

f __freeptd(1):
  c:TlsGetValue,__decode_pointer,__freefls_4,TlsSetValue
  g:LPVOID,DAT_10021498
  k:0x0,0xffffffff
  cf:
    if(DAT_100201b0 != -1){
    if((_Ptd ==(_ptiddata)0x0)&&(pvVar1 = TlsGetValue(DAT_100201b4),pvVar1 !=(LPVOID)0x0)){
    pcVar2 =(code *)TlsGetValue();
    _Ptd =(_ptiddata)(*pcVar2)(iVar3);
    pcVar2 =(code *)__decode_pointer(DAT_10021498);
    (*pcVar2)(iVar3,uVar4);
    __freefls_4();
    if(DAT_100201b4 != 0xffffffff){
    TlsSetValue(0x0);
    return;

f __mtinit(0):
  c:GetModuleHandleW,__crt_waiting_on_module_handle,GetProcAddress,TlsAlloc,TlsSetValue,__init_pointers,__encode_pointer,__mtinitlocks,__decode_pointer,__calloc_crt,__initptd,GetCurrentThreadId,__mtterm
  g:LS5,HMODULE,DAT_10021490,DAT_10021494,DAT_10021498,S10,S11,FARPROC
  k:0x0,0xffffffff,0x214
  cf:
    hModule = GetModuleHandleW(LS5);
    if(hModule ==(HMODULE)0x0){
    hModule =(HMODULE)__crt_waiting_on_module_handle(LS5);
    if(hModule !=(HMODULE)0x0){
    DAT_10021490 = GetProcAddress(S8);
    DAT_10021494 = GetProcAddress(S9);
    DAT_10021498 = GetProcAddress(S10);
    DAT_1002149c = GetProcAddress(S11);
    if((((DAT_10021490 ==(FARPROC)0x0)||(DAT_10021494 ==(FARPROC)0x0))||
    DAT_10021490 =(FARPROC)&LAB_10009ca1;
    DAT_100201b4 = TlsAlloc();
    if(DAT_100201b4 == 0xffffffff){
    return 0;
    BVar1 = TlsSetValue(DAT_10021494);
    if(BVar1 == 0){
    return 0;
    __init_pointers();
    DAT_10021490 =(FARPROC)__encode_pointer();
    DAT_10021494 =(FARPROC)__encode_pointer();
    DAT_10021498 =(FARPROC)__encode_pointer();
    DAT_1002149c =(FARPROC)__encode_pointer();
    iVar2 = __mtinitlocks();
    if(iVar2 != 0){
    pcVar3 =(code *)__decode_pointer();
    DAT_100201b0 =(*pcVar3)(pcVar5);
    if((DAT_100201b0 != -1)&&(_Ptd =(_ptiddata)__calloc_crt(1,0x214),_Ptd !=(_ptiddata)0x0))
    pcVar3 =(code *)__decode_pointer();
    iVar2 =(*pcVar3)(iVar2,p_Var6);
    if(iVar2 != 0){
    __initptd(0x0);
    DVar4 = GetCurrentThreadId();
    return 1;
    __mtterm();
    return 0;

f FUN_1000a2e2(0):
  cf:
    return 1;

f __get_sse2_info(0):
  c:cpuid_basic_info,cpuid_Version_info,FUN_1000a2e2
  k:0x4000,0x200,0x4000000
  cf:
    if(((uint)((uVar1 & 0x4000)!= 0)* 0x4000 |(uint)((uVar1 & 0x200)!= 0)* 0x200 |
    cpuid_basic_info();
    iVar2 = cpuid_Version_info();
    local_8 = *(uint *)(iVar2 + 8);
    if(((local_8 & 0x4000000)== 0)||(iVar2 = FUN_1000a2e2(),iVar2 == 0)){
    else{
    return uVar3;

f _abort(0):
  c:__NMSG_WRITE,___get_sigabrt,_raise,_memset,SetUnhandledExceptionFilter,UnhandledExceptionFilter,__exit
  g:PCONTEXT
  k:0x0,0x16,0x50
  cf:
    if(((byte)DAT_100201b8 & 1)!= 0){
    __NMSG_WRITE();
    p_Var1 = ___get_sigabrt();
    if(p_Var1 !=(_PHNDLR)0x0){
    _raise(0x16);
    if(((byte)DAT_100201b8 & 2)!= 0){
    _memset(0x50);
    local_2dc.ContextRecord =(PCONTEXT)&local_2d4;
    SetUnhandledExceptionFilter(0x0);
    UnhandledExceptionFilter();
    __exit();

f __set_abort_behavior(2):
  cf:
    return uVar1;

f __NMSG_WRITE(1):
  c:__set_error_mode,_strcpy_s,__invoke_watson,GetModuleFileNameA,_strlen,_strcat_s,___crtMessageBoxA,GetStdHandle,WriteFile
  g:DAT_10021164,S12,S14,S15,S16,HANDLE,LPOVERLAPPED
  k:0x17,0xfc,0x314,0x0,0x104,0x3c,0x1002147e,0x100201c4,0x12010,0xfffffff4,0xffffffff
  cf:
    do{
    if(param_1 ==(&DAT_100201c0)[local_8 * 2])break;
    }while(local_8 < 0x17);
    if(local_8 < 0x17){
    iVar3 = __set_error_mode();
    if((iVar3 != 1)&&((iVar3 = __set_error_mode(3),iVar3 != 0 ||(DAT_10021164 != 1)))){
    if(param_1 == 0xfc){
    return;
    eVar4 = _strcpy_s(0x314,S12);
    if(eVar4 != 0){
    __invoke_watson(0x0,0x0,0x0);
    DVar5 = GetModuleFileNameA(0x0,0x104);
    if((DVar5 == 0)&&
    __invoke_watson(0x0,0x0,0x0);
    sVar6 = _strlen();
    if(0x3c < sVar6 + 1){
    sVar6 = _strlen();
    (int)&DAT_100217b4 -(int)(sVar6 + 0x1002147e),S14,3);
    if(eVar4 != 0){
    __invoke_watson(0x0,0x0,0x0);
    eVar4 = _strcat_s(0x314,S15);
    if(eVar4 == 0){
    eVar4 = _strcat_s(0x314,0x100201c4);
    if(eVar4 == 0){
    ___crtMessageBoxA(S16,0x12010);
    return;
    __invoke_watson(0x0,0x0,0x0);
    hFile = GetStdHandle(0xfffffff4);
    if((hFile !=(HANDLE)0x0)&&(hFile !=(HANDLE)0xffffffff)){
    lpOverlapped =(LPOVERLAPPED)0x0;
    puVar1 =(undefined4 *)(uVar2 * 8 + 0x100201c4);
    sVar6 = _strlen();
    WriteFile();
    return;

f __FF_MSGBANNER(0):
  c:__set_error_mode,__NMSG_WRITE
  g:DAT_10021164
  k:0xfc,0xff
  cf:
    iVar1 = __set_error_mode();
    if(iVar1 != 1){
    iVar1 = __set_error_mode();
    if(iVar1 != 0){
    return;
    if(DAT_10021164 != 1){
    return;
    __NMSG_WRITE(0xfc);
    __NMSG_WRITE(0xff);
    return;

f FUN_1000a6bd(1):
  cf:
    return;

f FUN_1000a733(0):
  c:FUN_1000d764
  k:0xe
  cf:
    FUN_1000d764(0xe);
    return;

f _strcmp(2):
  k:0x10,0x18
  cf:
    if(((uint)_Str1 & 3)!= 0){
    if(((uint)_Str1 & 1)!= 0){
    bVar5 = bVar4 <(byte)*_Str2;
    if(bVar4 != *_Str2)goto LAB_1000a784;
    if(bVar4 == 0){
    return 0;
    if(((uint)_Str1 & 2)== 0)goto LAB_1000a750;
    uVar1 = *(undefined2 *)_Str1;
    bVar4 =(byte)uVar1;
    bVar5 = bVar4 <(byte)*_Str2;
    if(bVar4 != *_Str2)goto LAB_1000a784;
    if(bVar4 == 0){
    return 0;
    bVar4 =(byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 <((byte *)_Str2)[1];
    if(bVar4 !=((byte *)_Str2)[1])goto LAB_1000a784;
    if(bVar4 == 0){
    return 0;
    _Str2 =(char *)((byte *)_Str2 + 2);
    while(true){
    uVar2 = *(undefined4 *)_Str1;
    bVar4 =(byte)uVar2;
    bVar5 = bVar4 <(byte)*_Str2;
    if(bVar4 != *_Str2)break;
    if(bVar4 == 0){
    return 0;
    bVar4 =(byte)((uint)uVar2 >> 8);
    bVar5 = bVar4 <((byte *)_Str2)[1];
    if(bVar4 !=((byte *)_Str2)[1])break;
    if(bVar4 == 0){
    return 0;
    bVar4 =(byte)((uint)uVar2 >> 0x10);
    bVar5 = bVar4 <((byte *)_Str2)[2];
    if(bVar4 !=((byte *)_Str2)[2])break;
    bVar3 =(byte)((uint)uVar2 >> 0x18);
    if(bVar4 == 0){
    return 0;
    bVar5 = bVar3 <((byte *)_Str2)[3];
    if(bVar3 !=((byte *)_Str2)[3])break;
    _Str2 =(char *)((byte *)_Str2 + 4);
    if(bVar3 == 0){
    return 0;
    return(uint)bVar5 * -2 + 1;

f FUN_1000a7c8(1):
  cf:
    return;

f __callnewh(1):
  c:__decode_pointer
  k:0x0
  cf:
    pcVar1 =(code *)__decode_pointer();
    if(pcVar1 !=(code *)0x0){
    iVar2 =(*pcVar1)(_Size);
    if(iVar2 != 0){
    return 1;
    return 0;

f __CxxThrowException_8(2):
  c:RaiseException
  k:0x0
  cf:
    for(iVar1 = 8;iVar1 != 0;iVar1 = iVar1 + -1){
    if((param_2 !=(byte *)0x0)&&((*param_2 & 8)!= 0)){
    RaiseException();
    return;

f FUN_1000a84b(3):
  cf:
    do{
    }while(uVar16 != 0);
    return;

f __VEC_memcpy(3):
  c:FUN_1000a84b,elif
  k:0x1f,0xf
  cf:
    uVar3 =(int)param_2 >> 0x1f;
    iVar1 =(((uint)param_2 ^ uVar3)- uVar3 & 0xf ^ uVar3)- uVar3;
    uVar3 =(int)param_1 >> 0x1f;
    uVar6 =((uint)param_1 ^ uVar3)- uVar3 & 0xf ^ uVar3;
    if(iVar1 == 0 && uVar6 == uVar3){
    if(param_3 != uVar3){
    FUN_1000a84b();
    if(uVar3 != 0){
    puVar4 =(undefined1 *)((int)param_2 +(param_3 - uVar3));
    puVar7 =(undefined1 *)((int)param_1 +(param_3 - uVar3));
    for(;uVar3 != 0;uVar3 = uVar3 - 1){
    elif(iVar1 == uVar6 - uVar3){
    for(iVar2 = iVar1;iVar2 != 0;iVar2 = iVar2 + -1){
    *(undefined1 *)puVar8 = *(undefined1 *)puVar5;
    puVar5 =(undefined4 *)((int)puVar5 + 1);
    puVar8 =(undefined4 *)((int)puVar8 + 1);
    else{
    for(uVar3 = param_3 >> 2;uVar3 != 0;uVar3 = uVar3 - 1){
    for(uVar3 = param_3 & 3;uVar3 != 0;uVar3 = uVar3 - 1){
    *(undefined1 *)puVar5 = *(undefined1 *)param_2;
    param_2 =(undefined4 *)((int)param_2 + 1);
    puVar5 =(undefined4 *)((int)puVar5 + 1);
    return param_1;

f if(1):
  cf:
    for(iVar2 = iVar1;iVar2 != 0;iVar2 = iVar2 + -1){
    *(undefined1 *)puVar8 = *(undefined1 *)puVar5;
    puVar5 =(undefined4 *)((int)puVar5 + 1);
    puVar8 =(undefined4 *)((int)puVar8 + 1);

f CPtoLCID(1):
  k:0x3a4,0x411,0x3a8,0x804,0x3b5,0x412,0x3b6,0x404
  cf:
    if(in_EAX == 0x3a4){
    return 0x411;
    if(in_EAX == 0x3a8){
    return 0x804;
    if(in_EAX == 0x3b5){
    return 0x412;
    if(in_EAX != 0x3b6){
    return 0;
    return 0x404;

f setSBCS(1):
  c:_memset
  g:DAT_10020280
  k:0x1c,0x101,0xc,0x10,0x14,0x18,0x11d
  cf:
    _memset(0x1c,0x101);
    *(undefined4 *)(in_EAX + 4)= 0;
    *(undefined4 *)(in_EAX + 8)= 0;
    *(undefined4 *)(in_EAX + 0xc)= 0;
    *(undefined4 *)(in_EAX + 0x10)= 0;
    *(undefined4 *)(in_EAX + 0x14)= 0;
    *(undefined4 *)(in_EAX + 0x18)= 0;
    puVar1 =(undefined1 *)(in_EAX + 0x1c);
    do{
    *puVar1 = puVar1[(int)&DAT_10020280 - in_EAX];
    }while(iVar2 != 0);
    puVar1 =(undefined1 *)(in_EAX + 0x11d);
    do{
    *puVar1 = puVar1[(int)&DAT_10020280 - in_EAX];
    }while(iVar2 != 0);
    return;

f setSBUpLow(1):
  c:GetCPInfo,_memset,__security_check_cookie
  g:DAT_10020030,CHAR,BOOL
  k:0xfffffffc,0x11d,0x61,0x20,0x1a,0x1d,0x100,0xc
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    BVar3 = GetCPInfo();
    if(BVar3 == 0){
    do{
    pcVar2 =(char *)(unaff_ESI + 0x11d + uVar4);
    if(pcVar2 +(-0x61 -(unaff_ESI + 0x11d))+ 0x20 <(char *)0x1a){
    pbVar1 =(byte *)(unaff_ESI + 0x1d + uVar4);
    cVar6 =(char)uVar4 + ' ';
    else{
    if(pcVar2 +(-0x61 -(unaff_ESI + 0x11d))<(char *)0x1a){
    pbVar1 =(byte *)(unaff_ESI + 0x1d + uVar4);
    cVar6 =(char)uVar4 + -0x20;
    goto LAB_1000abc1;
    }while(uVar4 < 0x100);
    else{
    do{
    local_108[uVar4] =(CHAR)uVar4;
    }while(uVar4 < 0x100);
    if(local_51c.LeadByte[0] != 0){
    do{
    uVar4 =(uint)local_51c.LeadByte[0];
    if(uVar4 <= *pBVar7){
    _memset(0x20);
    }while(local_51c.LeadByte[0] != 0);
    *(BOOL *)(unaff_ESI + 0xc));
    0x100,*(int *)(unaff_ESI + 4),0);
    do{
    if((local_508[uVar4] & 1)== 0){
    if((local_508[uVar4] & 2)!= 0){
    pbVar1 =(byte *)(unaff_ESI + 0x1d + uVar4);
    goto LAB_1000ab5f;
    *(undefined1 *)(unaff_ESI + 0x11d + uVar4)= 0;
    else{
    pbVar1 =(byte *)(unaff_ESI + 0x1d + uVar4);
    *(CHAR *)(unaff_ESI + 0x11d + uVar4)= CVar5;
    }while(uVar4 < 0x100);
    __security_check_cookie(0xfffffffc);
    return;

f ___updatetmbcinfo(0):
  c:__getptd,__lock,InterlockedDecrement,_free,InterlockedIncrement,FUN_1000ac76,__amsg_exit
  g:DAT_10020280
  k:0x0,0xd,0x20
  cf:
    p_Var1 = __getptd();
    if(((p_Var1->_ownlocale & DAT_100207a4)== 0)||(p_Var1->ptlocinfo ==(pthreadlocinfo)0x0)){
    __lock(0xd);
    if(lpAddend !=(pthreadmbcinfo)PTR_DAT_100206a8){
    if(lpAddend !=(pthreadmbcinfo)0x0){
    LVar2 = InterlockedDecrement();
    if((LVar2 == 0)&&(lpAddend !=(pthreadmbcinfo)&DAT_10020280)){
    _free();
    p_Var1->ptmbcinfo =(pthreadmbcinfo)PTR_DAT_100206a8;
    lpAddend =(pthreadmbcinfo)PTR_DAT_100206a8;
    InterlockedIncrement();
    FUN_1000ac76();
    else{
    if(lpAddend ==(pthreadmbcinfo)0x0){
    __amsg_exit(0x20);
    return lpAddend;

f FUN_1000ac76(0):
  c:FUN_1000d764
  k:0xd
  cf:
    FUN_1000d764(0xd);
    return;

f getSystemCP(1):
  c:_LocaleUpdate,GetOEMCP,elif,GetACP
  g:UINT
  k:0x0,0x70,0xfffffffd
  cf:
    _LocaleUpdate::_LocaleUpdate(0x0);
    if(unaff_ESI == -2){
    UVar1 = GetOEMCP();
    elif(unaff_ESI == -3){
    UVar1 = GetACP();
    else{
    if(unaff_ESI != -4){
    if(local_8 == '\0'){
    return unaff_ESI;
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    return unaff_ESI;
    UVar1 = *(UINT *)(local_14[0] + 4);
    if(local_8 != '\0'){
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    return UVar1;

f if(1):
  c:GetACP
  cf:
    UVar1 = GetACP();

f __setmbcp_nolock(2):
  c:getSystemCP,_memset,CPtoLCID,setSBCS,__security_check_cookie,IsValidCodePage,GetCPInfo,setSBUpLow
  g:DAT_10020030
  k:0xfffffffc,0x0,0x1000ad45,0x1c,0x101,0x30,0x1d,0x100206ac,0xc,0x10,0xef,0x1000ad52,0xfde9,0xffff,0x1e,0x14,0x18,65000
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    uVar4 = getSystemCP();
    if(uVar4 != 0){
    local_20 =(byte *)0x0;
    if(*(uint *)((int)&DAT_100206b0 + uVar5)!= uVar4)goto code_r0x1000ad45;
    _memset(0x1c,0x101);
    pbVar8 = &DAT_100206c0 +(int)local_20 * 0x30;
    do{
    for(;(*pbVar8 != 0 &&(bVar3 = pbVar8[1],bVar3 != 0));pbVar8 = pbVar8 + 2){
    for(uVar5 =(uint)*pbVar8;uVar5 <= bVar3;uVar5 = uVar5 + 1){
    pbVar2 =(byte *)(param_2 + 0x1d + uVar5);
    *pbVar2 = *pbVar2 | *(byte *)(local_24 + 0x100206ac);
    }while(local_24 < 4);
    *(uint *)(param_2 + 4)= uVar4;
    *(undefined4 *)(param_2 + 8)= 1;
    iVar10 = CPtoLCID();
    *(int *)(param_2 + 0xc)= iVar10;
    puVar7 =(undefined2 *)(param_2 + 0x10);
    puVar9 =(undefined2 *)(&DAT_100206b4 + extraout_ECX);
    do{
    }while(iVar10 != 0);
    goto LAB_1000ae6a;
    setSBCS();
    __security_check_cookie(0xfffffffc);
    return;
    local_20 =(byte *)((int)local_20 + 1);
    if(0xef < uVar5)goto code_r0x1000ad52;
    goto LAB_1000ad39;
    if(((uVar4 == 65000)||(uVar4 == 0xfde9))||
    (BVar6 = IsValidCodePage(0xffff),BVar6 == 0))goto LAB_1000aed1;
    BVar6 = GetCPInfo();
    if(BVar6 != 0){
    _memset(0x1c,0x101);
    *(uint *)(param_2 + 4)= uVar4;
    *(undefined4 *)(param_2 + 0xc)= 0;
    if(local_1c.MaxCharSize < 2){
    *(undefined4 *)(param_2 + 8)= 0;
    else{
    if(local_1c.LeadByte[0] != '\0'){
    do{
    if(bVar3 == 0)break;
    for(uVar4 =(uint)pBVar11[-1];uVar4 <= bVar3;uVar4 = uVar4 + 1){
    pbVar8 =(byte *)(param_2 + 0x1d + uVar4);
    }while(*pBVar1 != 0);
    pbVar8 =(byte *)(param_2 + 0x1e);
    do{
    }while(iVar10 != 0);
    iVar10 = CPtoLCID();
    *(int *)(param_2 + 0xc)= iVar10;
    *(undefined4 *)(param_2 + 8)= extraout_EDX;
    *(undefined4 *)(param_2 + 0x10)= 0;
    *(undefined4 *)(param_2 + 0x14)= 0;
    *(undefined4 *)(param_2 + 0x18)= 0;
    setSBUpLow();
    goto LAB_1000aed1;
    if(DAT_100217cc == 0)goto LAB_1000aed1;
    goto LAB_1000ad26;

f __setmbcp(1):
  c:__getptd,___updatetmbcinfo,getSystemCP,__malloc_crt,__setmbcp_nolock,InterlockedDecrement,_free,InterlockedIncrement,__lock,FUN_1000b041,elif,__errno
  g:DAT_10020280
  k:0x220,0x0,0x88,0xd,0x101,0x100
  cf:
    p_Var1 = __getptd();
    ___updatetmbcinfo();
    iVar2 = getSystemCP();
    if(iVar2 == ptVar3->mbcodepage){
    else{
    ptVar3 =(pthreadmbcinfo)__malloc_crt(0x220);
    if(ptVar3 !=(pthreadmbcinfo)0x0){
    for(iVar6 = 0x88;iVar6 != 0;iVar6 = iVar6 + -1){
    ptVar7 =(pthreadmbcinfo)&ptVar7->mbcodepage;
    ptVar8 =(pthreadmbcinfo)&ptVar8->mbcodepage;
    local_24 = __setmbcp_nolock();
    if(local_24 == 0){
    LVar4 = InterlockedDecrement();
    if((LVar4 == 0)&&(p_Var1->ptmbcinfo !=(pthreadmbcinfo)&DAT_10020280)){
    _free();
    InterlockedIncrement();
    if(((p_Var1->_ownlocale & 2)== 0)&&(((byte)DAT_100207a4 & 1)== 0)){
    __lock(0xd);
    _DAT_100217e4 = *(undefined4 *)ptVar3->mbulinfo;
    for(iVar2 = 0;iVar2 < 5;iVar2 = iVar2 + 1){
    (&DAT_100217d0)[iVar2] = ptVar3->mbulinfo[iVar2 + 2];
    for(iVar2 = 0;iVar2 < 0x101;iVar2 = iVar2 + 1){
    (&DAT_100204a0)[iVar2] = ptVar3->mbctype[iVar2 + 4];
    for(iVar2 = 0;iVar2 < 0x100;iVar2 = iVar2 + 1){
    (&DAT_100205a8)[iVar2] = ptVar3->mbcasemap[iVar2 + 4];
    LVar4 = InterlockedDecrement();
    if((LVar4 == 0)&&(PTR_DAT_100206a8 != &DAT_10020280)){
    _free();
    PTR_DAT_100206a8 =(undefined *)ptVar3;
    InterlockedIncrement();
    FUN_1000b041();
    elif(local_24 == -1){
    if(ptVar3 !=(pthreadmbcinfo)&DAT_10020280){
    _free();
    piVar5 = __errno();
    return local_24;

f if(1):
  c:_free,__errno
  g:DAT_10020280
  cf:
    if(ptVar3 !=(pthreadmbcinfo)&DAT_10020280){
    _free();
    piVar5 = __errno();

f FUN_1000b041(0):
  c:FUN_1000d764
  k:0xd
  cf:
    FUN_1000d764(0xd);
    return;

f ___initmbctable(0):
  c:__setmbcp
  cf:
    if(DAT_10022d8c == 0){
    __setmbcp();
    return 0;

f ___freetlocinfo(1):
  c:_free,___free_lconv_mon,___free_lconv_num,___free_lc_time
  k:0xbc,0x0,0xb8,0xb4,0xb0,0xc0,0xc4,0xcc,0xd0,0xd4,0x2d,0x50,0x6
  cf:
    if((((*(undefined ***)((int)param_1 + 0xbc)!=(undefined **)0x0)&&
    piVar1 = *(int **)((int)param_1 + 0xb8);
    if((piVar1 !=(int *)0x0)&&(*piVar1 == 0)){
    _free();
    ___free_lconv_mon(0xbc);
    piVar1 = *(int **)((int)param_1 + 0xb4);
    if((piVar1 !=(int *)0x0)&&(*piVar1 == 0)){
    _free();
    ___free_lconv_num(0xbc);
    _free(0xb0);
    _free(0xbc);
    if((*(int **)((int)param_1 + 0xc0)!=(int *)0x0)&&(**(int **)((int)param_1 + 0xc0)== 0)){
    _free(0xc4);
    _free(0xcc);
    _free(0xd0);
    _free(0xc0);
    ppuVar2 = *(undefined ***)((int)param_1 + 0xd4);
    if((ppuVar2 != &PTR_DAT_10020a28)&&(ppuVar2[0x2d] ==(undefined *)0x0)){
    ___free_lc_time();
    _free(0xd4);
    puVar3 =(undefined4 *)((int)param_1 + 0x50);
    param_1 =(void *)0x6;
    do{
    if((((undefined *)puVar3[-2] != &DAT_100207a8)&&
    _free();
    if(((puVar3[-1] != 0)&&(piVar1 =(int *)puVar3[1],piVar1 !=(int *)0x0))&&(*piVar1 == 0))
    _free();
    param_1 =(void *)((int)param_1 + -1);
    }while(param_1 !=(void *)0x0);
    _free();
    return;

f ___addlocaleref(1):
  c:InterlockedIncrement
  k:0x2c,0x0,0x2e,0x2d,0x30,0x6,0x35
  cf:
    InterlockedIncrement();
    if((LONG *)param_1[0x2c] !=(LONG *)0x0){
    InterlockedIncrement(0x2c);
    if((LONG *)param_1[0x2e] !=(LONG *)0x0){
    InterlockedIncrement(0x2e);
    if((LONG *)param_1[0x2d] !=(LONG *)0x0){
    InterlockedIncrement(0x2d);
    if((LONG *)param_1[0x30] !=(LONG *)0x0){
    InterlockedIncrement(0x30);
    param_1 =(LONG *)0x6;
    do{
    if(((undefined *)pLVar2[-2] != &DAT_100207a8)&&((LONG *)*pLVar2 !=(LONG *)0x0)){
    InterlockedIncrement();
    if((pLVar2[-1] != 0)&&((LONG *)pLVar2[1] !=(LONG *)0x0)){
    InterlockedIncrement();
    param_1 =(LONG *)((int)param_1 + -1);
    }while(param_1 !=(LONG *)0x0);
    InterlockedIncrement(0x35);
    return;

f ___removelocaleref(1):
  c:InterlockedDecrement
  k:0x0,0x2c,0x2e,0x2d,0x30,0x6,0x35
  cf:
    if(param_1 !=(LONG *)0x0){
    InterlockedDecrement();
    if((LONG *)param_1[0x2c] !=(LONG *)0x0){
    InterlockedDecrement(0x2c);
    if((LONG *)param_1[0x2e] !=(LONG *)0x0){
    InterlockedDecrement(0x2e);
    if((LONG *)param_1[0x2d] !=(LONG *)0x0){
    InterlockedDecrement(0x2d);
    if((LONG *)param_1[0x30] !=(LONG *)0x0){
    InterlockedDecrement(0x30);
    param_1 =(LONG *)0x6;
    do{
    if(((undefined *)pLVar2[-2] != &DAT_100207a8)&&((LONG *)*pLVar2 !=(LONG *)0x0)){
    InterlockedDecrement();
    if((pLVar2[-1] != 0)&&((LONG *)pLVar2[1] !=(LONG *)0x0)){
    InterlockedDecrement();
    param_1 =(LONG *)((int)param_1 + -1);
    }while(param_1 !=(LONG *)0x0);
    InterlockedDecrement(0x35);
    return pLVar1;

f __updatetlocinfoEx_nolock(0):
  c:___addlocaleref,___removelocaleref,___freetlocinfo
  g:LONG
  k:0x0
  cf:
    if((unaff_EDI !=(LONG *)0x0)&&(in_EAX !=(undefined4 *)0x0)){
    pLVar1 =(LONG *)*in_EAX;
    if(pLVar1 != unaff_EDI){
    ___addlocaleref();
    if(pLVar1 !=(LONG *)0x0){
    ___removelocaleref();
    if((*pLVar1 == 0)&&(pLVar1 !=(LONG *)&DAT_100207b0)){
    ___freetlocinfo();
    return unaff_EDI;
    return(LONG *)0x0;

f ___updatetlocinfo(0):
  c:__getptd,__lock,__updatetlocinfoEx_nolock,FUN_1000b3b1,__amsg_exit
  k:0x0,0xc,0x20
  cf:
    p_Var1 = __getptd();
    if(((p_Var1->_ownlocale & DAT_100207a4)== 0)||(p_Var1->ptlocinfo ==(pthreadlocinfo)0x0)){
    __lock(0xc);
    __updatetlocinfoEx_nolock();
    FUN_1000b3b1();
    else{
    p_Var1 = __getptd();
    p_Var1 =(_ptiddata)p_Var1->ptlocinfo;
    if(p_Var1 ==(_ptiddata)0x0){
    __amsg_exit(0x20);
    return(pthreadlocinfo)p_Var1;

f FUN_1000b3b1(0):
  c:FUN_1000d764
  k:0xc
  cf:
    FUN_1000d764(0xc);
    return;

f __freea(1):
  c:_free
  k:0x0,0xdddd
  cf:
    if((_Memory !=(void *)0x0)&&(*(int *)((int)_Memory + -8)== 0xdddd)){
    _free();
    return;

f __crtLCMapStringA_stat(9):
  c:LCMapStringW,GetLastError,___ansicp,LCMapStringA,___convertcp,elif,_malloc,_memset,__freea,_free,MultiByteToWideChar,__security_check_cookie
  g:DAT_10020030,LS17,LPCWSTR,LPWSTR,LPSTR,LPCSTR,LPBOOL
  k:0xfffffffc,0x100,0x0,0x78,0xffffffff,0x14,0xffffffe0,0x401,0x00000000,0x24,0xffffffdc,0x400,0xffffffe4
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if(DAT_1002180c == 0){
    iVar3 = LCMapStringW(0x100,LS17,0x0);
    if(iVar3 == 0){
    DVar4 = GetLastError();
    if(DVar4 == 0x78){
    else{
    pcVar5 =(char *)param_3;
    if(0 <(int)param_4){
    do{
    if(*pcVar5 == '\0')goto LAB_1000b44e;
    }while(pcVar8 !=(char *)0x0);
    pcVar8 =(char *)0xffffffff;
    pcVar5 = param_4 + -(int)pcVar8;
    bVar2 =(int)(pcVar5 + -1)<(int)param_4;
    if(bVar2){
    if((DAT_1002180c == 2)||(DAT_1002180c == 0)){
    local_10 =(LPCWSTR)0x0;
    local_14 =(void *)0x0;
    if(param_1 ==(localeinfo_struct *)0x0){
    param_1 = *(localeinfo_struct **)(*in_ECX + 0x14);
    if(param_7 == 0){
    param_7 = *(int *)(*in_ECX + 4);
    UVar7 = ___ansicp();
    if(UVar7 == 0xffffffff)goto LAB_1000b770;
    if(UVar7 == param_7){
    LCMapStringA();
    else{
    local_10 =(LPCWSTR)___convertcp(0x0);
    if(local_10 ==(LPCWSTR)0x0)goto LAB_1000b770;
    local_c = LCMapStringA(0x0);
    if(local_c != 0){
    if(((int)local_c < 1)||(0xffffffe0 < local_c)){
    pcVar5 =(char *)0x0;
    elif(local_c + 8 < 0x401){
    if(&stack0x00000000 ==(undefined1 *)0x24)goto LAB_1000b74d;
    else{
    pcVar5 =(char *)_malloc();
    if(pcVar5 !=(char *)0x0){
    _memset();
    if(local_c != 0){
    (int)param_6);
    __freea();
    if(local_10 !=(LPCWSTR)0x0){
    _free();
    if((local_14 !=(void *)0x0)&&((void *)param_5 != local_14)){
    _free();
    goto LAB_1000b770;
    if(DAT_1002180c != 1)goto LAB_1000b770;
    if(param_7 == 0){
    param_7 = *(int *)(*in_ECX + 4);
    (int)param_4,(LPWSTR)0x0,0);
    if(cchWideChar == 0)goto LAB_1000b770;
    if(((int)cchWideChar < 1)||(0xffffffe0 / cchWideChar < 2)){
    local_10 =(LPCWSTR)0x0;
    else{
    if(uVar1 < 0x401){
    pWVar6 =(LPCWSTR)&stack0xffffffdc;
    local_10 =(LPCWSTR)&stack0xffffffdc;
    if(&stack0x00000000 !=(undefined1 *)0x24){
    else{
    pWVar6 =(LPCWSTR)_malloc();
    if(pWVar6 !=(LPCWSTR)0x0){
    goto LAB_1000b4f6;
    if(local_10 ==(LPCWSTR)0x0)goto LAB_1000b770;
    iVar3 = MultiByteToWideChar();
    if((iVar3 != 0)&&
    if((param_2 & 0x400)== 0){
    if(((int)local_c < 1)||(0xffffffe0 / local_c < 2)){
    pWVar6 =(LPCWSTR)0x0;
    else{
    if(uVar1 < 0x401){
    if(&stack0x00000000 ==(undefined1 *)0x24)goto LAB_1000b606;
    pWVar6 =(LPCWSTR)&stack0xffffffe4;
    else{
    pWVar6 =(LPCWSTR)_malloc();
    if(pWVar6 !=(LPCWSTR)0x0){
    iVar3 = LCMapStringW();
    if(iVar3 != 0){
    lpMultiByteStr =(LPSTR)param_5;
    if(param_6 ==(char *)0x0){
    lpMultiByteStr =(LPSTR)0x0;
    pcVar5 =(char *)0x0;
    (LPCSTR)0x0,(LPBOOL)0x0);
    __freea();
    elif((param_6 !=(char *)0x0)&&((int)local_c <=(int)param_6)){
    LCMapStringW();
    __freea();
    iVar3 = __security_check_cookie(0xfffffffc);
    return iVar3;

f if(1):
  k:0x00000000,0x24
  cf:
    if(&stack0x00000000 ==(undefined1 *)0x24)goto LAB_1000b74d;

f ___crtLCMapStringA(9):
  c:_LocaleUpdate
  k:0xffffffec,0x70,0xfffffffd
  cf:
    _LocaleUpdate::_LocaleUpdate(0xffffffec);
    (int)_LpDestStr,(char *)_CchDest,_Code_page,_BError,in_stack_ffffffec);
    if(local_8 != '\0'){
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    return iVar1;

f ___ascii_stricmp(2):
  k:0x41,0x1a
  cf:
    do{
    uVar1 =(uint)(byte)*_Str1;
    _Str1 =(char *)((byte *)_Str1 + 1);
    if(uVar1 - 0x41 < 0x1a){
    uVar2 =(uint)(byte)*_Str2;
    _Str2 =(char *)((byte *)_Str2 + 1);
    if(uVar2 - 0x41 < 0x1a){
    }while((uVar1 != 0)&&(uVar1 == uVar2));
    return uVar1 - uVar2;

f __stricmp_l(3):
  c:_LocaleUpdate,__errno,__invalid_parameter,elif,___ascii_stricmp,__tolower_l
  k:0x0,0x70,0xfffffffd
  cf:
    _LocaleUpdate::_LocaleUpdate();
    if(_Str1 ==(char *)0x0){
    piVar1 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    if(local_8 != '\0'){
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    elif(_Str2 ==(char *)0x0){
    piVar1 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    if(local_8 != '\0'){
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    else{
    if((local_14.locinfo)->lc_category[0].wlocale ==(wchar_t *)0x0){
    iVar2 = ___ascii_stricmp();
    else{
    do{
    iVar2 = __tolower_l();
    iVar3 = __tolower_l();
    _Str2 =(char *)((byte *)_Str2 + 1);
    if(iVar2 == 0)break;
    }while(iVar2 == iVar3);
    if(local_8 != '\0'){
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    return iVar2;

f __stricmp(2):
  c:___ascii_stricmp,__errno,__invalid_parameter,__stricmp_l
  k:0x0
  cf:
    if(DAT_100217e8 == 0){
    if((_Str1 !=(char *)0x0)&&(_Str2 !=(char *)0x0)){
    iVar2 = ___ascii_stricmp();
    return iVar2;
    piVar1 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    else{
    iVar2 = __stricmp_l(0x0);
    return iVar2;

f __malloc_crt(1):
  c:_malloc,Sleep
  g:DAT_10021810
  k:0x0,0xffffffff
  cf:
    while(true){
    pvVar1 = _malloc();
    if(pvVar1 !=(void *)0x0){
    return pvVar1;
    if(DAT_10021810 == 0)break;
    Sleep();
    if(DAT_10021810 < dwMilliseconds){
    if(dwMilliseconds == 0xffffffff){
    return(void *)0x0;

f __calloc_crt(2):
  c:__calloc_impl,Sleep
  g:DAT_10021810
  k:0x0,0xffffffff
  cf:
    while(true){
    piVar1 = __calloc_impl(0x0);
    if(piVar1 !=(int *)0x0){
    return piVar1;
    if(DAT_10021810 == 0)break;
    Sleep();
    if(DAT_10021810 < dwMilliseconds){
    if(dwMilliseconds == 0xffffffff){
    return(void *)0x0;

f __realloc_crt(2):
  c:_realloc,Sleep
  g:DAT_10021810
  k:0x0,0xffffffff
  cf:
    do{
    pvVar1 = _realloc();
    if(pvVar1 !=(void *)0x0){
    return pvVar1;
    if(_NewSize == 0){
    return(void *)0x0;
    if(DAT_10021810 == 0){
    return(void *)0x0;
    Sleep();
    if(DAT_10021810 < dwMilliseconds){
    }while(dwMilliseconds != 0xffffffff);
    return(void *)0x0;

f __msize(1):
  c:__errno,__invalid_parameter,__lock,___sbh_find_block,FUN_1000baa0,HeapSize
  g:DAT_10021954
  k:0x0
  cf:
    if(_Memory ==(void *)0x0){
    piVar1 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    else{
    if(DAT_10022c5c == 3){
    __lock();
    uVar3 = ___sbh_find_block();
    if(uVar3 != 0){
    local_20 = *(int *)((int)_Memory + -4)- 9;
    FUN_1000baa0();
    if(uVar3 != 0){
    return local_20;
    sVar2 = HeapSize(DAT_10021954);
    return sVar2;

f FUN_1000baa0(0):
  c:FUN_1000d764
  cf:
    FUN_1000d764();
    return;

f __crt_waiting_on_module_handle(1):
  c:Sleep,GetModuleHandleW
  g:HMODULE
  k:0x0,60000
  cf:
    do{
    Sleep();
    pHVar1 = GetModuleHandleW();
    if(60000 < dwMilliseconds){
    return;
    }while(pHVar1 ==(HMODULE)0x0);
    return;

f __amsg_exit(1):
  c:__FF_MSGBANNER,__NMSG_WRITE,__decode_pointer
  k:0xff
  cf:
    __FF_MSGBANNER();
    __NMSG_WRITE();
    pcVar1 =(code *)__decode_pointer();
    (*pcVar1)(0xff);
    return;

f ___crtCorExitProcess(1):
  c:GetModuleHandleW,GetProcAddress
  g:LS18,HMODULE,S19,FARPROC
  k:0x0
  cf:
    hModule = GetModuleHandleW(LS18);
    if(hModule !=(HMODULE)0x0){
    pFVar1 = GetProcAddress(S19);
    if(pFVar1 !=(FARPROC)0x0){
    (*pFVar1)(param_1);
    return;

f ___crtExitProcess(1):
  c:___crtCorExitProcess,ExitProcess
  cf:
    ___crtCorExitProcess();
    ExitProcess();

f FUN_1000bb45(0):
  c:__lock
  cf:
    __lock();
    return;

f FUN_1000bb4e(0):
  c:FUN_1000d764
  cf:
    FUN_1000d764();
    return;

f __initterm(1):
  k:0x0
  cf:
    for(;in_EAX < param_1;in_EAX = in_EAX + 1){
    if((code *)*in_EAX !=(code *)0x0){
    (*(code *)*in_EAX)();
    return;

f __initterm_e(2):
  k:0x0
  cf:
    while((param_1 < param_2 &&(iVar1 == 0))){
    if((code *)*param_1 !=(code *)0x0){
    iVar1 =(*(code *)*param_1)();
    return;

f __cinit(1):
  c:__IsNonwritableInCurrentImage,__initp_misc_cfltcvt_tab,__initterm_e,_atexit,__initterm
  k:0x0
  cf:
    if(DAT_10022d90 !=(code *)0x0){
    BVar1 = __IsNonwritableInCurrentImage();
    if(BVar1 != 0){
    (*DAT_10022d90)(param_1);
    __initp_misc_cfltcvt_tab();
    iVar2 = __initterm_e();
    if(iVar2 == 0){
    _atexit();
    __initterm();
    if(DAT_10022d94 !=(code *)0x0){
    BVar1 = __IsNonwritableInCurrentImage();
    if(BVar1 != 0){
    (*DAT_10022d94)(0,2,0);
    return iVar2;

f doexit(3):
  c:__lock,__decode_pointer,__encoded_null,__initterm,FUN_1000bd34,FUN_1000d764,___crtExitProcess
  g:DAT_10021844
  k:0x0
  cf:
    __lock();
    if(DAT_10021844 != 1){
    DAT_1002183c =(undefined1)param_3;
    if(param_2 == 0){
    piVar1 =(int *)__decode_pointer();
    if(piVar1 !=(int *)0x0){
    piVar2 =(int *)__decode_pointer();
    while(piVar2 = piVar2 + -1,piVar1 <= piVar2){
    iVar3 = __encoded_null();
    if(*piVar2 != iVar3){
    if(piVar2 < piVar1)break;
    pcVar4 =(code *)__decode_pointer();
    iVar3 = __encoded_null();
    (*pcVar4)();
    piVar5 =(int *)__decode_pointer();
    piVar6 =(int *)__decode_pointer();
    if((local_20 != piVar5)||(piVar1 = local_2c,local_24 != piVar6)){
    __initterm();
    FUN_1000bd34();
    if(param_3 == 0){
    FUN_1000d764();
    ___crtExitProcess();
    return;

f FUN_1000bd34(0):
  c:FUN_1000d764
  k:0x10
  cf:
    if(*(int *)(unaff_EBP + 0x10)!= 0){
    FUN_1000d764();
    return;

f __exit(1):
  c:doexit
  cf:
    doexit(_Code,1,0);
    return;

f __cexit(0):
  c:doexit
  cf:
    doexit(0,0,1);
    return;

f __init_pointers(0):
  c:__encoded_null,FUN_1000a7c8,FUN_1000f51a,FUN_1000818c,FUN_1000a6bd,FUN_1000f50b,__initp_misc_winsig,FUN_1000bf0d,__initp_eh_hooks,__encode_pointer
  k:0x1000bd49
  cf:
    uVar1 = __encoded_null();
    FUN_1000a7c8();
    FUN_1000f51a();
    FUN_1000818c();
    FUN_1000a6bd();
    FUN_1000f50b();
    __initp_misc_winsig();
    FUN_1000bf0d();
    __initp_eh_hooks();
    PTR___exit_10020898 =(undefined *)__encode_pointer(0x1000bd49);
    return;

f __ValidateImageBase(1):
  k:0x5a4d,0x3c,0x18,0x10b
  cf:
    if((*(short *)pImageBase == 0x5a4d)&&
    return(uint)((short)*(int *)((int)(pImageBase + *(int *)(pImageBase + 0x3c))+ 0x18)== 0x10b);
    return 0;

f __FindPESection(2):
  g:PIMAGE_SECTION_HEADER
  k:0x3c,0x14,0x18,0x0
  cf:
    iVar1 = *(int *)(pImageBase + 0x3c);
    (pImageBase + *(ushort *)(pImageBase + iVar1 + 0x14)+ 0x18 + iVar1);
    if(*(ushort *)(pImageBase + iVar1 + 6)!= 0){
    do{
    if((p_Var2->VirtualAddress <= rva)&&
    return p_Var2;
    }while(uVar3 < *(ushort *)(pImageBase + iVar1 + 6));
    return(PIMAGE_SECTION_HEADER)0x0;

f __IsNonwritableInCurrentImage(1):
  c:__ValidateImageBase,__FindPESection
  g:PIMAGE_SECTION_HEADER
  k:0x10000000,0x0,0x1f
  cf:
    BVar1 = __ValidateImageBase();
    if(BVar1 != 0){
    p_Var2 = __FindPESection(0x10000000);
    if(p_Var2 !=(PIMAGE_SECTION_HEADER)0x0){
    return ~(p_Var2->Characteristics >> 0x1f)& 1;
    return 0;

f FUN_1000bf0d(0):
  cf:
    return;

f __XcptFilter(2):
  c:__getptd_noexit,elif
  k:0x0,0x5,0x1,0xc000008e,0xc0000090,0xc0000091,0xc0000093,0xc000008d,0xc000008f,0xc0000092,0xffffffff
  cf:
    p_Var5 = __getptd_noexit();
    if(p_Var5 !=(_ptiddata)0x0){
    puVar1 =(ulong *)p_Var5->_pxcptacttab;
    do{
    if(*puVar6 == _ExceptionNum)break;
    }while(puVar6 < puVar1 + DAT_100208a8 * 3);
    if((puVar1 + DAT_100208a8 * 3 <= puVar6)||(*puVar6 != _ExceptionNum)){
    puVar6 =(ulong *)0x0;
    if((puVar6 ==(ulong *)0x0)||(pcVar2 =(code *)puVar6[2],pcVar2 ==(code *)0x0)){
    p_Var5 =(_ptiddata)0x0;
    elif(pcVar2 ==(code *)0x5){
    p_Var5 =(_ptiddata)0x1;
    else{
    if(pcVar2 !=(code *)0x1){
    if(puVar6[1] == 8){
    if(DAT_1002089c < DAT_100208a0 + DAT_1002089c){
    do{
    *(undefined4 *)(iVar7 + 8 +(int)p_Var5->_pxcptacttab)= 0;
    }while(iVar8 < DAT_100208a0 + DAT_1002089c);
    if(uVar4 == 0xc000008e){
    elif(uVar4 == 0xc0000090){
    elif(uVar4 == 0xc0000091){
    elif(uVar4 == 0xc0000093){
    elif(uVar4 == 0xc000008d){
    elif(uVar4 == 0xc000008f){
    elif(uVar4 == 0xc0000092){
    (*pcVar2)(8,p_Var5->_tfpecode);
    else{
    (*pcVar2)(puVar6[1]);
    p_Var5 =(_ptiddata)0xffffffff;
    return(int)p_Var5;

f if(1):

f if(1):

f if(1):

f if(1):

f if(1):

f if(1):

f ___CppXcptFilter(2):
  c:__XcptFilter
  k:0xe06d7363
  cf:
    if(_ExceptionNum == 0xe06d7363){
    iVar1 = __XcptFilter(0xe06d7363);
    return iVar1;
    return 0;

f __flsbuf(2):
  c:__fileno,__errno,__getbuf,__write,__lseeki64
  k:0x82,0x40,0x10,0x10c,0x108,0xffffffff,0xfffffffe,0x1f,0x20,0x200000000,0xff
  cf:
    _File =(FILE *)__fileno();
    if((uVar6 & 0x82)== 0){
    piVar2 = __errno();
    return -1;
    if((uVar6 & 0x40)!= 0){
    piVar2 = __errno();
    goto LAB_1000c0b4;
    if((uVar6 & 1)!= 0){
    if((uVar6 & 0x10)== 0){
    return -1;
    if(((uVar6 & 0x10c)== 0)&&
    __getbuf();
    if((_File_00->_flag & 0x108U)== 0){
    local_8 = __write();
    else{
    uVar6 =(int)pcVar1 -(int)_Buf;
    if((int)uVar6 < 1){
    if((_File ==(FILE *)0xffffffff)||(_File ==(FILE *)0xfffffffe)){
    else{
    puVar5 =(undefined *)(((uint)_File & 0x1f)* 0x40 +(&DAT_10022c80)[(int)_File >> 5]);
    if(((puVar5[4] & 0x20)!= 0)&&
    (lVar7 = __lseeki64(0x200000000),lVar7 == -1))goto LAB_1000c1dc;
    else{
    local_8 = __write();
    *_File_00->_base =(char)_Ch;
    if(local_8 == uVar6){
    return _Ch & 0xff;
    return -1;

f write_char(0):
  c:__flsbuf
  k:0x40,0x0,0xffffffff
  cf:
    if(((in_ECX->_flag & 0x40)== 0)||(in_ECX->_base !=(char *)0x0)){
    if(*piVar1 < 0){
    uVar2 = __flsbuf();
    else{
    uVar2 =(uint)in_AL;
    if(uVar2 == 0xffffffff){
    return;

f write_multi_char(2):
  c:write_char
  cf:
    do{
    if(param_2 < 1){
    return;
    write_char();
    }while(*in_EAX != -1);
    return;

f write_string(1):
  c:write_char,__errno
  k:0xc,0x40,0x2a
  cf:
    if(((*(byte *)(unaff_EDI + 0xc)& 0x40)== 0)||(*(int *)(unaff_EDI + 8)!= 0)){
    while(0 < param_1){
    write_char();
    if(*in_EAX == -1){
    piVar1 = __errno();
    if(*piVar1 != 0x2a){
    return;
    write_char();
    else{
    return;

f __output_l(4):
  c:_LocaleUpdate,__fileno,__isleadbyte_l,write_char,elif,CONCAT44,__aulldvrm,__malloc_crt,__decode_pointer,_strlen,write_multi_char,write_string,_wctomb_s,__get_printf_count_output,_free,__errno,__invalid_parameter,__security_check_cookie
  g:DAT_10020030,CONCAT44
  k:0xfffffffc,0x0,0x40,0xffffffff,0xfffffffe,0x1f,0x24,0x7f,0x80,0x20,0x59,0xf,0x23,0x2b,0x2d,0x30,0x2a,0x49,0x36,0x34,0x33,0x32,0x69,0x6f
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    local_228 =(wchar_t *)_ArgList;
    _LocaleUpdate::_LocaleUpdate();
    if(_File !=(FILE *)0x0){
    if((_File->_flag & 0x40)== 0){
    uVar4 = __fileno();
    if((uVar4 == 0xffffffff)||(uVar4 == 0xfffffffe)){
    else{
    puVar9 =(undefined *)((uVar4 & 0x1f)* 0x40 +(&DAT_10022c80)[(int)uVar4 >> 5]);
    if((puVar9[0x24] & 0x7f)== 0){
    if((uVar4 == 0xffffffff)||(uVar4 == 0xfffffffe)){
    else{
    puVar9 =(undefined *)((uVar4 & 0x1f)* 0x40 +(&DAT_10022c80)[(int)uVar4 >> 5]);
    if((puVar9[0x24] & 0x80)== 0)goto LAB_1000c39c;
    else{
    if(_Format !=(char *)0x0){
    local_248 =(wchar_t *)0x0;
    while((local_215 != 0 &&
    if((byte)(local_215 - 0x20)< 0x59){
    uVar4 =(int)(char)(&DAT_1001aa08)[(char)local_215] & 0xf;
    else{
    local_270 =(int)(char)(&DAT_1001aa28)[uVar4 * 8 + iVar8] >> 4;
    switch(local_270){
    case 0:
    switchD_1000c415_caseD_0:
    iVar8 = __isleadbyte_l();
    if(iVar8 != 0){
    write_char();
    local_240 =(byte *)_Format + 2;
    if(*pbVar11 == 0)goto LAB_1000c303;
    write_char();
    break;
    case 1:
    break;
    case 2:
    if(local_215 == 0x20){
    elif(local_215 == 0x23){
    elif(local_215 == 0x2b){
    elif(local_215 == 0x2d){
    elif(local_215 == 0x30){
    break;
    case 3:
    if(local_215 == 0x2a){
    local_228 =(wchar_t *)((int)_ArgList + 4);
    local_238 = *(int *)_ArgList;
    if(local_238 < 0){
    else{
    local_238 = local_238 * 10 + -0x30 +(int)(char)local_215;
    break;
    case 4:
    break;
    case 5:
    if(local_215 == 0x2a){
    local_228 =(wchar_t *)((int)_ArgList + 4);
    local_21c = *(int *)_ArgList;
    if(local_21c < 0){
    else{
    local_21c = local_21c * 10 + -0x30 +(int)(char)local_215;
    break;
    case 6:
    if(local_215 == 0x49){
    if((bVar1 == 0x36)&&(((byte *)_Format)[2] == 0x34)){
    local_240 =(byte *)_Format + 3;
    elif((bVar1 == 0x33)&&(((byte *)_Format)[2] == 0x32)){
    local_240 =(byte *)_Format + 3;
    elif(((((bVar1 != 100)&&(bVar1 != 0x69))&&(bVar1 != 0x6f))&&
    goto switchD_1000c415_caseD_0;
    elif(local_215 == 0x68){
    elif(local_215 == 0x6c){
    if(*pbVar11 == 0x6c){
    local_240 =(byte *)_Format + 2;
    else{
    elif(local_215 == 0x77){
    break;
    case 7:
    if((char)local_215 < 'e'){
    if(local_215 == 100){
    if(((local_214 & 0x8000)== 0)&&((local_214 & 0x1000)== 0)){
    local_228 =(wchar_t *)((int)_ArgList + 4);
    if((local_214 & 0x20)== 0){
    uVar4 = *(uint *)_ArgList;
    if((local_214 & 0x40)== 0){
    else{
    uVar10 =(int)uVar4 >> 0x1f;
    else{
    if((local_214 & 0x40)== 0){
    uVar4 =(uint)(ushort)*(wchar_t *)_ArgList;
    else{
    uVar4 =(uint)*(wchar_t *)_ArgList;
    uVar10 =(int)uVar4 >> 0x1f;
    else{
    uVar4 = *(uint *)_ArgList;
    uVar10 = *(uint *)((int)_ArgList + 4);
    local_228 =(wchar_t *)((int)_ArgList + 8);
    if((((local_214 & 0x40)!= 0)&&((int)uVar10 < 1))&&((int)uVar10 < 0)){
    uVar10 = -(uVar10 + bVar14);
    uVar15 = CONCAT44();
    if((local_214 & 0x9000)== 0){
    if(local_21c < 0){
    else{
    if(0x200 < local_21c){
    if(uVar4 == 0 && uVar10 == 0){
    while(true){
    if((local_21c < 1)&&((uint)uVar15 == 0 && uVar4 == 0))break;
    uVar15 = __aulldvrm(0x1f);
    if(0x39 < iVar8){
    *(char *)pwVar13 =(char)iVar8;
    pwVar13 =(wchar_t *)((int)pwVar13 + -1);
    uVar10 =(uint)((ulonglong)uVar15 >> 0x20);
    local_224 =(int)&local_11 + -(int)pwVar13;
    local_220 =(wchar_t *)((int)pwVar13 + 1);
    if(((local_214 & 0x200)!= 0)&&((local_224 == 0 ||(*(char *)local_220 != '0'))))
    *(char *)pwVar13 = '0';
    local_224 =(int)&local_11 + -(int)pwVar13 + 1;
    elif((char)local_215 < 'T'){
    if(local_215 == 0x53){
    if((local_214 & 0x830)== 0){
    goto LAB_1000c72c;
    if(local_215 == 0x41){
    if(local_21c < 0){
    elif(local_21c == 0){
    if(local_215 == 0x67){
    else{
    if(0x200 < local_21c){
    if(0xa3 < local_21c){
    local_248 =(wchar_t *)__malloc_crt();
    if(local_248 ==(wchar_t *)0x0){
    local_27c = *(undefined4 *)_ArgList;
    local_228 =(wchar_t *)((int)_ArgList + 8);
    local_278 = *(undefined4 *)((int)_ArgList + 4);
    iVar5 =(int)(char)local_215;
    pcVar6 =(code *)__decode_pointer();
    (*pcVar6)(puVar16,pwVar17,sVar12,iVar5,iVar8,uVar18,plVar19);
    if((uVar4 != 0)&&(local_21c == 0)){
    pcVar6 =(code *)__decode_pointer();
    (*pcVar6)(pwVar17,plVar19);
    if((local_215 == 0x67)&&(uVar4 == 0)){
    pcVar6 =(code *)__decode_pointer();
    (*pcVar6)(pwVar17,plVar19);
    if((char)*pwVar13 == '-'){
    local_220 =(wchar_t *)((int)pwVar13 + 1);
    local_224 = _strlen();
    elif(local_215 == 0x43){
    if((local_214 & 0x830)== 0){
    local_228 =(wchar_t *)((int)_ArgList + 4);
    if((local_214 & 0x810)== 0){
    local_210[0]._0_1_ =(char)*(wchar_t *)_ArgList;
    else{
    if(eVar7 != 0){
    elif((local_215 == 0x45)||(local_215 == 0x47))goto LAB_1000c6ab;
    else{
    if(local_215 == 0x58)goto LAB_1000ca65;
    if(local_215 == 0x5a){
    psVar2 = *(short **)_ArgList;
    local_228 =(wchar_t *)((int)_ArgList + 4);
    pwVar13 =(wchar_t *)PTR_s__null__100208ac;
    local_220 =(wchar_t *)PTR_s__null__100208ac;
    if((psVar2 ==(short *)0x0)||
    goto LAB_1000c85e;
    local_224 =(size_t)*psVar2;
    if((local_214 & 0x800)== 0){
    else{
    local_224 =(int)local_224 / 2;
    else{
    if(local_215 == 0x61)goto LAB_1000c6be;
    if(local_215 == 99)goto LAB_1000c79f;
    if(local_244 == 0){
    if((local_214 & 0x40)!= 0){
    if((local_214 & 0x100)== 0){
    if((local_214 & 1)== 0){
    if((local_214 & 2)== 0)goto LAB_1000cc86;
    else{
    iVar8 =(local_238 - local_224)- local_234;
    if((local_214 & 0xc)== 0){
    write_multi_char(0x20);
    write_string();
    if(((local_214 & 8)!= 0)&&((local_214 & 4)== 0)){
    write_multi_char(0x30);
    if((local_23c == 0)||((int)local_224 < 1)){
    write_string();
    else{
    do{
    eVar7 = _wctomb_s();
    if((eVar7 != 0)||(local_26c[0] == 0)){
    break;
    write_string();
    }while(local_264 != 0);
    if((-1 < local_22c)&&((local_214 & 4)!= 0)){
    write_multi_char(0x20);
    else{
    if('p' <(char)local_215){
    if(local_215 == 0x73){
    if(local_21c == -1){
    local_228 =(wchar_t *)((int)_ArgList + 4);
    local_220 = *(wchar_t **)_ArgList;
    if((local_214 & 0x810)== 0){
    if(local_220 ==(wchar_t *)0x0){
    pwVar13 =(wchar_t *)PTR_s__null__100208ac;
    local_220 =(wchar_t *)PTR_s__null__100208ac;
    for(;(iVar8 != 0 &&(iVar8 = iVar8 + -1,(char)*pwVar13 != '\0'));
    local_224 =(int)pwVar13 -(int)local_220;
    else{
    if(local_220 ==(wchar_t *)0x0){
    local_220 =(wchar_t *)PTR_u__null__100208b0;
    for(pwVar13 = local_220;
    (iVar8 != 0 &&(iVar8 = iVar8 + -1,*pwVar13 != L'\0'));
    local_224 =(int)pwVar13 -(int)local_220 >> 1;
    goto LAB_1000cc3d;
    if(local_215 == 0x75)goto LAB_1000c907;
    if(local_215 != 0x78)goto LAB_1000cc3d;
    if((local_214 & 0x80)!= 0){
    local_22f =(char)local_24c + 'Q';
    goto LAB_1000c911;
    if(local_215 == 0x70){
    goto LAB_1000ca91;
    if((char)local_215 < 'e')goto LAB_1000cc3d;
    if((char)local_215 < 'h')goto LAB_1000c6be;
    if(local_215 == 0x69)goto LAB_1000c900;
    if(local_215 != 0x6e){
    if(local_215 != 0x6f)goto LAB_1000cc3d;
    if((local_214 & 0x80)!= 0){
    goto LAB_1000c911;
    piVar3 = *(int **)_ArgList;
    local_228 =(wchar_t *)((int)_ArgList + 4);
    iVar8 = __get_printf_count_output();
    if(iVar8 == 0)goto LAB_1000c303;
    if((local_214 & 0x20)== 0){
    else{
    *(undefined2 *)piVar3 =(undefined2)local_22c;
    if(local_248 !=(wchar_t *)0x0){
    _free();
    local_248 =(wchar_t *)0x0;
    _Format =(char *)local_240;
    _ArgList =(va_list)local_228;
    if(local_254 != '\0'){
    *(uint *)(local_258 + 0x70)= *(uint *)(local_258 + 0x70)& 0xfffffffd;
    goto LAB_1000ce00;
    piVar3 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    if(local_254 != '\0'){
    *(uint *)(local_258 + 0x70)= *(uint *)(local_258 + 0x70)& 0xfffffffd;
    iVar8 = __security_check_cookie(0xfffffffc);
    return iVar8;

f if(1):

f if(1):

f if(1):

f if(1):

f if(1):

f if(1):
  k:0x6c
  cf:
    if(*pbVar11 == 0x6c){
    local_240 =(byte *)_Format + 2;
    else{

f if(1):

f if(1):
  k:0x67
  cf:
    if(local_215 == 0x67){

f if(1):
  k:0x830,0x810
  cf:
    if((local_214 & 0x830)== 0){
    local_228 =(wchar_t *)((int)_ArgList + 4);
    if((local_214 & 0x810)== 0){
    local_210[0]._0_1_ =(char)*(wchar_t *)_ArgList;
    else{
    if(eVar7 != 0){

f __ioinit(0):
  c:GetStartupInfoA,__calloc_crt,___crtInitCritSecAndSpinCount,GetStdHandle,elif,SetHandleCount
  g:UINT,HANDLE
  k:0x20,0x40,0x0,0x200,0x10,0x25,0x26,0xd,0x7ff,0x80,0xffffffff,0xfffffffe,0x1f,0x81,0xfffffff5,0xff,4000
  cf:
    GetStartupInfoA();
    puVar2 =(undefined4 *)__calloc_crt(0x20,0x40);
    if(puVar2 ==(undefined4 *)0x0){
    else{
    for(;puVar2 < DAT_10022c80 + 0x200;puVar2 = puVar2 + 0x10){
    *(undefined1 *)(puVar2 + 1)= 0;
    *(undefined1 *)((int)puVar2 + 5)= 10;
    *(undefined1 *)(puVar2 + 9)= 0;
    *(undefined1 *)((int)puVar2 + 0x25)= 10;
    *(undefined1 *)((int)puVar2 + 0x26)= 10;
    *(undefined1 *)(puVar2 + 0xd)= 0;
    if((local_68.cbReserved2 != 0)&&((UINT *)local_68.lpReserved2 !=(UINT *)0x0)){
    UVar9 = *(UINT *)local_68.lpReserved2;
    pUVar6 =(UINT *)((int)local_68.lpReserved2 + 4);
    local_20 =(byte *)((int)pUVar6 + UVar9);
    if(0x7ff <(int)UVar9){
    while((UVar10 = UVar9,(int)DAT_10022c60 <(int)UVar9 &&
    (&DAT_10022c80)[local_24] = puVar2;
    for(;puVar2 < puVar1 + 0x200;puVar2 = puVar2 + 0x10){
    *(undefined1 *)(puVar2 + 1)= 0;
    *(undefined1 *)((int)puVar2 + 5)= 10;
    *(byte *)(puVar2 + 9)= *(byte *)(puVar2 + 9)& 0x80;
    *(undefined1 *)((int)puVar2 + 0x25)= 10;
    *(undefined1 *)((int)puVar2 + 0x26)= 10;
    *(undefined1 *)(puVar2 + 0xd)= 0;
    puVar1 =(&DAT_10022c80)[local_24];
    if(0 <(int)UVar10){
    do{
    pvVar5 = *(HANDLE *)local_20;
    if((((pvVar5 !=(HANDLE)0xffffffff)&&(pvVar5 !=(HANDLE)0xfffffffe))&&
    ((local_24 & 0x1f)* 0x40 +(int)(&DAT_10022c80)[(int)local_24 >> 5]);
    *puVar2 = *(undefined4 *)local_20;
    *(byte *)(puVar2 + 1)=(byte)*pUVar6;
    BVar4 = ___crtInitCritSecAndSpinCount(4000);
    if(BVar4 == 0)goto LAB_1000d07b;
    pUVar6 =(UINT *)((int)pUVar6 + 1);
    }while((int)local_24 <(int)UVar10);
    do{
    if((*piVar8 == -1)||(*piVar8 == -2)){
    *(undefined1 *)(piVar8 + 1)= 0x81;
    if(iVar7 == 0){
    else{
    DVar3 = 0xfffffff5 -(iVar7 != 1);
    pvVar5 = GetStdHandle();
    if(((pvVar5 ==(HANDLE)0xffffffff)||(pvVar5 ==(HANDLE)0x0))||
    *(byte *)(piVar8 + 1)= *(byte *)(piVar8 + 1)| 0x40;
    else{
    *piVar8 =(int)pvVar5;
    if((DVar3 & 0xff)== 2){
    *(byte *)(piVar8 + 1)= *(byte *)(piVar8 + 1)| 0x40;
    elif((DVar3 & 0xff)== 3){
    *(byte *)(piVar8 + 1)= *(byte *)(piVar8 + 1)| 8;
    BVar4 = ___crtInitCritSecAndSpinCount(4000);
    if(BVar4 == 0)goto LAB_1000d07b;
    else{
    *(byte *)(piVar8 + 1)= *(byte *)(piVar8 + 1)| 0x80;
    }while(iVar7 < 3);
    SetHandleCount();
    return iVar7;

f __ioterm(0):
  c:DeleteCriticalSection,_free
  k:0x800,0x40,0xc,0x10022d80
  cf:
    do{
    if(uVar3 != 0){
    for(;uVar3 < uVar1 + 0x800;uVar3 = uVar3 + 0x40){
    if(*(int *)(uVar3 + 8)!= 0){
    DeleteCriticalSection(0xc);
    _free();
    }while((int)puVar2 < 0x10022d80);
    return;

f __setenvp(0):
  c:___initmbctable,_strlen,__calloc_crt,_free,_strcpy_s,__invoke_watson
  g:DAT_10021158,DAT_10021824
  k:0x0
  cf:
    if(DAT_10022d8c == 0){
    ___initmbctable();
    if(DAT_10021158 !=(char *)0x0){
    for(;*pcVar4 != '\0';pcVar4 = pcVar4 + sVar2 + 1){
    if(*pcVar4 != '='){
    sVar2 = _strlen();
    puVar1 =(undefined4 *)__calloc_crt();
    if(puVar1 !=(undefined4 *)0x0){
    do{
    if(*pcVar4 == '\0'){
    _free(DAT_10021158);
    DAT_10021158 =(char *)0x0;
    return 0;
    sVar2 = _strlen();
    if(*pcVar4 != '='){
    _Dst =(char *)__calloc_crt();
    if(_Dst ==(char *)0x0){
    _free(DAT_10021824);
    DAT_10021824 =(undefined4 *)0x0;
    return -1;
    eVar3 = _strcpy_s();
    if(eVar3 != 0){
    __invoke_watson(0x0,0x0,0x0);
    }while(true);
    return -1;

f parse_cmdline(3):
  c:__ismbblead
  k:0x0,0x22,0x20,0x5c
  cf:
    if(param_1 !=(undefined4 *)0x0){
    do{
    if(*in_EDX == 0x22){
    else{
    if(pbVar5 !=(byte *)0x0){
    iVar3 = __ismbblead();
    if(iVar3 != 0){
    if(param_2 !=(byte *)0x0){
    if(bVar6 == 0){
    goto LAB_1000d244;
    }while((bVar2)||((bVar6 != 0x20 &&(bVar6 != 9))));
    if(pbVar5 !=(byte *)0x0){
    while(*pbVar7 != 0){
    for(;(*pbVar7 == 0x20 ||(*pbVar7 == 9));pbVar7 = pbVar7 + 1){
    if(*pbVar7 == 0)break;
    if(param_1 !=(undefined4 *)0x0){
    while(true){
    for(;*pbVar7 == 0x5c;pbVar7 = pbVar7 + 1){
    if(*pbVar7 == 0x22){
    if(((uVar4 & 1)== 0)&&((!bVar2 ||(pbVar8 = pbVar7 + 1,*pbVar8 != 0x22)))){
    while(uVar4 != 0){
    if(pbVar5 !=(byte *)0x0){
    if((bVar6 == 0)||((!bVar2 &&((bVar6 == 0x20 ||(bVar6 == 9))))))break;
    if(bVar1){
    if(pbVar5 ==(byte *)0x0){
    iVar3 = __ismbblead();
    if(iVar3 != 0){
    else{
    iVar3 = __ismbblead();
    if(iVar3 != 0){
    if(pbVar5 !=(byte *)0x0){
    if(param_1 !=(undefined4 *)0x0){
    return;

f __setargv(0):
  c:___initmbctable,GetModuleFileNameA,parse_cmdline
  g:DAT_10021848
  k:0x0,0x104,0x3fffffff,0xffffffff
  cf:
    if(DAT_10022d8c == 0){
    ___initmbctable();
    GetModuleFileNameA(0x0,&DAT_10021848,0x104);
    if((DAT_10022da0 ==(char *)0x0)||(local_8 = DAT_10022da0,*DAT_10022da0 == '\0')){
    parse_cmdline(0x0,0x0);
    if((local_c < 0x3fffffff)&&(local_10 != 0xffffffff)){
    if((local_10 <= _Size)&&
    parse_cmdline();
    return 0;
    return -1;

f ___crtGetEnvironmentStringsA(0):
  c:GetEnvironmentStringsW,GetLastError,GetEnvironmentStrings,__malloc_crt,FreeEnvironmentStringsA,_memcpy,WideCharToMultiByte,_free,FreeEnvironmentStringsW
  g:LPWCH,DAT_10021950,LPVOID,LPCH,LPSTR
  k:0x0,0x78
  cf:
    lpWideCharStr =(LPWCH)0x0;
    if(DAT_10021950 == 0){
    lpWideCharStr = GetEnvironmentStringsW();
    if(lpWideCharStr !=(LPWCH)0x0){
    goto LAB_1000d45a;
    DVar3 = GetLastError();
    if(DVar3 == 0x78){
    if(DAT_10021950 != 1){
    if((DAT_10021950 != 2)&&(DAT_10021950 != 0)){
    return(LPVOID)0x0;
    _Src = GetEnvironmentStrings();
    if(_Src ==(LPCH)0x0){
    return(LPVOID)0x0;
    while(cVar1 != '\0'){
    do{
    }while(*pcVar7 != '\0');
    _Dst = __malloc_crt();
    if(_Dst ==(void *)0x0){
    FreeEnvironmentStringsA();
    return(LPVOID)0x0;
    _memcpy();
    FreeEnvironmentStringsA();
    return _Dst;
    if((lpWideCharStr ==(LPWCH)0x0)&&
    return(LPVOID)0x0;
    while(WVar2 != L'\0'){
    do{
    }while(*pWVar5 != L'\0');
    iVar6 =((int)pWVar5 -(int)lpWideCharStr >> 1)+ 1;
    _Size = WideCharToMultiByte(0x0,0x0,0x0);
    local_8 =(LPSTR)0x0;
    if(((_Size != 0)&&(lpMultiByteStr =(LPSTR)__malloc_crt(_Size),lpMultiByteStr !=(LPSTR)0x0))
    _free();
    local_8 =(LPSTR)0x0;
    FreeEnvironmentStringsW();
    return local_8;

f __RTC_Initialize(0):
  cf:
    return;

f __heap_init(0):
  c:HeapCreate
  g:DAT_10021954,HANDLE
  k:0x1000,0x0
  cf:
    DAT_10021954 = HeapCreate(0x1000);
    if(DAT_10021954 ==(HANDLE)0x0){
    return 0;
    return 1;

f __heap_term(0):
  c:VirtualFree,HeapFree,HeapDestroy
  g:DAT_10021954,HANDLE
  k:0x10,0x8000,0x0
  cf:
    if(DAT_10022c5c == 3){
    if(0 < DAT_10022c44){
    puVar2 =(undefined4 *)((int)DAT_10022c48 + 0x10);
    do{
    VirtualFree(0x8000);
    HeapFree(DAT_10021954);
    }while(iVar1 < DAT_10022c44);
    HeapFree(DAT_10021954);
    HeapDestroy(DAT_10021954);
    DAT_10021954 =(HANDLE)0x0;
    return;

f ___security_init_cookie(0):
  c:GetSystemTimeAsFileTime,GetCurrentProcessId,GetCurrentThreadId,GetTickCount,QueryPerformanceCounter,elif
  g:DAT_10020030
  k:0xbb40e64e,0xffff0000
  cf:
    if((DAT_10020030 == 0xbb40e64e)||((DAT_10020030 & 0xffff0000)== 0)){
    GetSystemTimeAsFileTime();
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter();
    if(DAT_10020030 == 0xbb40e64e){
    elif((DAT_10020030 & 0xffff0000)== 0){
    else{
    return;

f __mtinitlocks(0):
  c:___crtInitCritSecAndSpinCount
  g:DAT_10020904,DAT_10020900
  k:0x24,4000
  cf:
    do{
    if((&DAT_10020904)[iVar2 * 2] == 1){
    (&DAT_10020900)[iVar2 * 2] = puVar3;
    BVar1 = ___crtInitCritSecAndSpinCount(4000);
    if(BVar1 == 0){
    (&DAT_10020900)[iVar2 * 2] = 0;
    return 0;
    }while(iVar2 < 0x24);
    return 1;

f __mtdeletelocks(0):
  c:DeleteCriticalSection,_free
  g:LPCRITICAL_SECTION
  k:0x0,0x10020a20
  cf:
    do{
    lpCriticalSection =(LPCRITICAL_SECTION)*puVar1;
    if((lpCriticalSection !=(LPCRITICAL_SECTION)0x0)&&(puVar1[1] != 1)){
    DeleteCriticalSection();
    _free();
    }while((int)puVar1 < 0x10020a20);
    do{
    if(((LPCRITICAL_SECTION)*puVar1 !=(LPCRITICAL_SECTION)0x0)&&(puVar1[1] == 1)){
    DeleteCriticalSection();
    }while((int)puVar1 < 0x10020a20);
    return;

f FUN_1000d764(1):
  c:LeaveCriticalSection
  cf:
    LeaveCriticalSection();
    return;

f __mtinitlocknum(1):
  c:__FF_MSGBANNER,__NMSG_WRITE,___crtExitProcess,__malloc_crt,__errno,__lock,___crtInitCritSecAndSpinCount,_free,FUN_1000d835
  g:DAT_10021954,LPCRITICAL_SECTION
  k:0x1e,0xff,0x18,0x0,4000
  cf:
    if(DAT_10021954 == 0){
    __FF_MSGBANNER();
    __NMSG_WRITE(0x1e);
    ___crtExitProcess(0xff);
    if(*piVar1 == 0){
    _Memory =(LPCRITICAL_SECTION)__malloc_crt(0x18);
    if(_Memory ==(LPCRITICAL_SECTION)0x0){
    piVar1 = __errno();
    else{
    __lock();
    if(*piVar1 == 0){
    BVar2 = ___crtInitCritSecAndSpinCount(4000);
    if(BVar2 == 0){
    _free();
    piVar1 = __errno();
    else{
    *piVar1 =(int)_Memory;
    else{
    _free();
    FUN_1000d835();
    return iVar3;

f FUN_1000d835(0):
  c:FUN_1000d764
  cf:
    FUN_1000d764();
    return;

f __lock(1):
  c:__mtinitlocknum,__amsg_exit,EnterCriticalSection
  g:DAT_10020900
  k:0x11
  cf:
    if((&DAT_10020900)[_File * 2] == 0){
    iVar1 = __mtinitlocknum();
    if(iVar1 == 0){
    __amsg_exit(0x11);
    EnterCriticalSection();
    return;

f ___sbh_find_block(1):
  k:0x14,0xc,0x100000
  cf:
    while(true){
    if(DAT_10022c44 * 0x14 + DAT_10022c48 <= uVar1){
    return 0;
    if((uint)(param_1 - *(int *)(uVar1 + 0xc))< 0x100000)break;
    return uVar1;

f ___sbh_free_block(2):
  c:VirtualFree,HeapFree
  g:DAT_10021954
  k:0x204,0x144,0x3f,0x20,0x80000000,0x1f,0x44,0xc4,0x0,0x8000,0x4000,0x43,0xffffffff,0x14
  cf:
    puVar12 =(uint *)(param_2 + -4);
    piVar4 =(int *)(uVar14 * 0x204 + 0x144 + uVar6);
    if((local_8 & 1)== 0){
    puVar10 =(uint *)(local_8 +(int)puVar12);
    uVar7 = *(uint *)(param_2 + -8);
    if((uVar13 & 1)== 0){
    uVar9 =((int)uVar13 >> 4)- 1;
    if(0x3f < uVar9){
    if(puVar10[1] == puVar10[2]){
    if(uVar9 < 0x20){
    pcVar2 =(char *)(uVar9 + 4 + uVar6);
    uVar9 = ~(0x80000000U >>((byte)uVar9 & 0x1f));
    puVar11 =(uint *)(uVar6 + 0x44 + uVar14 * 4);
    if(*pcVar2 == '\0'){
    else{
    pcVar2 =(char *)(uVar9 + 4 + uVar6);
    uVar9 = ~(0x80000000U >>((byte)uVar9 - 0x20 & 0x1f));
    puVar11 =(uint *)(uVar6 + 0xc4 + uVar14 * 4);
    if(*pcVar2 == '\0'){
    *(uint *)(puVar10[2] + 4)= puVar10[1];
    *(uint *)(puVar10[1] + 8)= puVar10[2];
    puVar10 =(uint *)(((int)local_8 >> 4)- 1);
    if((uint *)0x3f < puVar10){
    puVar10 =(uint *)0x3f;
    if((uVar7 & 1)== 0){
    puVar12 =(uint *)((int)puVar12 - uVar7);
    puVar11 =(uint *)(((int)uVar7 >> 4)- 1);
    if((uint *)0x3f < puVar11){
    puVar11 =(uint *)0x3f;
    puVar10 =(uint *)(((int)local_8 >> 4)- 1);
    if((uint *)0x3f < puVar10){
    puVar10 =(uint *)0x3f;
    if(puVar11 != puVar10){
    if(puVar12[1] == puVar12[2]){
    if(puVar11 <(uint *)0x20){
    uVar13 = ~(0x80000000U >>((byte)puVar11 & 0x1f));
    puVar3 =(uint *)(uVar6 + 0x44 + uVar14 * 4);
    pcVar2 =(char *)((int)puVar11 + uVar6 + 4);
    if(*pcVar2 == '\0'){
    else{
    uVar13 = ~(0x80000000U >>((byte)puVar11 - 0x20 & 0x1f));
    puVar3 =(uint *)(uVar6 + 0xc4 + uVar14 * 4);
    pcVar2 =(char *)((int)puVar11 + uVar6 + 4);
    if(*pcVar2 == '\0'){
    *(uint *)(puVar12[2] + 4)= puVar12[1];
    *(uint *)(puVar12[1] + 8)= puVar12[2];
    if(((uVar7 & 1)!= 0)||(puVar11 != puVar10)){
    piVar1 = piVar4 +(int)puVar10 * 2;
    puVar12[2] =(uint)piVar1;
    piVar1[1] =(int)puVar12;
    *(uint **)(puVar12[1] + 8)= puVar12;
    if(puVar12[1] == puVar12[2]){
    cVar5 = *(char *)((int)puVar10 + uVar6 + 4);
    *(char *)((int)puVar10 + uVar6 + 4)= cVar5 + '\x01';
    bVar8 =(byte)puVar10;
    if(puVar10 <(uint *)0x20){
    if(cVar5 == '\0'){
    *param_1 = *param_1 | 0x80000000U >>(bVar8 & 0x1f);
    puVar10 =(uint *)(uVar6 + 0x44 + uVar14 * 4);
    *puVar10 = *puVar10 | 0x80000000U >>(bVar8 & 0x1f);
    else{
    if(cVar5 == '\0'){
    param_1[1] = param_1[1] | 0x80000000U >>(bVar8 - 0x20 & 0x1f);
    puVar10 =(uint *)(uVar6 + 0xc4 + uVar14 * 4);
    *puVar10 = *puVar10 | 0x80000000U >>(bVar8 - 0x20 & 0x1f);
    *(uint *)((local_8 - 4)+(int)puVar12)= local_8;
    if(*piVar4 == 0){
    if(DAT_10021aa8 !=(uint *)0x0){
    VirtualFree(0x8000,0x8000,0x4000);
    DAT_10021aa8[2] = DAT_10021aa8[2] | 0x80000000U >>((byte)DAT_10022c58 & 0x1f);
    *(undefined4 *)(DAT_10021aa8[4] + 0xc4 + DAT_10022c58 * 4)= 0;
    *(char *)(DAT_10021aa8[4] + 0x43)= *(char *)(DAT_10021aa8[4] + 0x43)+ -1;
    if(*(char *)(DAT_10021aa8[4] + 0x43)== '\0'){
    if(DAT_10021aa8[2] == 0xffffffff){
    VirtualFree(0x8000);
    HeapFree(DAT_10021954);
    (DAT_10022c44 * 0x14 -(int)DAT_10021aa8)+ -0x14 + DAT_10022c48);
    if(DAT_10021aa8 < param_1){
    return;

f ___sbh_alloc_new_region(0):
  c:HeapReAlloc,HeapAlloc,VirtualAlloc,HeapFree
  g:DAT_10021954,LPVOID
  k:0x10,0x0,0x14,0x41c4,0x100000,0x2000,0xffffffff
  cf:
    if(DAT_10022c44 == DAT_10022c54){
    pvVar1 = HeapReAlloc(DAT_10021954,0x10);
    if(pvVar1 ==(LPVOID)0x0){
    return(undefined4 *)0x0;
    puVar2 =(undefined4 *)(DAT_10022c44 * 0x14 +(int)DAT_10022c48);
    pvVar1 = HeapAlloc(DAT_10021954,0x41c4);
    if(pvVar1 !=(LPVOID)0x0){
    pvVar1 = VirtualAlloc(0x0,0x100000,0x2000);
    if(pvVar1 !=(LPVOID)0x0){
    *(undefined4 *)puVar2[4] = 0xffffffff;
    return puVar2;
    HeapFree(DAT_10021954);
    return(undefined4 *)0x0;

f ___sbh_alloc_new_group(1):
  c:VirtualAlloc
  g:LPVOID
  k:0x10,0x8000,0xc,0x1000,0x0,0x7000,0x3ff,0x401,0x1fc,0x14,0x1f8,0x200,0x700c,0x7010,0x44,0xc4,0x43,0x80000000,0x1f
  cf:
    iVar2 = *(int *)(param_1 + 0x10);
    for(iVar3 = *(int *)(param_1 + 8);-1 < iVar3;iVar3 = iVar3 * 2){
    do{
    *(int *)(iVar4 + 8)= iVar4;
    *(int *)(iVar4 + 4)= iVar4;
    }while(iVar7 != 0);
    lpAddress =(LPVOID)(iVar8 * 0x8000 + *(int *)(param_1 + 0xc));
    pvVar5 = VirtualAlloc(0x8000,0x1000);
    if(pvVar5 ==(LPVOID)0x0){
    else{
    if(lpAddress <=(LPVOID)((int)lpAddress + 0x7000U)){
    piVar6 =(int *)((int)lpAddress + 0x10);
    iVar7 =((uint)((int)((int)lpAddress + 0x7000U)-(int)lpAddress)>> 0xc)+ 1;
    do{
    *piVar6 =(int)(piVar6 + 0x3ff);
    piVar6[1] =(int)(piVar6 + -0x401);
    }while(iVar7 != 0);
    *(int *)(iVar3 + 0x1fc)=(int)lpAddress + 0xc;
    *(int *)((int)lpAddress + 0x14)= iVar3 + 0x1f8;
    *(int *)(iVar3 + 0x200)=(int)lpAddress + 0x700c;
    *(int *)((int)lpAddress + 0x7010)= iVar3 + 0x1f8;
    *(undefined4 *)(iVar2 + 0x44 + iVar8 * 4)= 0;
    *(undefined4 *)(iVar2 + 0xc4 + iVar8 * 4)= 1;
    cVar1 = *(char *)(iVar2 + 0x43);
    *(char *)(iVar2 + 0x43)= cVar1 + '\x01';
    if(cVar1 == '\0'){
    *(uint *)(param_1 + 4)= *(uint *)(param_1 + 4)| 1;
    *(uint *)(param_1 + 8)= *(uint *)(param_1 + 8)& ~(0x80000000U >>((byte)iVar8 & 0x1f));
    return iVar8;

f ___sbh_resize_block(3):
  c:elif
  k:0x3f,0x20,0x80000000,0x1f,0x44,0xc4
  cf:
    iVar9 = *(int *)(param_2 + -4)+ -1;
    puVar8 =(uint *)(*(int *)(param_2 + -4)+ -5 + param_2);
    if(iVar9 <(int)uVar12){
    if(((uVar13 & 1)!= 0)||((int)(uVar13 + iVar9)<(int)uVar12)){
    return 0;
    local_c =((int)uVar13 >> 4)- 1;
    if(0x3f < local_c){
    if(puVar8[1] == puVar8[2]){
    if(local_c < 0x20){
    pcVar1 =(char *)(local_c + 4 + uVar7);
    uVar11 = ~(0x80000000U >>((byte)local_c & 0x1f));
    puVar2 =(uint *)(uVar7 + 0x44 + uVar10 * 4);
    if(*pcVar1 == '\0'){
    else{
    pcVar1 =(char *)(local_c + 4 + uVar7);
    uVar11 = ~(0x80000000U >>((byte)local_c - 0x20 & 0x1f));
    puVar2 =(uint *)(uVar7 + 0xc4 + uVar10 * 4);
    if(*pcVar1 == '\0'){
    *(uint *)(puVar8[2] + 4)= puVar8[1];
    *(uint *)(puVar8[1] + 8)= puVar8[2];
    iVar9 = uVar13 +(iVar9 - uVar12);
    if(0 < iVar9){
    uVar13 =(iVar9 >> 4)- 1;
    if(0x3f < uVar13){
    *(undefined4 *)(iVar3 + 4)= *(undefined4 *)(iVar5 + 4);
    *(int *)(iVar3 + 8)= iVar5;
    *(int *)(iVar5 + 4)= iVar3;
    *(int *)(*(int *)(iVar3 + 4)+ 8)= iVar3;
    if(*(int *)(iVar3 + 4)== *(int *)(iVar3 + 8)){
    cVar6 = *(char *)(uVar13 + 4 + uVar7);
    *(char *)(uVar13 + 4 + uVar7)= cVar6 + '\x01';
    if(uVar13 < 0x20){
    if(cVar6 == '\0'){
    *param_1 = *param_1 | 0x80000000U >>((byte)uVar13 & 0x1f);
    puVar8 =(uint *)(uVar7 + 0x44 + uVar10 * 4);
    else{
    if(cVar6 == '\0'){
    param_1[1] = param_1[1] | 0x80000000U >>((byte)uVar13 - 0x20 & 0x1f);
    puVar8 =(uint *)(uVar7 + 0xc4 + uVar10 * 4);
    *puVar8 = *puVar8 | 0x80000000U >>((byte)uVar13 & 0x1f);
    piVar4 =(int *)(param_2 + -4 + uVar12);
    *(int *)(iVar9 + -4 +(int)piVar4)= iVar9;
    *(uint *)(param_2 + -4)= uVar12 + 1;
    *(uint *)(param_2 + -8 + uVar12)= uVar12 + 1;
    elif((int)uVar12 < iVar9){
    *(uint *)(param_2 + -4)= uVar12 + 1;
    piVar4 =(int *)(param_2 + -4 + uVar12);
    uVar11 =(param_3 >> 4)- 1;
    if(0x3f < uVar11){
    if((uVar13 & 1)== 0){
    uVar12 =((int)uVar13 >> 4)- 1;
    if(0x3f < uVar12){
    if(puVar8[1] == puVar8[2]){
    if(uVar12 < 0x20){
    pcVar1 =(char *)(uVar12 + 4 + uVar7);
    uVar12 = ~(0x80000000U >>((byte)uVar12 & 0x1f));
    puVar2 =(uint *)(uVar7 + 0x44 + uVar10 * 4);
    if(*pcVar1 == '\0'){
    else{
    pcVar1 =(char *)(uVar12 + 4 + uVar7);
    uVar12 = ~(0x80000000U >>((byte)uVar12 - 0x20 & 0x1f));
    puVar2 =(uint *)(uVar7 + 0xc4 + uVar10 * 4);
    if(*pcVar1 == '\0'){
    *(uint *)(puVar8[2] + 4)= puVar8[1];
    *(uint *)(puVar8[1] + 8)= puVar8[2];
    uVar11 =(param_3 >> 4)- 1;
    if(0x3f < uVar11){
    iVar9 = *(int *)(iVar5 + 4);
    *(int **)(iVar5 + 4)= piVar4;
    *(int **)(piVar4[1] + 8)= piVar4;
    if(piVar4[1] == piVar4[2]){
    cVar6 = *(char *)(uVar11 + 4 + uVar7);
    *(char *)(uVar11 + 4 + uVar7)= cVar6 + '\x01';
    if(uVar11 < 0x20){
    if(cVar6 == '\0'){
    *param_1 = *param_1 | 0x80000000U >>((byte)uVar11 & 0x1f);
    puVar8 =(uint *)(uVar7 + 0x44 + uVar10 * 4);
    else{
    if(cVar6 == '\0'){
    param_1[1] = param_1[1] | 0x80000000U >>((byte)uVar11 - 0x20 & 0x1f);
    puVar8 =(uint *)(uVar7 + 0xc4 + uVar10 * 4);
    *puVar8 = *puVar8 | 0x80000000U >>((byte)uVar11 & 0x1f);
    *(int *)(param_3 + -4 +(int)piVar4)= param_3;
    return 1;

f ___sbh_alloc_block(1):
  c:___sbh_alloc_new_group
  k:0x17,0xfffffff0,0x20,0xffffffff,0x1f,0x0,0x11,0x3f,0x80000000,0x31
  cf:
    uVar7 =(int)param_1 + 0x17U & 0xfffffff0;
    iVar8 =((int)((int)param_1 + 0x17U)>> 4)+ -1;
    bVar6 =(byte)iVar8;
    if(iVar8 < 0x20){
    uVar15 = 0xffffffff >>(bVar6 & 0x1f);
    else{
    local_c = 0xffffffff >>(bVar6 - 0x20 & 0x1f);
    for(;(param_1 < puVar9 &&((param_1[1] & local_c)== 0 &&(*param_1 & uVar15)== 0));
    if(param_1 == puVar9){
    for(;(puVar13 < DAT_10022c50 &&((puVar13[1] & local_c)== 0 &&(*puVar13 & uVar15)== 0));
    if(puVar13 == DAT_10022c50){
    for(;(puVar13 < puVar9 &&(puVar13[2] == 0));puVar13 = puVar13 + 5){
    if(puVar13 == puVar9){
    for(;(puVar14 < DAT_10022c50 &&(puVar14[2] == 0));puVar14 = puVar14 + 5){
    if((puVar14 == DAT_10022c50)&&
    return(int *)0x0;
    iVar8 = ___sbh_alloc_new_group();
    *(int *)param_1[4] = iVar8;
    if(*(int *)param_1[4] == -1){
    return(int *)0x0;
    piVar5 =(int *)param_1[4];
    if((local_8 == -1)||
    puVar9 =(uint *)(piVar5 + 0x11);
    while((uVar11 & local_c)== 0 &&(*puVar9 & uVar15)== 0){
    if(uVar15 == 0){
    for(;-1 <(int)uVar15;uVar15 = uVar15 * 2){
    piVar12 =(int *)piVar3[iVar8 * 2 + 1];
    iVar16 =(iVar10 >> 4)+ -1;
    if(0x3f < iVar16){
    if(iVar16 != iVar8){
    if(piVar12[1] == piVar12[2]){
    if(iVar8 < 0x20){
    pcVar2 =(char *)((int)piVar5 + iVar8 + 4);
    uVar15 = ~(0x80000000U >>((byte)iVar8 & 0x1f));
    if(*pcVar2 == '\0'){
    else{
    pcVar2 =(char *)((int)piVar5 + iVar8 + 4);
    uVar15 = ~(0x80000000U >>((byte)iVar8 - 0x20 & 0x1f));
    if(*pcVar2 == '\0'){
    *(int *)(piVar12[2] + 4)= piVar12[1];
    *(int *)(piVar12[1] + 8)= piVar12[2];
    if(iVar10 == 0)goto LAB_1000e2f2;
    piVar12[2] =(int)piVar1;
    piVar1[1] =(int)piVar12;
    *(int **)(piVar12[1] + 8)= piVar12;
    if(piVar12[1] == piVar12[2]){
    cVar4 = *(char *)(iVar16 + 4 +(int)piVar5);
    *(char *)(iVar16 + 4 +(int)piVar5)= cVar4 + '\x01';
    bVar6 =(byte)iVar16;
    if(iVar16 < 0x20){
    if(cVar4 == '\0'){
    *param_1 = *param_1 | 0x80000000U >>(bVar6 & 0x1f);
    piVar5[local_8 + 0x11] = piVar5[local_8 + 0x11] | 0x80000000U >>(bVar6 & 0x1f);
    else{
    if(cVar4 == '\0'){
    param_1[1] = param_1[1] | 0x80000000U >>(bVar6 - 0x20 & 0x1f);
    piVar5[local_8 + 0x31] = piVar5[local_8 + 0x31] | 0x80000000U >>(bVar6 - 0x20 & 0x1f);
    if(iVar10 != 0){
    *(int *)(iVar10 + -4 +(int)piVar12)= iVar10;
    piVar12 =(int *)((int)piVar12 + iVar10);
    *(uint *)((int)piVar12 +(uVar7 - 4))= uVar7 + 1;
    if(((iVar8 == 0)&&(param_1 == DAT_10021aa8))&&(local_8 == DAT_10022c58)){
    DAT_10021aa8 =(uint *)0x0;
    return piVar12 + 1;

f __local_unwind4(3):
  c:__NLG_Notify,FUN_100105f4
  g:DAT_10020030
  k:0xc,0xfffffffe,0x10,0x101
  cf:
    local_20 = DAT_10020030 ^(uint)&pvStack_28;
    while(true){
    uVar2 = *(uint *)(param_2 + 0xc);
    if((uVar2 == 0xfffffffe)||((param_3 != 0xfffffffe &&(uVar2 <= param_3))))break;
    puVar1 =(undefined4 *)((*(uint *)(param_2 + 8)^ *param_1)+ 0x10 + uVar2 * 0xc);
    *(undefined4 *)(param_2 + 0xc)= *puVar1;
    if(puVar1[1] == 0){
    __NLG_Notify(0x101);
    FUN_100105f4();
    return;

f FUN_1000e40e(1):
  c:__local_unwind4
  k:0x28,0x18,0x1c
  cf:
    __local_unwind4(0x28,0x18,0x1c);
    return;

f _EH4_CallFilterFunc(1):
  cf:
    (*(code *)param_1)();
    return;

f _EH4_TransferToHandler(1):
  c:__NLG_Notify
  cf:
    __NLG_Notify();
    (*(code *)UNRECOVERED_JUMPTABLE)();
    return;

f _EH4_GlobalUnwind(1):
  c:RtlUnwind
  k:0x1000e46f,0x0
  cf:
    RtlUnwind(0x1000e46f,0x0,0x0);
    return;

f _EH4_LocalUnwind(4):
  c:__local_unwind4
  cf:
    __local_unwind4();
    return;

f __initp_misc_winsig(1):
  cf:
    return;

f siglookup(1):
  k:0xc
  cf:
    do{
    if(*(int *)(uVar1 + 4)== in_EDX)break;
    }while(uVar1 < DAT_100208a8 * 0xc + param_1);
    if((DAT_100208a8 * 0xc + param_1 <= uVar1)||(*(int *)(uVar1 + 4)!= in_EDX)){
    return uVar1;

f ___get_sigabrt(0):
  c:__decode_pointer
  cf:
    p_Var1 =(_PHNDLR)__decode_pointer();
    return p_Var1;

f _raise(1):
  c:__getptd_noexit,siglookup,elif,__errno,__invalid_parameter,__decode_pointer,__exit,__lock,__encoded_null,FUN_1000e661
  k:0x0,0xc,0xb,0xf,0x15,0x16,0x1
  cf:
    p_Var8 =(_ptiddata)0x0;
    if(_SigNum < 0xc){
    if(_SigNum != 0xb){
    if(_SigNum == 2){
    goto LAB_1000e5a2;
    if(_SigNum != 4){
    if(_SigNum == 6)goto LAB_1000e580;
    if(_SigNum != 8)goto LAB_1000e564;
    p_Var8 = __getptd_noexit();
    if(p_Var8 ==(_ptiddata)0x0){
    return -1;
    uVar2 = siglookup();
    puVar7 =(undefined4 *)(uVar2 + 8);
    pcVar5 =(code *)*puVar7;
    else{
    if(_SigNum == 0xf){
    elif(_SigNum == 0x15){
    else{
    if(_SigNum != 0x16){
    piVar3 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    return -1;
    pcVar5 =(code *)__decode_pointer();
    if(pcVar5 ==(code *)0x1){
    return 0;
    if(pcVar5 ==(code *)0x0){
    __exit();
    if(bVar1){
    __lock();
    if(((_SigNum == 8)||(_SigNum == 0xb))||(_SigNum == 4)){
    p_Var8->_tpxcptinfoptrs =(void *)0x0;
    if(_SigNum == 8){
    goto LAB_1000e606;
    else{
    if(_SigNum == 8){
    for(local_28 = DAT_1002089c;local_28 < DAT_100208a0 + DAT_1002089c;local_28 = local_28 + 1)
    *(undefined4 *)(local_28 * 0xc + 8 +(int)p_Var8->_pxcptacttab)= 0;
    goto LAB_1000e640;
    uVar6 = __encoded_null();
    FUN_1000e661();
    if(_SigNum == 8){
    (*pcVar5)(8,p_Var8->_tfpecode);
    else{
    (*pcVar5)(_SigNum);
    if((_SigNum != 0xb)&&(_SigNum != 4)){
    return 0;
    if(_SigNum == 8){
    return 0;

f if(1):

f FUN_1000e661(0):
  c:FUN_1000d764
  k:0x1c
  cf:
    if(*(int *)(unaff_EBP + -0x1c)!= 0){
    FUN_1000d764();
    return;

f ___crtMessageBoxA(3):
  c:__encoded_null,LoadLibraryA,GetProcAddress,__encode_pointer,__decode_pointer
  g:S20,HMODULE,S21,FARPROC,S22,S23,S24,S25
  k:0x0
  cf:
    iVar1 = __encoded_null();
    if(DAT_10021ac4 == 0){
    hModule = LoadLibraryA(S20);
    if(hModule ==(HMODULE)0x0){
    return 0;
    pFVar2 = GetProcAddress(S21);
    if(pFVar2 ==(FARPROC)0x0){
    return 0;
    DAT_10021ac4 = __encode_pointer();
    pFVar2 = GetProcAddress(S22);
    DAT_10021ac8 = __encode_pointer();
    pFVar2 = GetProcAddress(S23);
    DAT_10021acc = __encode_pointer();
    pFVar2 = GetProcAddress(S24);
    DAT_10021ad4 = __encode_pointer();
    if(DAT_10021ad4 != 0){
    pFVar2 = GetProcAddress(S25);
    DAT_10021ad0 = __encode_pointer();
    if((DAT_10021ad0 != iVar1)&&(DAT_10021ad4 != iVar1)){
    pcVar3 =(code *)__decode_pointer();
    pcVar4 =(code *)__decode_pointer();
    if(((pcVar3 !=(code *)0x0)&&(pcVar4 !=(code *)0x0))&&
    goto LAB_1000e7df;
    if((((DAT_10021ac8 != iVar1)&&
    local_8 =(*pcVar3)(local_8);
    pcVar3 =(code *)__decode_pointer();
    if(pcVar3 ==(code *)0x0){
    return 0;
    iVar1 =(*pcVar3)(local_8,_LpText,_LpCaption,_UType);
    return iVar1;

f _strcat_s(3):
  c:__errno,__invalid_parameter
  k:0x0
  cf:
    if((_Dst !=(char *)0x0)&&(_SizeInBytes != 0)){
    if(_Src !=(char *)0x0){
    do{
    if(*pcVar3 == '\0')break;
    }while(_SizeInBytes != 0);
    if(_SizeInBytes != 0){
    do{
    if(cVar1 == '\0')break;
    }while(_SizeInBytes != 0);
    if(_SizeInBytes != 0){
    return 0;
    piVar2 = __errno();
    goto LAB_1000e828;
    piVar2 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    return eVar4;

f _strncpy_s(4):
  c:__errno,elif,__invalid_parameter
  k:0x0,0xffffffff,0x50
  cf:
    if(_MaxCount == 0){
    if(_Dst ==(char *)0x0){
    if(_SizeInBytes == 0){
    return 0;
    else{
    if(_SizeInBytes != 0){
    if(_MaxCount == 0){
    return 0;
    if(_Src !=(char *)0x0){
    if(_MaxCount == 0xffffffff){
    do{
    if(cVar1 == '\0')break;
    }while(rVar4 != 0);
    else{
    do{
    if((cVar1 == '\0')||(rVar4 = rVar4 - 1,rVar4 == 0))break;
    }while(_MaxCount != 0);
    if(_MaxCount == 0){
    if(rVar4 != 0){
    return 0;
    if(_MaxCount == 0xffffffff){
    return 0x50;
    piVar2 = __errno();
    goto LAB_1000e8b1;
    elif(_Dst !=(char *)0x0)goto LAB_1000e8a0;
    piVar2 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    return eVar5;

f __set_error_mode(1):
  c:__errno,__invalid_parameter
  g:DAT_10021160
  k:0x0
  cf:
    if(-1 < _Mode){
    if(_Mode < 3){
    return iVar2;
    if(_Mode == 3){
    return DAT_10021160;
    piVar1 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    return -1;

f __crtGetStringTypeA_stat(8):
  c:GetStringTypeW,GetLastError,___ansicp,_free,_malloc,_memset,__freea,__security_check_cookie
  g:DAT_10020030,LS17,LPWSTR,LPCWSTR
  k:0xfffffffc,0x78,0x0,0x14,0xffffffff,0x7ffffff1,0x401,0xffffffe8,0x00000000,0x18
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if(DAT_10021b14 == 0){
    BVar1 = GetStringTypeW(LS17);
    if(BVar1 == 0){
    DVar2 = GetLastError();
    if(DVar2 == 0x78){
    goto LAB_1000e9d5;
    else{
    if((DAT_10021b14 == 2)||(DAT_10021b14 == 0)){
    _Memory =(void *)0x0;
    if(param_6 == 0){
    param_6 = *(int *)(*in_ECX + 0x14);
    if(param_5 ==(ushort *)0x0){
    param_5 = *(ushort **)(*in_ECX + 4);
    puVar5 =(ushort *)___ansicp();
    if((puVar5 !=(ushort *)0xffffffff)&&
    _free();
    goto LAB_1000eb22;
    if(DAT_10021b14 != 1)goto LAB_1000eb22;
    local_c =(int *)0x0;
    if(param_5 ==(ushort *)0x0){
    param_5 = *(ushort **)(*in_ECX + 4);
    (int)param_3,(LPWSTR)0x0,0);
    if(cchWideChar == 0)goto LAB_1000eb22;
    lpWideCharStr =(LPCWSTR)0x0;
    if((0 <(int)cchWideChar)&&(cchWideChar < 0x7ffffff1)){
    if(_Size < 0x401){
    pWVar3 =(LPCWSTR)&stack0xffffffe8;
    lpWideCharStr =(LPCWSTR)&stack0xffffffe8;
    if(&stack0x00000000 !=(undefined1 *)0x18){
    else{
    pWVar3 =(LPCWSTR)_malloc();
    if(pWVar3 !=(LPCWSTR)0x0){
    goto LAB_1000ea65;
    if(lpWideCharStr !=(LPCWSTR)0x0){
    _memset();
    if(iVar4 != 0){
    local_c =(int *)GetStringTypeW();
    __freea();
    iVar4 = __security_check_cookie(0xfffffffc);
    return iVar4;

f ___crtGetStringTypeA(7):
  c:_LocaleUpdate
  k:0xffffffec,0x70,0xfffffffd
  cf:
    _LocaleUpdate::_LocaleUpdate(0xffffffec);
    if(local_8 != '\0'){
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    return iVar1;

f ___free_lc_time(1):
  c:_free
  k:0x0,0xb,0xc,0xd,0xe,0xf,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,0x20,0x21
  cf:
    if(param_1 !=(undefined4 *)0x0){
    _free();
    _free(0xb);
    _free(0xc);
    _free(0xd);
    _free();
    _free(0xe);
    _free(0xf);
    _free(0x10);
    _free(0x11);
    _free(0x12);
    _free(0x13);
    _free(0x14);
    _free(0x15);
    _free(0x16);
    _free(0x17);
    _free(0x18);
    _free(0x19);
    _free(0x1a);
    _free(0x1b);
    _free(0x1c);
    _free(0x1d);
    _free(0x1e);
    _free(0x1f);
    _free(0x20);
    _free(0x21);
    _free(0x22);
    _free(0x23);
    _free(0x24);
    _free(0x25);
    _free(0x26);
    _free(0x27);
    _free(0x28);
    _free(0x29);
    _free(0x2a);
    return;

f ___free_lconv_num(1):
  c:_free
  k:0x0
  cf:
    if(param_1 !=(undefined4 *)0x0){
    if((undefined *)*param_1 != PTR_DAT_10020ae8){
    _free();
    if((undefined *)param_1[1] != PTR_DAT_10020aec){
    _free();
    if((undefined *)param_1[2] != PTR_DAT_10020af0){
    _free();
    return;

f ___free_lconv_mon(1):
  c:_free
  k:0xc,0x10,0x14,0x18,0x1c,0x20,0x24
  cf:
    if(param_1 != 0){
    if(*(undefined **)(param_1 + 0xc)!= PTR_DAT_10020af4){
    _free(0xc);
    if(*(undefined **)(param_1 + 0x10)!= PTR_DAT_10020af8){
    _free(0x10);
    if(*(undefined **)(param_1 + 0x14)!= PTR_DAT_10020afc){
    _free(0x14);
    if(*(undefined **)(param_1 + 0x18)!= PTR_DAT_10020b00){
    _free(0x18);
    if(*(undefined **)(param_1 + 0x1c)!= PTR_DAT_10020b04){
    _free(0x1c);
    if(*(undefined **)(param_1 + 0x20)!= PTR_DAT_10020b08){
    _free(0x20);
    if(*(undefined **)(param_1 + 0x24)!= PTR_DAT_10020b0c){
    _free(0x24);
    return;

f _strcspn(2):
  cf:
    while(true){
    if(bVar1 == 0)break;
    _Control =(char *)((byte *)_Control + 1);
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' <<(bVar1 & 7);
    do{
    if(bVar1 == 0){
    return sVar2;
    _Str =(char *)((byte *)_Str + 1);
    }while((abStack_28[(int)(uint)bVar1 >> 3] >>(bVar1 & 7)& 1)== 0);
    return sVar2;

f _strpbrk(2):
  cf:
    while(true){
    if(bVar1 == 0)break;
    _Control =(char *)((byte *)_Control + 1);
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' <<(bVar1 & 7);
    do{
    pbVar2 =(byte *)_Str;
    if(bVar1 == 0){
    return(char *)(uint)bVar1;
    _Str =(char *)(pbVar2 + 1);
    }while((abStack_28[(int)(uint)bVar1 >> 3] >>(bVar1 & 7)& 1)== 0);
    return(char *)pbVar2;

f ___ansicp(1):
  c:GetLocaleInfoA,_atol,__security_check_cookie
  g:DAT_10020030
  k:0xfffffffc,0x1004
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    iVar1 = GetLocaleInfoA(0x1004);
    if(iVar1 != 0){
    _atol();
    __security_check_cookie(0xfffffffc);
    return;

f ___convertcp(6):
  c:GetCPInfo,MultiByteToWideChar,_strlen,_malloc,_memset,_free,elif,WideCharToMultiByte,__freea,__security_check_cookie
  g:DAT_10020030,LPCWSTR,LPBOOL
  k:0xfffffffc,0x0,0xffffffff,0x7ffffff0,0x401,0xffffffbc,0x00000000,0x44
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if(param_1 == param_2)goto LAB_1000f05b;
    BVar2 = GetCPInfo();
    if((((BVar2 == 0)||(local_1c.MaxCharSize != 1))||
    uVar6 = MultiByteToWideChar(0x0);
    if(bVar7)goto LAB_1000f05b;
    else{
    if(cbMultiByte == 0xffffffff){
    sVar3 = _strlen();
    if((bVar7 ||(int)uVar6 < 0)||(0x7ffffff0 < uVar6)){
    local_20 =(LPCWSTR)0x0;
    else{
    if(_Size < 0x401){
    pWVar4 =(LPCWSTR)&stack0xffffffbc;
    local_20 =(LPCWSTR)&stack0xffffffbc;
    if(&stack0x00000000 !=(undefined1 *)0x44){
    else{
    pWVar4 =(LPCWSTR)_malloc();
    if(pWVar4 !=(LPCWSTR)0x0){
    goto LAB_1000ef9b;
    if(local_20 !=(LPCWSTR)0x0){
    _memset();
    iVar5 = MultiByteToWideChar();
    if(iVar5 != 0){
    if(param_5 ==(LPSTR)0x0){
    if(((bVar1)||
    (LPBOOL)0x0);
    if(uVar6 == 0){
    _free();
    elif(cbMultiByte != 0xffffffff){
    else{
    WideCharToMultiByte(0x0,0x0);
    __freea();
    __security_check_cookie(0xfffffffc);
    return;

f if(1):

f __alloca_probe_16(0):
  c:CARRY4
  g:CARRY4
  cf:
    return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);

f __alloca_probe_8(0):
  c:CARRY4
  g:CARRY4
  cf:
    return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);

f __tolower_l(2):
  c:_LocaleUpdate,__isctype_l,__errno,CONCAT11
  g:CHAR,LPSTR,CONCAT11
  k:0x100,0x70,0xfffffffd
  cf:
    _LocaleUpdate::_LocaleUpdate();
    if((uint)_C < 0x100){
    if((int)(local_1c.locinfo)->locale_name[3] < 2){
    uVar2 = *(ushort *)(local_1c.locinfo[1].lc_category[0].locale + _C * 2)& 1;
    else{
    uVar2 = __isctype_l();
    if(uVar2 == 0){
    if(local_10 == '\0'){
    return iVar1;
    *(uint *)(local_14 + 0x70)= *(uint *)(local_14 + 0x70)& 0xfffffffd;
    return iVar1;
    uVar2 =(uint)*(byte *)((int)local_1c.locinfo[1].lc_category[0].wlocale + _C);
    else{
    CVar5 =(CHAR)_C;
    if(((int)(local_1c.locinfo)->locale_name[3] < 2)||
    piVar4 = __errno();
    else{
    _C._0_1_ =(CHAR)((uint)_C >> 8);
    local_8 =(CHAR)_C;
    iVar3,(LPSTR)&local_c,3,(local_1c.locinfo)->lc_codepage,1);
    if(iVar3 == 0)goto LAB_1000f0fd;
    uVar2 =(uint)local_c;
    if(iVar3 != 1){
    uVar2 =(uint)CONCAT11();
    if(local_10 != '\0'){
    *(uint *)(local_14 + 0x70)= *(uint *)(local_14 + 0x70)& 0xfffffffd;
    return uVar2;

f __calloc_impl(3):
  c:__lock,___sbh_alloc_block,FUN_1000f2ad,_memset,HeapAlloc,__callnewh,__errno,__invalid_parameter
  g:DAT_10021954
  k:0xffffffe0,0x0,0x1,0xffffffe1
  cf:
    if((param_1 == 0)||(param_2 <= 0xffffffe0 / param_1)){
    _Size =(uint *)(param_1 * param_2);
    if(_Size ==(uint *)0x0){
    dwBytes =(uint *)0x1;
    do{
    piVar1 =(int *)0x0;
    if(dwBytes <(uint *)0xffffffe1){
    if((DAT_10022c5c == 3)&&
    __lock();
    piVar1 = ___sbh_alloc_block();
    FUN_1000f2ad();
    if(piVar1 !=(int *)0x0){
    _memset();
    goto LAB_1000f262;
    else{
    if(piVar1 !=(int *)0x0){
    return piVar1;
    piVar1 =(int *)HeapAlloc(DAT_10021954);
    if(piVar1 !=(int *)0x0){
    return piVar1;
    if(DAT_10021aac == 0){
    if(param_3 ==(undefined4 *)0x0){
    return(int *)0x0;
    iVar2 = __callnewh();
    }while(iVar2 != 0);
    if(param_3 !=(undefined4 *)0x0){
    else{
    piVar1 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    return(int *)0x0;

f FUN_1000f2ad(0):
  c:FUN_1000d764
  cf:
    FUN_1000d764();
    return;

f _realloc(2):
  c:_malloc,_free,__lock,___sbh_find_block,___sbh_resize_block,___sbh_alloc_block,_memcpy,___sbh_free_block,HeapAlloc,FUN_1000f413,HeapReAlloc,__errno,__callnewh,GetLastError,__get_errno_from_oserr
  g:DAT_10021954,LPVOID
  k:0x0,0xffffffe0
  cf:
    if(_Memory ==(void *)0x0){
    pvVar1 = _malloc();
    return pvVar1;
    if(_NewSize == 0){
    _free();
    return(void *)0x0;
    if(DAT_10022c5c == 3){
    do{
    local_20 =(int *)0x0;
    if((uint *)0xffffffe0 < _NewSize)goto LAB_1000f4a8;
    __lock();
    local_24 =(uint *)___sbh_find_block();
    if(local_24 !=(uint *)0x0){
    if(_NewSize <= DAT_10022c4c){
    iVar2 = ___sbh_resize_block();
    if(iVar2 == 0){
    local_20 = ___sbh_alloc_block();
    if(local_20 !=(int *)0x0){
    puVar3 =(uint *)(*(int *)((int)_Memory + -4)- 1);
    if(_NewSize <= puVar3){
    puVar3 =(uint *)_NewSize;
    _memcpy();
    local_24 =(uint *)___sbh_find_block();
    ___sbh_free_block();
    else{
    local_20 =(int *)_Memory;
    if(local_20 ==(int *)0x0){
    if((uint *)_NewSize ==(uint *)0x0){
    local_20 =(int *)HeapAlloc(DAT_10021954);
    if(local_20 !=(int *)0x0){
    puVar3 =(uint *)(*(int *)((int)_Memory + -4)- 1);
    if(_NewSize <= puVar3){
    puVar3 =(uint *)_NewSize;
    _memcpy();
    ___sbh_free_block();
    FUN_1000f413();
    if(local_24 ==(uint *)0x0){
    if((uint *)_NewSize ==(uint *)0x0){
    local_20 =(int *)HeapReAlloc(DAT_10021954);
    if(local_20 !=(int *)0x0){
    return local_20;
    if(DAT_10021aac == 0){
    piVar4 = __errno();
    if(local_24 !=(uint *)0x0){
    return(void *)0x0;
    goto LAB_1000f4d5;
    iVar2 = __callnewh();
    }while(iVar2 != 0);
    piVar4 = __errno();
    if(local_24 !=(uint *)0x0)goto LAB_1000f4b4;
    else{
    do{
    if((uint *)0xffffffe0 < _NewSize)goto LAB_1000f4a8;
    if((uint *)_NewSize ==(uint *)0x0){
    pvVar6 = HeapReAlloc(DAT_10021954);
    if(pvVar6 !=(LPVOID)0x0){
    return pvVar6;
    if(DAT_10021aac == 0){
    piVar4 = __errno();
    DVar5 = GetLastError();
    iVar2 = __get_errno_from_oserr();
    return(void *)0x0;
    iVar2 = __callnewh();
    }while(iVar2 != 0);
    piVar4 = __errno();
    DVar5 = GetLastError();
    iVar2 = __get_errno_from_oserr();
    return(void *)0x0;
    __callnewh();
    piVar4 = __errno();
    return(void *)0x0;

f FUN_1000f413(0):
  c:FUN_1000d764
  cf:
    FUN_1000d764();
    return;

f __initp_misc_cfltcvt_tab(0):
  c:__encode_pointer
  k:0x28
  cf:
    do{
    piVar1 =(int *)((int)&PTR_LAB_10020b30 + uVar3);
    iVar2 = __encode_pointer();
    }while(uVar3 < 0x28);
    return;

f FUN_1000f50b(1):
  cf:
    return;

f FUN_1000f51a(1):
  cf:
    return;

f ___crtInitCritSecAndSpinCount(2):
  c:InitializeCriticalSectionAndSpinCount
  cf:
    BVar1 = InitializeCriticalSectionAndSpinCount();
    return BVar1;

f __lseeki64_nolock(3):
  c:__get_osfhandle,__errno,SetFilePointer,GetLastError,__dosmaperr,CONCAT44
  g:LONG,HANDLE,CONCAT44
  k:0xffffffff,0x1f,0x40
  cf:
    local_8 =(LONG)_Offset;
    hFile =(HANDLE)__get_osfhandle();
    if(hFile ==(HANDLE)0xffffffff){
    piVar2 = __errno();
    else{
    DVar3 = SetFilePointer();
    if(DVar3 == 0xffffffff){
    DVar4 = GetLastError();
    if(DVar4 != 0){
    __dosmaperr();
    goto LAB_1000f5ba;
    pbVar1 =(byte *)((&DAT_10022c80)[_FileHandle >> 5] + 4 +(_FileHandle & 0x1fU)* 0x40);
    return CONCAT44(local_8,DVar3);

f __lseeki64(3):
  c:___doserrno,__errno,__invalid_parameter,___lock_fhandle,__lseeki64_nolock,FUN_1000f71d,CONCAT44
  g:CONCAT44
  k:0x1f,0x40,0x0
  cf:
    if(_FileHandle == -2){
    puVar1 = ___doserrno();
    piVar2 = __errno();
    else{
    if((-1 < _FileHandle)&&((uint)_FileHandle < DAT_10022c60)){
    iVar3 =(_FileHandle & 0x1fU)* 0x40;
    if((*(byte *)((&DAT_10022c80)[_FileHandle >> 5] + 4 + iVar3)& 1)== 0){
    puVar1 = ___doserrno();
    piVar2 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    else{
    ___lock_fhandle();
    if((*(byte *)((&DAT_10022c80)[_FileHandle >> 5] + 4 + iVar3)& 1)== 0){
    piVar2 = __errno();
    puVar1 = ___doserrno();
    else{
    local_28 = __lseeki64_nolock();
    FUN_1000f71d();
    goto LAB_1000f717;
    puVar1 = ___doserrno();
    piVar2 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    return CONCAT44(local_28._4_4_,(undefined4)local_28);

f FUN_1000f71d(0):
  c:__unlock_fhandle
  cf:
    __unlock_fhandle();
    return;

f __write_nolock(3):
  c:___doserrno,__errno,__invalid_parameter,__lseeki64_nolock,__isatty,GetLastError,elif,__getptd,GetConsoleMode,GetConsoleCP,_isleadbyte,_mbtowc,__putwch_nolock,__dosmaperr,__security_check_cookie
  g:DAT_10020030,WCHAR,LPOVERLAPPED,LPDWORD,LPCSTR,LPBOOL,CHAR,DWORD
  k:0xfffffffc,0x0,0x1f,0x40,0x24,0x20,0x200000000,0x80,0x13ff,0x13fe,0x6a8,0xd55,0x38,0x2,0x34
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    local_1ad0 =(WCHAR *)_Buf;
    local_1acc =(char *)0x0;
    if(_MaxCharCount == 0)goto LAB_1000fe4d;
    if(_Buf ==(void *)0x0){
    puVar3 = ___doserrno();
    piVar4 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    goto LAB_1000fe4d;
    piVar4 = &DAT_10022c80 +(_FileHandle >> 5);
    iVar8 =(_FileHandle & 0x1fU)* 0x40;
    cVar10 =(char)(*(char *)(*piVar4 + iVar8 + 0x24)* '\x02')>> 1;
    if(((cVar10 == '\x02')||(cVar10 == '\x01'))&&((~_MaxCharCount & 1)== 0)){
    puVar3 = ___doserrno();
    piVar4 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    goto LAB_1000fe4d;
    if((*(byte *)(*piVar4 + iVar8 + 4)& 0x20)!= 0){
    __lseeki64_nolock(0x200000000);
    iVar5 = __isatty();
    if((iVar5 == 0)||((*(byte *)(iVar8 + 4 + *piVar4)& 0x80)== 0)){
    if((*(byte *)((undefined4 *)(*piVar4 + iVar8)+ 1)& 0x80)== 0){
    (LPOVERLAPPED)0x0);
    if(BVar7 == 0){
    local_1ac4 = GetLastError();
    else{
    if(local_1acc !=(char *)0x0)goto LAB_1000fe4d;
    goto LAB_1000fdd3;
    if(cVar10 == '\0'){
    if(_MaxCharCount == 0)goto LAB_1000fe0f;
    do{
    local_1ac0 =(WCHAR *)0x0;
    uVar9 =(int)local_1ac8 -(int)local_1ad0;
    do{
    if(_MaxCharCount <= uVar9)break;
    pWVar13 =(WCHAR *)((int)local_1ac8 + 1);
    if((char)WVar1 == '\n'){
    *(char *)pWVar11 = '\r';
    pWVar11 =(WCHAR *)((int)pWVar11 + 1);
    local_1ac0 =(WCHAR *)((int)local_1ac0 + 1);
    *(char *)pWVar11 =(char)WVar1;
    pWVar11 =(WCHAR *)((int)pWVar11 + 1);
    local_1ac0 =(WCHAR *)((int)local_1ac0 + 1);
    }while(local_1ac0 <(WCHAR *)0x13ff);
    (LPDWORD)&local_1ad8,(LPOVERLAPPED)0x0);
    if(BVar7 == 0)goto LAB_1000fdbe;
    local_1acc = local_1acc +(int)local_1ad8;
    (piVar4 = local_1adc,(uint)((int)local_1ac8 -(int)local_1ad0)< _MaxCharCount));
    goto LAB_1000fdca;
    if(cVar10 == '\x02'){
    if(_MaxCharCount != 0){
    do{
    local_1ac8 =(WCHAR *)0x0;
    uVar9 =(int)local_1ac0 -(int)local_1ad0;
    do{
    if(_MaxCharCount <= uVar9)break;
    if(WVar1 == L'\n'){
    }while(local_1ac8 <(WCHAR *)0x13fe);
    (LPDWORD)&local_1ad8,(LPOVERLAPPED)0x0);
    if(BVar7 == 0)goto LAB_1000fdbe;
    local_1acc = local_1acc +(int)local_1ad8;
    (piVar4 = local_1adc,(uint)((int)local_1ac0 -(int)local_1ad0)< _MaxCharCount));
    goto LAB_1000fdca;
    elif(_MaxCharCount != 0){
    do{
    local_1ac8 =(WCHAR *)0x0;
    uVar9 =(int)local_1ac0 -(int)local_1ad0;
    do{
    if(_MaxCharCount <= uVar9)break;
    if(WVar1 == L'\n'){
    }while(local_1ac8 <(WCHAR *)0x6a8);
    pcVar12 =(char *)0x0;
    local_1414,0xd55,(LPCSTR)0x0,(LPBOOL)0x0);
    if(iVar5 == 0)goto LAB_1000fdbe;
    do{
    iVar5 -(int)pcVar12,(LPDWORD)&local_1ad8,(LPOVERLAPPED)0x0);
    if(BVar7 == 0){
    local_1ac4 = GetLastError();
    break;
    pcVar12 = pcVar12 +(int)local_1ad8;
    }while((int)pcVar12 < iVar5);
    goto LAB_1000fdca;
    else{
    p_Var6 = __getptd();
    local_1ae4 =(uint)(p_Var6->ptlocinfo->lc_category[0].wlocale ==(wchar_t *)0x0);
    BVar7 = GetConsoleMode();
    if((BVar7 == 0)||((local_1ae4 != 0 &&(cVar10 == '\0'))))goto LAB_1000fabe;
    local_1ae8 = GetConsoleCP();
    local_1ac8 =(WCHAR *)0x0;
    if(_MaxCharCount != 0){
    local_1ac0 =(WCHAR *)0x0;
    do{
    if(local_1add == '\0'){
    cVar10 =(char)*pWVar11;
    local_1ae4 =(uint)(cVar10 == '\n');
    if(*(int *)(iVar5 + 0x38)== 0){
    iVar5 = _isleadbyte();
    if(iVar5 == 0){
    goto LAB_1000f925;
    if((char *)((int)local_1ad0 +(_MaxCharCount -(int)pWVar11))<(char *)0x2){
    *(char *)(iVar8 + 0x34 + *piVar4)=(char)*pWVar11;
    *(undefined4 *)(iVar8 + 0x38 + *piVar4)= 1;
    break;
    iVar5 = _mbtowc();
    if(iVar5 == -1)break;
    pWVar11 =(WCHAR *)((int)pWVar11 + 1);
    local_1ac0 =(WCHAR *)((int)local_1ac0 + 1);
    else{
    local_10._0_1_ = *(CHAR *)(iVar5 + 0x34);
    *(undefined4 *)(iVar5 + 0x38)= 0;
    iVar5 = _mbtowc();
    if(iVar5 == -1)break;
    pWVar11 =(WCHAR *)((int)pWVar11 + 1);
    local_1ac0 =(WCHAR *)((int)local_1ac0 + 1);
    (LPCSTR)0x0,(LPBOOL)0x0);
    if(nNumberOfBytesToWrite == 0)break;
    (LPDWORD)&local_1ac8,(LPOVERLAPPED)0x0);
    if(BVar7 == 0)goto LAB_1000fdbe;
    local_1acc =(char *)((int)local_1ac0 + local_1ad4);
    if((int)local_1ac8 <(int)nNumberOfBytesToWrite)break;
    if(local_1ae4 != 0){
    (LPOVERLAPPED)0x0);
    if(BVar7 == 0)goto LAB_1000fdbe;
    if((int)local_1ac8 < 1)break;
    else{
    if((local_1add == '\x01')||(local_1add == '\x02')){
    local_1ac4 =(DWORD)(ushort)*pWVar11;
    local_1ae4 =(uint)(*pWVar11 == L'\n');
    if((local_1add == '\x01')||(local_1add == '\x02')){
    wVar2 = __putwch_nolock();
    if(wVar2 !=(wchar_t)local_1ac4)goto LAB_1000fdbe;
    if(local_1ae4 != 0){
    wVar2 = __putwch_nolock();
    if(wVar2 !=(wchar_t)local_1ac4)goto LAB_1000fdbe;
    }while(local_1ac0 < _MaxCharCount);
    goto LAB_1000fdca;
    if(local_1ac4 != 0){
    if(local_1ac4 == 5){
    piVar4 = __errno();
    puVar3 = ___doserrno();
    else{
    __dosmaperr();
    goto LAB_1000fe4d;
    if(((*(byte *)(iVar8 + 4 + *piVar4)& 0x40)== 0)||((char)*local_1ad0 != '\x1a')){
    piVar4 = __errno();
    puVar3 = ___doserrno();
    iVar8 = __security_check_cookie(0xfffffffc);
    return iVar8;

f if(1):
  c:GetLastError
  g:WCHAR,LPCSTR,LPBOOL,LPDWORD,LPOVERLAPPED
  k:0x0,0x6a8,0xd55
  cf:
    do{
    local_1ac8 =(WCHAR *)0x0;
    uVar9 =(int)local_1ac0 -(int)local_1ad0;
    do{
    if(_MaxCharCount <= uVar9)break;
    if(WVar1 == L'\n'){
    }while(local_1ac8 <(WCHAR *)0x6a8);
    pcVar12 =(char *)0x0;
    local_1414,0xd55,(LPCSTR)0x0,(LPBOOL)0x0);
    if(iVar5 == 0)goto LAB_1000fdbe;
    do{
    iVar5 -(int)pcVar12,(LPDWORD)&local_1ad8,(LPOVERLAPPED)0x0);
    if(BVar7 == 0){
    local_1ac4 = GetLastError();
    break;
    pcVar12 = pcVar12 +(int)local_1ad8;
    }while((int)pcVar12 < iVar5);
    goto LAB_1000fdca;

f __write(3):
  c:___doserrno,__errno,___lock_fhandle,__write_nolock,FUN_1000ff2c,__invalid_parameter
  k:0x1f,0x40,0x0
  cf:
    if(_FileHandle == -2){
    puVar1 = ___doserrno();
    piVar2 = __errno();
    else{
    if((-1 < _FileHandle)&&((uint)_FileHandle < DAT_10022c60)){
    iVar3 =(_FileHandle & 0x1fU)* 0x40;
    if((*(byte *)((&DAT_10022c80)[_FileHandle >> 5] + 4 + iVar3)& 1)!= 0){
    ___lock_fhandle();
    if((*(byte *)((&DAT_10022c80)[_FileHandle >> 5] + 4 + iVar3)& 1)== 0){
    piVar2 = __errno();
    puVar1 = ___doserrno();
    else{
    local_20 = __write_nolock();
    FUN_1000ff2c();
    return local_20;
    puVar1 = ___doserrno();
    piVar2 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    return -1;

f FUN_1000ff2c(0):
  c:__unlock_fhandle
  cf:
    __unlock_fhandle();
    return;

f __getbuf(1):
  c:__malloc_crt
  k:0x1000,0x0
  cf:
    pcVar1 =(char *)__malloc_crt(0x1000);
    if(pcVar1 ==(char *)0x0){
    _File->_base =(char *)&_File->_charbuf;
    else{
    return;

f __isatty(1):
  c:__errno,__invalid_parameter
  k:0x0
  cf:
    if(_FileHandle == -2){
    piVar1 = __errno();
    return 0;
    if((_FileHandle < 0)||(DAT_10022c60 <=(uint)_FileHandle)){
    piVar1 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    else{
    return uVar2;

f FUN_1000ffe3(0):
  cf:
    return &PTR_DAT_10020b58;

f __lock_file(1):
  c:EnterCriticalSection,__lock
  k:0x80105b
  cf:
    if((_File < &PTR_DAT_10020b58)||((FILE *)&DAT_10020db8 < _File)){
    EnterCriticalSection();
    else{
    __lock(0x80105b);
    return;

f __lock_file2(2):
  c:__lock,EnterCriticalSection
  k:0x14,0x10,0xc,0x8000,0x20
  cf:
    if(_Index < 0x14){
    __lock(0x10);
    *(uint *)((int)_File + 0xc)= *(uint *)((int)_File + 0xc)| 0x8000;
    return;
    EnterCriticalSection(0x20);
    return;

f __unlock_file(1):
  c:FUN_1000d764,LeaveCriticalSection
  k:0x10020db9,0x80105b
  cf:
    if(((FILE *)((int)&PTR_LAB_10020b54 + 3U)< _File)&&(_File <(FILE *)0x10020db9)){
    FUN_1000d764(0x80105b);
    return;
    LeaveCriticalSection();
    return;

f __unlock_file2(2):
  c:FUN_1000d764,LeaveCriticalSection
  k:0x14,0xc,0xffff7fff,0x10,0x20
  cf:
    if(_Index < 0x14){
    *(uint *)((int)_File + 0xc)= *(uint *)((int)_File + 0xc)& 0xffff7fff;
    FUN_1000d764(0x10);
    return;
    LeaveCriticalSection(0x20);
    return;

f __fileno(1):
  c:__errno,__invalid_parameter
  k:0x0
  cf:
    if(_File ==(FILE *)0x0){
    piVar1 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    else{
    return iVar2;

f __get_printf_count_output(0):
  g:DAT_10020030
  cf:
    return(uint)(DAT_10021b28 ==(DAT_10020030 | 1));

f __wctomb_s_l(5):
  c:__errno,__invalid_parameter,_LocaleUpdate,_memset,GetLastError,elif
  g:LAB_10010204,LPCSTR,LPBOOL
  k:0x0,0x7fffffff,0x16,0x14,0x100,0x70,0xfffffffd,0x7a,0x22
  cf:
    if((_MbCh ==(char *)0x0)&&(_SizeInBytes != 0)){
    if(_SizeConverted !=(int *)0x0){
    else{
    if(_SizeConverted !=(int *)0x0){
    if(0x7fffffff < _SizeInBytes){
    piVar2 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    return 0x16;
    _LocaleUpdate::_LocaleUpdate();
    if(*(int *)(local_14[0] + 0x14)== 0){
    if((ushort)_WCh < 0x100){
    if(lpMultiByteStr !=(char *)0x0){
    if(_Size == 0)goto LAB_1001029b;
    *lpMultiByteStr =(char)_WCh;
    if(_SizeConverted !=(int *)0x0){
    if(local_8 != '\0'){
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    goto LAB_10010204;
    if((lpMultiByteStr !=(char *)0x0)&&(_Size != 0)){
    _memset();
    else{
    _MbCh =(char *)0x0;
    (LPCSTR)0x0,(LPBOOL)&_MbCh);
    if(iVar1 == 0){
    DVar3 = GetLastError();
    if(DVar3 == 0x7a){
    if((lpMultiByteStr !=(char *)0x0)&&(_Size != 0)){
    _memset();
    piVar2 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    if(local_8 == '\0'){
    return 0x22;
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    return 0x22;
    elif(_MbCh ==(char *)0x0){
    if(_SizeConverted !=(int *)0x0){
    goto LAB_100102d6;
    piVar2 = __errno();
    if(local_8 != '\0'){
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    return iVar1;

f _wctomb_s(4):
  c:__wctomb_s_l
  k:0x0
  cf:
    eVar1 = __wctomb_s_l(0x0);
    return eVar1;

f __isleadbyte_l(2):
  c:_LocaleUpdate
  k:0xff,0x70,0xfffffffd,0x8000,200
  cf:
    _LocaleUpdate::_LocaleUpdate();
    uVar1 = *(ushort *)(*(int *)(local_14[0] + 200)+(_C & 0xffU)* 2);
    if(local_8 != '\0'){
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    return uVar1 & 0x8000;

f _isleadbyte(1):
  c:__isleadbyte_l
  k:0x0
  cf:
    iVar1 = __isleadbyte_l(0x0);
    return iVar1;

f __aulldvrm(4):
  c:CONCAT44,CARRY4
  g:CONCAT44,CARRY4
  k:0x1f,0xffffffff,0x20
  cf:
    if(param_4 == 0){
    (ulonglong)param_3);
    else{
    do{
    uVar9 = uVar9 >> 1 |(uint)((uVar8 & 1)!= 0)<< 0x1f;
    uVar3 = uVar3 >> 1 |(uint)((uVar6 & 1)!= 0)<< 0x1f;
    }while(uVar5 != 0);
    uVar1 = CONCAT44()/(ulonglong)uVar9;
    iVar4 =(int)uVar1;
    lVar2 =(ulonglong)param_3 *(uVar1 & 0xffffffff);
    uVar3 =(uint)((ulonglong)lVar2 >> 0x20);
    if(((CARRY4(uVar3,iVar4 * param_4))||(param_2 < uVar8))||
    return CONCAT44(uVar3,iVar4);

f x_ismbbtype_l(4):
  c:_LocaleUpdate
  g:LAB_10010499
  k:0x1d,0xff,0x70,0xfffffffd,200
  cf:
    _LocaleUpdate::_LocaleUpdate();
    if((*(byte *)(local_10 + 0x1d +(param_2 & 0xff))&(byte)param_4)== 0){
    if(param_3 == 0){
    else{
    uVar1 =(uint)*(ushort *)(*(int *)(local_14 + 200)+(param_2 & 0xff)* 2)& param_3;
    if(uVar1 == 0)goto LAB_10010499;
    if(local_8 != '\0'){
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    return uVar1;

f __ismbblead(1):
  c:x_ismbbtype_l
  k:0x0
  cf:
    iVar1 = x_ismbbtype_l(0x0);
    return iVar1;

f __global_unwind2(1):
  c:RtlUnwind
  k:0x100104d8,0x0
  cf:
    RtlUnwind(0x100104d8,0x0,0x0);
    return;

f __local_unwind2(2):
  c:__NLG_Notify,FUN_100105f4
  k:0xc,0xffffffff,0x101
  cf:
    while(true){
    uVar1 = *(uint *)(param_1 + 0xc);
    if((uVar1 == 0xffffffff)||((param_2 != 0xffffffff &&(uVar1 <= param_2))))break;
    local_18 = *(undefined4 *)(*(int *)(param_1 + 8)+ uVar1 * 0xc);
    *(undefined4 *)(param_1 + 0xc)= local_18;
    if(*(int *)(*(int *)(param_1 + 8)+ 4 + uVar1 * 0xc)== 0){
    __NLG_Notify(0x101);
    FUN_100105f4();
    return;

f __NLG_Notify1(1):
  cf:
    return in_EAX;

f __NLG_Notify(1):
  cf:
    return;

f FUN_100105f4(0):
  cf:
    (*in_EAX)();
    return;

f __isctype_l(3):
  c:_LocaleUpdate,__isleadbyte_l
  g:CHAR,BOOL
  k:0x101,0xff,0x70,0xfffffffd
  cf:
    _LocaleUpdate::_LocaleUpdate();
    if(_C + 1U < 0x101){
    local_8[0] = *(ushort *)(local_1c.locinfo[1].lc_category[0].locale + _C * 2);
    else{
    iVar1 = __isleadbyte_l(0xff);
    CVar3 =(CHAR)_C;
    if(iVar1 == 0){
    else{
    _C._0_1_ =(CHAR)((uint)_C >> 8);
    local_c =(CHAR)_C;
    (BOOL)(local_1c.locinfo)->lc_category[0].wlocale);
    if(BVar2 == 0){
    if(local_10 != '\0'){
    *(uint *)(local_14 + 0x70)= *(uint *)(local_14 + 0x70)& 0xfffffffd;
    return 0;
    if(local_10 != '\0'){
    *(uint *)(local_14 + 0x70)= *(uint *)(local_14 + 0x70)& 0xfffffffd;
    return(uint)local_8[0] & _Type;

f _atol(1):
  c:_strtol
  k:0x0
  cf:
    lVar1 = _strtol(0x0);
    return lVar1;

f __alloca_probe(0):
  k:0xfffff000
  cf:
    for(puVar1 =(undefined4 *)((uint)auStack_4 & 0xfffff000);puVar2 < puVar1;
    return;

f __free_osfhnd(1):
  c:elif,SetStdHandle,__errno,___doserrno
  g:DAT_10021164,LAB_10010796
  k:0x1f,0x40,0x0,0xffffffff
  cf:
    if((-1 < param_1)&&((uint)param_1 < DAT_10022c60)){
    iVar3 =(param_1 & 0x1fU)* 0x40;
    piVar1 =(int *)((&DAT_10022c80)[param_1 >> 5] + iVar3);
    if(((*(byte *)(piVar1 + 1)& 1)!= 0)&&(*piVar1 != -1)){
    if(DAT_10021164 == 1){
    if(param_1 == 0){
    elif(param_1 == 1){
    else{
    if(param_1 != 2)goto LAB_10010796;
    SetStdHandle(0x0);
    *(undefined4 *)(iVar3 +(&DAT_10022c80)[param_1 >> 5])= 0xffffffff;
    return 0;
    piVar1 = __errno();
    puVar2 = ___doserrno();
    return -1;

f if(1):

f __get_osfhandle(1):
  c:___doserrno,__errno,__invalid_parameter
  k:0x0
  cf:
    if(_FileHandle == -2){
    puVar1 = ___doserrno();
    piVar2 = __errno();
    return -1;
    if(((_FileHandle < 0)||(DAT_10022c60 <=(uint)_FileHandle))||
    puVar1 = ___doserrno();
    piVar2 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    else{
    return iVar4;

f ___lock_fhandle(1):
  c:__lock,___crtInitCritSecAndSpinCount,FUN_100108c8
  k:0x1f,0x40,0xc,4000
  cf:
    iVar2 =(_Filehandle & 0x1fU)* 0x40 +(&DAT_10022c80)[_Filehandle >> 5];
    if(*(int *)(iVar2 + 8)== 0){
    __lock();
    if(*(int *)(iVar2 + 8)== 0){
    BVar1 = ___crtInitCritSecAndSpinCount(0xc,4000);
    local_20 =(uint)(BVar1 != 0);
    *(int *)(iVar2 + 8)= *(int *)(iVar2 + 8)+ 1;
    FUN_100108c8();
    if(local_20 != 0){
    ((&DAT_10022c80)[_Filehandle >> 5] + 0xc +(_Filehandle & 0x1fU)* 0x40));
    return local_20;

f FUN_100108c8(0):
  c:FUN_1000d764
  cf:
    FUN_1000d764();
    return;

f __unlock_fhandle(1):
  k:0xc,0x1f,0x40
  cf:
    ((&DAT_10022c80)[_Filehandle >> 5] + 0xc +(_Filehandle & 0x1fU)* 0x40));
    return;

f __putwch_nolock(1):
  c:___initconout,WriteConsoleW,GetLastError,GetConsoleOutputCP,WriteConsoleA,__security_check_cookie
  g:DAT_10020030,HANDLE,LPBOOL,LPCSTR
  k:0xfffffffc,0xfffffffe,0xffffffff,0x0,0x78
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if(DAT_10020ea0 != 0){
    if(DAT_10020f14 ==(HANDLE)0xfffffffe){
    ___initconout();
    if(DAT_10020f14 ==(HANDLE)0xffffffff)goto LAB_100109a4;
    BVar2 = WriteConsoleW(0x0);
    if(BVar2 != 0){
    goto LAB_100109a4;
    if((DAT_10020ea0 != 2)||(DVar3 = GetLastError(),DVar3 != 0x78))goto LAB_100109a4;
    lpUsedDefaultChar =(LPBOOL)0x0;
    lpDefaultChar =(LPCSTR)0x0;
    CodePage = GetConsoleOutputCP();
    if(DAT_10020f14 !=(HANDLE)0xffffffff){
    WriteConsoleA(0x0);
    wVar1 = __security_check_cookie(0xfffffffc);
    return wVar1;

f __mbtowc_l(4):
  c:_LocaleUpdate,__isleadbyte_l,__errno
  k:0x0,0x70,0xfffffffd
  cf:
    if((_SrcCh !=(char *)0x0)&&(_SrcSizeInBytes != 0)){
    if(*_SrcCh != '\0'){
    _LocaleUpdate::_LocaleUpdate();
    if((local_14.locinfo)->lc_category[0].wlocale !=(wchar_t *)0x0){
    iVar2 = __isleadbyte_l();
    if(iVar2 == 0){
    (uint)(_DstCh !=(wchar_t *)0x0));
    if(iVar2 != 0)goto LAB_10010a0c;
    else{
    pwVar1 =(local_14.locinfo)->locale_name[3];
    if((((1 <(int)pwVar1)&&((int)pwVar1 <=(int)_SrcSizeInBytes))&&
    pwVar1 =(local_14.locinfo)->locale_name[3];
    if(local_8 == '\0'){
    return(int)pwVar1;
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    return(int)pwVar1;
    piVar3 = __errno();
    if(local_8 != '\0'){
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    return -1;
    if(_DstCh !=(wchar_t *)0x0){
    *_DstCh =(ushort)(byte)*_SrcCh;
    if(local_8 != '\0'){
    *(uint *)(local_c + 0x70)= *(uint *)(local_c + 0x70)& 0xfffffffd;
    return 1;
    if(_DstCh !=(wchar_t *)0x0){
    return 0;

f _mbtowc(3):
  c:__mbtowc_l
  k:0x0
  cf:
    iVar1 = __mbtowc_l(0x0);
    return iVar1;

f __flush(1):
  c:__fileno,__write
  k:0x108
  cf:
    if((((byte)_File->_flag & 3)== 2)&&((_File->_flag & 0x108U)!= 0)){
    uVar3 =(int)_File->_ptr -(int)_Buf;
    if(0 <(int)uVar3){
    _FileHandle = __fileno();
    uVar1 = __write();
    if(uVar1 == uVar3){
    if((char)_File->_flag < '\0'){
    else{
    return iVar2;

f __fflush_nolock(1):
  c:flsall,__flush,__fileno,__commit
  k:0x0,0x4000
  cf:
    if(_File ==(FILE *)0x0){
    iVar1 = flsall();
    else{
    iVar1 = __flush();
    if(iVar1 == 0){
    if((_File->_flag & 0x4000U)== 0){
    else{
    iVar1 = __fileno();
    iVar1 = __commit();
    iVar1 = -(uint)(iVar1 != 0);
    else{
    return iVar1;

f flsall(1):
  c:__lock,__lock_file2,__fflush_nolock,elif,FUN_10010cdf,FUN_10010d0e
  g:FILE
  k:0xc,0x83
  cf:
    __lock();
    for(_Index = 0;_Index < DAT_10022c40;_Index = _Index + 1){
    piVar1 =(int *)(DAT_10021c28 + _Index * 4);
    if((*piVar1 != 0)&&(_File =(void *)*piVar1,(*(byte *)((int)_File + 0xc)& 0x83)!= 0)){
    __lock_file2();
    _File_00 = *(FILE **)(DAT_10021c28 + _Index * 4);
    if((_File_00->_flag & 0x83U)!= 0){
    if(param_1 == 1){
    iVar2 = __fflush_nolock();
    if(iVar2 != -1){
    elif((param_1 == 0)&&((_File_00->_flag & 2U)!= 0)){
    iVar2 = __fflush_nolock();
    if(iVar2 == -1){
    FUN_10010cdf();
    FUN_10010d0e();
    if(param_1 != 1){
    return local_20;

f FUN_10010cdf(0):
  c:__unlock_file2
  cf:
    __unlock_file2();
    return;

f FUN_10010d0e(0):
  c:FUN_1000d764
  cf:
    FUN_1000d764();
    return;

f strtoxl(5):
  c:_LocaleUpdate,__errno,__invalid_parameter,__isctype_l,elif
  k:0x0,0x24,0x70,0xfffffffd,0x2d,0x2b,0x30,0x78,0x58,0x10,0xffffffff,0x103,0x7fffffff,0x9f,0x1a
  cf:
    _LocaleUpdate::_LocaleUpdate();
    if(param_3 !=(char **)0x0){
    if((param_2 ==(char *)0x0)||((param_4 != 0 &&((param_4 < 2 ||(0x24 < param_4)))))){
    piVar3 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    if(local_c != '\0'){
    *(uint *)(local_10 + 0x70)= *(uint *)(local_10 + 0x70)& 0xfffffffd;
    return 0;
    pbVar2 =(byte *)param_2;
    while(true){
    if((int)ptVar5->locale_name[3] < 2){
    uVar4 = *(ushort *)(ptVar5[1].lc_category[0].locale +(uint)bVar8 * 2)& 8;
    else{
    uVar4 = __isctype_l();
    if(uVar4 == 0)break;
    if(bVar8 == 0x2d){
    elif(bVar8 == 0x2b)goto LAB_10010dd9;
    if(((param_4 < 0)||(param_4 == 1))||(0x24 < param_4)){
    if(param_3 !=(char **)0x0){
    if(local_c != '\0'){
    *(uint *)(local_10 + 0x70)= *(uint *)(local_10 + 0x70)& 0xfffffffd;
    return 0;
    if(param_4 == 0){
    if(bVar8 != 0x30){
    goto LAB_10010e3f;
    if((*pbVar9 != 0x78)&&(*pbVar9 != 0x58)){
    goto LAB_10010e3f;
    elif((param_4 != 0x10)||(bVar8 != 0x30))goto LAB_10010e3f;
    if((*pbVar9 == 0x78)||(*pbVar9 == 0x58)){
    uVar4 =(uint)(0xffffffff /(ulonglong)(uint)param_4);
    do{
    uVar1 = *(ushort *)(ptVar5[1].lc_category[0].locale +(uint)bVar8 * 2);
    if((uVar1 & 4)== 0){
    if((uVar1 & 0x103)== 0){
    if((param_5 & 8U)== 0){
    if(param_3 !=(char **)0x0){
    pbVar9 =(byte *)param_2;
    elif(((param_5 & 4U)!= 0)||
    piVar3 = __errno();
    if((param_5 & 1U)== 0){
    local_8 =((param_5 & 2U)!= 0)+ 0x7fffffff;
    else{
    if(param_3 !=(char **)0x0){
    *param_3 =(char *)pbVar9;
    if((param_5 & 2U)!= 0){
    if(local_c == '\0'){
    return local_8;
    *(uint *)(local_10 + 0x70)= *(uint *)(local_10 + 0x70)& 0xfffffffd;
    return local_8;
    iVar7 =(int)(char)bVar8;
    if((byte)(bVar8 + 0x9f)< 0x1a){
    else{
    uVar6 =(int)(char)bVar8 - 0x30;
    if((uint)param_4 <= uVar6)goto LAB_10010e9c;
    if((local_8 < uVar4)||
    else{
    if(param_3 ==(char **)0x0)goto LAB_10010e9c;
    }while(true);

f _strtol(3):
  c:strtoxl
  k:0x0
  cf:
    if(DAT_100217e8 == 0){
    else{
    ppuVar2 =(undefined **)0x0;
    uVar1 = strtoxl();
    return uVar1;

f ___ascii_strnicmp(3):
  c:CONCAT11,CONCAT31
  g:CONCAT11,CONCAT31
  k:0x40,0x5b,0x20
  cf:
    if(_MaxCount != 0){
    do{
    uVar3 = CONCAT11();
    if(bVar2 == 0)break;
    uVar3 = CONCAT11();
    uVar4 =(uint)uVar3;
    if(cVar1 == '\0')break;
    _Str1 =(char *)((byte *)_Str1 + 1);
    if((0x40 < bVar2)&&(bVar2 < 0x5b)){
    uVar4 =(uint)CONCAT11(0x20);
    uVar3 =(ushort)uVar4;
    bVar2 =(byte)uVar4;
    if((0x40 < bVar2)&&(bVar2 < 0x5b)){
    uVar3 =(ushort)CONCAT31(0x20);
    bVar2 =(byte)(uVar3 >> 8);
    bVar5 = bVar2 <(byte)uVar3;
    if(bVar2 !=(byte)uVar3)goto LAB_10010fd1;
    }while(_MaxCount != 0);
    bVar2 =(byte)(uVar3 >> 8);
    bVar5 = bVar2 <(byte)uVar3;
    if(bVar2 !=(byte)uVar3){
    if(!bVar5){
    return _MaxCount;

f ___initconout(0):
  c:CreateFileA
  g:S26
  k:0x40000000,0x0
  cf:
    DAT_10020f14 = CreateFileA(S26,0x40000000,0x0,0x0);
    return;

f __fclose_nolock(1):
  c:__errno,__invalid_parameter,__flush,__freebuf,__fileno,__close,elif,_free
  k:0x0,0x83
  cf:
    if(_File ==(FILE *)0x0){
    piVar1 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    else{
    if((_File->_flag & 0x83)!= 0){
    iVar3 = __flush();
    __freebuf();
    iVar2 = __fileno();
    iVar2 = __close();
    if(iVar2 < 0){
    elif(_File->_tmpfname !=(char *)0x0){
    _free();
    _File->_tmpfname =(char *)0x0;
    return iVar3;

f __commit(1):
  c:__errno,___lock_fhandle,__get_osfhandle,FlushFileBuffers,GetLastError,___doserrno,FUN_100111f7,__invalid_parameter
  g:HANDLE
  k:0x1f,0x40,0x0
  cf:
    if(_FileHandle == -2){
    piVar1 = __errno();
    else{
    if((-1 < _FileHandle)&&((uint)_FileHandle < DAT_10022c60)){
    iVar4 =(_FileHandle & 0x1fU)* 0x40;
    if((*(byte *)(iVar4 + 4 +(&DAT_10022c80)[_FileHandle >> 5])& 1)!= 0){
    ___lock_fhandle();
    if((*(byte *)(iVar4 + 4 +(&DAT_10022c80)[_FileHandle >> 5])& 1)!= 0){
    hFile =(HANDLE)__get_osfhandle();
    BVar2 = FlushFileBuffers();
    if(BVar2 == 0){
    local_20 = GetLastError();
    else{
    if(local_20 == 0)goto LAB_100111e2;
    puVar3 = ___doserrno();
    piVar1 = __errno();
    FUN_100111f7();
    return local_20;
    piVar1 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    return -1;

f FUN_100111f7(0):
  c:__unlock_fhandle
  cf:
    __unlock_fhandle();
    return;

f __close_nolock(1):
  c:__get_osfhandle,CloseHandle,GetLastError,__free_osfhnd,__dosmaperr
  g:LAB_10011267,HANDLE,LAB_10011269
  k:0x84,0x1f,0x40
  cf:
    iVar1 = __get_osfhandle();
    if(iVar1 != -1){
    if(((_FileHandle == 1)&&((*(byte *)(DAT_10022c80 + 0x84)& 1)!= 0))||
    iVar1 = __get_osfhandle();
    iVar2 = __get_osfhandle();
    if(iVar2 == iVar1)goto LAB_10011267;
    hObject =(HANDLE)__get_osfhandle();
    BVar3 = CloseHandle();
    if(BVar3 == 0){
    DVar4 = GetLastError();
    goto LAB_10011269;
    __free_osfhnd();
    *(undefined1 *)((&DAT_10022c80)[_FileHandle >> 5] + 4 +(_FileHandle & 0x1fU)* 0x40)= 0;
    if(DVar4 == 0){
    else{
    __dosmaperr();
    return iVar5;

f __close(1):
  c:___doserrno,__errno,___lock_fhandle,__close_nolock,FUN_10011360,__invalid_parameter
  g:FUN_10011360
  k:0x1f,0x40,0x0
  cf:
    if(_FileHandle == -2){
    puVar1 = ___doserrno();
    piVar2 = __errno();
    else{
    if((-1 < _FileHandle)&&((uint)_FileHandle < DAT_10022c60)){
    iVar3 =(_FileHandle & 0x1fU)* 0x40;
    if((*(byte *)((&DAT_10022c80)[_FileHandle >> 5] + 4 + iVar3)& 1)!= 0){
    ___lock_fhandle();
    if((*(byte *)((&DAT_10022c80)[_FileHandle >> 5] + 4 + iVar3)& 1)== 0){
    piVar2 = __errno();
    else{
    local_20 = __close_nolock();
    FUN_10011360();
    return local_20;
    puVar1 = ___doserrno();
    piVar2 = __errno();
    __invalid_parameter(0x0,0x0,0x0);
    return -1;

f FUN_10011360(0):
  c:__unlock_fhandle
  cf:
    __unlock_fhandle();
    return;

f __freebuf(1):
  c:_free
  k:0x83,0x0
  cf:
    if(((_File->_flag & 0x83U)!= 0)&&((_File->_flag & 8U)!= 0)){
    _free();
    _File->_ptr =(char *)0x0;
    _File->_base =(char *)0x0;
    return;

f FUN_1001146e(2):
  c:FID_conflict_runtime_error
  cf:
    FID_conflict_runtime_error();
    *(undefined ***)this = std::out_of_range::vftable;
    return(undefined4 *)this;

f FUN_10011496(2):
  c:FID_conflict__logic_error,FUN_10008417
  g:FUN_10008417
  cf:
    *(undefined ***)this = std::out_of_range::vftable;
    FID_conflict__logic_error();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(exception *)this;

f FUN_100114bd(0):
  c:FID_conflict_length_error,__CxxThrowException_8,swi
  g:S27
  cf:
    basic_string<>(local_2c,S27);
    FID_conflict_length_error();
    __CxxThrowException_8();
    pcVar1 =(code *)swi();
    (*pcVar1)();
    return;

f FUN_100114f5(0):
  c:FUN_1001146e,__CxxThrowException_8,swi
  g:S28
  cf:
    basic_string<>(local_2c,S28);
    FUN_1001146e();
    __CxxThrowException_8();
    pcVar1 =(code *)swi();
    (*pcVar1)();
    return;

f FUN_1001152d(2):
  c:FID_conflict_runtime_error
  cf:
    FID_conflict_runtime_error();
    *(undefined ***)this = std::out_of_range::vftable;
    return(undefined4 *)this;

f WinUsb_QueryDeviceInformation(0):
  c:WinUsb_QueryDeviceInformation
  cf:
    WinUsb_QueryDeviceInformation();
    return;

f WinUsb_QueryPipe(0):
  c:WinUsb_QueryPipe
  cf:
    WinUsb_QueryPipe();
    return;

f WinUsb_QueryInterfaceSettings(0):
  c:WinUsb_QueryInterfaceSettings
  cf:
    WinUsb_QueryInterfaceSettings();
    return;

f WinUsb_Initialize(0):
  c:WinUsb_Initialize
  cf:
    WinUsb_Initialize();
    return;

f WinUsb_SetPipePolicy(0):
  c:WinUsb_SetPipePolicy
  cf:
    WinUsb_SetPipePolicy();
    return;

f WinUsb_ReadPipe(0):
  c:WinUsb_ReadPipe
  cf:
    WinUsb_ReadPipe();
    return;

f WinUsb_FlushPipe(0):
  c:WinUsb_FlushPipe
  cf:
    WinUsb_FlushPipe();
    return;

f WinUsb_WritePipe(0):
  c:WinUsb_WritePipe
  cf:
    WinUsb_WritePipe();
    return;

f WinUsb_Free(0):
  c:WinUsb_Free
  cf:
    WinUsb_Free();
    return;

f RtlUnwind(4):
  c:RtlUnwind
  cf:
    RtlUnwind();
    return;

f _JumpToContinuation(2):
  cf:
    (*(code *)param_1)();
    return;

f FID_conflict__CallMemberFunction1(2):
  c:LOCK,UNLOCK
  g:LOCK,UNLOCK
  cf:
    LOCK();
    UNLOCK();
    (*(code *)UNRECOVERED_JUMPTABLE)();
    return;

f _UnwindNestedFrames(2):
  c:RtlUnwind
  k:0x100115ea,0x0,0xfffffffd
  cf:
    RtlUnwind(0x100115ea,0x0);
    *(uint *)(param_2 + 4)= *(uint *)(param_2 + 4)& 0xfffffffd;
    *(void **)pvVar1 = ExceptionList;
    return;

f FID_conflict____CxxFrameHandler3(4):
  k:0x0
  cf:
    (param_1,param_2,param_3,param_4,in_EAX,0,(EHRegistrationNode *)0x0,'\0');
    return uVar1;

f CatchGuardHandler(4):
  c:__security_check_cookie
  cf:
    __security_check_cookie();
    (EHRegistrationNode *)param_2,'\0');
    return _Var1;

f _CallSETranslator(7):
  c:__getptd
  g:DAT_10020030
  k:0x123,0x10011727
  cf:
    if(param_1 ==(EHExceptionRecord *)0x123){
    *(undefined4 *)param_2 = 0x10011727;
    else{
    local_24 = DAT_10020030 ^(uint)&local_2c;
    local_2c =(undefined4 *)ExceptionList;
    p_Var1 = __getptd();
    local_30 =(code *)p_Var1->_translator;
    (*local_30)(*(undefined4 *)param_1,&local_38);
    if(local_8 != 0){
    return local_3c;

f TranslatorGuardHandler(4):
  c:__security_check_cookie,_UnwindNestedFrames
  k:0x66,0x24,0x18,0x0
  cf:
    __security_check_cookie();
    if((*(uint *)(param_1 + 4)& 0x66)!= 0){
    *(undefined4 *)(param_2 + 0x24)= 1;
    return 1;
    *(EHRegistrationNode **)(param_2 + 0x18),'\x01');
    if(*(int *)(param_2 + 0x24)== 0){
    _UnwindNestedFrames();
    (void *)0x0,(_s_FuncInfo *)0x0,0,(EHRegistrationNode *)0x0);
    _Var1 =(*local_8)();
    return _Var1;

f _GetRangeOfTrysToCheck(5):
  c:_inconsistency
  k:0xffffffff
  cf:
    while(uVar4 = uVar2,-1 < param_2){
    if(uVar5 == 0xffffffff){
    _inconsistency();
    if(((pTVar1[uVar5].tryHigh < param_3)&&(param_3 <= pTVar1[uVar5].catchHigh))||
    if((param_1->nTryBlocks < uVar3)||(uVar3 < uVar5)){
    _inconsistency();
    return pTVar1 + uVar5;

f __CreateFrameInfo(2):
  c:__getptd
  cf:
    p_Var1 = __getptd();
    return param_1;

f __IsExceptionObjectToBeDestroyed(1):
  c:__getptd
  k:0x0
  cf:
    p_Var1 = __getptd();
    piVar2 =(int *)p_Var1->_pFrameInfoChain;
    while(true){
    if(piVar2 ==(int *)0x0){
    return 1;
    if(*piVar2 == param_1)break;
    piVar2 =(int *)piVar2[1];
    return 0;

f __FindAndUnlinkFrame(1):
  c:__getptd,_inconsistency
  cf:
    p_Var2 = __getptd();
    if(param_1 == p_Var2->_pFrameInfoChain){
    p_Var2 = __getptd();
    p_Var2->_pFrameInfoChain = *(void **)((int)param_1 + 4);
    else{
    p_Var2 = __getptd();
    do{
    if(*(int *)((int)pvVar3 + 4)== 0){
    _inconsistency();
    return;
    pvVar1 = *(void **)((int)pvVar3 + 4);
    }while(param_1 != *(void **)((int)pvVar3 + 4));
    *(undefined4 *)((int)pvVar3 + 4)= *(undefined4 *)((int)param_1 + 4);
    return;

f _CallCatchBlock2(5):
  c:__CallSettingFrame_12
  g:DAT_10020030
  cf:
    local_14 = DAT_10020030 ^(uint)&local_1c;
    pvVar1 =(void *)__CallSettingFrame_12();
    return pvVar1;

f __EH_prolog3(1):
  g:DAT_10020030
  k:0x10,0xc
  cf:
    *(undefined4 *)((int)auStack_1c + iVar1 + 0x10)= unaff_EBX;
    *(undefined4 *)((int)auStack_1c + iVar1 + 0xc)= unaff_ESI;
    *(undefined4 *)((int)auStack_1c + iVar1 + 8)= unaff_EDI;
    *(uint *)((int)auStack_1c + iVar1 + 4)= DAT_10020030 ^(uint)&param_1;
    *(undefined4 *)((int)auStack_1c + iVar1)= unaff_retaddr;
    return;

f __EH_prolog3_catch(1):
  g:DAT_10020030
  k:0x10,0xc
  cf:
    *(undefined4 *)((int)auStack_1c + iVar1 + 0x10)= unaff_EBX;
    *(undefined4 *)((int)auStack_1c + iVar1 + 0xc)= unaff_ESI;
    *(undefined4 *)((int)auStack_1c + iVar1 + 8)= unaff_EDI;
    *(uint *)((int)auStack_1c + iVar1 + 4)= DAT_10020030 ^(uint)&param_1;
    *(undefined4 *)((int)auStack_1c + iVar1)= unaff_retaddr;
    return;

f FUN_100119fe(2):
  c:exception,FUN_10008417
  g:FUN_10008417
  cf:
    *(undefined ***)this = std::bad_exception::vftable;
    exception::~exception();
    if((param_1 & 1)!= 0){
    FUN_10008417();
    return(exception *)this;

f ___TypeMatch(3):
  c:_strcmp
  cf:
    iVar1 = *(int *)(param_1 + 4);
    if((iVar1 == 0)||(*(char *)(iVar1 + 8)== '\0')){
    else{
    if(iVar1 == *(int *)(param_2 + 4)){
    if(((((*param_2 & 2)== 0)||((*param_1 & 8)!= 0))&&
    (((*param_3 & 2)== 0 ||((*param_1 & 2)!= 0))))goto LAB_10011a7d;
    else{
    iVar1 = _strcmp();
    if(iVar1 == 0)goto LAB_10011a5c;
    return uVar2;

f ___FrameUnwindFilter(1):
  c:__getptd,elif,terminate
  k:0x1fbcb0b3,0x1f928c9d
  cf:
    if(*(int *)*param_1 == -0x1fbcb0b3){
    p_Var1 = __getptd();
    if(0 < p_Var1->_ProcessingThrow){
    p_Var1 = __getptd();
    elif(*(int *)*param_1 == -0x1f928c9d){
    p_Var1 = __getptd();
    terminate();
    return extraout_EAX;
    return 0;

f ___FrameUnwindToState(4):
  c:__getptd,_inconsistency,__CallSettingFrame_12,FUN_10011b93
  k:0x81,0x103
  cf:
    if(*(int *)(param_3 + 4)< 0x81){
    iVar4 =(int)*(char *)(param_1 + 8);
    else{
    iVar4 = *(int *)(param_1 + 8);
    p_Var1 = __getptd();
    while(iVar4 != param_4){
    if((iVar4 < 0)||(*(int *)(param_3 + 4)<= iVar4)){
    _inconsistency();
    piVar3 =(int *)(*(int *)(param_3 + 8)+ iVar2);
    if(piVar3[1] != 0){
    *(int *)(param_1 + 8)= iVar4;
    __CallSettingFrame_12(0x103);
    FUN_10011b93();
    if(iVar4 != param_4){
    _inconsistency();
    *(int *)(param_1 + 8)= iVar4;
    return;

f FUN_10011b93(0):
  c:__getptd
  cf:
    p_Var1 = __getptd();
    if(0 < p_Var1->_ProcessingThrow){
    p_Var1 = __getptd();
    return;

f ___DestructExceptionObject(1):
  c:FID_conflict__CallMemberFunction1
  g:UNRECOVERED_JUMPTABLE
  k:0x0,0x1f928c9d
  cf:
    if((((param_1 !=(int *)0x0)&&(*param_1 == -0x1f928c9d))&&(param_1[7] != 0))&&
    FID_conflict__CallMemberFunction1(UNRECOVERED_JUMPTABLE);
    return;

f ___AdjustPointer(2):
  cf:
    if(-1 < param_2[1]){
    iVar1 = iVar1 + *(int *)(*(int *)(param_2[1] + param_1)+ param_2[2])+ param_2[1];
    return iVar1;

f IsInExceptionSpec(2):
  c:_inconsistency,terminate
  k:0x0,0x1c,0xc
  cf:
    if(unaff_EDI ==(int *)0x0){
    _inconsistency();
    terminate();
    if(0 < *unaff_EDI){
    do{
    piVar3 = *(int **)(*(int *)(param_1 + 0x1c)+ 0xc);
    if(0 < iVar2){
    do{
    *(uint **)(param_1 + 0x1c));
    if(iVar1 != 0){
    break;
    }while(0 < iVar2);
    }while(local_c < *unaff_EDI);
    return local_5;

f FUN_10011cec(1):
  c:__getptd,_inconsistency,FUN_10009960,terminate,__CxxThrowException_8,swi
  g:FUN_10009960
  k:0x0
  cf:
    p_Var2 = __getptd();
    if(p_Var2->_curexcspec !=(void *)0x0){
    _inconsistency();
    FUN_10009960();
    terminate();
    p_Var2 = __getptd();
    __CxxThrowException_8(0x0);
    pcVar1 =(code *)swi();
    (*pcVar1)();
    return;

f Catch_All_10011d1d(0):
  c:__getptd,__CxxThrowException_8,swi
  k:0x0
  cf:
    p_Var2 = __getptd();
    p_Var2->_curexcspec = *(void **)(unaff_EBP + 8);
    __CxxThrowException_8(0x0);
    pcVar1 =(code *)swi();
    (*pcVar1)();
    return;

f CallCatchBlock(7):
  c:__CreateFrameInfo,__getptd,_CallCatchBlock2,FUN_10011e5b
  k:0x18,0x1,0xfffffffe
  cf:
    local_28 = *(undefined4 *)(param_2 + -4);
    local_2c = __CreateFrameInfo(0x18);
    p_Var1 = __getptd();
    local_8 =(undefined *)0x1;
    local_20 = _CallCatchBlock2();
    local_8 =(undefined *)0xfffffffe;
    FUN_10011e5b();
    return local_20;

f FUN_10011e5b(0):
  c:__FindAndUnlinkFrame,__getptd,__IsExceptionObjectToBeDestroyed,___DestructExceptionObject
  k:0x24,0x28,0x2c,0x30,0x1f928c9d
  cf:
    *(undefined4 *)(unaff_EDI + -4)= *(undefined4 *)(unaff_EBP + -0x24);
    __FindAndUnlinkFrame(0x28);
    p_Var1 = __getptd();
    p_Var1->_curexception = *(void **)(unaff_EBP + -0x2c);
    p_Var1 = __getptd();
    p_Var1->_curcontext = *(void **)(unaff_EBP + -0x30);
    if((((*unaff_ESI == -0x1f928c9d)&&(unaff_ESI[4] == 3))&&
    iVar2 = __IsExceptionObjectToBeDestroyed();
    if(iVar2 != 0){
    ___DestructExceptionObject();
    return;

f ___BuildCatchObjectHelper(4):
  c:_ValidateRead,___AdjustPointer,_memmove,_inconsistency
  k:0xc,0x18,0x14
  cf:
    if(((param_3[1] == 0)||(*(char *)(param_3[1] + 8)== '\0'))||
    return '\0';
    if(-1 <(int)*param_3){
    param_2 =(int *)(param_3[2] + 0xc +(int)param_2);
    if((*param_3 & 8)== 0){
    pvVar2 = *(void **)(param_1 + 0x18);
    if((*param_4 & 1)== 0){
    if(*(int *)(param_4 + 0x18)== 0){
    iVar1 = _ValidateRead();
    if((iVar1 != 0)&&(iVar1 = _ValidateRead(param_2,1),iVar1 != 0)){
    _Size = *(size_t *)(param_4 + 0x14);
    pvVar2 =(void *)___AdjustPointer(0x18);
    _memmove();
    return '\0';
    else{
    iVar1 = _ValidateRead();
    if(((iVar1 != 0)&&(iVar1 = _ValidateRead(param_2,1),iVar1 != 0))&&
    return((*param_4 & 4)!= 0)+ '\x01';
    else{
    iVar1 = _ValidateRead();
    if((iVar1 != 0)&&(iVar1 = _ValidateRead(param_2,1),iVar1 != 0)){
    _memmove(0x18,0x14);
    if(*(int *)(param_4 + 0x14)!= 4){
    return '\0';
    if(iVar1 == 0){
    return '\0';
    goto LAB_10011f56;
    else{
    iVar1 = _ValidateRead(0x18);
    if((iVar1 != 0)&&(iVar1 = _ValidateRead(param_2,1),iVar1 != 0)){
    iVar1 = *(int *)(param_1 + 0x18);
    iVar1 = ___AdjustPointer();
    return '\0';
    _inconsistency();
    return '\0';

f ___BuildCatchObject(4):
  c:___BuildCatchObjectHelper,CONCAT31,___AdjustPointer,FID_conflict__CallMemberFunction1,elif
  g:CONCAT31
  k:0x80000000,0xc,0x18
  cf:
    if((*param_3 & 0x80000000)== 0){
    piVar2 =(int *)(param_3[2] + 0xc +(int)param_2);
    cVar1 = ___BuildCatchObjectHelper();
    if(CONCAT31(extraout_var,cVar1)== 1){
    ___AdjustPointer(0x18);
    FID_conflict__CallMemberFunction1(0x18);
    elif(CONCAT31(extraout_var,cVar1)== 2){
    ___AdjustPointer(0x18);
    FID_conflict__CallMemberFunction1(0x18);
    return;

f CatchIt(11):
  c:___BuildCatchObject,_UnwindNestedFrames,___FrameUnwindToState,_JumpToContinuation
  k:0x0
  cf:
    if(param_5 !=(_s_FuncInfo *)0x0){
    ___BuildCatchObject();
    if(param_7 ==(_s_CatchableType *)0x0){
    param_7 =(_s_CatchableType *)unaff_ESI;
    _UnwindNestedFrames();
    ___FrameUnwindToState();
    *(int *)(unaff_ESI + 8)= unaff_EDI[1] + 1;
    ,(ulong)pEVar2);
    if(pvVar1 !=(void *)0x0){
    _JumpToContinuation();
    return;

f FindHandlerForForeignException(8):
  c:__getptd,__encoded_null,_inconsistency,_GetRangeOfTrysToCheck
  k:0x7ffffffd,0x0,0x1fbcb0b3,0xfffffff4
  cf:
    if(*(int *)param_1 != -0x7ffffffd){
    p_Var2 = __getptd();
    if(p_Var2->_translator !=(void *)0x0){
    p_Var2 = __getptd();
    pvVar3 =(void *)__encoded_null();
    if(((p_Var2->_translator != pvVar3)&&(*(int *)param_1 != -0x1fbcb0b3))&&
    return;
    if(param_5->nTryBlocks == 0){
    _inconsistency();
    p_Var5 = _GetRangeOfTrysToCheck(0xfffffff4);
    if(local_8 < uVar6){
    do{
    if((p_Var5->tryLow <= param_6)&&(param_6 <= p_Var5->tryHigh)){
    if(((pTVar1 ==(TypeDescriptor *)0x0)||(*(char *)&pTVar1[1].pVFTable == '\0'))&&
    unaff_EBX,unaff_EDI,unaff_ESI,(uchar)uVar6);
    }while(local_8 < uVar6);
    return;

f FindHandler(8):
  c:_inconsistency,__getptd,_ValidateRead,IsInExceptionSpec,terminate,___DestructExceptionObject,bad_exception,__CxxThrowException_8,_GetRangeOfTrysToCheck,___TypeMatch,_UnwindNestedFrames,___FrameUnwindToState,FUN_10011cec
  g:LAB_10012547,LAB_10012385,S29,LAB_10012573
  k:0x81,0x1f928c9d,0x19930520,0x10,0x14,0x19930521,0x19930522,0x1c,0x0,0xffffffd0,0xc,0x1fffffff
  cf:
    if(param_5->maxState < 0x81){
    local_c =(int)(char)param_2[8];
    else{
    local_c = *(int *)(param_2 + 8);
    if((local_c < -1)||(param_5->maxState <= local_c)){
    _inconsistency();
    p_Var9 =(_s_FuncInfo *)param_1;
    if(*(int *)param_1 != -0x1f928c9d)goto LAB_10012547;
    p_Var7 =(_s_FuncInfo *)0x19930520;
    if(*(int *)(param_1 + 0x10)!= 3)goto LAB_100123b4;
    iVar5 = *(int *)(param_1 + 0x14);
    if(((iVar5 != 0x19930520)&&(iVar5 != 0x19930521))&&(iVar5 != 0x19930522))goto LAB_100123b4;
    if(*(int *)(param_1 + 0x1c)!= 0)goto LAB_100123b4;
    p_Var4 = __getptd();
    if(p_Var4->_curexception !=(void *)0x0){
    p_Var4 = __getptd();
    param_1 =(EHExceptionRecord *)p_Var4->_curexception;
    p_Var4 = __getptd();
    param_3 =(_CONTEXT *)p_Var4->_curcontext;
    iVar5 = _ValidateRead();
    if(iVar5 == 0){
    _inconsistency();
    if((((*(int *)param_1 == -0x1f928c9d)&&(*(int *)(param_1 + 0x10)== 3))&&
    _inconsistency();
    p_Var4 = __getptd();
    if(p_Var4->_curexcspec ==(void *)0x0)goto LAB_100123b4;
    p_Var4 = __getptd();
    piVar8 =(int *)p_Var4->_curexcspec;
    p_Var4 = __getptd();
    p_Var4->_curexcspec =(void *)0x0;
    uVar2 = IsInExceptionSpec();
    if(uVar2 != '\0')goto LAB_100123b4;
    p_Var7 =(_s_FuncInfo *)0x0;
    if(0 < *piVar8){
    do{
    (type_info *)&std::bad_exception::RTTI_Type_Descriptor);
    if(bVar3)goto LAB_10012385;
    p_Var7 =(_s_FuncInfo *)&p_Var7->pTryBlockMap;
    }while(iVar5 < *piVar8);
    do{
    terminate();
    ___DestructExceptionObject();
    std::bad_exception::bad_exception(0xffffffd0,S29);
    __CxxThrowException_8(0xffffffd0);
    p_Var9 =(_s_FuncInfo *)param_1;
    if(((*(int *)param_1 == -0x1f928c9d)&&(*(int *)(param_1 + 0x10)== 3))&&
    if(param_5->nTryBlocks != 0){
    p_Var6 = _GetRangeOfTrysToCheck();
    for(;local_14 < local_20;local_14 = local_14 + 1){
    if((p_Var6->tryLow <= local_c)&&(local_c <= p_Var6->tryHigh)){
    for(local_1c = p_Var6->nCatches;0 < local_1c;local_1c = local_1c + -1){
    piVar8 = *(int **)(*(int *)(param_1 + 0x1c)+ 0xc);
    for(local_18 = *piVar8;0 < local_18;local_18 = local_18 + -1){
    p_Var9 =(_s_FuncInfo *)*piVar8;
    iVar5 = ___TypeMatch(0x1c);
    if(iVar5 != 0){
    unaff_ESI,unaff_EBX,(uchar)in_stack_ffffffd0);
    goto LAB_1001249d;
    if(param_6 != '\0'){
    ___DestructExceptionObject();
    if((((local_5 != '\0')||((param_5->magicNumber_and_bbtFlags & 0x1fffffff)< 0x19930521))
    goto LAB_10012573;
    __getptd();
    p_Var4 = __getptd();
    if(param_8 ==(EHRegistrationNode *)0x0){
    _UnwindNestedFrames();
    ___FrameUnwindToState();
    FUN_10011cec();
    if(param_5->nTryBlocks == 0)goto LAB_10012573;
    }while(param_6 != '\0');
    ((EHExceptionRecord *)p_Var9,param_2,param_3,param_4,param_5,local_c,param_7,param_8);
    p_Var4 = __getptd();
    if(p_Var4->_curexcspec !=(void *)0x0){
    _inconsistency();
    return;

f FUN_1001258b(2):
  c:exception
  cf:
    std::exception::exception();
    *(undefined ***)this = std::bad_exception::vftable;
    return(exception *)this;

f ___InternalCxxFrameHandler(8):
  c:__getptd,FindHandler,elif,___FrameUnwindToState
  k:0x27,0x1f928c9d,0x66
  cf:
    p_Var1 = __getptd();
    if((((*(int *)((p_Var1->_setloc_data)._cacheout + 0x27)!= 0)||(*(int *)param_1 == -0x1f928c9d)
    if(((byte)param_1[4] & 0x66)== 0){
    if((param_5->nTryBlocks != 0)||
    if((*(int *)param_1 == -0x1f928c9d)&&
    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    return uVar2;
    FindHandler();
    elif((param_5->maxState != 0)&&(param_6 == 0)){
    ___FrameUnwindToState();
    return 1;

f __CallSettingFrame_12(3):
  c:__NLG_Notify1
  k:0x100
  cf:
    pcVar1 =(code *)__NLG_Notify1();
    (*pcVar1)();
    if(param_3 == 0x100){
    __NLG_Notify1();
    return;

f _ValidateRead(2):
  k:0x0
  cf:
    return(uint)(param_1 !=(void *)0x0);

f FUN_100126f0(1):
  c:FUN_10004ce0
  k:0x14
  cf:
    FUN_10004ce0(0x14);
    return;

f FUN_10012710(2):
  c:FUN_10004ce0,FUN_10005f30
  k:0x14
  cf:
    if((-1 <(int)param_1)&&(iVar1 = FUN_10004ce0((int)this + 0x14),(int)param_1 < iVar1)){
    puVar2 =(undefined4 *)FUN_10005f30(0x14);
    return *puVar2;
    return 0;

f FUN_10012750(1):
  c:FUN_10001a50
  cf:
    FUN_10001a50();
    return;

f FUN_10012770(1):
  cf:
    std::basic_string<>::~basic_string<>(param_1);
    return;

f FUN_10012790(1):
  cf:
    std::basic_string<>::basic_string<>(param_1);
    return param_1;

f FUN_100127b0(1):
  c:FUN_10004ce0,FUN_10005f30,FUN_10005e90,FUN_10005fe0
  k:0x14,0x0
  cf:
    for(local_8 = 0;uVar1 = FUN_10004ce0(param_1 + 0x14),local_8 < uVar1;local_8 = local_8 + 1){
    puVar2 =(undefined4 *)FUN_10005f30(0x14);
    if((void *)*puVar2 !=(void *)0x0){
    FUN_10005e90();
    FUN_10005fe0(0x14);
    return;

f FUN_10012830(1):
  c:SetupDiDestroyDeviceInfoList,FUN_100127b0,FUN_10001c80
  k:0x10,0x14
  cf:
    if(*(int *)(param_1 + 0x10)!= -1){
    SetupDiDestroyDeviceInfoList(0x10);
    FUN_100127b0();
    FUN_10001c80(0x14);
    return;

f FUN_10012870(1):
  c:FUN_10005f60
  k:0x14,0x00000004
  cf:
    FUN_10005f60(0x14,0x00000004);
    return;

f FUN_10012890(2):
  c:FUN_10005ec0
  k:0xc,0x10,0xffffffff,0x14
  cf:
    *(undefined4 *)this = *param_1;
    *(undefined4 *)((int)this + 4)= param_1[1];
    *(undefined4 *)((int)this + 8)= param_1[2];
    *(undefined4 *)((int)this + 0xc)= param_1[3];
    *(undefined4 *)((int)this + 0x10)= 0xffffffff;
    FUN_10005ec0(0x14);
    return(undefined4 *)this;

f FUN_100128e0(2):
  cf:
    std::basic_string<>::operator=((basic_string<> *)this,param_1);
    return;

f FUN_10012900(1):
  c:FUN_100127b0,SetupDiGetClassDevsA,FUN_100193d0,SetupDiEnumDeviceInfo,operator_new,FUN_10012790,FUN_100069ac,FUN_100128e0,FUN_1000837a,FUN_10012870,__security_check_cookie
  g:DAT_10020030,HDEVINFO,FUN_10012790,PSP_DEVICE_INTERFACE_DETAIL_DATA_A,PSP_DEVINFO_DATA,FUN_10012870
  k:0xfffffffc,0x0,0x12,0xffffffff,0x1c
  cf:
    local_14 = DAT_10020030 ^(uint)&stack0xfffffffc;
    FUN_100127b0();
    pvVar1 = SetupDiGetClassDevsA(0x0,0x0,0x12);
    param_1[1].Data1 =(ulong)pvVar1;
    if(param_1[1].Data1 == 0xffffffff){
    FUN_100193d0();
    else{
    while(BVar2 = SetupDiEnumDeviceInfo((HDEVINFO)param_1[1].Data1,local_c,&local_30),BVar2 != 0)
    FUN_100193d0();
    pbVar3 =(basic_string<> *)operator_new(0x1c);
    if(pbVar3 ==(basic_string<> *)0x0){
    local_34 =(basic_string<> *)0x0;
    else{
    local_34 = FUN_10012790();
    local_38 =(PSP_DEVICE_INTERFACE_DETAIL_DATA_A)0x0;
    while(BVar2 = SetupDiEnumDeviceInterfaces
    (PSP_DEVINFO_DATA)0x0);
    local_38 =(PSP_DEVICE_INTERFACE_DETAIL_DATA_A)FUN_100069ac();
    (PSP_DEVINFO_DATA)0x0);
    if(local_60 == 0){
    FUN_100193d0();
    else{
    FUN_100193d0();
    if(local_58 == 0){
    FUN_100128e0();
    FUN_1000837a();
    FUN_10012870();
    if((int)local_c < 1){
    FUN_100193d0();
    else{
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10012bf0(1):
  cf:
    return;

f FUN_100133b0(1):
  c:ReleaseMutex
  k:0x128
  cf:
    ReleaseMutex(0x128);
    return;

f FUN_100133d0(1):
  c:WaitForSingleObject,OutputDebugStringA
  g:S30
  k:0x128,0x102,2000
  cf:
    while(true){
    DVar1 = WaitForSingleObject(0x128,2000);
    if(DVar1 != 0x102)break;
    OutputDebugStringA(S30);
    return;

f FUN_10013410(5):
  k:0x120,0x18,0x20
  cf:
    if(*(int *)((int)this + 0x120)== -1){
    else{
    iVar1 =(**(code **)(*this + 0x18))(param_1,param_2);
    if(iVar1 == 0){
    iVar1 =(**(code **)(*this + 0x20))(param_3,param_4);
    return iVar1;

f FUN_10013470(3):
  k:0x1c
  cf:
    (**(code **)(*this + 0x1c))(0,param_1,param_2);
    return;

f FUN_100134a0(3):
  c:ReadFile,GetLastError
  g:DWORD
  k:0x40,0x0,300
  cf:
    BVar1 = ReadFile(0x40,0x0);
    DVar2 = GetLastError();
    *(DWORD *)((int)this + 300)= DVar2;
    if(BVar1 == 0){
    else{
    return local_14;

f FUN_10013500(3):
  k:0x14
  cf:
    (**(code **)(*this + 0x14))(0,0,param_1,param_2);
    return;

f FUN_10013530(3):
  c:WriteFile,GetLastError
  g:DWORD
  k:0x40,0x0,300
  cf:
    local_8 = WriteFile(0x40,0x0);
    DVar1 = GetLastError();
    *(DWORD *)((int)this + 300)= DVar1;
    return(-(uint)(local_8 != 0)& 2)- 2;

f FUN_10013580(0):
  c:ReleaseMutex
  cf:
    ReleaseMutex();
    return;

f FUN_100135a0(0):
  c:WaitForSingleObject
  k:2000
  cf:
    WaitForSingleObject(2000);
    return;

f FUN_100135c0(0):
  c:UnmapViewOfFile,CloseHandle
  g:LPCVOID,HANDLE
  k:0x0
  cf:
    if(DAT_10021c04 !=(LPCVOID)0x0){
    UnmapViewOfFile();
    CloseHandle();
    DAT_10021c04 =(LPCVOID)0x0;
    DAT_10021c00 =(HANDLE)0x0;
    CloseHandle();
    DAT_10021c08 =(HANDLE)0x0;
    return;

f FUN_10013620(0):
  c:OpenFileMappingA,MapViewOfFile,_memset,CreateMutexA
  g:HANDLE,S31
  k:0x0,0xf001f,0xa60
  cf:
    if(DAT_10021c00 ==(HANDLE)0x0){
    DAT_10021c00 = OpenFileMappingA(0xf001f);
    if((DAT_10021c00 ==(HANDLE)0x0)&&
    DAT_10021c04 = MapViewOfFile(0xf001f,0xa60);
    if(bVar1){
    _memset(0xa60);
    if(DAT_10021c08 ==(HANDLE)0x0){
    DAT_10021c08 = CreateMutexA(0x0,S31);
    return;

f FUN_100136f0(1):
  c:_memset
  k:0x3c
  cf:
    _memset(0x3c);
    return param_1;

f FUN_10013720(1):
  c:CONCAT22,CONCAT11
  g:CONCAT22,CONCAT11
  k:0x10
  cf:
    return CONCAT22((short)((uint)&param_1 >> 0x10),CONCAT11((undefined1)param_1,param_1._1_1_));

f FUN_10013750(4):
  c:FUN_100133b0,elif,FUN_10003860,_memset,_memcpy,FUN_10003820,GetTickCount,GetLastError
  g:FUN_10003860,FUN_10003820,DWORD,LPOVERLAPPED
  k:0x120,0x176,0x0,0x136,0x138,0x13e,0xffff,0x13a,0x178,0x200,300
  cf:
    if(*(int *)((int)this + 0x120)== -1){
    FUN_100133b0();
    elif((*(char *)((int)this + 0x176)== '\0')&&
    FUN_100133b0();
    else{
    if((param_1 !=(void *)0x0)&&(*(char *)((int)this + 0x136)== '\v')){
    uVar2 = FUN_10003860(0x138);
    local_20 =(ushort)uVar2;
    if(local_20 < 5){
    _memset();
    else{
    _memcpy(0x13e,0xffff);
    if(param_3 == 0){
    *(undefined1 *)((int)this + 0x176)= 1;
    if(*(char *)((int)this + 0x136)== '\v'){
    param_3 = FUN_10003820(0x13a);
    elif(*(char *)((int)this + 0x136)== '\t'){
    uVar3 = FUN_10003860(0x138);
    param_3 =(size_t)(short)uVar3;
    else{
    FUN_100133b0();
    elif(*(char *)((int)this + 0x136)== '\t'){
    uVar3 = FUN_10003860(0x138);
    if(param_3 ==(int)(short)uVar3){
    _memcpy(0x13a);
    *(undefined1 *)((int)this + 0x176)= 0;
    DVar1 = GetTickCount();
    *(DWORD *)((int)this + 0x178)= DVar1;
    FUN_100133b0();
    else{
    FUN_100133b0();
    else{
    local_c = FUN_10003820(0x13a);
    if((int)param_3 <(int)local_c){
    FUN_100133b0();
    else{
    while(local_8 != 0){
    if(0x200 <(int)local_8){
    local_28,&local_2c,(LPOVERLAPPED)0x0);
    if(local_18 != 1)break;
    DVar1 = GetTickCount();
    *(DWORD *)((int)this + 0x178)= DVar1;
    *(undefined1 *)((int)this + 0x176)= 0;
    FUN_100133b0();
    if(local_18 != 1){
    DVar1 = GetLastError();
    *(DWORD *)((int)this + 300)= DVar1;
    return param_3;

f FUN_10013a10(1):
  c:FUN_10013620,FUN_100135a0,FUN_10013580,previous_character
  g:FUN_10013620,FUN_10013580
  k:0x105
  cf:
    FUN_10013620();
    FUN_100135a0();
    do{
    if(9 < local_c){
    FUN_10013580();
    return local_5;
    iVar1 = previous_character(0x105);
    if(iVar1 == 0){
    goto LAB_10013a67;
    }while(true);

f FUN_10013a80(1):
  c:FUN_10013620,FUN_100135a0,FUN_10013580,previous_character,_memset
  g:FUN_10013620,FUN_10013580
  k:0x105,0xa38
  cf:
    FUN_10013620();
    FUN_100135a0();
    do{
    if(9 < local_8){
    FUN_10013580();
    return;
    iVar1 = previous_character(0x105);
    if(iVar1 == 0){
    _memset(0x105,0x105);
    *(undefined4 *)(DAT_10021c04 + 0xa38 + local_8 * 4)= 0;
    goto LAB_10013b02;
    }while(true);

f FUN_10013b10(1):
  c:FUN_10013620,FUN_100135a0,_strcpy_s,GetCurrentProcessId,FUN_10013580
  g:FUN_10013620,DWORD,FUN_10013580
  k:0x105,0xa38
  cf:
    FUN_10013620();
    FUN_100135a0();
    while(true){
    if((9 < local_8)||
    if(*(char *)(DAT_10021c04 + 4 + local_8 * 0x105)== '\0')break;
    _strcpy_s(0x105,0x105);
    DVar2 = GetCurrentProcessId();
    *(DWORD *)(DAT_10021c04 + 0xa38 + local_8 * 4)= DVar2;
    FUN_10013580();
    return;

f FUN_10013bd0(1):
  c:FUN_100037e0,FUN_100136f0,CreateMutexA,_memset
  k:0x4c,0x131,0x136,0x0,0x105
  cf:
    FUN_100037e0();
    *(undefined1 *)(param_1 + 0x4c)= 0;
    *(undefined1 *)((int)param_1 + 0x131)= 0;
    FUN_100136f0(0x136);
    pvVar1 = CreateMutexA(0x0,0x0);
    _memset(0x105);
    return param_1;

f FUN_10013cb0(5):
  c:_memcpy,_memset,FUN_10013720
  g:FUN_10013720
  k:0x3c
  cf:
    *(undefined1 *)this = param_1;
    *(undefined1 *)((int)this + 1)= param_2;
    _memcpy();
    _memset(0x3c);
    uVar1 = FUN_10013720();
    *(short *)((int)this + 2)=(short)uVar1;
    return(undefined1 *)this;

f FUN_10013d20(1):
  c:FUN_10013cb0,FUN_100136f0,FUN_10013530,FUN_100134a0,FUN_10003860,__security_check_cookie
  g:DAT_10020030,FUN_10013530,FUN_10003860
  k:0xfffffffc,0x130,0x131,0xd,0x0,0x11c,0x118,0x132
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if(*(char *)((int)param_1 + 0x130)== '\0'){
    uVar1 = *(undefined1 *)((int)param_1 + 0x131);
    *(char *)((int)param_1 + 0x131)= *(char *)((int)param_1 + 0x131)+ '\x01';
    FUN_10013cb0(0xd,0x0);
    FUN_100136f0();
    iVar2 = FUN_10013530(0x11c);
    if(iVar2 == 0){
    DVar3 = FUN_100134a0(0x118);
    if((0 <(int)DVar3)&&(local_4c[0] == local_8c[0])){
    uVar4 = FUN_10003860();
    if((short)uVar4 == 4){
    *(undefined1 *)((int)param_1 + 0x130)= 1;
    *(undefined4 *)((int)param_1 + 0x132)= local_48;
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10013e50(5):
  c:FUN_100133d0,FUN_10013cb0,FUN_10013530,GetTickCount,FUN_10003820,_memcpy,FUN_10003860,FUN_100136f0,FUN_100134a0,GetLastError,FUN_100133b0,__security_check_cookie
  g:DAT_10020030,FUN_10013530,LAB_10014147,FUN_10003820,FUN_10003860,LPOVERLAPPED
  k:0xfffffffc,0x124,0x39,0x3d,0x0,0x131,0x11c,0x178,0x118,0x10,0x200
  cf:
    local_10 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if((*(int *)((int)this + 0x124)!= -1)&&((int)param_2 < 0x39)){
    FUN_100133d0();
    if(((int)param_4 < 0x3d)&&(param_1 ==(void *)0x0)){
    uVar1 = *(undefined1 *)((int)this + 0x131);
    *(char *)((int)this + 0x131)= *(char *)((int)this + 0x131)+ '\x01';
    FUN_10013cb0();
    local_64 = FUN_10013530(0x11c);
    if(local_64 == 0){
    DVar3 = GetTickCount();
    *(DWORD *)((int)this + 0x178)= DVar3;
    goto LAB_10014147;
    else{
    local_60 = FUN_10003820();
    uVar1 = *(undefined1 *)((int)this + 0x131);
    *(char *)((int)this + 0x131)= *(char *)((int)this + 0x131)+ '\x01';
    FUN_10013cb0();
    if(param_1 !=(void *)0x0){
    _memcpy();
    uVar4 = FUN_10003860();
    local_a2 =(undefined2)uVar4;
    local_64 = FUN_10013530(0x11c);
    if(local_64 == 0){
    FUN_100136f0();
    DVar3 = FUN_100134a0(0x118);
    if((((int)DVar3 < 1)||(local_54 != local_a4))||(local_53 != local_a3)){
    iVar2 =(-(uint)(local_54 != '\f')& 3)- 0x10;
    else{
    while(param_4 != 0){
    if(0x200 <(int)param_4){
    (LPOVERLAPPED)0x0);
    if(local_58 != 1)break;
    local_c =(void *)((int)local_c + local_e8);
    DVar3 = GetTickCount();
    *(DWORD *)((int)this + 0x178)= DVar3;
    if(local_58 != 0)goto LAB_10014147;
    GetLastError();
    else{
    FUN_100133b0();
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10014160(2):
  c:FUN_10013cb0,FUN_100136f0,FUN_10013530,__security_check_cookie
  g:DAT_10020030,FUN_10013530
  k:0xfffffffc,0x11c,0x131,0x0,0x132
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if((*(int *)((int)this + 0x11c)!= -1)&&
    uVar1 = *(undefined1 *)((int)this + 0x131);
    *(char *)((int)this + 0x131)= *(char *)((int)this + 0x131)+ '\x01';
    FUN_10013cb0(0x0);
    FUN_100136f0();
    iVar2 = FUN_10013530(0x11c);
    if((iVar2 == 0)&&
    *(undefined4 *)((int)this + 0x132)= local_48;
    __security_check_cookie(0xfffffffc);
    return;

f FUN_100142b0(2):
  c:FUN_10013d20
  k:0x11c,0x132
  cf:
    if(*(int *)((int)this + 0x11c)== -1){
    else{
    cVar1 = FUN_10013d20();
    if(cVar1 == '\0'){
    else{
    *param_1 = *(undefined4 *)((int)this + 0x132);
    return uVar2;

f FUN_10014300(1):
  c:CloseHandle,FUN_10013a80,FUN_100135c0
  k:0x110,0xffffffff,0x114,0x118,0x11c,0x120,0x124,0x10c
  cf:
    if(*(int *)(param_1 + 0x110)!= -1){
    CloseHandle(0x110);
    *(undefined4 *)(param_1 + 0x110)= 0xffffffff;
    if(*(int *)(param_1 + 0x114)!= -1){
    CloseHandle(0x114);
    *(undefined4 *)(param_1 + 0x114)= 0xffffffff;
    if(*(int *)(param_1 + 0x118)!= -1){
    CloseHandle(0x118);
    *(undefined4 *)(param_1 + 0x118)= 0xffffffff;
    if(*(int *)(param_1 + 0x11c)!= -1){
    CloseHandle(0x11c);
    *(undefined4 *)(param_1 + 0x11c)= 0xffffffff;
    if(*(int *)(param_1 + 0x120)!= -1){
    CloseHandle(0x120);
    *(undefined4 *)(param_1 + 0x120)= 0xffffffff;
    if(*(int *)(param_1 + 0x124)!= -1){
    CloseHandle(0x124);
    *(undefined4 *)(param_1 + 0x124)= 0xffffffff;
    if(*(int *)(param_1 + 0x10c)!= -1){
    CloseHandle(0x10c);
    *(undefined4 *)(param_1 + 0x10c)= 0xffffffff;
    FUN_10013a80();
    FUN_100135c0();
    return;

f FUN_10014440(1):
  c:FUN_10014300,CloseHandle,FUN_10003800
  g:FUN_10014300,FUN_10003800
  k:0x4a
  cf:
    FUN_10014300();
    CloseHandle(0x4a);
    FUN_10003800();
    return;

f FUN_10014480(2):
  c:FUN_100019b0,FUN_10001a50,__security_check_cookie
  g:DAT_10020030,S32,HANDLE,LPSECURITY_ATTRIBUTES,LPCSTR
  k:0xfffffffc,0x0
  cf:
    local_14 = DAT_10020030 ^(uint)&stack0xfffffffc;
    FUN_100019b0();
    std::basic_string<>::operator=(local_30,S32);
    std::basic_string<>::operator=(local_30,param_2);
    hTemplateFile =(HANDLE)0x0;
    lpSecurityAttributes =(LPSECURITY_ATTRIBUTES)0x0;
    lpFileName =(LPCSTR)FUN_10001a50();
    std::basic_string<>::~basic_string<>((basic_string<> *)local_30);
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10014520(1):
  c:FUN_10005fe0,CreateToolhelp32Snapshot,Process32First,FUN_10005f60,Process32Next,CloseHandle,__security_check_cookie
  g:DAT_10020030,HANDLE
  k:0xfffffffc,0xffffffff
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    FUN_10005fe0();
    hObject =(HANDLE)CreateToolhelp32Snapshot();
    if(hObject !=(HANDLE)0xffffffff){
    iVar1 = Process32First();
    while(iVar1 != 0){
    FUN_10005f60();
    iVar1 = Process32Next();
    CloseHandle();
    __security_check_cookie(0xfffffffc);
    return;

f FUN_100145d0(1):
  c:FUN_10012890,FUN_10012900,FUN_100126f0,FUN_10012710,FUN_10012750,FUN_10001a50,FUN_10013a10,CloseHandle,FUN_100039f0,FUN_10012830,__security_check_cookie
  g:DAT_10020030,FUN_10012890,FUN_10012900,FUN_10012710,FUN_10012750,HANDLE,LPSECURITY_ATTRIBUTES,LPCSTR,FUN_10012830
  k:0xfffffffc,0x0,0xffffffff
  cf:
    local_18 = DAT_10020030 ^(uint)&stack0xfffffffc;
    FUN_10012890();
    local_14 = FUN_10012900();
    if(local_14 == 0){
    iVar2 = FUN_100126f0();
    if(0 < iVar2){
    while(true){
    iVar2 = FUN_100126f0();
    if(iVar2 <=(int)local_4c)break;
    local_54 =(basic_string<> *)FUN_10012710();
    pcVar3 =(char *)FUN_10012750();
    basic_string<>(local_70,pcVar3);
    puVar4 =(uchar *)FUN_10001a50();
    cVar1 = FUN_10013a10();
    if(cVar1 == '\0'){
    hTemplateFile =(HANDLE)0x0;
    lpSecurityAttributes =(LPSECURITY_ATTRIBUTES)0x0;
    lpFileName =(LPCSTR)FUN_10001a50();
    if(local_50 !=(HANDLE)0xffffffff){
    CloseHandle();
    FUN_100039f0();
    local_8 =(uint)local_8._1_3_ << 8;
    std::basic_string<>::~basic_string<>((basic_string<> *)local_70);
    else{
    local_8 =(uint)local_8._1_3_ << 8;
    std::basic_string<>::~basic_string<>((basic_string<> *)local_70);
    FUN_10012830();
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10014730(0):
  c:FUN_10005ec0,FUN_10014520,FUN_10013620,FUN_100135a0,FUN_10013580,FUN_10001c80,FUN_10004ce0,FUN_10005f30,_memset
  g:FUN_10014520,FUN_10013620,FUN_10013580
  k:0x105,0xa38
  cf:
    FUN_10005ec0();
    FUN_10014520();
    FUN_10013620();
    FUN_100135a0();
    do{
    if(9 < local_2c){
    FUN_10013580();
    FUN_10001c80();
    return;
    if(*(char *)(DAT_10021c04 + 4 + local_2c * 0x105)!= '\0'){
    iVar1 = *(int *)(DAT_10021c04 + 0xa38 + local_2c * 4);
    while(true){
    uVar3 = FUN_10004ce0();
    if(uVar3 <= local_38)break;
    piVar4 =(int *)FUN_10005f30();
    if(*piVar4 == iVar1){
    break;
    if(!bVar2){
    _memset(0x105,0x105);
    *(undefined4 *)(DAT_10021c04 + 0xa38 + local_2c * 4)= 0;
    }while(true);

f FUN_10014870(1):
  c:FUN_100193d0,FUN_10014730,FUN_10003910,FUN_100145d0,FUN_100039a0,operator_new,_memset,FUN_100039c0,FUN_10001a50,_strcpy_s,FUN_10005f60,FUN_10003980
  g:FUN_10014730,FUN_10003910,FUN_10003980
  k:0x109,0x0,0x105
  cf:
    FUN_100193d0();
    FUN_10014730();
    FUN_10003910();
    cVar2 = FUN_100145d0();
    if(cVar2 != '\0'){
    while(true){
    uVar3 = FUN_100039a0();
    if(uVar3 <= local_30)break;
    local_44 =(undefined4 *)operator_new(0x109);
    if(local_44 ==(undefined4 *)0x0){
    local_44 =(undefined4 *)0x0;
    else{
    _memset(0x109);
    pbVar4 =(basic_string<> *)FUN_100039c0();
    _Src =(char *)FUN_10001a50();
    _strcpy_s(0x105);
    FUN_10005f60();
    FUN_10003980();
    return uVar1;

f FUN_100149b0(1):
  c:FUN_10003910,FUN_100145d0,FUN_100039c0,FUN_10001a10,FUN_10003980
  g:FUN_10003910,FUN_10003980
  cf:
    FUN_10003910();
    cVar1 = FUN_100145d0();
    if(cVar1 != '\0'){
    pbVar2 =(basic_string<> *)FUN_100039c0();
    FUN_10001a10();
    FUN_10003980();
    return cVar1 != '\0';

f FUN_10014a40(2):
  c:FUN_10003910,FUN_100145d0,FUN_100039a0,FUN_100039c0,compare,FUN_10001a10,FUN_10003980
  g:FUN_10003910,FUN_10003980
  cf:
    FUN_10003910();
    cVar1 = FUN_100145d0();
    if(cVar1 != '\0'){
    while(true){
    uVar2 = FUN_100039a0();
    if(uVar2 <= local_30)break;
    this =(basic_string<> *)FUN_100039c0();
    iVar3 = std::basic_string<>::compare();
    if(iVar3 == 0){
    pbVar4 =(basic_string<> *)FUN_100039c0();
    FUN_10001a10();
    break;
    FUN_10003980();
    return local_29;

f FUN_10014b10(2):
  c:_strlen,FUN_10014a40,GetCommType,FUN_100149b0,FUN_10001a50,GetLastError,FUN_100193d0,FUN_10014480,_sprintf,OutputDebugStringA,_strcpy_s,FUN_10013b10,FUN_10013d20,__security_check_cookie
  g:DAT_10020030,HANDLE,LPSECURITY_ATTRIBUTES,LPCSTR,FUN_10014480,S33
  k:0xfffffffc,0x0,0x10c,0x110,0x114,0x118,0x11c,0x120,0x124,0x105,0x176
  cf:
    local_14 = DAT_10020030 ^(uint)&stack0xfffffffc;
    std::basic_string<>::basic_string<>(local_30);
    if(param_1 !=(char *)0x0){
    sVar2 = _strlen();
    if(sVar2 != 0){
    FUN_10014a40();
    CVar3 = mInstUsb::GetCommType();
    if(CVar3 == 0){
    FUN_100149b0();
    CVar3 = mInstUsb::GetCommType();
    if(CVar3 != 0){
    pvVar5 =(HANDLE)0x0;
    lpSecurityAttributes =(LPSECURITY_ATTRIBUTES)0x0;
    lpFileName =(LPCSTR)FUN_10001a50();
    *(HANDLE *)((int)this + 0x10c)= pvVar5;
    if(*(int *)((int)this + 0x10c)== -1){
    GetLastError();
    FUN_100193d0();
    std::basic_string<>::~basic_string<>(local_30);
    goto LAB_10014dd2;
    uVar4 = FUN_10014480();
    *(undefined4 *)((int)this + 0x110)= uVar4;
    if(*(int *)((int)this + 0x110)== -1){
    local_38 = GetLastError();
    _sprintf(S33);
    OutputDebugStringA();
    std::basic_string<>::~basic_string<>(local_30);
    goto LAB_10014dd2;
    uVar4 = FUN_10014480();
    *(undefined4 *)((int)this + 0x114)= uVar4;
    uVar4 = FUN_10014480();
    *(undefined4 *)((int)this + 0x118)= uVar4;
    uVar4 = FUN_10014480();
    *(undefined4 *)((int)this + 0x11c)= uVar4;
    uVar4 = FUN_10014480();
    *(undefined4 *)((int)this + 0x120)= uVar4;
    uVar4 = FUN_10014480();
    *(undefined4 *)((int)this + 0x124)= uVar4;
    _Src =(char *)FUN_10001a50();
    _strcpy_s(0x105);
    FUN_10013b10();
    *(undefined1 *)((int)this + 0x176)= 0;
    cVar1 = FUN_10013d20();
    if(cVar1 == '\0'){
    (**(code **)(*this + 8))();
    std::basic_string<>::~basic_string<>(local_30);
    else{
    std::basic_string<>::~basic_string<>(local_30);
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10014df0(1):
  c:ReleaseMutex
  cf:
    ReleaseMutex();
    return;

f FUN_10014e10(1):
  c:WaitForSingleObject,OutputDebugStringA
  g:S34
  k:0x102,2000
  cf:
    while(true){
    DVar1 = WaitForSingleObject(2000);
    if(DVar1 != 0x102)break;
    OutputDebugStringA(S34);
    return;

f FUN_10014e50(5):
  k:0x18,0x20
  cf:
    if(*(int *)((int)this + 4)== -1){
    else{
    iVar1 =(**(code **)(*this + 0x18))(param_1,param_2);
    if(iVar1 == 0){
    iVar1 =(**(code **)(*this + 0x20))(param_3,param_4);
    return iVar1;

f FUN_10014eb0(3):
  k:0x1c
  cf:
    (**(code **)(*this + 0x1c))(0,param_1,param_2);
    return;

f FUN_10014ee0(2):
  c:GetLastError
  g:LPOVERLAPPED,DWORD
  k:0x1c,0x0,0x40c
  cf:
    local_c =(int)this + 0x1c;
    (LPOVERLAPPED)0x0);
    if(local_10 != 1){
    DVar1 = GetLastError();
    *(DWORD *)((int)this + 0x40c)= DVar1;
    return local_8;

f FUN_10014f50(3):
  k:0x14
  cf:
    (**(code **)(*this + 0x14))(0,0,param_1,param_2);
    return;

f FUN_10014f80(2):
  g:LPOVERLAPPED
  k:0x1c,0x0
  cf:
    local_c =(int)this + 0x1c;
    (LPOVERLAPPED)0x0);
    return(-(uint)(BVar1 != 0)& 2)- 2;

f FUN_10014fe0(1):
  c:CloseHandle,ReleaseMutex,OutputDebugStringA
  g:S35
  k:0xffffffff
  cf:
    if(*(int *)(param_1 + 4)!= -1){
    CloseHandle();
    *(undefined4 *)(param_1 + 4)= 0xffffffff;
    if(*(int *)(param_1 + 8)!= 0){
    BVar1 = ReleaseMutex();
    if(BVar1 != 0){
    OutputDebugStringA(S35);
    return;

f FUN_10015040(1):
  c:FUN_10013cb0,FUN_100136f0,FUN_10014e10,FUN_10014f80,FUN_10014ee0,FUN_10003860,FUN_10014df0,__security_check_cookie
  g:DAT_10020030,FUN_10003860
  k:0xfffffffc,0x410,0x411,0xd,0x0,0x412
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if(*(char *)((int)param_1 + 0x410)== '\0'){
    uVar1 = *(undefined1 *)((int)param_1 + 0x411);
    *(char *)((int)param_1 + 0x411)= *(char *)((int)param_1 + 0x411)+ '\x01';
    FUN_10013cb0(0xd,0x0);
    FUN_100136f0();
    FUN_10014e10();
    iVar2 = FUN_10014f80();
    if(iVar2 == 0){
    DVar3 = FUN_10014ee0();
    if((0 <(int)DVar3)&&(local_4c[0] == local_8c[0])){
    uVar4 = FUN_10003860();
    if((short)uVar4 == 4){
    *(undefined1 *)((int)param_1 + 0x410)= 1;
    *(undefined4 *)((int)param_1 + 0x412)= local_48;
    FUN_10014df0();
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10015170(4):
  c:FUN_10014df0,elif,FUN_10003860,_memset,_memcpy,FUN_10003820,GetTickCount,GetLastError
  g:FUN_10003860,FUN_10003820,DWORD,LPOVERLAPPED
  k:0x456,0x0,0x416,0x418,0x41e,0xffff,0x41a,0x458,0x1c,0x1000,0x40c
  cf:
    if(*(int *)((int)this + 4)== -1){
    FUN_10014df0();
    elif((*(char *)((int)this + 0x456)== '\0')&&
    FUN_10014df0();
    else{
    if((param_1 !=(void *)0x0)&&(*(char *)((int)this + 0x416)== '\v')){
    uVar2 = FUN_10003860(0x418);
    local_24 =(ushort)uVar2;
    if(local_24 < 5){
    _memset();
    else{
    _memcpy(0x41e,0xffff);
    if(param_3 == 0){
    *(undefined1 *)((int)this + 0x456)= 1;
    if(*(char *)((int)this + 0x416)== '\v'){
    param_3 = FUN_10003820(0x41a);
    elif(*(char *)((int)this + 0x416)== '\t'){
    uVar3 = FUN_10003860(0x418);
    param_3 =(size_t)(short)uVar3;
    else{
    FUN_10014df0();
    elif(*(char *)((int)this + 0x416)== '\t'){
    uVar3 = FUN_10003860(0x418);
    if(param_3 ==(int)(short)uVar3){
    _memcpy(0x41a);
    *(undefined1 *)((int)this + 0x456)= 0;
    DVar1 = GetTickCount();
    *(DWORD *)((int)this + 0x458)= DVar1;
    FUN_10014df0();
    else{
    FUN_10014df0();
    else{
    local_c = FUN_10003820(0x41a);
    if((int)param_3 <(int)local_c){
    FUN_10014df0();
    else{
    local_14 =(int)this + 0x1c;
    while(local_8 != 0){
    if(0x1000 <(int)local_8){
    (LPOVERLAPPED)0x0);
    if(local_1c != 1)break;
    DVar1 = GetTickCount();
    *(DWORD *)((int)this + 0x458)= DVar1;
    *(undefined1 *)((int)this + 0x456)= 0;
    FUN_10014df0();
    if(local_1c != 1){
    DVar1 = GetLastError();
    *(DWORD *)((int)this + 0x40c)= DVar1;
    return param_3;

f FUN_10015430(5):
  c:FUN_10014e10,FUN_10013cb0,FUN_10014f80,GetTickCount,FUN_10003820,_memcpy,FUN_10003860,FUN_100136f0,FUN_10014ee0,GetLastError,FUN_10014df0,__security_check_cookie
  g:DAT_10020030,LAB_10015712,FUN_10003820,FUN_10003860,LPOVERLAPPED
  k:0xfffffffc,0x39,0x3d,0x0,0x411,0x458,0x10,0x1c,0x1000
  cf:
    local_14 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if((*(int *)((int)this + 4)!= -1)&&((int)param_2 < 0x39)){
    FUN_10014e10();
    if(((int)param_4 < 0x3d)&&(param_1 ==(void *)0x0)){
    uVar1 = *(undefined1 *)((int)this + 0x411);
    *(char *)((int)this + 0x411)= *(char *)((int)this + 0x411)+ '\x01';
    FUN_10013cb0();
    local_64 = FUN_10014f80();
    if(local_64 == 0){
    DVar3 = GetTickCount();
    *(DWORD *)((int)this + 0x458)= DVar3;
    goto LAB_10015712;
    else{
    local_60 = FUN_10003820();
    uVar1 = *(undefined1 *)((int)this + 0x411);
    *(char *)((int)this + 0x411)= *(char *)((int)this + 0x411)+ '\x01';
    FUN_10013cb0();
    if(param_1 !=(void *)0x0){
    _memcpy();
    uVar4 = FUN_10003860();
    local_a2 =(undefined2)uVar4;
    local_64 = FUN_10014f80();
    if(local_64 == 0){
    FUN_100136f0();
    DVar3 = FUN_10014ee0();
    if((((int)DVar3 < 1)||(local_54 != local_a4))||(local_53 != local_a3)){
    iVar2 =(-(uint)(local_54 != '\f')& 3)- 0x10;
    else{
    local_c =(int)this + 0x1c;
    while(param_4 != 0){
    if(0x1000 <(int)param_4){
    local_ec,&local_e8,(LPOVERLAPPED)0x0);
    if(local_58 != 1)break;
    local_10 =(void *)((int)local_10 + local_e8);
    DVar3 = GetTickCount();
    *(DWORD *)((int)this + 0x458)= DVar3;
    if(local_58 != 0)goto LAB_10015712;
    GetLastError();
    else{
    FUN_10014df0();
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10015730(2):
  c:FUN_10013cb0,FUN_100136f0,FUN_10014f80,__security_check_cookie
  g:DAT_10020030
  k:0xfffffffc,0x413,0x411,0x0,0x412
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if((*(int *)((int)this + 4)!= -1)&&((bool)param_1 !=(*(char *)((int)this + 0x413)== '\x01'))
    uVar1 = *(undefined1 *)((int)this + 0x411);
    *(char *)((int)this + 0x411)= *(char *)((int)this + 0x411)+ '\x01';
    FUN_10013cb0(0x0);
    FUN_100136f0();
    iVar2 = FUN_10014f80();
    if((iVar2 == 0)&&
    *(undefined4 *)((int)this + 0x412)= local_48;
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10015870(2):
  c:FUN_10015040
  g:FUN_10015040
  k:0x412
  cf:
    if(*(int *)((int)this + 4)== -1){
    else{
    cVar1 = FUN_10015040();
    if(cVar1 == '\0'){
    else{
    *param_1 = *(undefined4 *)((int)this + 0x412);
    return uVar2;

f FUN_100158c0(2):
  c:_strlen,GetLastError,_sprintf,OutputDebugStringA,FUN_10015040,CloseHandle,__security_check_cookie
  g:DAT_10020030,LPSECURITY_ATTRIBUTES,HANDLE,LPVOID,LPOVERLAPPED,S36,FUN_10015040
  k:0xfffffffc,0x0,0xc,0x400,0x456,0xffffffff
  cf:
    local_18 = DAT_10020030 ^(uint)&stack0xfffffffc;
    for(local_10 = 0;local_10 < 10;local_10 = local_10 + 1){
    if(((param_1 ==(char *)0x0)||(sVar2 = _strlen(param_1),sVar2 == 0))||
    (LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
    *(HANDLE *)((int)this + 4)= pvVar4;
    if(*(int *)((int)this + 4)!= -1)break;
    if(*(int *)((int)this + 4)!= -1){
    (LPVOID)((int)this + 0xc),0x400,&local_8,(LPOVERLAPPED)0x0);
    if(local_c == 0){
    local_14 = GetLastError();
    _sprintf(S36);
    OutputDebugStringA();
    *(undefined1 *)((int)this + 0x456)= 0;
    if((local_c == 0)||(cVar1 = FUN_10015040(this),cVar1 == '\0')){
    CloseHandle();
    *(undefined4 *)((int)this + 4)= 0xffffffff;
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10015a40(1):
  c:FUN_10014fe0,CloseHandle,FUN_10003800
  g:FUN_10003800
  cf:
    FUN_10014fe0();
    CloseHandle();
    FUN_10003800();
    return;

f FUN_10015a80(1):
  c:FUN_100037e0,FUN_100136f0,CreateMutexA
  k:0x416,0x411,0x104,0x0
  cf:
    FUN_100037e0();
    FUN_100136f0(0x416);
    *(undefined1 *)((int)param_1 + 0x411)= 0;
    *(undefined1 *)(param_1 + 0x104)= 0;
    pvVar1 = CreateMutexA(0x0,0x0);
    return param_1;

f FUN_10015af0(1):
  c:operator_new,_memset,_strcpy_s,FUN_10005f60,CloseHandle
  g:LPSECURITY_ATTRIBUTES,HANDLE
  k:0x0,0xffffffff,0x109,0x105
  cf:
    for(local_c = 0;local_c < 10;local_c = local_c + 1){
    (LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
    if(local_10 !=(HANDLE)0xffffffff){
    local_20 =(undefined4 *)operator_new(0x109);
    if(local_20 ==(undefined4 *)0x0){
    local_20 =(undefined4 *)0x0;
    else{
    _memset(0x109);
    _strcpy_s(0x105);
    FUN_10005f60();
    CloseHandle();
    return local_5;

f FUN_10015be0(1):
  c:ReleaseMutex
  k:300
  cf:
    ReleaseMutex(300);
    return;

f FUN_10015c00(1):
  c:WaitForSingleObject,OutputDebugStringA
  g:S37
  k:0x102,300,2000
  cf:
    while(true){
    DVar1 = WaitForSingleObject(300,2000);
    if(DVar1 != 0x102)break;
    OutputDebugStringA(S37);
    return;

f FUN_10015c40(5):
  k:0x110,0x18,0x20
  cf:
    if(*(int *)((int)this + 0x110)== -1){
    else{
    iVar1 =(**(code **)(*this + 0x18))(param_1,param_2);
    if(iVar1 == 0){
    iVar1 =(**(code **)(*this + 0x20))(param_3,param_4);
    return iVar1;

f FUN_10015ca0(3):
  k:0x1c
  cf:
    (**(code **)(*this + 0x1c))(0,param_1,param_2);
    return;

f FUN_10015cd0(3):
  k:0x14
  cf:
    (**(code **)(*this + 0x14))(0,0,param_1,param_2);
    return;

f FUN_10015d00(2):
  k:0x580,0x110
  cf:
    *(undefined4 *)((int)this + 0x580)= param_1;
    if(*(int *)((int)this + 0x110)!= -1){
    (int)this + 0x580);
    return;

f FUN_10015d80(0):
  cf:
    return;

f FUN_10015d90(0):
  cf:
    return;

f FUN_10015da0(2):
  c:_memset,RegisterDeviceNotificationA,__security_check_cookie
  g:DAT_10020030
  k:0xfffffffc,0x20
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    _memset(0x20);
    pvVar1 = RegisterDeviceNotificationA();
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10015e20(0):
  c:ReleaseMutex
  cf:
    ReleaseMutex();
    return;

f FUN_10015e40(0):
  c:WaitForSingleObject
  k:0xffffffff
  cf:
    WaitForSingleObject(0xffffffff);
    return;

f FUN_10015e60(3):
  c:GetLastError,FUN_100193d0
  k:0x110
  cf:
    if(*(int *)((int)this + 0x110)!= -1){
    if(iVar1 == 0){
    GetLastError();
    FUN_100193d0();
    else{
    return local_10;

f FUN_10015ee0(3):
  c:CreateEventA,GetLastError,FUN_100193d0
  g:HANDLE
  k:0x110,0x0
  cf:
    if(*(int *)((int)this + 0x110)== -1){
    else{
    local_8 =(HANDLE)0x0;
    local_8 = CreateEventA(0x0,0x0);
    if(iVar1 == 0){
    GetLastError();
    FUN_100193d0();
    return local_24;

f FUN_10015ff0(1):
  c:FUN_100193d0,CloseHandle,_memset,WinUsb_Free,ReleaseMutex,OutputDebugStringA
  g:S38
  k:0x10c,0xffffffff,0x105,0x110,300
  cf:
    FUN_100193d0();
    if(*(int *)(param_1 + 0x10c)!= -1){
    CloseHandle(0x10c);
    *(undefined4 *)(param_1 + 0x10c)= 0xffffffff;
    _memset(0x105);
    if(*(int *)(param_1 + 0x110)!= -1){
    WinUsb_Free(0x110);
    *(undefined4 *)(param_1 + 0x110)= 0xffffffff;
    if(*(int *)(param_1 + 300)!= 0){
    BVar1 = ReleaseMutex(300);
    if(BVar1 != 0){
    OutputDebugStringA(S38);
    return;

f FUN_100160b0(1):
  c:WinUsb_QueryDeviceInformation,GetLastError,FUN_100193d0,elif,_memset,WinUsb_QueryInterfaceSettings,WinUsb_QueryPipe,_memcpy
  k:0x110,0xc,0xff,0x114,0x120
  cf:
    if(*(int *)(param_1 + 0x110)!= -1){
    iVar2 = WinUsb_QueryDeviceInformation(0x110);
    if(iVar2 == 0){
    GetLastError();
    FUN_100193d0();
    else{
    if(local_11 == '\x01'){
    FUN_100193d0();
    elif(local_11 == '\x02'){
    FUN_100193d0();
    elif(local_11 == '\x03'){
    FUN_100193d0();
    _memset();
    _memset(0xc);
    iVar2 = WinUsb_QueryInterfaceSettings(0x110);
    if(iVar2 != 0){
    for(local_2c = 0;(int)local_2c <(int)(uint)local_c;local_2c = local_2c + 1){
    iVar2 = WinUsb_QueryPipe(0x110,0xff);
    if(iVar2 != 0){
    switch(local_24){
    case 0:
    FUN_100193d0();
    break;
    case 1:
    FUN_100193d0();
    break;
    case 2:
    FUN_100193d0();
    local_34 =(void *)(param_1 + 0x114);
    if(bVar1 == 0){
    local_34 =(void *)(param_1 + 0x120);
    _memcpy(0xc);
    break;
    case 3:
    FUN_100193d0();
    break;
    default:
    FUN_100193d0();
    return;

f if(1):
  c:FUN_100193d0
  cf:
    FUN_100193d0();

f if(1):
  c:FUN_100193d0
  cf:
    FUN_100193d0();

f FUN_10016310(1):
  c:FUN_10015ff0,CloseHandle,FUN_10003800
  g:FUN_10003800
  k:0x4b
  cf:
    FUN_10015ff0();
    CloseHandle(0x4b);
    FUN_10003800();
    return;

f FUN_10016350(1):
  c:FUN_100037e0,FUN_100136f0,CreateMutexA,_memset
  k:0x14d,0x535,0x53a,0x0,0x105
  cf:
    FUN_100037e0();
    *(undefined1 *)(param_1 + 0x14d)= 0;
    *(undefined1 *)((int)param_1 + 0x535)= 0;
    FUN_100136f0(0x53a);
    pvVar1 = CreateMutexA(0x0,0x0);
    _memset(0x105);
    return param_1;

f FUN_10016400(1):
  c:FUN_10015e40,FUN_10015e20,previous_character
  k:0xb,0x105,0x187c,0x1f,0x1880
  cf:
    FUN_10015e40();
    do{
    if(0xb < local_8){
    FUN_10015e20();
    return;
    iVar1 = previous_character(0x105);
    if(iVar1 == 0){
    *(undefined1 *)(DAT_10021bf0 + 4 + local_8 * 0x105)= 0;
    *(int *)(DAT_10021bf0 + 0x187c)= *(int *)(DAT_10021bf0 + 0x187c)+ -1;
    ~(1 <<((byte)local_8 & 0x1f))& *(uint *)(DAT_10021bf0 + 0x1880);
    goto LAB_1001649b;
    }while(true);

f FUN_100164b0(1):
  c:FUN_10015e40,_strcpy_s,FUN_10015e20,previous_character
  g:S39,LAB_10016530
  k:0xb,0x105,0xc40,0x187c
  cf:
    FUN_10015e40();
    do{
    if(0xb < local_10){
    if((bVar1)&&(local_c != -1)){
    _strcpy_s(0x105,0x105);
    _strcpy_s(0xc40,0x105,S39);
    *(int *)(DAT_10021bf0 + 0x187c)= *(int *)(DAT_10021bf0 + 0x187c)+ 1;
    FUN_10015e20();
    return;
    if((*(char *)(DAT_10021bf0 + 4 + local_10 * 0x105)== '\0')&&(local_c == -1)){
    else{
    iVar2 = previous_character(0x105);
    if(iVar2 == 0){
    goto LAB_10016530;
    }while(true);

f FUN_100165b0(2):
  c:FUN_10015e60
  k:0x40
  cf:
    FUN_10015e60(0x40);
    return;

f FUN_100165d0(2):
  c:FUN_10015ee0
  k:0x40,0xfffffffe
  cf:
    DVar1 = FUN_10015ee0(0x40);
    return(0 <(int)DVar1)- 1 & 0xfffffffe;

f FUN_10016600(2):
  c:FUN_10013cb0,FUN_100136f0,FUN_100165d0,__security_check_cookie
  g:DAT_10020030
  k:0xfffffffc,0x10c,0x535,0x0,0x536
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if((*(int *)((int)this + 0x10c)!= -1)&&
    uVar1 = *(undefined1 *)((int)this + 0x535);
    *(char *)((int)this + 0x535)= *(char *)((int)this + 0x535)+ '\x01';
    FUN_10013cb0(0x0);
    FUN_100136f0();
    uVar2 = FUN_100165d0();
    if((uVar2 == 0)&&
    *(undefined4 *)((int)this + 0x536)= local_48;
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10016740(4):
  c:UnregisterDeviceNotification,FUN_100193d0,DestroyWindow,FUN_10015da0,PostQuitMessage,elif,FUN_100164b0,MessageBeep,Sleep,FUN_10016400,DefWindowProcA
  g:HDEVNOTIFY,FUN_10016400
  k:0x11,0x10,0x0,0x219,0x8000,0x1c,0x30,0x8004,100
  cf:
    if(param_2 < 0x11){
    if(param_2 == 0x10){
    if(DAT_10021c24 !=(HDEVNOTIFY)0x0){
    UnregisterDeviceNotification();
    FUN_100193d0();
    DestroyWindow();
    return 1;
    if(param_2 == 1){
    FUN_10015da0();
    FUN_100193d0();
    return 1;
    if(param_2 == 2){
    PostQuitMessage();
    return 1;
    elif(param_2 == 0x219){
    if(param_3 == 0x8000){
    FUN_100193d0();
    FUN_100164b0(0x1c);
    MessageBeep(0x30);
    Sleep(100);
    return 1;
    if(param_3 != 0x8004){
    return 1;
    FUN_100193d0();
    FUN_10016400(0x1c);
    return 1;
    LVar1 = DefWindowProcA();
    return LVar1;

f if(1):
  c:FUN_100193d0,FUN_100164b0,MessageBeep,Sleep,FUN_10016400
  g:FUN_10016400
  k:0x8000,0x1c,0x30,0x8004,100
  cf:
    if(param_3 == 0x8000){
    FUN_100193d0();
    FUN_100164b0(0x1c);
    MessageBeep(0x30);
    Sleep(100);
    return 1;
    if(param_3 != 0x8004){
    return 1;
    FUN_100193d0();
    FUN_10016400(0x1c);
    return 1;

f FUN_100168b0(1):
  c:FUN_10013cb0,FUN_100136f0,FUN_10015c00,FUN_100165d0,FUN_100165b0,FUN_10015be0,__security_check_cookie
  g:DAT_10020030
  k:0xfffffffc,0x11a,0x535,0x10
  cf:
    local_10 = DAT_10020030 ^(uint)&stack0xfffffffc;
    local_c = *(undefined2 *)((int)param_1 + 0x11a);
    uVar1 = *(undefined1 *)((int)param_1 + 0x535);
    *(char *)((int)param_1 + 0x535)= *(char *)((int)param_1 + 0x535)+ '\x01';
    FUN_10013cb0(0x10);
    FUN_100136f0();
    FUN_10015c00();
    uVar2 = FUN_100165d0();
    if(uVar2 == 0){
    iVar3 = FUN_100165b0();
    if((0 < iVar3)&&(local_54[0] == local_9c[0])){
    FUN_10015be0();
    __security_check_cookie(0xfffffffc);
    return;

f FUN_100169a0(1):
  c:FUN_10013cb0,FUN_100136f0,FUN_10015c00,FUN_100165d0,FUN_100165b0,FUN_10003860,FUN_10015be0,__security_check_cookie
  g:DAT_10020030,FUN_10003860
  k:0xfffffffc,0x534,0x535,0xd,0x0,0x536
  cf:
    local_8 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if(*(char *)((int)param_1 + 0x534)== '\0'){
    uVar1 = *(undefined1 *)((int)param_1 + 0x535);
    *(char *)((int)param_1 + 0x535)= *(char *)((int)param_1 + 0x535)+ '\x01';
    FUN_10013cb0(0xd,0x0);
    FUN_100136f0();
    FUN_10015c00();
    uVar2 = FUN_100165d0();
    if(uVar2 == 0){
    iVar3 = FUN_100165b0();
    if((0 < iVar3)&&(local_4c[0] == local_8c[0])){
    uVar4 = FUN_10003860();
    if((short)uVar4 == 4){
    *(undefined1 *)((int)param_1 + 0x534)= 1;
    *(undefined4 *)((int)param_1 + 0x536)= local_48;
    FUN_10015be0();
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10016ad0(4):
  c:FUN_10015be0,elif,FUN_10003860,_memset,_memcpy,FUN_10003820,GetTickCount,FUN_100193d0,FUN_100069ac,FUN_1000837a,GetLastError
  g:FUN_10003860,FUN_10003820,DWORD
  k:0x110,0xfffffff5,0x57a,0xfffffffc,0x0,0x53a,0x53c,0x542,0xffff,0x53e,0xfffffff6,0x57c,0xfffffff2,0x11a,0x530
  cf:
    if(*(int *)((int)this + 0x110)== -1){
    FUN_10015be0();
    _Size =(void *)0xfffffff5;
    elif((*(char *)((int)this + 0x57a)== '\0')&&
    FUN_10015be0();
    _Size =(void *)0xfffffffc;
    else{
    if((param_1 !=(void *)0x0)&&(*(char *)((int)this + 0x53a)== '\v')){
    uVar3 = FUN_10003860(0x53c);
    if((ushort)uVar3 < 5){
    _memset();
    else{
    _memcpy(0x542,0xffff);
    if(param_3 ==(void *)0x0){
    *(undefined1 *)((int)this + 0x57a)= 1;
    if(*(char *)((int)this + 0x53a)== '\v'){
    _Size =(void *)FUN_10003820(0x53e);
    elif(*(char *)((int)this + 0x53a)== '\t'){
    uVar4 = FUN_10003860(0x53c);
    _Size =(void *)(int)(short)uVar4;
    else{
    FUN_10015be0();
    _Size =(void *)0xfffffff6;
    elif(*(char *)((int)this + 0x53a)== '\t'){
    uVar4 = FUN_10003860(0x53c);
    if(param_3 ==(void *)(int)(short)uVar4){
    _memcpy(0x53e);
    *(undefined1 *)((int)this + 0x57a)= 0;
    DVar5 = GetTickCount();
    *(DWORD *)((int)this + 0x57c)= DVar5;
    FUN_10015be0();
    else{
    FUN_10015be0();
    _Size =(void *)0xfffffff2;
    else{
    _Size =(void *)FUN_10003820(0x53e);
    FUN_100193d0();
    if((int)param_3 <(int)_Size){
    FUN_10015be0();
    _Size =(void *)0xfffffff2;
    else{
    if(_Size !=(void *)0x0){
    local_24 =(void *)0x0;
    if((int)_Size %(int)(uint)*(ushort *)((int)this + 0x11a)== 0){
    local_8 =(void *)((int)_Size + 1);
    local_24 =(void *)FUN_100069ac();
    FUN_100193d0();
    for(local_28 =(void *)0x0;(int)local_28 <(int)local_8;
    (void *)((int)local_8 -(int)local_28));
    if(iVar2 < 0){
    break;
    DVar5 = GetTickCount();
    *(DWORD *)(iVar6 + 0x57c)= DVar5;
    if(bVar1){
    FUN_100193d0();
    if(local_24 !=(void *)0x0){
    _memcpy();
    else{
    FUN_100193d0();
    if(local_24 !=(void *)0x0){
    FUN_1000837a();
    *(undefined1 *)((int)this + 0x57a)= 0;
    FUN_10015be0();
    if(!bVar1){
    DVar5 = GetLastError();
    *(DWORD *)(iVar2 + 0x530)= DVar5;
    _Size =(void *)0xfffffffc;
    return _Size;

f FUN_10016e30(5):
  c:FUN_10015c00,FUN_10013cb0,FUN_100165d0,GetTickCount,FUN_10003820,_memcpy,FUN_10003860,FUN_100136f0,FUN_100165b0,FUN_10015ee0,FUN_100193d0,FUN_10015e60,GetLastError,FUN_10015be0,__security_check_cookie
  g:DAT_10020030,DWORD,LAB_10017158,FUN_10003820,FUN_10003860
  k:0xfffffffc,0x110,0x3d,0x0,0x535,0x57c,0x10,0x7fff
  cf:
    local_10 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if((*(int *)((int)this + 0x110)!= -1)&&
    FUN_10015c00();
    if((param_4 < 0x3d)&&(param_1 ==(void *)0x0)){
    uVar1 = *(undefined1 *)((int)this + 0x535);
    *(char *)((int)this + 0x535)= *(char *)((int)this + 0x535)+ '\x01';
    FUN_10013cb0();
    local_60 = FUN_100165d0();
    if(local_60 == 0){
    DVar3 = GetTickCount();
    *(DWORD *)((int)this + 0x57c)= DVar3;
    goto LAB_10017158;
    else{
    local_5c = FUN_10003820();
    uVar1 = *(undefined1 *)((int)this + 0x535);
    *(char *)((int)this + 0x535)= *(char *)((int)this + 0x535)+ '\x01';
    FUN_10013cb0();
    if(param_1 !=(void *)0x0){
    _memcpy();
    uVar4 = FUN_10003860();
    local_a2 =(undefined2)uVar4;
    local_60 = FUN_100165d0();
    if(local_60 == 0){
    FUN_100136f0();
    iVar5 = FUN_100165b0();
    if(((iVar5 < 1)||(local_54 != local_a4))||(local_53 != local_a3)){
    uVar2 =(-(uint)(local_54 != '\f')& 3)- 0x10;
    else{
    if(param_4 != 0){
    while(0 < param_4){
    if(0x7fff < param_4){
    local_e8 = FUN_10015ee0();
    if((int)local_e8 < 0){
    break;
    DVar3 = GetTickCount();
    *(DWORD *)((int)this + 0x57c)= DVar3;
    local_c =(void *)((int)local_c + local_ec);
    if(0 < param_4){
    FUN_100193d0();
    FUN_10015e60();
    if(local_58 != 0)goto LAB_10017158;
    GetLastError();
    FUN_100193d0();
    else{
    FUN_10015be0();
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10017170(2):
  c:FUN_100169a0
  k:0x10c,0x536
  cf:
    if(*(int *)((int)this + 0x10c)== -1){
    else{
    cVar1 = FUN_100169a0();
    if(cVar1 == '\0'){
    else{
    *param_1 = *(undefined4 *)((int)this + 0x536);
    return uVar2;

f FUN_100171c0(0):
  c:GetModuleHandleA,RegisterClassA,FUN_100193d0,SetEvent
  g:HICON,HCURSOR,HBRUSH,LPCSTR,HWND,HMENU,HINSTANCE,LPVOID
  k:0x0
  cf:
    local_2c.hIcon =(HICON)0x0;
    local_2c.hInstance = GetModuleHandleA(0x0);
    local_2c.hCursor =(HCURSOR)0x0;
    local_2c.hbrBackground =(HBRUSH)0x0;
    local_2c.lpszMenuName =(LPCSTR)0x0;
    DAT_10021bf8 =(HWND)0x0;
    RegisterClassA();
    (HWND)0x0,(HMENU)0x0,(HINSTANCE)0x0,(LPVOID)0x0);
    FUN_100193d0();
    SetEvent();
    return DAT_10021bf8 !=(HWND)0x0;

f FUN_10017280(0):
  c:FUN_100193d0,FUN_100171c0,GetMessageA,TranslateMessage,DispatchMessageA,GetModuleHandleA,UnregisterClassA
  g:HWND
  k:0x0
  cf:
    FUN_100193d0();
    bVar1 = FUN_100171c0();
    if(bVar1){
    while(BVar2 = GetMessageA(&local_20,(HWND)0x0,0,0),BVar2 != 0){
    TranslateMessage();
    DispatchMessageA();
    hInstance = GetModuleHandleA(0x0);
    UnregisterClassA();
    FUN_100193d0();
    return 0;

f FUN_10017340(1):
  c:FUN_10012890,FUN_10012900,FUN_100126f0,FUN_10012710,FUN_10012750,CONCAT31,FUN_10001a50,CloseHandle,FUN_100039f0,FUN_10012830,__security_check_cookie
  g:DAT_10020030,FUN_10012890,FUN_10012900,FUN_10012710,FUN_10012750,CONCAT31,HANDLE,LPSECURITY_ATTRIBUTES,LPCSTR,FUN_10012830
  k:0xfffffffc,0x0,0xffffffff
  cf:
    local_18 = DAT_10020030 ^(uint)&stack0xfffffffc;
    FUN_10012890();
    local_14 = FUN_10012900();
    if(local_14 == 0){
    iVar1 = FUN_100126f0();
    if(0 < iVar1){
    while(true){
    iVar1 = FUN_100126f0();
    if(iVar1 <=(int)local_4c)break;
    local_54 =(basic_string<> *)FUN_10012710();
    pcVar2 =(char *)FUN_10012750();
    basic_string<>(local_70,pcVar2);
    local_8 = CONCAT31();
    hTemplateFile =(HANDLE)0x0;
    lpSecurityAttributes =(LPSECURITY_ATTRIBUTES)0x0;
    lpFileName =(LPCSTR)FUN_10001a50();
    if(local_50 !=(HANDLE)0xffffffff){
    CloseHandle();
    FUN_100039f0();
    std::basic_string<>::~basic_string<>((basic_string<> *)local_70);
    FUN_10012830();
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10017470(1):
  c:FUN_100193d0,FUN_10003910,FUN_10017340,FUN_100039a0,operator_new,_memset,FUN_100039c0,FUN_10001a50,_strcpy_s,FUN_10005f60,FUN_10003980
  g:FUN_10003910,FUN_10017340,FUN_10003980
  k:0x109,0x0,0x105
  cf:
    FUN_100193d0();
    FUN_10003910();
    cVar2 = FUN_10017340();
    if(cVar2 != '\0'){
    while(true){
    uVar3 = FUN_100039a0();
    if(uVar3 <= local_30)break;
    local_44 =(undefined4 *)operator_new(0x109);
    if(local_44 ==(undefined4 *)0x0){
    local_44 =(undefined4 *)0x0;
    else{
    _memset(0x109);
    pbVar4 =(basic_string<> *)FUN_100039c0();
    _Src =(char *)FUN_10001a50();
    _strcpy_s(0x105);
    FUN_10005f60();
    FUN_10003980();
    return uVar1;

f FUN_100175a0(1):
  c:FUN_10003910,FUN_10017340,FUN_100039c0,FUN_10001a10,FUN_10003980
  g:FUN_10003910,FUN_10017340,FUN_10003980
  cf:
    FUN_10003910();
    cVar1 = FUN_10017340();
    if(cVar1 != '\0'){
    pbVar2 =(basic_string<> *)FUN_100039c0();
    FUN_10001a10();
    FUN_10003980();
    return cVar1 != '\0';

f FUN_10017630(2):
  c:FUN_10003910,FUN_10017340,FUN_100039a0,FUN_100039c0,compare,FUN_10001a10,FUN_10003980
  g:FUN_10003910,FUN_10017340,FUN_10003980
  cf:
    FUN_10003910();
    cVar1 = FUN_10017340();
    if(cVar1 != '\0'){
    while(true){
    uVar2 = FUN_100039a0();
    if(uVar2 <= local_30)break;
    this =(basic_string<> *)FUN_100039c0();
    iVar3 = std::basic_string<>::compare();
    if(iVar3 == 0){
    pbVar4 =(basic_string<> *)FUN_100039c0();
    FUN_10001a10();
    break;
    FUN_10003980();
    return local_29;

f FUN_10017700(2):
  c:_strlen,FUN_100193d0,FUN_10017630,GetCommType,FUN_100175a0,FUN_10001a50,GetLastError,_strcpy_s,WinUsb_Initialize,FUN_100160b0,WinUsb_FlushPipe,FUN_100169a0,FUN_100168b0,__security_check_cookie
  g:DAT_10020030,FUN_10017630,HANDLE,LPSECURITY_ATTRIBUTES,LPCSTR
  k:0xfffffffc,0x0,0x10c,0x105,0x110,0x57a,0x124,0x118,0x580
  cf:
    uVar2 = DAT_10020030 ^(uint)&stack0xfffffffc;
    if((param_1 ==(char *)0x0)||(sVar3 = _strlen(param_1),pcVar5 = param_1,sVar3 == 0)){
    FUN_100193d0();
    (**(code **)(*this + 8))(uVar2,pcVar5);
    std::basic_string<>::basic_string<>(local_30);
    if((param_1 !=(char *)0x0)&&(sVar3 = _strlen(param_1),sVar3 != 0)){
    FUN_10017630();
    CVar4 = mInstUsb::GetCommType();
    if(CVar4 == 0){
    FUN_100175a0();
    CVar4 = mInstUsb::GetCommType();
    if(CVar4 != 0){
    pvVar7 =(HANDLE)0x0;
    lpSecurityAttributes =(LPSECURITY_ATTRIBUTES)0x0;
    lpFileName =(LPCSTR)FUN_10001a50();
    *(HANDLE *)((int)this + 0x10c)= pvVar7;
    if(*(int *)((int)this + 0x10c)== -1){
    GetLastError();
    FUN_100193d0();
    std::basic_string<>::~basic_string<>(local_30);
    goto LAB_10017a5f;
    pcVar5 =(char *)FUN_10001a50();
    _strcpy_s(0x105);
    FUN_100193d0();
    iVar6 = WinUsb_Initialize(0x10c,0x110);
    if((bool)local_31){
    FUN_100193d0();
    FUN_100160b0();
    else{
    GetLastError();
    FUN_100193d0();
    *(undefined1 *)((int)this + 0x57a)= 0;
    if(local_31 == '\0'){
    (**(code **)(*this + 8))();
    std::basic_string<>::~basic_string<>(local_30);
    else{
    (*(undefined4 *)((int)this + 0x110),*(undefined1 *)((int)this + 0x124),3,4,&local_38);
    (*(undefined4 *)((int)this + 0x110),*(undefined1 *)((int)this + 0x118),3,4,&local_38);
    WinUsb_FlushPipe(0x110,0x118);
    WinUsb_FlushPipe(0x110,0x124);
    cVar1 = FUN_100169a0();
    if(cVar1 == '\0'){
    std::basic_string<>::~basic_string<>(local_30);
    else{
    FUN_100168b0();
    (int)this + 0x580);
    std::basic_string<>::~basic_string<>(local_30);
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10017af0(1):
  c:OutputDebugStringA
  cf:
    OutputDebugStringA();
    return;

f FUN_10017b10(2):
  c:FUN_10015d80,elif,FUN_10015d90
  cf:
    if(param_2 == 0){
    FUN_10015d80();
    elif(param_2 == 1){
    FUN_10015d90();
    return 1;

f if(1):
  c:FUN_10015d90
  cf:
    FUN_10015d90();

f FUN_10018270(1):
  c:FUN_100193d0
  k:0x19,0x10,0x14
  cf:
    FUN_100193d0();
    if((*(char *)(param_1 + 0x19)!= '\0')&&(*(int *)(param_1 + 0x10)== 1)){
    *(undefined4 *)(param_1 + 0x10)= 2;
    *(undefined4 *)(param_1 + 0x14)= 2;
    return;

f FUN_100182b0(1):
  c:GetExitCodeThread,TerminateThread,FUN_10017af0,CloseHandle,FUN_10001840
  g:S41,FUN_10001840
  k:0x28,0x103,0x2c,0x1a
  cf:
    if(*(int *)(param_1 + 0x28)!= 0){
    GetExitCodeThread(0x28);
    if(local_8 == 0x103){
    TerminateThread(0x28);
    FUN_10017af0(S41);
    CloseHandle(0x28);
    *(undefined4 *)(param_1 + 0x28)= 0;
    if(*(char *)(param_1 + 0x2c)!= '\0'){
    FUN_10001840();
    *(undefined1 *)(param_1 + 0x2c)= 0;
    *(undefined1 *)(param_1 + 0x1a)= 0;
    return;

f FUN_10018350(1):
  c:GetExitCodeThread,TerminateThread,FUN_10017af0,CloseHandle
  g:S42
  k:0x20,0x103
  cf:
    if(*(int *)(param_1 + 0x20)!= 0){
    GetExitCodeThread(0x20);
    if(local_8 == 0x103){
    TerminateThread(0x20);
    FUN_10017af0(S42);
    CloseHandle(0x20);
    *(undefined4 *)(param_1 + 0x20)= 0;
    return;

f if(1):
  c:connect64
  cf:
    local_8 = connect64();

f if(1):
  c:connectWinUSB
  cf:
    local_8 = connectWinUSB();

f FUN_10018740(5):
  c:FUN_10001b50,FUN_10001b70,FUN_10001a10
  cf:
    while(true){
    uVar1 = FUN_10001b50();
    if(uVar1 <= local_c){
    return 0;
    piVar2 =(int *)FUN_10001b70();
    if((param_2 == *piVar2)||(param_2 == 0))break;
    iVar3 = FUN_10001b70();
    FUN_10001a10();
    puVar4 =(undefined4 *)FUN_10001b70();
    iVar3 = FUN_10001b70();
    *param_5 = *(undefined4 *)(iVar3 + 4);
    return 1;

f FUN_100187d0(5):
  c:FUN_10001b50,FUN_10001b70,compare,FUN_10001a10
  cf:
    while(true){
    uVar1 = FUN_10001b50();
    if(uVar1 <= local_c){
    return 0;
    iVar2 = FUN_10001b70();
    iVar2 = std::basic_string<>::compare();
    if(iVar2 == 0)break;
    iVar2 = FUN_10001b70();
    FUN_10001a10();
    puVar3 =(undefined4 *)FUN_10001b70();
    iVar2 = FUN_10001b70();
    *param_5 = *(undefined4 *)(iVar2 + 4);
    return 1;

f FUN_10018870(1):
  c:FUN_100182b0,disconnectPartial
  k:0x14,0x10,0xc,0x18
  cf:
    if(*(int *)(param_1 + 0x14)== 2){
    *(undefined4 *)(param_1 + 0x10)= 2;
    *(undefined4 *)(param_1 + 0xc)= 0;
    FUN_100182b0();
    mInstUsb::disconnectPartial();
    *(undefined4 *)(param_1 + 0x14)= 1;
    *(undefined1 *)(param_1 + 0x18)= 1;
    return;

f FUN_100188c0(1):
  c:sendMessage,FUN_100193d0,__security_check_cookie
  g:DAT_10020030
  k:0xfffffffc,0xc,0x10
  cf:
    local_c = DAT_10020030 ^(uint)&stack0xfffffffc;
    for(local_20 = 0;local_20 < 0xc;local_20 = local_20 + 1){
    lVar1 = mInstUsb::sendMessage(0x10);
    if((lVar1 == 0)&&
    FUN_100193d0();
    __security_check_cookie(0xfffffffc);
    return;

f FUN_10018a00(1):
  c:reconnect
  k:0x10
  cf:
    lVar1 = mInstUsb::reconnect();
    if(lVar1 == 0){
    *(undefined4 *)(param_1 + 0x10)= 1;
    return lVar1;

f FUN_10018a40(1):
  c:FUN_10001810,FUN_100188c0,FUN_100193d0,FUN_10001840
  g:FUN_10001810,FUN_10001840
  k:0x10,0x2c,0xffffff00
  cf:
    if(*(int *)(param_1 + 0x10)== 1){
    FUN_10001810();
    *(undefined1 *)(param_1 + 0x2c)= 1;
    iVar1 = FUN_100188c0();
    if(iVar1 < 0){
    FUN_100193d0();
    uVar2 = FUN_10001840();
    *(undefined1 *)(param_1 + 0x2c)= 0;
    return uVar2 & 0xffffff00;

f FUN_10018aa0(1):
  c:OutputDebugStringA,Sleep,GetTickCount,FUN_10018a40
  g:S43
  k:0x10,0x1a,0x3e9,0xc,0x28,500
  cf:
    OutputDebugStringA(S43);
    do{
    while((*(int *)(param_1 + 0x10)!= 1 ||(*(char *)(param_1 + 0x1a)== '\0'))){
    Sleep(500);
    Sleep(0x3e9);
    DVar1 = GetTickCount();
    if(*(int *)(param_1 + 0xc)== 0){
    else{
    iVar2 =(**(code **)(**(int **)(param_1 + 0xc)+ 0x28))();
    if(bVar3){
    FUN_10018a40();
    }while(true);

f FUN_10018b60(1):
  c:FUN_10018aa0
  cf:
    FUN_10018aa0();
    return;

f FUN_10018b70(1):
  c:CreateThread,FUN_10017af0
  g:HANDLE,S44,S45
  k:0x28,0x0
  cf:
    if(*(int *)((int)param_1 + 0x28)== 0){
    pvVar1 = CreateThread(0x0);
    *(HANDLE *)((int)param_1 + 0x28)= pvVar1;
    local_9 = *(int *)((int)param_1 + 0x28)== 0;
    if(local_9){
    FUN_10017af0(S44);
    else{
    FUN_10017af0(S45);
    return local_9;

f FUN_10018bf0(1):
  c:FUN_10017af0,Sleep,FUN_100193d0,FUN_10018870,FUN_10018a00,FUN_10018b70,elif
  g:S46,FUN_10018870
  k:0x1b,0x10,0x1a,0xc,0x14,0x7d1,0x18,0x1c,1000,5000,2000
  cf:
    FUN_10017af0(S46);
    do{
    while(true){
    while(*(char *)((int)param_1 + 0x1b)== '\0'){
    if((*(int *)((int)param_1 + 0x10)== 1)&&(*(char *)((int)param_1 + 0x1a)== '\0')){
    Sleep(1000);
    *(undefined1 *)((int)param_1 + 0x1a)= 1;
    Sleep(5000);
    if(*(int *)((int)param_1 + 0x10)!= 1)break;
    if(*(char *)((int)param_1 + 0x1a)== '\0'){
    Sleep(1000);
    *(undefined1 *)((int)param_1 + 0x1a)= 1;
    else{
    if(((*(int *)((int)param_1 + 0xc)!= 0)&&
    FUN_100193d0();
    *(undefined4 *)((int)param_1 + 0x14)= 2;
    FUN_10018870();
    Sleep(0x7d1);
    if(*(int *)((int)param_1 + 0x10)== 2){
    if(*(int *)((int)param_1 + 0x14)== 1){
    if(*(char *)((int)param_1 + 0x18)!= '\0'){
    Sleep(0x1c);
    *(undefined1 *)((int)param_1 + 0x18)= 0;
    FUN_100193d0();
    lVar3 = FUN_10018a00();
    if(lVar3 == 0){
    FUN_100193d0();
    FUN_10018b70();
    *(undefined4 *)((int)param_1 + 0x10)= 1;
    elif(*(int *)((int)param_1 + 0x14)== 2){
    FUN_10018870();
    Sleep(2000);
    else{
    FUN_100193d0();
    Sleep(2000);
    }while(true);

f FUN_10018de0(1):
  c:FUN_10018bf0
  cf:
    FUN_10018bf0();
    return;

f FUN_10018df0(1):
  c:CreateThread,FUN_10017af0
  g:HANDLE,S47,S48
  k:0x20,0x0
  cf:
    if(*(int *)((int)param_1 + 0x20)== 0){
    pvVar1 = CreateThread(0x0);
    *(HANDLE *)((int)param_1 + 0x20)= pvVar1;
    local_9 = *(int *)((int)param_1 + 0x20)== 0;
    if(local_9){
    FUN_10017af0(S47);
    else{
    FUN_10017af0(S48);
    return local_9;

f FUN_10018e60(1):
  c:FUN_10001c20,FUN_10005ec0,FUN_10015af0,FUN_10014870,FUN_10017470,FUN_10004ce0,FUN_10005f30,_strlen,FUN_100069ac,_strcpy_s,FUN_10001890,FUN_10001ba0,FUN_1000837a,FUN_10008417,FUN_100018b0,FUN_10001c80,__security_check_cookie
  g:DAT_10020030,FUN_10014870,FUN_10017470,FUN_10001890,FUN_10008417
  k:0xfffffffc,0xffffff38,0xc9
  cf:
    local_40 = DAT_10020030 ^(uint)&stack0xfffffffc;
    FUN_10001c20();
    FUN_10005ec0();
    FUN_10015af0();
    FUN_10014870();
    FUN_10017470();
    while(true){
    uVar1 = FUN_10004ce0();
    if(uVar1 <= local_30)break;
    piVar2 =(int *)FUN_10005f30();
    sVar3 = _strlen();
    local_38 =(char *)FUN_100069ac();
    piVar2 =(int *)FUN_10005f30();
    _strcpy_s();
    puVar4 =(undefined4 *)FUN_10005f30();
    local_34 =(-(uint)(*(int *)*puVar4 != 2)& 0xffffff38)+ 0xc9;
    FUN_10001890();
    puVar4 =(undefined4 *)FUN_10005f30();
    local_60 = *(undefined4 *)*puVar4;
    std::basic_string<>::operator=(local_5c,local_38);
    FUN_10001ba0();
    FUN_1000837a();
    puVar4 =(undefined4 *)FUN_10005f30();
    FUN_10008417();
    local_8 =(uint)local_8._1_3_ << 8;
    FUN_100018b0();
    FUN_10001c80();
    __security_check_cookie(0xfffffffc);
    return;

f FUN_100193d0(0):
  cf:
    return;

f Unwind_100193e0(0):
  k:0x28
  cf:
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x28));
    return;

f Unwind_10019420(0):
  c:FUN_10001150
  g:FUN_10001150
  cf:
    FUN_10001150();
    return;

f Unwind_10019470(0):
  c:exception
  k:0x10
  cf:
    exception::~exception(0x10);
    return;

f Unwind_100194a0(0):
  c:FUN_10008417
  g:FUN_10008417
  k:0x14
  cf:
    FUN_10008417(0x14);
    return;

f Unwind_100194ab(0):
  c:FUN_10008417
  g:FUN_10008417
  k:0x1c
  cf:
    FUN_10008417(0x1c);
    return;

f Unwind_100194d1(0):
  k:0x2c
  cf:
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x2c));
    return;

f Unwind_100194fe(0):
  c:FUN_10012830
  g:FUN_10012830
  k:0x40
  cf:
    FUN_10012830(0x40);
    return;

f Unwind_10019506(0):
  k:0x6c
  cf:
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x6c));
    return;

f Unwind_10019533(0):
  c:FUN_10001c80
  k:0x24
  cf:
    FUN_10001c80(0x24);
    return;

f Unwind_10019556(0):
  c:FUN_10012830
  g:FUN_10012830
  k:0x40
  cf:
    FUN_10012830(0x40);
    return;

f Unwind_1001955e(0):
  k:0x6c
  cf:
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x6c));
    return;

f Unwind_1001958b(0):
  c:FUN_10003980
  g:FUN_10003980
  k:0x24
  cf:
    FUN_10003980(0x24);
    return;

f Unwind_100195ae(0):
  c:FUN_10003980
  g:FUN_10003980
  k:0x24
  cf:
    FUN_10003980(0x24);
    return;

f Unwind_100195d1(0):
  c:FUN_10003980
  g:FUN_10003980
  k:0x24
  cf:
    FUN_10003980(0x24);
    return;

f Unwind_100195f4(0):
  c:FUN_10003980
  g:FUN_10003980
  k:0x24
  cf:
    FUN_10003980(0x24);
    return;

f Unwind_10019617(0):
  c:FUN_10003980
  g:FUN_10003980
  k:0x24
  cf:
    FUN_10003980(0x24);
    return;

f Unwind_1001963a(0):
  c:FUN_10003980
  g:FUN_10003980
  k:0x24
  cf:
    FUN_10003980(0x24);
    return;

f Unwind_1001965d(0):
  c:FUN_10001c80
  k:0x28
  cf:
    FUN_10001c80(0x28);
    return;

f Unwind_10019665(0):
  c:FUN_100018b0
  k:0x60
  cf:
    FUN_100018b0(0x60);
    return;

f Unwind_10019692(0):
  k:0x2c
  cf:
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x2c));
    return;

f Unwind_100196c2(0):
  k:0x2c
  cf:
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x2c));
    return;

f Unwind_100196ef(0):
  c:FUN_10001b30
  k:0x28
  cf:
    FUN_10001b30(0x28);
    return;

f Unwind_100196f7(0):
  k:0x48
  cf:
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x48));
    return;

f Unwind_10019724(0):
  c:FUN_10001b30
  k:0x24
  cf:
    FUN_10001b30(0x24);
    return;

f Unwind_10019760(0):
  k:0x44
  cf:
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x44));
    return;

f Unwind_10019790(0):
  c:FUN_10005dd0
  cf:
    FUN_10005dd0();
    return;

f Unwind_10019820(0):
  k:0x50
  cf:
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x50));
    return;

f Unwind_10019850(0):
  k:0x34
  cf:
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x34));
    return;

f Unwind_10019880(0):
  k:0x40
  cf:
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x40));
    return;

f Unwind_10019888(0):
  k:0x60
  cf:
    std::basic_string<>::~basic_string<>((basic_string<> *)(unaff_EBP + -0x60));
    return;

f Unwind_100198e0(0):
  c:FUN_100018b0
  k:0x48
  cf:
    FUN_100018b0(0x48);
    return;

f Unwind_100198e8(0):
  c:FUN_100018b0
  k:0x70
  cf:
    FUN_100018b0(0x70);
    return;

f Unwind_10019920(0):
  c:FUN_10003a70
  k:0x14
  cf:
    FUN_10003a70(0x14);
    return;

f FUN_10019950(0):
  c:FUN_10003910,_atexit
  g:FUN_10003910,FUN_10019970
  cf:
    FUN_10003910();
    _atexit(FUN_10019970);
    return;

f FUN_10019970(0):
  c:FUN_10003980
  g:FUN_10003980
  cf:
    FUN_10003980();
    return;
