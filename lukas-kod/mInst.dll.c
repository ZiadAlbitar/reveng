exception * __thiscall FUN_10001010(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_alloc::vftable;
  exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (exception *)this;
}

undefined4 * __fastcall FUN_10001150(undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = 0;
  param_1[1] = 0xeeeeeeee;
  uVar1 = FUN_10034298(0x100);
  param_1[3] = uVar1;
  uVar1 = FUN_10034298(0x400);
  param_1[4] = uVar1;
  param_1[6] = 0x400;
  param_1[5] = 0;
  param_1[7] = 0;
  uVar1 = FUN_10034298(0x400);
  param_1[8] = uVar1;
  param_1[10] = 0x400;
  param_1[9] = 0;
  return param_1;
}

void __fastcall FUN_100011c0(int param_1)

{
  FUN_100355e9(*(void **)(param_1 + 0xc));
  FUN_100355e9(*(void **)(param_1 + 0x10));
  FUN_100355e9(*(void **)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 4) = 0xcdcdcdcd;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}

void __fastcall FUN_10001200(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0xeeeeeeee;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[9] = 0;
  return;
}

void __cdecl FUN_10001220(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x15);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x15);
  }
  return;
}

void __cdecl FUN_10001240(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  cVar1 = *(char *)((int)piVar2 + 0x15);
  while (cVar1 == '\0') {
    piVar2 = (int *)*piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x15);
  }
  return;
}

void __thiscall FUN_10001260(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x15) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)((int)this + 0x18) + 4)) {
    *(int *)(*(int *)((int)this + 0x18) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}

exception * __thiscall FUN_10001420(void *this,exception *param_1)

{
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_alloc::vftable;
  return (exception *)this;
}

void __thiscall FUN_10001440(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x15) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)((int)this + 0x18) + 4)) {
    *(int **)(*(int *)((int)this + 0x18) + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}

void FUN_100014e0(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x15);
  while (cVar1 == '\0') {
    FUN_100014e0((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_100355b4(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x15);
  }
  return;
}

void FUN_100015b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)operator_new(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[2] = param_3;
    puVar1[1] = param_2;
    puVar1[3] = *param_4;
    puVar1[4] = param_4[1];
    *(undefined1 *)(puVar1 + 5) = param_5;
    *(undefined1 *)((int)puVar1 + 0x15) = 0;
  }
  return;
}

void FUN_100015f0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)operator_new(0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = param_2;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_3;
  }
  return;
}

void FUN_10001770(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)operator_new(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 5) = 1;
  *(undefined1 *)((int)puVar1 + 0x15) = 0;
  return;
}

void __fastcall FUN_100017b0(int param_1)

{
  if (0xf < *(uint *)(param_1 + 0x18)) {
    FUN_100355b4(*(void **)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}

int __fastcall FUN_100017e0(int param_1)

{
  if (0xf < *(uint *)(param_1 + 0x24)) {
    return *(int *)(param_1 + 0x10);
  }
  return param_1 + 0x10;
}

void __thiscall FUN_10001bd0(void *this,char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_10001a80(this,(undefined4 *)param_1,(int)pcVar2 - (int)(param_1 + 1));
  return;
}

undefined4 * __thiscall FUN_10001c00(void *this,void *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f338;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_1003532d((undefined4 *)this);
  *(undefined ***)this = std::logic_error::vftable;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0xf;
  local_4 = 0;
  *(undefined1 *)((int)this + 0x10) = 0;
  FUN_100019a0((void *)((int)this + 0xc),param_1,0,0xffffffff);
  ExceptionList = local_c;
  return (undefined4 *)this;
}

undefined4 * __thiscall FUN_10001c60(void *this,undefined4 param_1)

{
  FUN_10001c00(this,param_1);
  *(undefined ***)this = std::length_error::vftable;
  return (undefined4 *)this;
}

undefined4 * __thiscall FUN_10001c80(void *this,undefined4 param_1)

{
  FUN_10001c00(this,param_1);
  *(undefined ***)this = std::out_of_range::vftable;
  return (undefined4 *)this;
}

void __fastcall FUN_10001ca0(exception *param_1)

{
  *(undefined ***)param_1 = std::logic_error::vftable;
  if (0xf < *(uint *)(param_1 + 0x24)) {
    FUN_100355b4(*(void **)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x24) = 0xf;
  *(undefined4 *)(param_1 + 0x20) = 0;
  param_1[0x10] = (exception)0x0;
  exception::~exception(param_1);
  return;
}

exception * __thiscall FUN_10001ce0(void *this,undefined4 param_1,byte param_2)

{
  *(undefined ***)this = std::logic_error::vftable;
  if (0xf < *(uint *)((int)this + 0x24)) {
    FUN_100355b4(*(void **)((int)this + 0x10));
  }
  *(undefined4 *)((int)this + 0x24) = 0xf;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined1 *)((int)this + 0x10) = 0;
  exception::~exception((exception *)this);
  if ((param_2 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (exception *)this;
}

int __thiscall FUN_10001d30(void *this,char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  *(undefined4 *)((int)this + 0x18) = 0xf;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined1 *)((int)this + 4) = 0;
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_10001a80(this,(undefined4 *)param_1,(int)pcVar2 - (int)(param_1 + 1));
  return (int)this;
}

undefined4 * __fastcall FUN_10001d70(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f738;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = (undefined4 *)operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = param_1;
  }
  *param_1 = puVar1;
  local_4 = 0;
  iVar2 = FUN_10001770();
  param_1[6] = iVar2;
  *(undefined1 *)(iVar2 + 0x15) = 1;
  *(undefined4 *)(param_1[6] + 4) = param_1[6];
  *(undefined4 *)param_1[6] = param_1[6];
  *(undefined4 *)(param_1[6] + 8) = param_1[6];
  param_1[7] = 0;
  ExceptionList = local_c;
  return param_1;
}

exception * __thiscall FUN_10001fe0(void *this,exception *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f338;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::logic_error::vftable;
  *(undefined4 *)((int)this + 0x24) = 0xf;
  *(undefined4 *)((int)this + 0x20) = 0;
  local_4 = 0;
  *(undefined1 *)((int)this + 0x10) = 0;
  FUN_100019a0((void *)((int)this + 0xc),param_1 + 0xc,0,0xffffffff);
  ExceptionList = local_c;
  return (exception *)this;
}

void __fastcall FUN_10002880(int param_1)

{
  int iVar1;
  int iVar2;
  
  DMutex::Lock((DMutex *)(param_1 + 0xc));
  iVar1 = *(int *)(param_1 + 0x60);
  iVar2 = FUN_100015f0(iVar1,*(undefined4 *)(iVar1 + 4),(undefined4 *)&stack0x00000004);
  FUN_10019bc0((void *)(param_1 + 0x4c),1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  DMutex::Unlock((DMutex *)(param_1 + 0xc));
  return;
}

void __thiscall FUN_100028d0(void *this,undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  DMutex::Lock((DMutex *)((int)this + 0xc));
  FUN_10001200(param_1);
  iVar1 = *(int *)((int)this + 0x44);
  iVar2 = FUN_100015f0(iVar1,*(undefined4 *)(iVar1 + 4),&param_1);
  FUN_10019bc0((void *)((int)this + 0x30),1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  DMutex::Unlock((DMutex *)((int)this + 0xc));
  return;
}

void __thiscall FUN_10002930(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = param_1;
  param_1[1] = 0xd;
  if ((*(byte *)(param_1 + 2) & 0x10) != 0) {
    FUN_100025e0(this,*param_1,(int *)&param_1);
    FUN_100028d0(this,puVar1);
  }
  return;
}

void __thiscall FUN_10002970(void *this,uint param_1,undefined4 param_2)

{
  uint local_14;
  undefined4 local_10;
  int local_c [3];
  
  DMutex::Lock((DMutex *)((int)this + 0xc));
  if (200 < *(int *)((int)this + 0x2c)) {
    FID_conflict__wprintf
              ("Warning: Clearing AsyncCmd Status Entries (too many old entries exist)\n");
    FUN_10002520((int)this);
  }
  local_14 = param_1;
  local_10 = param_2;
  FUN_10002070((void *)((int)this + 0x10),local_c,&local_14);
  DMutex::Unlock((DMutex *)((int)this + 0xc));
  return;
}

void __fastcall FUN_100029d0(undefined4 *param_1)

{
  int local_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_1004f548;
  pvStack_c = ExceptionList;
  local_4 = (void *)0x0;
  ExceptionList = &pvStack_c;
  FUN_10002440(param_1,local_14,(undefined4 *)*param_1,*(int **)param_1[6],(undefined4 *)*param_1,
               (int *)param_1[6]);
  FUN_100355b4((void *)param_1[6]);
  param_1[6] = 0;
  param_1[7] = 0;
  FUN_100355b4((void *)*param_1);
  ExceptionList = local_4;
  return;
}

void __fastcall FUN_10002a40(undefined4 *param_1)

{
  int aiStack_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  puStack_8 = &LAB_1004f548;
  pvStack_c = ExceptionList;
  pvStack_4 = (void *)0x0;
  ExceptionList = &pvStack_c;
  FUN_10002440(param_1,aiStack_14,(undefined4 *)*param_1,*(int **)param_1[6],(undefined4 *)*param_1,
               (int *)param_1[6]);
  FUN_100355b4((void *)param_1[6]);
  param_1[6] = 0;
  param_1[7] = 0;
  FUN_100355b4((void *)*param_1);
  ExceptionList = pvStack_4;
  return;
}

void __fastcall FUN_10002a50(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_1004f23c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = AsyncRequestManager::vftable;
  local_4 = (void *)0x3;
  FUN_100017f0((int)param_1);
  FUN_100190d0((int)(param_1 + 0x13));
  FUN_100355b4((void *)param_1[0x13]);
  FUN_100190d0((int)(param_1 + 0xc));
  FUN_100355b4((void *)param_1[0xc]);
  FUN_100029d0(param_1 + 4);
  DMutex::~DMutex((DMutex *)(param_1 + 3));
  ExceptionList = local_4;
  return;
}

undefined4 * __fastcall FUN_10002b70(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f23c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = AsyncRequestManager::vftable;
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  DMutex::DMutex((DMutex *)(param_1 + 3));
  local_4 = 0;
  FUN_10001d70(param_1 + 4);
  local_4._0_1_ = 1;
  FUN_100220f0(param_1 + 0xc);
  local_4._0_1_ = 2;
  FUN_100220f0(param_1 + 0x13);
  local_4 = CONCAT31(local_4._1_3_,3);
  FUN_10002780((int)param_1);
  ExceptionList = local_c;
  return param_1;
}

undefined4 * __thiscall FUN_10002c00(void *this,byte param_1)

{
  FUN_10002a50((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

void __fastcall FUN_10002c20(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(1);
  }
  return;
}

void __thiscall FUN_10002c30(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x60) = param_1;
  return;
}

DTaskBase * __thiscall FUN_10002c40(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_1004f278;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_10017c30(this,"ColdDataCollector",'\0');
  local_4 = (void *)0x0;
  *(undefined ***)this = ColdDataCollector::vftable;
  *(undefined4 *)((int)this + 0x68) = 0;
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined1 *)((int)this + 0x70) = 1;
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x78) = param_1;
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x80) = 0;
  *(undefined4 *)((int)this + 0x9c) = 0;
  *(undefined4 *)((int)this + 0xa0) = 0;
  *(undefined4 *)((int)this + 0xa4) = 0;
  *(undefined4 *)((int)this + 0xa8) = 0;
  *(undefined4 *)((int)this + 0xac) = 1;
  *(undefined4 *)((int)this + 0xb8) = 1;
  *(undefined4 *)((int)this + 0xbc) = 200000;
  *(undefined4 *)((int)this + 0xc0) = 0;
  *(undefined1 *)((int)this + 0xc4) = 1;
  *(undefined4 *)((int)this + 200) = 0;
  *(undefined1 *)((int)this + 0xcc) = 1;
  *(undefined4 *)((int)this + 0xd0) = 0;
  *(undefined4 *)((int)this + 0xd4) = 0;
  *(undefined4 *)((int)this + 0xd8) = 0x32;
  *(undefined4 *)((int)this + 0xdc) = 2000;
  *(undefined4 *)((int)this + 0xe0) = 0;
  *(undefined4 *)((int)this + 0xe4) = 0;
  *(undefined1 *)((int)this + 0xe8) = 0;
  uVar1 = FUN_10034298(1000000);
  *(undefined4 *)((int)this + 0xb0) = uVar1;
  uVar1 = FUN_10034298(0x10010);
  *(undefined4 *)((int)this + 0xb4) = uVar1;
  if (*(int *)((int)this + 0x60) < 1) {
    *(undefined4 *)((int)this + 0x60) = 10000;
  }
  *(int *)((int)this + 200) = *(int *)((int)this + 0x60) / 0x32;
  DTaskBase::StartTask((DTaskBase *)this,8);
  ExceptionList = local_4;
  return (DTaskBase *)this;
}

undefined4 FUN_10002d80(void)

{
  return 0xffffffff;
}

undefined4 __fastcall FUN_10002d90(int param_1)

{
  return *(undefined4 *)(param_1 + 0x6c);
}

undefined4 __fastcall FUN_10002da0(int param_1)

{
  return *(undefined4 *)(param_1 + 0xb8);
}

void __fastcall FUN_10002db0(DTaskBase *param_1)

{
  undefined4 uStack00000004;
  void *pvStack_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_1004f278;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(undefined ***)param_1 = ColdDataCollector::vftable;
  local_4 = (void *)0x0;
  FUN_100355e9(*(void **)(param_1 + 0xb0));
  FUN_100355e9(*(void **)(param_1 + 0xb4));
  if (*(undefined4 **)(param_1 + 0x78) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x78))(1);
  }
  uStack00000004 = 0xffffffff;
  FUN_10017c80(param_1);
  ExceptionList = local_4;
  return;
}

undefined4 __fastcall FUN_10002e30(int param_1)

{
  int iVar1;
  undefined1 auStack_28 [8];
  undefined1 local_20 [4];
  undefined1 local_1c;
  undefined1 local_1b;
  char local_1a;
  undefined1 local_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  
  FUN_10014dc0(local_20,1,0,(undefined1 *)0x0,0);
  local_1c = 1;
  local_1b = 0x2a;
  local_1a = '\0';
  local_19 = 0;
  (**(code **)(**(int **)(param_1 + 0x78) + 0x38))();
  iVar1 = (**(code **)(**(int **)(param_1 + 0x78) + 0x30))(local_20,0x10,auStack_28);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x78) + 0x24))(&local_1c,0x10,&stack0xffffffd0);
  }
  (**(code **)(**(int **)(param_1 + 0x78) + 0x3c))();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (local_1a != '@') {
    return 0xfffffffe;
  }
  *(uint *)(param_1 + 0x74) = (uint)CONCAT11(uStack_18,uStack_17);
  FUN_10021c10();
  if (CONCAT11(uStack_16,uStack_15) == 0) {
    FUN_10021c10();
    return 0;
  }
  FUN_10021c10();
  return 0;
}

undefined4 __fastcall FUN_10002f40(int param_1)

{
  int iVar1;
  undefined1 auStack_28 [8];
  undefined1 local_20 [4];
  undefined1 auStack_1c [2];
  char cStack_1a;
  
  FUN_10014dc0(local_20,2,0,(undefined1 *)0x0,0);
  FUN_10021c10();
  (**(code **)(**(int **)(param_1 + 0x78) + 0x38))();
  iVar1 = (**(code **)(**(int **)(param_1 + 0x78) + 0x30))(local_20,0x10,auStack_28);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x78) + 0x24))(auStack_1c,0x10,&stack0xffffffd0);
  }
  (**(code **)(**(int **)(param_1 + 0x78) + 0x3c))();
  if ((iVar1 == 0) && (cStack_1a == '@')) {
    FUN_10021c10();
    return 0;
  }
  return 0xffffffff;
}

undefined4 __fastcall FUN_10002fe0(int param_1)

{
  int iVar1;
  undefined1 auStack_28 [8];
  undefined1 local_20 [4];
  undefined1 auStack_1c [2];
  char cStack_1a;
  
  FUN_10014dc0(local_20,0x19,0,(undefined1 *)0x0,0);
  (**(code **)(**(int **)(param_1 + 0x78) + 0x38))();
  iVar1 = (**(code **)(**(int **)(param_1 + 0x78) + 0x30))(local_20,0x10,auStack_28);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x78) + 0x24))(auStack_1c,0x10,&stack0xffffffd0);
  }
  (**(code **)(**(int **)(param_1 + 0x78) + 0x3c))();
  if ((iVar1 == 0) && (cStack_1a == '@')) {
    return 0;
  }
  return 0xffffffff;
}

undefined4 __fastcall FUN_10003070(int param_1)

{
  if (*(int *)(param_1 + 0x68) == 1) {
    FUN_10021c10();
    FUN_10002f40(param_1);
  }
  FUN_10021c10();
  (**(code **)(**(int **)(param_1 + 0x78) + 0xc))();
  *(undefined4 *)(param_1 + 0x68) = 0;
  return 0;
}

undefined4 __thiscall FUN_100030b0(void *this,undefined4 param_1)

{
  FUN_10021c10();
  if (*(int *)((int)this + 0x68) == 1) {
    FUN_10002f40((int)this);
  }
  (**(code **)(**(int **)((int)this + 0x78) + 0x18))(param_1);
  *(undefined4 *)((int)this + 0x68) = 0;
  return 0;
}

undefined4 __thiscall FUN_10003360(void *this,undefined4 *param_1,undefined4 *param_2)

{
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    *param_1 = *(undefined4 *)((int)this + 0x50);
    *param_2 = *(undefined4 *)((int)this + 0x54);
    return 0;
  }
  return 0xffffffff;
}

undefined4 __thiscall FUN_10003390(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_28 [8];
  undefined1 local_20 [4];
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  
  DTaskBase::LockData((DTaskBase *)this);
  *(undefined4 *)((int)this + 0x58) = param_1;
  *(undefined4 *)((int)this + 0x5c) = param_2;
  DTaskBase::UnlockData((DTaskBase *)this);
  FUN_10014dc0(local_20,0x69,0,(undefined1 *)0x0,0);
  local_1c = (undefined1)((uint)param_1 >> 0x18);
  local_1b = (undefined1)((uint)param_1 >> 0x10);
  local_1a = (undefined1)((uint)param_1 >> 8);
  local_18 = (undefined1)((uint)param_2 >> 0x18);
  local_17 = (undefined1)((uint)param_2 >> 0x10);
  local_16 = (undefined1)((uint)param_2 >> 8);
  local_19 = (undefined1)param_1;
  local_15 = (undefined1)param_2;
  (**(code **)(**(int **)((int)this + 0x78) + 0x38))();
  iVar1 = (**(code **)(**(int **)((int)this + 0x78) + 0x30))(local_20,0x10,auStack_28);
  if (iVar1 == 0) {
    (**(code **)(**(int **)((int)this + 0x78) + 0x24))(&local_1c,0x10,&stack0xffffffd0);
  }
  (**(code **)(**(int **)((int)this + 0x78) + 0x3c))();
  return 0;
}

void __fastcall FUN_10003460(int param_1)

{
  DWORD DVar1;
  
  DVar1 = timeGetTime();
  *(DWORD *)(param_1 + 0xa4) = DVar1;
  return;
}

void __fastcall FUN_10003480(int param_1)

{
  int iVar1;
  DWORD DVar2;
  
  if (*(int *)(param_1 + 0xa4) != 0) {
    DVar2 = timeGetTime();
    iVar1 = *(int *)(param_1 + 0xa4);
    *(undefined4 *)(param_1 + 0xa4) = 0;
    *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + (DVar2 - iVar1);
  }
  return;
}

void __fastcall FUN_100034b0(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x9c) != 0) {
    FUN_100362d0(*(undefined4 *)(param_1 + 0xa0),param_2);
    FUN_10021c10();
    return;
  }
  FUN_10021c10();
  return;
}

undefined4 __fastcall FUN_10003c40(int param_1)

{
  int iVar1;
  undefined1 auStack_28 [8];
  undefined1 local_20 [4];
  undefined1 auStack_1c [2];
  char cStack_1a;
  
  FUN_10014dc0(local_20,99,0,(undefined1 *)0x0,0);
  (**(code **)(**(int **)(param_1 + 0x78) + 0x38))();
  iVar1 = (**(code **)(**(int **)(param_1 + 0x78) + 0x30))(local_20,0x10,auStack_28);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x78) + 0x24))(auStack_1c,0x10,&stack0xffffffd0);
  }
  (**(code **)(**(int **)(param_1 + 0x78) + 0x3c))();
  if ((iVar1 == 0) && (cStack_1a == '@')) {
    return 0;
  }
  return 0xffffffff;
}

undefined4 __fastcall FUN_10003cc0(int param_1)

{
  int iVar1;
  undefined1 auStack_28 [8];
  undefined1 local_20 [4];
  undefined1 auStack_1c [2];
  char cStack_1a;
  
  FUN_10014dc0(local_20,0x61,0,(undefined1 *)0x0,0);
  (**(code **)(**(int **)(param_1 + 0x78) + 0x38))();
  iVar1 = (**(code **)(**(int **)(param_1 + 0x78) + 0x30))(local_20,0x10,auStack_28);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x78) + 0x24))(auStack_1c,0x10,&stack0xffffffd0);
  }
  (**(code **)(**(int **)(param_1 + 0x78) + 0x3c))();
  if ((iVar1 == 0) && (cStack_1a == '@')) {
    return 0;
  }
  return 0xffffffff;
}

undefined4 __thiscall
FUN_10004200(void *this,uint param_1,uint param_2,undefined4 *param_3,undefined1 *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((*(uint *)((int)this + 0x5c) & 0x100) != 0) && ((param_2 & 0x100) != 0)) {
    *param_3 = 0x100;
    *param_4 = 1;
    return 0;
  }
  if (((*(uint *)((int)this + 0x5c) & 0x10) != 0) && ((param_2 & 0x10) != 0)) {
    *param_3 = 0x10;
    *param_4 = 1;
    return 0;
  }
  uVar1 = *(uint *)((int)this + 0x58);
  if (((uVar1 & 0x100) != 0) && ((param_1 & 0x100) != 0)) {
    *param_3 = 0x100;
    *param_4 = 0;
    return 0;
  }
  if (((uVar1 & 0x10) != 0) && ((param_1 & 0x10) != 0)) {
    *param_3 = 0x10;
    *param_4 = 0;
    return 0;
  }
  if (((uVar1 & 1) != 0) && ((param_1 & 1) != 0)) {
    uVar2 = 1;
  }
  *param_3 = uVar2;
  *param_4 = 0;
  return 0;
}

uint __thiscall FUN_100042d0(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int unaff_EDI;
  undefined4 unaff_retaddr;
  undefined1 auStack_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined4 *puStack_8;
  
  FUN_10014dc0(local_10,0x18,*(undefined1 *)((int)this + 0x8c),(undefined1 *)0x0,0);
  local_c = (undefined1)((uint)param_2 >> 0x18);
  local_b = (undefined1)((uint)param_2 >> 0x10);
  local_a = (undefined1)((uint)param_2 >> 8);
  local_9 = (undefined1)param_2;
  (**(code **)(**(int **)((int)this + 0x78) + 0x38))();
  iVar1 = (**(code **)(**(int **)((int)this + 0x78) + 0x30))(local_10,0x10,auStack_14);
  if ((iVar1 != 0) ||
     (iVar1 = (**(code **)(**(int **)((int)this + 0x78) + 0x28))
                        (&DAT_10196e48,unaff_retaddr,&stack0xffffffdc), iVar1 != 0)) {
    FUN_10021c10();
  }
  (**(code **)(**(int **)((int)this + 0x78) + 0x3c))();
  if (iVar1 != 0) {
    FUN_10021c10();
    return 0;
  }
  uVar2 = (uint)CONCAT21(CONCAT11(DAT_10196e4d,DAT_10196e4e),DAT_10196e4f);
  if (unaff_EDI != uVar2 + 8) {
    FUN_10021c10();
  }
  FUN_10035ce0(puStack_8,(undefined4 *)&DAT_10196e50,uVar2);
  return uVar2;
}

undefined4 __fastcall FUN_100044d0(void *param_1)

{
  if (*(int **)((int)param_1 + 0x4c) != (int *)0x0) {
    FUN_100043f0(param_1,*(int **)((int)param_1 + 0x4c));
  }
  return 0;
}

undefined4 __thiscall
FUN_100047c0(void *this,uint param_1,undefined4 *param_2,uint param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_EBX;
  undefined1 local_30 [4];
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined4 local_20 [7];
  int iStack_4;
  
  puVar1 = param_2;
  if (param_2 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  FUN_10014dc0(local_30,0xb7,0,(undefined1 *)0x0,0);
  *(int *)((int)this + 0xe0) = *(int *)((int)this + 0xe0) + 1;
  local_2b = (undefined1)(param_1 >> 0x10);
  local_2c = (undefined1)(param_1 >> 0x18);
  local_2a = (undefined1)(param_1 >> 8);
  local_26 = *(undefined1 *)((int)this + 0xe1);
  local_28 = (undefined1)(param_3 >> 8);
  local_25 = *(undefined1 *)((int)this + 0xe0);
  *param_5 = *(undefined4 *)((int)this + 0xe0);
  local_24 = (undefined1)((uint)param_4 >> 0x18);
  local_23 = (undefined1)((uint)param_4 >> 0x10);
  local_21 = (undefined1)param_4;
  local_29 = (undefined1)param_1;
  local_27 = (undefined1)param_3;
  local_22 = (undefined1)((uint)param_4 >> 8);
  FUN_1002ee20(param_1,local_20,puVar1,param_3);
  (**(code **)(**(int **)((int)this + 0x78) + 0x38))();
  iVar2 = (**(code **)(**(int **)((int)this + 0x78) + 0x30))(local_30,0x30,&param_2);
  if ((iVar2 == 0) && (iStack_4 == 0x30)) {
    iVar2 = (**(code **)(**(int **)((int)this + 0x78) + 0x24))
                      (&stack0xffffffc4,0x10,&stack0xffffffc0);
  }
  (**(code **)(**(int **)((int)this + 0x78) + 0x3c))();
  if ((iVar2 == 0) && (unaff_EBX == 0x10)) {
    return 0;
  }
  FUN_10021c10();
  return 0xffffffff;
}

undefined4 __thiscall FUN_10004a50(void *this,undefined4 *param_1)

{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  undefined1 auStack_84 [4];
  undefined1 local_80 [4];
  undefined1 local_7c;
  undefined1 local_7b;
  undefined1 local_7a;
  undefined1 local_79;
  undefined1 local_78;
  undefined1 local_77;
  
  FUN_10014dc0(local_80,0xb6,0,(undefined1 *)0x0,0);
  *(int *)((int)this + 0xe0) = *(int *)((int)this + 0xe0) + 1;
  local_78 = *(undefined1 *)((int)this + 0xe1);
  local_77 = (undefined1)*(undefined4 *)((int)this + 0xe0);
  *param_1 = *(undefined4 *)((int)this + 0xe0);
  local_7c = 0;
  local_7b = 0;
  local_7a = 0;
  local_79 = 0;
  (**(code **)(**(int **)((int)this + 0x78) + 0x38))();
  iVar1 = (**(code **)(**(int **)((int)this + 0x78) + 0x30))(local_80,0x10,auStack_84);
  if ((iVar1 == 0) && (unaff_ESI == 0x10)) {
    iVar1 = (**(code **)(**(int **)((int)this + 0x78) + 0x24))
                      (&stack0xffffff74,0x10,&stack0xffffff6c);
  }
  (**(code **)(**(int **)((int)this + 0x78) + 0x3c))();
  if ((iVar1 == 0) && (unaff_EDI == 0x10)) {
    return 0;
  }
  FUN_10021c10();
  return 0xffffffff;
}

undefined4 __thiscall FUN_10004b30(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined3 uVar4;
  uint uVar3;
  undefined4 unaff_ESI;
  int unaff_EDI;
  undefined1 *puVar5;
  char cVar6;
  undefined1 auStack_84 [4];
  undefined1 local_80 [8];
  undefined1 local_78;
  undefined1 local_77;
  undefined4 *puStack_4;
  
  FUN_10014dc0(local_80,0xb5,0,(undefined1 *)0x0,0);
  local_78 = (undefined1)((uint)param_1 >> 8);
  local_77 = (undefined1)param_1;
  (**(code **)(**(int **)((int)this + 0x78) + 0x38))();
  puVar5 = auStack_84;
  iVar1 = (**(code **)(**(int **)((int)this + 0x78) + 0x30))(local_80,0x10);
  if ((iVar1 == 0) && (unaff_EDI == 0x10)) {
    iVar1 = (**(code **)(**(int **)((int)this + 0x78) + 0x24))
                      (&stack0xffffff74,0x10,&stack0xffffff6c);
  }
  uVar2 = (**(code **)(**(int **)((int)this + 0x78) + 0x3c))();
  if ((iVar1 != 0) || (puVar5 != (undefined1 *)0x10)) {
    uVar3 = FUN_10021c10();
    return uVar3 & 0xffffff00;
  }
  cVar6 = (char)((uint)unaff_ESI >> 0x10);
  uVar4 = (undefined3)((uint)uVar2 >> 8);
  if (cVar6 == '@') {
    *puStack_4 = 0;
    return CONCAT31(uVar4,1);
  }
  if (cVar6 == 'A') {
    *puStack_4 = 0xffffffff;
    return CONCAT31(uVar4,1);
  }
  if (cVar6 == '`') {
    *puStack_4 = 0;
    return (uint)puStack_4 & 0xffffff00;
  }
  *puStack_4 = 0xfffffffe;
  return CONCAT31(uVar4,1);
}

undefined4 __thiscall
FUN_10005170(void *this,undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int unaff_EBX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_30 [4];
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined4 local_20 [7];
  int iStack_4;
  
  puVar2 = param_2;
  if (param_2 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  FUN_10014dc0(local_30,0xb1,0,(undefined1 *)0x0,0);
  local_2a = (undefined1)((uint)param_1 >> 8);
  local_2c = (undefined1)((uint)param_1 >> 0x18);
  local_28 = (undefined1)((uint)param_3 >> 8);
  local_27 = (undefined1)param_3;
  local_2b = (undefined1)((uint)param_1 >> 0x10);
  local_29 = (undefined1)param_1;
  puVar3 = local_20;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  (**(code **)(**(int **)((int)this + 0x78) + 0x38))();
  iVar1 = (**(code **)(**(int **)((int)this + 0x78) + 0x30))(local_30,0x30,&param_2);
  if ((iVar1 == 0) && (iStack_4 == 0x30)) {
    iVar1 = (**(code **)(**(int **)((int)this + 0x78) + 0x24))
                      (&stack0xffffffc4,0x30,&stack0xffffffc0);
  }
  (**(code **)(**(int **)((int)this + 0x78) + 0x3c))();
  if ((iVar1 == 0) && (unaff_EBX == 0x30)) {
    FUN_10021c10();
    return 0;
  }
  FUN_10021c10();
  return 0xffffffff;
}

void __thiscall FUN_10005400(void *this,int param_1)

{
  *(int *)((int)this + 0x60) = param_1;
  if (param_1 < 1) {
    *(undefined4 *)((int)this + 0x60) = 10000;
  }
  *(int *)((int)this + 200) = *(int *)((int)this + 0x60) / 0x32;
  return;
}

undefined4 __fastcall FUN_10005430(int param_1)

{
  int iVar1;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  undefined1 local_10 [16];
  
  FUN_10014dc0(local_10,0x68,0,(undefined1 *)0x0,0);
  (**(code **)(**(int **)(param_1 + 0x78) + 0x38))();
  iVar1 = (**(code **)(**(int **)(param_1 + 0x78) + 0x30))(local_10,0x10,&uStack_28);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x78) + 0x24))(&stack0xffffffd4,0x10,&stack0xffffffd0)
    ;
  }
  (**(code **)(**(int **)(param_1 + 0x78) + 0x3c))();
  if (iVar1 == 0) {
    *(uint *)(param_1 + 0x50) =
         CONCAT31(CONCAT21(CONCAT11(uStack_28,uStack_27),uStack_26),uStack_25);
    *(uint *)(param_1 + 0x54) =
         CONCAT31(CONCAT21(CONCAT11(uStack_24,uStack_23),uStack_22),uStack_21);
    FUN_10021c10();
    return 0;
  }
  FUN_10021c10();
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  return 0xffffffff;
}

undefined4 __fastcall FUN_100055e0(int param_1,undefined4 param_2)

{
  FUN_100034b0(param_1,param_2);
  return 0;
}

undefined4 * __cdecl
FUN_100055f0(ushort param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = (uint)param_1;
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    *puVar1 = DMsg::vftable;
    puVar1[4] = param_4;
    puVar1[5] = param_5;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

undefined4 * __cdecl
FUN_10005630(ushort param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)operator_new(0x2c);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = (uint)param_1;
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[7] = param_4;
    puVar1[8] = param_6;
    *puVar1 = DataMsg::vftable;
    puVar1[9] = param_5;
    puVar1[10] = param_7;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

undefined4 * __thiscall FUN_10005690(void *this,byte param_1)

{
  *(undefined ***)this = DMsg::vftable;
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

DTaskBase * __thiscall FUN_100056b0(void *this,byte param_1)

{
  FUN_10002db0((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

undefined4 __thiscall
FUN_100058e0(void *this,undefined4 param_1,undefined1 param_2,undefined4 *param_3,undefined4 param_4
            )

{
  uint uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  
  puVar2 = param_3;
  if (*(int *)((int)this + 0x68) != 1) {
    return 0xffffffff;
  }
  uVar5 = (uint)param_3 & 0xffff;
  uVar1 = uVar5 + 0x20;
  puVar3 = (undefined1 *)FUN_10034298(uVar1);
  if (puVar3 == (undefined1 *)0x0) {
    FUN_10021c10();
    return 0xffffffff;
  }
  puVar3[4] = param_2;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[0xb] = (char)param_4;
  puVar3[6] = 0;
  puVar3[10] = (char)((uint)param_4 >> 8);
  *puVar3 = 0x15;
  puVar3[3] = 8;
  puVar3[5] = 1;
  puVar3[8] = (char)((uint)puVar2 >> 8);
  puVar3[9] = (char)puVar2;
  FUN_10035ce0((undefined4 *)(puVar3 + 0x10),param_3,uVar5);
  uVar4 = FUN_10003230(this,puVar3,uVar1,(int)&param_3);
  FUN_100355e9(puVar3);
  return uVar4;
}

int __fastcall FUN_100060a0(DTaskBase *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = (**(code **)(**(int **)(param_1 + 0x78) + 0x10))();
  if (cVar1 == '\0') {
    FUN_10021c10();
    return -1;
  }
  iVar2 = FUN_10005990(param_1);
  return iVar2;
}

undefined4 __fastcall FUN_100060d0(void *param_1)

{
  int iVar1;
  undefined4 unaff_ESI;
  
  if (*(int *)((int)param_1 + 0x68) != 1) {
    FUN_10021c10();
    return 0xffffffff;
  }
  *(undefined4 *)((int)param_1 + 0xac) = 0;
  *(undefined4 *)((int)param_1 + 0xa8) = 1;
  FUN_10021c10();
  iVar1 = FUN_100058e0(param_1,0x10,0xe0,(undefined4 *)0x4,unaff_ESI);
  if (iVar1 != 0) {
    FUN_10021c10();
    return 0xffffffff;
  }
  return 0;
}

undefined4 __fastcall FUN_10006150(void *param_1)

{
  int iVar1;
  undefined4 unaff_ESI;
  
  FUN_10021c10();
  iVar1 = FUN_100058e0(param_1,0x20,0xe0,(undefined4 *)0x1,unaff_ESI);
  if (iVar1 != 0) {
    FUN_10021c10();
    return 0xffffffff;
  }
  return 0;
}

undefined4 __fastcall FUN_100061a0(void *param_1)

{
  int iVar1;
  undefined4 unaff_ESI;
  
  FUN_10021c10();
  iVar1 = FUN_100058e0(param_1,0x21,0xe0,(undefined4 *)0x1,unaff_ESI);
  if (iVar1 != 0) {
    FUN_10021c10();
    return 0xffffffff;
  }
  return 0;
}

undefined4 __fastcall FUN_100061f0(void *param_1)

{
  int iVar1;
  undefined4 unaff_ESI;
  
  FUN_10021c10();
  iVar1 = FUN_100058e0(param_1,0x11,0xe0,(undefined4 *)0x4,unaff_ESI);
  if (iVar1 != 0) {
    FUN_10021c10();
    return 0xffffffff;
  }
  return 0;
}

undefined4 __thiscall FUN_10006240(void *this,char param_1)

{
  int iVar1;
  
  if (param_1 != '\0') {
    *(undefined4 *)((int)this + 0x84) = 2;
    *(undefined4 *)((int)this + 0x8c) = 0;
    *(undefined4 *)((int)this + 0x90) = 0;
    *(undefined4 *)((int)this + 0x88) = 100;
    *(undefined4 *)((int)this + 0x9c) = 0;
    *(undefined4 *)((int)this + 0xa0) = 0;
    *(undefined4 *)((int)this + 0xa4) = 0;
  }
  iVar1 = FUN_100060d0(this);
  if (iVar1 != 0) {
    FUN_10021c10();
    return 0xffffffff;
  }
  return 0;
}

void __fastcall FUN_10006810(int param_1)

{
  DMutex::Lock((DMutex *)(param_1 + 0x10));
  return;
}

void __fastcall FUN_10006820(int param_1)

{
  DMutex::Unlock((DMutex *)(param_1 + 0x10));
  return;
}

undefined4 * __fastcall FUN_10006830(undefined4 *param_1)

{
  FUN_1000c420(param_1);
  *param_1 = ColdFtirBtIf::vftable;
  param_1[5] = 0;
  return param_1;
}

void __fastcall FUN_10006850(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 1;
  return;
}

void __fastcall FUN_10006860(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0;
  return;
}

void FUN_10006870(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_1 = 0;
  *param_2 = 0;
  *param_3 = 0;
  return;
}

void __fastcall FUN_100068a0(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004f298;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = ColdFtirBtIf::vftable;
  local_4 = 0;
  if ((undefined4 *)param_1[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[5])(1);
  }
  local_4 = 0xffffffff;
  FUN_1000c450(param_1);
  ExceptionList = pvStack_c;
  return;
}

void __thiscall FUN_10006900(void *this,undefined4 *param_1)

{
  *(undefined4 *)((int)this + 4) = *param_1;
  return;
}

undefined4 __fastcall FUN_10006910(int param_1)

{
  undefined4 *puVar1;
  void *this;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f25b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = (undefined4 *)operator_new(8);
  local_4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    this = (void *)0x0;
  }
  else {
    this = (void *)FUN_10031190(puVar1);
  }
  local_4 = 0xffffffff;
  *(void **)(param_1 + 0x14) = this;
  iVar2 = FUN_100312d0(this,*(int *)(param_1 + 4));
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 8) = 1;
    ExceptionList = local_c;
    return 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  ExceptionList = local_c;
  return 0xffffffff;
}

void __thiscall FUN_100069d0(void *this,undefined1 param_1)

{
  if (*(int *)((int)this + 0x14) != 0) {
    FUN_10021c10();
    FUN_100311d0(*(void **)((int)this + 0x14),param_1);
    *(undefined4 *)((int)this + 8) = 0;
  }
  return;
}

bool __fastcall FUN_10006a00(int param_1)

{
  return *(int *)(param_1 + 8) == 1;
}

void __fastcall FUN_10006a10(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    uVar1 = FUN_100311f0(*(int *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 8) = uVar1;
    return;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

int __thiscall
FUN_10006b60(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  int iVar1;
  
  iVar1 = -1;
  if (((*(void **)((int)this + 0x14) != (void *)0x0) && (*(int *)((int)this + 8) == 1)) &&
     (iVar1 = FUN_10031240(*(void **)((int)this + 0x14),param_1,param_2,param_3,param_4), iVar1 != 0
     )) {
    FUN_10006a10((int)this);
  }
  return iVar1;
}

undefined4 FUN_10006bb0(void)

{
  return 0xffffffff;
}

void __fastcall FUN_10006bc0(int param_1)

{
  DMutex::Lock((DMutex *)(param_1 + 0x10));
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_100312a0(*(int *)(param_1 + 0x14));
    return;
  }
  return;
}

void __fastcall FUN_10006be0(int param_1)

{
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_100312b0(*(int *)(param_1 + 0x14));
  }
  DMutex::Unlock((DMutex *)(param_1 + 0x10));
  return;
}

undefined1 FUN_10006c00(void)

{
  return 0;
}

undefined4 * __thiscall FUN_10006c10(void *this,byte param_1)

{
  FUN_100068a0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

undefined4 __fastcall FUN_10006c30(int param_1)

{
  FUN_10006a10(param_1);
  return *(undefined4 *)(param_1 + 8);
}

undefined4 * __fastcall FUN_10006c40(undefined4 *param_1)

{
  FUN_1000c420(param_1);
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  *param_1 = ColdFtirDevice::vftable;
  param_1[7] = 0x1fc;
  param_1[8] = 0x3c;
  param_1[9] = 1;
  _memset(param_1 + 10,0,0x105);
  return param_1;
}

undefined4 __fastcall FUN_10006c90(int param_1)

{
  return *(undefined4 *)(param_1 + 0x24);
}

undefined4 * __thiscall FUN_10006ca0(void *this,undefined4 param_1)

{
  FUN_1000c420((undefined4 *)this);
  *(undefined ***)this = ColdFtirDevice::vftable;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined1 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0x1fc;
  *(undefined4 *)((int)this + 0x20) = 0x3c;
  *(undefined4 *)((int)this + 0x24) = param_1;
  _memset((void *)((int)this + 0x28),0,0x105);
  return (undefined4 *)this;
}

void __fastcall FUN_10006eb0(int param_1)

{
  if (*(char *)(param_1 + 0x18) != '\0') {
    FUN_10021c10();
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}

void __fastcall FUN_10006ee0(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 1;
  if (*(mInstUsb **)(param_1 + 0x14) != (mInstUsb *)0x0) {
                    // WARNING: Could not recover jumptable at 0x10006eeb. Too many branches
                    // WARNING: Treating indirect jump as call
    mInstUsb::EnableAutoReconnect(*(mInstUsb **)(param_1 + 0x14));
    return;
  }
  return;
}

void __fastcall FUN_10006f00(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0;
  if (*(mInstUsb **)(param_1 + 0x14) != (mInstUsb *)0x0) {
                    // WARNING: Could not recover jumptable at 0x10006f0b. Too many branches
                    // WARNING: Treating indirect jump as call
    mInstUsb::DisableAutoReconnect(*(mInstUsb **)(param_1 + 0x14));
    return;
  }
  return;
}

undefined1 __fastcall FUN_10006f20(int param_1)

{
  return *(undefined1 *)(param_1 + 0x18);
}

void __fastcall FUN_10006f30(int param_1)

{
  ConnState CVar1;
  
  if (*(mInstUsb **)(param_1 + 0x14) != (mInstUsb *)0x0) {
    CVar1 = mInstUsb::GetConnState(*(mInstUsb **)(param_1 + 0x14));
    *(ConnState *)(param_1 + 8) = CVar1;
    return;
  }
  *(undefined4 *)(param_1 + 8) = 2;
  return;
}

undefined4 __thiscall FUN_10006f50(void *this,void *param_1,long param_2,long *param_3)

{
  long lVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (*(char *)((int)this + 0x18) == '\0') {
    return 0xffffffff;
  }
  lVar1 = mInstUsb::receiveMessage(*(mInstUsb **)((int)this + 0x14),param_1,param_2);
  if (0 < lVar1) {
    *param_3 = lVar1;
    uVar2 = 0;
  }
  return uVar2;
}

undefined4 __thiscall FUN_10007000(void *this,void *param_1,long param_2,long *param_3)

{
  long lVar1;
  
  if (*(char *)((int)this + 0x18) == '\0') {
    return 0xffffffff;
  }
  lVar1 = mInstUsb::sendMessage(*(mInstUsb **)((int)this + 0x14),param_1,param_2);
  if (lVar1 == 0) {
    *param_3 = param_2;
    return 0;
  }
  FUN_10021c10();
  return 0xffffffff;
}

undefined4 __thiscall FUN_10007050(void *this,void *param_1,long param_2,void *param_3,long param_4)

{
  long lVar1;
  
  if (*(char *)((int)this + 0x18) == '\0') {
    return 0xffffffff;
  }
  lVar1 = mInstUsb::sendMessage(*(mInstUsb **)((int)this + 0x14),param_1,param_2,param_3,param_4);
  if (lVar1 == 0) {
    return 0;
  }
  FUN_10021c10();
  return 0xffffffff;
}

void __fastcall FUN_10007100(undefined4 *param_1)

{
  mInstUsb *this;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004f298;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = ColdFtirDevice::vftable;
  local_4 = 0;
  FUN_10006e70((int)param_1);
  this = (mInstUsb *)param_1[5];
  if (this != (mInstUsb *)0x0) {
    mInstUsb::~mInstUsb(this);
    FUN_100355b4(this);
  }
  FUN_1000c450(param_1);
  ExceptionList = puStack_8;
  return;
}

undefined4 __fastcall FUN_10007170(int param_1)

{
  FUN_10006f30(param_1);
  return *(undefined4 *)(param_1 + 8);
}

undefined4 * __thiscall FUN_10007180(void *this,byte param_1)

{
  FUN_10007100((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

void * __cdecl FUN_100071c0(void *param_1,int param_2,int param_3)

{
  int iVar1;
  void *_Dst;
  
  iVar1 = param_2 - (int)param_1 >> 2;
  _Dst = (void *)(param_3 + iVar1 * -4);
  if (0 < iVar1) {
    _memmove_s(_Dst,iVar1 * 4,param_1,iVar1 * 4);
  }
  return _Dst;
}

void * FUN_100071f0(void *param_1,int param_2,void *param_3)

{
  rsize_t _DstSize;
  int iVar1;
  
  iVar1 = param_2 - (int)param_1 >> 2;
  _DstSize = iVar1 * 4;
  if (iVar1 != 0) {
    _memmove_s(param_3,_DstSize,param_1,_DstSize);
  }
  return (void *)(_DstSize + (int)param_3);
}

void FUN_10007260(void)

{
  code *pcVar1;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f2b8;
  pvStack_c = ExceptionList;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  ExceptionList = &pvStack_c;
  FUN_10001a80(local_50,(undefined4 *)"vector<T> too long",0x12);
  local_4 = 0;
  FUN_10001c00(local_34,local_50);
  local_34[0] = std::length_error::vftable;
  __CxxThrowException_8(local_34,&DAT_10062230);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

undefined4 * __fastcall FUN_10007650(undefined4 *param_1)

{
  FUN_1000c420(param_1);
  param_1[5] = 0;
  param_1[6] = 0;
  *param_1 = ColdFtirNetIf::vftable;
  param_1[7] = 0x1fc;
  param_1[8] = 0x3c;
  return param_1;
}

void __thiscall FUN_100077d0(void *this,bool param_1)

{
  if (*(int *)((int)this + 0x14) != 0) {
    FUN_10021c10();
    NetIf::ForceDisconnect(*(NetIf **)((int)this + 0x14),param_1);
    *(undefined4 *)((int)this + 8) = 0;
  }
  return;
}

void __fastcall FUN_10007800(int param_1)

{
  ConnState CVar1;
  
  if (*(NetIf **)(param_1 + 0x14) != (NetIf *)0x0) {
    CVar1 = NetIf::GetConnState(*(NetIf **)(param_1 + 0x14));
    *(ConnState *)(param_1 + 8) = CVar1;
    return;
  }
  *(undefined4 *)(param_1 + 8) = 2;
  return;
}

long __thiscall FUN_10007950(void *this,uchar *param_1,ulong param_2,uchar *param_3,ulong param_4)

{
  long lVar1;
  
  lVar1 = -1;
  if (((*(int *)((int)this + 8) == 1) && (*(NetIf **)((int)this + 0x14) != (NetIf *)0x0)) &&
     (lVar1 = NetIf::SendMessageA(*(NetIf **)((int)this + 0x14),param_1,param_2,param_3,param_4),
     lVar1 != 0)) {
    FUN_10007800((int)this);
  }
  return lVar1;
}

void __fastcall FUN_100079a0(int param_1)

{
  DMutex::Lock((DMutex *)(param_1 + 0x10));
  if (*(NetIf **)(param_1 + 0x14) != (NetIf *)0x0) {
    NetIf::Lock(*(NetIf **)(param_1 + 0x14));
    return;
  }
  return;
}

void __fastcall FUN_100079c0(int param_1)

{
  if (*(NetIf **)(param_1 + 0x14) != (NetIf *)0x0) {
    NetIf::Unlock(*(NetIf **)(param_1 + 0x14));
  }
  DMutex::Unlock((DMutex *)(param_1 + 0x10));
  return;
}

void __thiscall FUN_100079e0(void *this,XferState *param_1,long *param_2,long *param_3)

{
  if (*(NetIf **)((int)this + 0x14) != (NetIf *)0x0) {
    NetIf::GetXferStatus(*(NetIf **)((int)this + 0x14),param_1,param_2,param_3);
    return;
  }
  *param_1 = 0;
  *param_2 = 0;
  *param_3 = 0;
  return;
}

void __fastcall FUN_10007a10(undefined4 *param_1)

{
  NetIf *this;
  undefined4 uStack00000004;
  void *pvStack_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_1004f298;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = ColdFtirNetIf::vftable;
  local_4 = (void *)0x0;
  FUN_100355e9((void *)param_1[6]);
  this = (NetIf *)param_1[5];
  if (this != (NetIf *)0x0) {
    NetIf::~NetIf(this);
    FUN_100355b4(this);
  }
  uStack00000004 = 0xffffffff;
  FUN_1000c450(param_1);
  ExceptionList = local_4;
  return;
}

undefined4 __fastcall FUN_10007a80(int param_1)

{
  FUN_10007800(param_1);
  return *(undefined4 *)(param_1 + 8);
}

undefined4 * __thiscall FUN_10007a90(void *this,byte param_1)

{
  FUN_10007a10((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

DTaskBase * __fastcall FUN_10007ab0(DTaskBase *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f278;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10017c30(param_1,"EmulatedDataCollector",'\0');
  *(undefined ***)param_1 = EmulatedDataCollector::vftable;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 1;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 500;
  local_4 = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 200000;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  DTaskBase::StartTask(param_1,8);
  ExceptionList = local_c;
  return param_1;
}

undefined4 FUN_10007b50(void)

{
  return 0;
}

undefined4 FUN_10007b60(void)

{
  return 0xffffffff;
}

undefined4 FUN_10007b70(void)

{
  return 0x5a;
}

void __fastcall FUN_10007b80(DTaskBase *param_1)

{
  *(undefined ***)param_1 = EmulatedDataCollector::vftable;
  FUN_10017c80(param_1);
  return;
}

undefined4 __fastcall FUN_10007b90(int *param_1)

{
  FUN_10017d20((int)param_1);
  (**(code **)(*param_1 + 0x5c))();
  (**(code **)(*param_1 + 0x7c))();
  return 0;
}

void FUN_10008210(undefined4 param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4,
                 int *param_5)

{
  int iVar1;
  undefined4 unaff_retaddr;
  
  iVar1 = FUN_100026a0(&DAT_10196de0,param_1,(int *)&param_5,param_3,param_4,param_5,unaff_retaddr,
                       param_1,param_2);
  if (iVar1 == 0) {
    *param_2 = (uint)param_5;
  }
  return;
}

undefined4 FUN_10008250(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = 0;
  return CONCAT31((int3)((uint)param_2 >> 8),1);
}

undefined4 __thiscall FUN_10008260(void *this,undefined4 *param_1)

{
  *(int *)((int)this + 0x94) = *(int *)((int)this + 0x94) + 1;
  *param_1 = *(undefined4 *)((int)this + 0x94);
  return 0;
}

undefined4 __fastcall FUN_10008280(int param_1)

{
  FUN_1002e9a0(*(void **)(param_1 + 0x4c),0x7019,0x201);
  FUN_1002e9a0(*(void **)(param_1 + 0x4c),0x7029,0x301);
  FUN_1002e9a0(*(void **)(param_1 + 0x4c),0x7039,0x101);
  FUN_1002e9a0(*(void **)(param_1 + 0x4c),0x7049,0x10a);
  FUN_1002e9a0(*(void **)(param_1 + 0x4c),0x8019,0x14);
  FUN_1002e9a0(*(void **)(param_1 + 0x4c),0x1039,0x1020304);
  FUN_1002e9a0(*(void **)(param_1 + 0x4c),0x1049,1);
  FUN_1002ea20(*(void **)(param_1 + 0x4c),0x102e,"1234");
  FUN_1002ea20(*(void **)(param_1 + 0x4c),0x130e,"1234");
  FUN_1002ea20(*(void **)(param_1 + 0x4c),0x131e,"1234");
  FUN_1002ea20(*(void **)(param_1 + 0x4c),0x132e,"1234");
  FUN_1002ea20(*(void **)(param_1 + 0x4c),0x133e,"1234");
  FUN_1002ea20(*(void **)(param_1 + 0x4c),0x134e,"1234");
  FUN_1002ea20(*(void **)(param_1 + 0x4c),0x135e,"1234");
  FUN_1002ea20(*(void **)(param_1 + 0x4c),0x136e,"1234");
  FUN_1002ea20(*(void **)(param_1 + 0x4c),0x13fe,"Emulator_1");
  FUN_1002e9a0(*(void **)(param_1 + 0x4c),0x1109,1);
  FUN_1002e9a0(*(void **)(param_1 + 0x4c),0x1119,0xa5000001);
  return 0;
}

undefined4 __fastcall FUN_100083d0(int param_1)

{
  int *piVar1;
  int local_4;
  
  local_4 = param_1;
  FUN_10022450(*(int *)(param_1 + 0x44));
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1101,1);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1111,3);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1121,1);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1131,3);
  FUN_1002e9c0(*(void **)(param_1 + 0x44),0x1144,0);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1301,2);
  local_4 = 0x20402;
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1311,0x20402);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1321,0);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1331,0);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1341,0);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1351,2);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1361,0x162e);
  FUN_10027530(*(void **)(param_1 + 0x44),0x101,4);
  FUN_10027530(*(void **)(param_1 + 0x44),0x111,0x200);
  FUN_10027530(*(void **)(param_1 + 0x44),0x121,0x80);
  FUN_10027530(*(void **)(param_1 + 0x44),0x131,200);
  FUN_10027530(*(void **)(param_1 + 0x44),0x141,0x8c);
  FUN_10027530(*(void **)(param_1 + 0x44),0x221,0);
  FUN_10027530(*(void **)(param_1 + 0x44),0x3101,1);
  FUN_10027530(*(void **)(param_1 + 0x44),0x3111,0);
  FUN_10027530(*(void **)(param_1 + 0x44),0x3121,0);
  FUN_10027530(*(void **)(param_1 + 0x44),0x3131,1);
  FUN_10027530(*(void **)(param_1 + 0x44),0x3141,1);
  FUN_10027530(*(void **)(param_1 + 0x44),0x1221,0x28);
  FUN_10027570(*(void **)(param_1 + 0x44),0x1234,0x402ccccd);
  FUN_10027530(*(void **)(param_1 + 0x44),0x1201,0xde);
  FUN_10027530(*(void **)(param_1 + 0x44),0x1211,200);
  FUN_1002e9c0(*(void **)(param_1 + 0x44),0x3154,0x45ee7000);
  FUN_10027570(*(void **)(param_1 + 0x44),0x3184,0x45eea7d7);
  FUN_10027570(*(void **)(param_1 + 0x44),0x3194,0xbef0a3d7);
  piVar1 = &local_4;
  (**(code **)(**(int **)(param_1 + 0x4c) + 0xcc))(0x1109);
  FUN_10027530(*(void **)(param_1 + 0x44),0x1151,piVar1);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1011,16000);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1021,22000);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1031,0xffffe890);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1041,4);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1861,0x800);
  FUN_1002e9a0(*(void **)(param_1 + 0x44),0x1051,0x8170600);
  FUN_1002e9c0(*(void **)(param_1 + 0x44),0x1944,0x42426666);
  FUN_1002e9c0(*(void **)(param_1 + 0x44),0x1954,0x4247999a);
  FUN_1002e9c0(*(void **)(param_1 + 0x44),0x1964,0x42480000);
  FUN_1002e9c0(*(void **)(param_1 + 0x44),0x1974,0x42200000);
  FUN_1002e9c0(*(void **)(param_1 + 0x44),0x1984,0x41a00000);
  FUN_1002e9c0(*(void **)(param_1 + 0x44),0x1994,0x41200000);
  FUN_1002e9c0(*(void **)(param_1 + 0x44),0x19c4,0x3f6147ae);
  FUN_1002e9c0(*(void **)(param_1 + 0x44),0x19e4,0x402d70a4);
  FUN_1002e9c0(*(void **)(param_1 + 0x44),0x19f4,0x3f0ccccd);
  FUN_10022460(*(int *)(param_1 + 0x44));
  FUN_10027470(*(void **)(param_1 + 0x48),*(int *)(param_1 + 0x44));
  return 0;
}

undefined4 FUN_10008760(undefined4 *param_1,undefined4 *param_2)

{
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    *param_1 = 1;
    *param_2 = 0;
    return 0;
  }
  return 0xffffffff;
}

int * FUN_10008790(undefined4 *param_1,uint param_2)

{
  int *this;
  
  this = FUN_100281d0(&DAT_101998f0,param_2);
  FUN_10028190(this,1,0);
  FUN_10028150(this,param_1,param_2);
  return this;
}

DTaskBase * __thiscall FUN_100087d0(void *this,byte param_1)

{
  FUN_10007b80((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

void __fastcall FUN_10008b40(int param_1)

{
  int local_4;
  
  local_4 = param_1;
  std::_Lockit::_Lockit((_Lockit *)&local_4,0);
  if (*(int *)(param_1 + 4) != -1) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  }
  FUN_10034502(&local_4);
  return;
}

uint __fastcall FUN_10008b70(uint param_1)

{
  int iVar1;
  uint local_4;
  
  local_4 = param_1;
  std::_Lockit::_Lockit((_Lockit *)&local_4,0);
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) && (iVar1 != -1)) {
    *(int *)(param_1 + 4) = iVar1 + -1;
  }
  iVar1 = *(int *)(param_1 + 4);
  FUN_10034502((int *)&local_4);
  return ~-(uint)(iVar1 != 0) & param_1;
}

void __fastcall FUN_10008bb0(undefined4 *param_1)

{
  *param_1 = std::locale::facet::vftable;
  return;
}

int * __thiscall FUN_10008c10(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1;
  iVar1 = **(int **)((int)this + 0x24);
  *param_1 = iVar1;
  std::_Lockit::_Lockit((_Lockit *)&param_1,0);
  if (*(int *)(iVar1 + 4) != -1) {
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
  }
  FUN_10034502((int *)&param_1);
  return piVar2;
}

ios_base * __thiscall FUN_10008c50(void *this,byte param_1)

{
  *(undefined ***)this = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor((ios_base *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (ios_base *)this;
}

DTaskBase * __fastcall FUN_10008c80(DTaskBase *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f278;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10017c30(param_1,"FileDataCollector",'\0');
  local_4 = 0;
  *(undefined ***)param_1 = FileDataCollector::vftable;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 200000;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  DTaskBase::StartTask(param_1,8);
  ExceptionList = local_c;
  return param_1;
}

undefined4 FUN_10008cf0(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = 2;
  return CONCAT31((int3)((uint)param_2 >> 8),1);
}

undefined4 FUN_10008d00(void)

{
  return 0xffffffff;
}

undefined4 FUN_10008d10(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = 0;
  return 0xffffffff;
}

undefined4 FUN_10008d20(void)

{
  return 100;
}

void __fastcall FUN_10008d30(DTaskBase *param_1)

{
  *(undefined ***)param_1 = FileDataCollector::vftable;
  FUN_10017c80(param_1);
  return;
}

undefined4 __fastcall FUN_10008d40(int param_1)

{
  FUN_10017d20(param_1);
  return 0;
}

undefined4 __thiscall FUN_10008e60(void *this,int param_1,undefined4 *param_2,undefined4 param_3)

{
  if (param_1 == 0x31) {
    *(undefined4 *)((int)this + 0x78) = *param_2;
  }
  else if (param_1 == 0x41) {
    *(undefined4 *)((int)this + 0x7c) = *param_2;
  }
  if (*(int **)((int)this + 0x44) != (int *)0x0) {
    (**(code **)(**(int **)((int)this + 0x44) + 0xbc))(param_1,param_2,param_3);
  }
  return 0;
}

undefined4 FUN_10008ea0(void)

{
  FUN_10021c10();
  return 0xffffffff;
}

int FUN_10008ec0(int param_1)

{
  return -(uint)(param_1 != 1);
}

undefined4 __fastcall FUN_10008ed0(int param_1)

{
  int *this;
  
  this = FUN_100281d0(&DAT_101998f0,*(uint *)(param_1 + 0x74));
  *(int **)(param_1 + 0x70) = this;
  if (this != (int *)0x0) {
    FUN_10021aa0(this,*(undefined4 *)(param_1 + 0x6c));
    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + 1;
    return 0;
  }
  return 0xffffffff;
}

void __fastcall FUN_10008f00(ios_base *param_1)

{
  *(undefined ***)param_1 = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor(param_1);
  return;
}

void __fastcall FUN_10008f10(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -8) + 4) + -8 + param_1) =
       std::basic_istream<>::vftable;
  return;
}

undefined4 __fastcall FUN_10008f90(int param_1)

{
  if (**(int **)(param_1 + 0x20) != 0) {
    return **(undefined4 **)(param_1 + 0x30);
  }
  return 0;
}

int * __thiscall FUN_10009010(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1;
  iVar1 = **(int **)((int)this + 0x38);
  *param_1 = iVar1;
  std::_Lockit::_Lockit((_Lockit *)&param_1,0);
  if (*(int *)(iVar1 + 4) != -1) {
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
  }
  FUN_10034502((int *)&param_1);
  return piVar2;
}

undefined4 * __thiscall FUN_10009050(void *this,undefined4 param_1,undefined4 param_2)

{
  _Ctypevec *p_Var1;
  _Ctypevec local_10;
  
  *(undefined4 *)((int)this + 4) = param_2;
  *(undefined ***)this = std::ctype<char>::vftable;
  p_Var1 = __Getctype(&local_10);
  *(uint *)((int)this + 8) = p_Var1->_Page;
  *(short **)((int)this + 0xc) = p_Var1->_Table;
  *(int *)((int)this + 0x10) = p_Var1->_Delfl;
  *(wchar_t **)((int)this + 0x14) = p_Var1->_LocaleName;
  return (undefined4 *)this;
}

void __thiscall FUN_10009090(void *this,byte param_1)

{
  __Tolower((uint)param_1,(_Ctypevec *)((int)this + 8));
  return;
}

void __thiscall FUN_100090e0(void *this,byte param_1)

{
  __Toupper((uint)param_1,(_Ctypevec *)((int)this + 8));
  return;
}

undefined1 FUN_10009130(undefined1 param_1)

{
  return param_1;
}

void __thiscall FUN_10009140(void *this,int param_1,int param_2,undefined4 param_3)

{
                    // WARNING: Load size is inaccurate
  (**(code **)(*this + 0x1c))(param_1,param_2,param_3,param_2 - param_1);
  return;
}

int FUN_10009170(void *param_1,int param_2,void *param_3,uint param_4)

{
  if (param_4 < (uint)(param_2 - (int)param_1)) {
    FUN_10035812();
  }
  _memcpy_s(param_3,param_4,param_1,param_2 - (int)param_1);
  return param_2;
}

undefined1 FUN_100091b0(undefined1 param_1)

{
  return param_1;
}

void __thiscall
FUN_100091c0(void *this,int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
                    // WARNING: Load size is inaccurate
  (**(code **)(*this + 0x28))(param_1,param_2,param_3,param_4,param_2 - param_1);
  return;
}

int FUN_100091f0(void *param_1,int param_2,undefined4 param_3,void *param_4,uint param_5)

{
  if (param_5 < (uint)(param_2 - (int)param_1)) {
    FUN_10035812();
  }
  _memcpy_s(param_4,param_5,param_1,param_2 - (int)param_1);
  return param_2;
}

DTaskBase * __thiscall FUN_10009280(void *this,byte param_1)

{
  FUN_10008d30((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

void __fastcall FUN_100092a0(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)*param_1 + 4) + 0x28 + *param_1);
  if (iVar1 != 0) {
    FUN_10034966((undefined4 *)(iVar1 + 4));
    return;
  }
  return;
}

void __thiscall FUN_10009330(void *this,undefined4 param_1,undefined4 param_2)

{
                    // WARNING: Load size is inaccurate
  (**(code **)(*this + 0x1c))(param_1,0xffffffff,param_2);
  return;
}

undefined4 __fastcall FUN_10009350(undefined4 param_1)

{
  return param_1;
}

void FUN_10009360(void)

{
  return;
}

undefined4 __fastcall FUN_10009370(int param_1)

{
  if (**(int **)(param_1 + 0x24) != 0) {
    return **(undefined4 **)(param_1 + 0x34);
  }
  return 0;
}

uint __fastcall FUN_10009390(int *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 == -1) {
    return 0xffffffff;
  }
  *(int *)param_1[0xc] = *(int *)param_1[0xc] + -1;
  pbVar1 = *(byte **)param_1[8];
  *(byte **)param_1[8] = pbVar1 + 1;
  return (uint)*pbVar1;
}

void FUN_100093c0(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}

void FUN_100093e0(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}

ios_base * __thiscall FUN_10009400(void *this,byte param_1)

{
  ios_base *piVar1;
  
  piVar1 = (ios_base *)((int)this + -8);
  *(undefined ***)(*(int *)(*(int *)piVar1 + 4) + -8 + (int)this) = std::basic_istream<>::vftable;
  *(undefined ***)this = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor((ios_base *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(piVar1);
  }
  return piVar1;
}

undefined4 * __thiscall FUN_10009440(void *this,byte param_1)

{
  FUN_100092c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

void __fastcall FUN_100094a0(int param_1)

{
  *(int *)(param_1 + 0x20) = param_1 + 0x18;
  *(int *)(param_1 + 0x24) = param_1 + 0x1c;
  *(int *)(param_1 + 0x10) = param_1 + 8;
  *(int *)(param_1 + 0x30) = param_1 + 0x28;
  *(undefined4 **)(param_1 + 0x14) = (undefined4 *)(param_1 + 0xc);
  *(int *)(param_1 + 0x34) = param_1 + 0x2c;
  *(undefined4 *)(param_1 + 0xc) = 0;
  **(undefined4 **)(param_1 + 0x24) = 0;
  **(undefined4 **)(param_1 + 0x34) = 0;
  **(undefined4 **)(param_1 + 0x10) = 0;
  **(undefined4 **)(param_1 + 0x20) = 0;
  **(undefined4 **)(param_1 + 0x30) = 0;
  return;
}

undefined4
FUN_10009560(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 param_5,undefined4 param_6,undefined4 *param_7)

{
  *param_4 = param_2;
  *param_7 = param_5;
  return 3;
}

undefined4
FUN_10009580(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  *param_4 = param_2;
  return 3;
}

uint FUN_100095a0(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = param_3 - param_2;
  if (param_4 < (uint)(param_3 - param_2)) {
    uVar1 = param_4;
  }
  return uVar1;
}

undefined4 * __thiscall FUN_100095c0(void *this,byte param_1)

{
  *(undefined ***)this = std::locale::facet::vftable;
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

void * __thiscall FUN_10009820(void *this,void *param_1)

{
  if (0xf < *(uint *)((int)this + 0x18)) {
    FUN_10009500(param_1,*(undefined4 **)((int)this + 4),(int)this);
    return param_1;
  }
  FUN_10009500(param_1,(undefined4 *)((int)this + 4),(int)this);
  return param_1;
}

bool __cdecl FUN_10009860(char param_1,FILE *param_2)

{
  int iVar1;
  
  iVar1 = FID_conflict__fputc((int)param_1,param_2);
  return iVar1 != -1;
}

uint __fastcall FUN_10009920(int *param_1)

{
  byte *pbVar1;
  uint uVar2;
  
  pbVar1 = *(byte **)param_1[8];
  if ((pbVar1 != (byte *)0x0) && (uVar2 = *(uint *)param_1[8], uVar2 < *(int *)param_1[0xc] + uVar2)
     ) {
    return (uint)*pbVar1;
  }
  uVar2 = (**(code **)(*param_1 + 0x14))();
  if (uVar2 == 0xffffffff) {
    return 0xffffffff;
  }
  (**(code **)(*param_1 + 8))(uVar2);
  return uVar2;
}

_Lockit * __thiscall FUN_10009af0(void *this,basic_string<> *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f324;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  std::_Lockit::_Lockit((_Lockit *)this,0);
  *(undefined4 *)((int)this + 0x1c) = 0xf;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined1 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x38) = 0xf;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined1 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x54) = 0xf;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined1 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x70) = 0xf;
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined1 *)((int)this + 0x5c) = 0;
  local_4 = 4;
  std::_Locinfo::_Locinfo_ctor((_Locinfo *)this,param_1);
  ExceptionList = local_c;
  return (_Lockit *)this;
}

void __fastcall FUN_10009b70(_Locinfo *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004f324;
  pvStack_c = ExceptionList;
  local_4 = 4;
  ExceptionList = &pvStack_c;
  std::_Locinfo::_Locinfo_dtor(param_1);
  if (0xf < *(uint *)(param_1 + 0x70)) {
    FUN_100355b4(*(void **)(param_1 + 0x5c));
  }
  *(undefined4 *)(param_1 + 0x70) = 0xf;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  param_1[0x5c] = (_Locinfo)0x0;
  if (0xf < *(uint *)(param_1 + 0x54)) {
    FUN_100355b4(*(void **)(param_1 + 0x40));
  }
  *(undefined4 *)(param_1 + 0x54) = 0xf;
  *(undefined4 *)(param_1 + 0x50) = 0;
  param_1[0x40] = (_Locinfo)0x0;
  if (0xf < *(uint *)(param_1 + 0x38)) {
    FUN_100355b4(*(void **)(param_1 + 0x24));
  }
  *(undefined4 *)(param_1 + 0x38) = 0xf;
  *(undefined4 *)(param_1 + 0x34) = 0;
  param_1[0x24] = (_Locinfo)0x0;
  if (0xf < *(uint *)(param_1 + 0x1c)) {
    FUN_100355b4(*(void **)(param_1 + 8));
  }
  *(undefined4 *)(param_1 + 0x1c) = 0xf;
  *(undefined4 *)(param_1 + 0x18) = 0;
  param_1[8] = (_Locinfo)0x0;
  FUN_10034502((int *)param_1);
  ExceptionList = puStack_8;
  return;
}

void __fastcall FUN_10009c40(int param_1)

{
  if (0xf < *(uint *)(param_1 + 0x50)) {
    FUN_100355b4(*(void **)(param_1 + 0x3c));
  }
  *(undefined4 *)(param_1 + 0x50) = 0xf;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined1 *)(param_1 + 0x3c) = 0;
  if (0xf < *(uint *)(param_1 + 0x34)) {
    FUN_100355b4(*(void **)(param_1 + 0x20));
  }
  *(undefined4 *)(param_1 + 0x34) = 0xf;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined1 *)(param_1 + 0x20) = 0;
  if (0xf < *(uint *)(param_1 + 0x18)) {
    FUN_100355b4(*(void **)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}

undefined4 * __thiscall FUN_1000a5c0(void *this,void *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f338;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_1003532d((undefined4 *)this);
  *(undefined ***)this = std::runtime_error::vftable;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0xf;
  local_4 = 0;
  *(undefined1 *)((int)this + 0x10) = 0;
  FUN_100019a0((void *)((int)this + 0xc),param_1,0,0xffffffff);
  ExceptionList = local_c;
  return (undefined4 *)this;
}

void * __thiscall FUN_1000a620(void *this,void *param_1)

{
  int iVar1;
  
                    // WARNING: Load size is inaccurate
  iVar1 = *this;
  *(undefined4 *)((int)param_1 + 0x18) = 0xf;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  *(undefined1 *)((int)param_1 + 4) = 0;
  FUN_100019a0(param_1,(void *)(iVar1 + 0x18),0,0xffffffff);
  return param_1;
}

void __fastcall FUN_1000a740(exception *param_1)

{
  *(undefined ***)param_1 = std::runtime_error::vftable;
  if (0xf < *(uint *)(param_1 + 0x24)) {
    FUN_100355b4(*(void **)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x24) = 0xf;
  *(undefined4 *)(param_1 + 0x20) = 0;
  param_1[0x10] = (exception)0x0;
  exception::~exception(param_1);
  return;
}

exception * __thiscall FUN_1000a780(void *this,undefined4 param_1,byte param_2)

{
  *(undefined ***)this = std::runtime_error::vftable;
  if (0xf < *(uint *)((int)this + 0x24)) {
    FUN_100355b4(*(void **)((int)this + 0x10));
  }
  *(undefined4 *)((int)this + 0x24) = 0xf;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined1 *)((int)this + 0x10) = 0;
  exception::~exception((exception *)this);
  if ((param_2 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (exception *)this;
}

exception * __thiscall FUN_1000b150(void *this,exception *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f338;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::runtime_error::vftable;
  *(undefined4 *)((int)this + 0x24) = 0xf;
  *(undefined4 *)((int)this + 0x20) = 0;
  local_4 = 0;
  *(undefined1 *)((int)this + 0x10) = 0;
  FUN_100019a0((void *)((int)this + 0xc),param_1 + 0xc,0,0xffffffff);
  ExceptionList = local_c;
  return (exception *)this;
}

void * __thiscall FUN_1000b260(void *this,void *param_1)

{
  FUN_100019a0(this,param_1,0,0xffffffff);
  FUN_100019a0((void *)((int)this + 0x1c),(void *)((int)param_1 + 0x1c),0,0xffffffff);
  FUN_100019a0((void *)((int)this + 0x38),(void *)((int)param_1 + 0x38),0,0xffffffff);
  *(undefined4 *)((int)this + 0x54) = *(undefined4 *)((int)param_1 + 0x54);
  *(undefined4 *)((int)this + 0x58) = *(undefined4 *)((int)param_1 + 0x58);
  *(undefined4 *)((int)this + 0x5c) = *(undefined4 *)((int)param_1 + 0x5c);
  *(undefined4 *)((int)this + 0x60) = *(undefined4 *)((int)param_1 + 0x60);
  *(undefined4 *)((int)this + 100) = *(undefined4 *)((int)param_1 + 100);
  *(undefined4 *)((int)this + 0x68) = *(undefined4 *)((int)param_1 + 0x68);
  *(undefined4 *)((int)this + 0x6c) = *(undefined4 *)((int)param_1 + 0x6c);
  return this;
}

void __fastcall FUN_1000b2d0(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004f388;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = std::basic_filebuf<>::vftable;
  local_4 = 0;
  if (*(char *)(param_1 + 0x12) != '\0') {
    FUN_1000ada0((int)param_1);
  }
  local_4 = 0xffffffff;
  FUN_100092c0(param_1);
  ExceptionList = pvStack_c;
  return;
}

undefined4 * __thiscall FUN_1000b330(void *this,byte param_1)

{
  FUN_1000b2d0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

void __cdecl FUN_1000b540(void *param_1)

{
  FUN_1000b260(&DAT_100dab18,param_1);
  return;
}

void __fastcall FUN_1000b610(int param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004f3cb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x58) + 4) + -0x58 + param_1) =
       std::basic_ifstream<>::vftable;
  local_4 = 0;
  FUN_1000b2d0((undefined4 *)(param_1 + -0x50));
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x58) + 4) + -8 + param_1 + -0x50) =
       std::basic_istream<>::vftable;
  ExceptionList = local_c;
  return;
}

void __thiscall FUN_1000b670(void *this,int *param_1)

{
  char cVar1;
  facet *pfVar2;
  
  pfVar2 = FUN_1000b400(param_1);
  cVar1 = (**(code **)(*(int *)pfVar2 + 4))();
  if (cVar1 != '\0') {
    *(undefined4 *)((int)this + 0x3c) = 0;
    return;
  }
  *(facet **)((int)this + 0x3c) = pfVar2;
  FUN_100094a0((int)this);
  return;
}

void __fastcall FUN_1000b7c0(int param_1)

{
  ios_base *piVar1;
  
  piVar1 = (ios_base *)(param_1 + 0x58);
  FUN_1000b610((int)piVar1);
  *(undefined ***)piVar1 = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor(piVar1);
  return;
}

ios_base * __thiscall FUN_1000b830(void *this,byte param_1)

{
  FUN_1000b610((int)this);
  *(undefined ***)this = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor((ios_base *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4((ios_base *)((int)this + -0x58));
  }
  return (ios_base *)((int)this + -0x58);
}

undefined4 * __thiscall FUN_1000ba00(void *this,int *param_1,char param_2)

{
  int iVar1;
  uint uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f428;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int **)this = param_1;
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 0x28 + (int)param_1);
  if (iVar1 != 0) {
    FUN_1003495d((undefined4 *)(iVar1 + 4));
  }
                    // WARNING: Load size is inaccurate
  local_4 = 0;
  uVar2 = FUN_1000b870(*this,param_2);
  *(char *)((int)this + 4) = (char)uVar2;
  ExceptionList = local_c;
  return (undefined4 *)this;
}

int * __thiscall FUN_1000ba70(void *this,int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  void *this_00;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f467;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 != 0) {
    ExceptionList = &local_c;
    *(undefined ***)this = &PTR_10053f34;
    *(undefined ***)((int)this + 0x58) = std::basic_ios<>::vftable;
    local_4 = 0;
  }
                    // WARNING: Load size is inaccurate
  *(undefined ***)((int)this + *(int *)(*this + 4)) = std::basic_istream<>::vftable;
                    // WARNING: Load size is inaccurate
  *(undefined4 *)((int)this + 4) = 0;
  this_00 = (void *)(*(int *)(*this + 4) + (int)this);
  FUN_1000b1e0(this_00);
  puVar1 = (undefined4 *)((int)this + 8);
  *(undefined4 **)((int)this_00 + 0x28) = puVar1;
  *(undefined4 *)((int)this_00 + 0x2c) = 0;
  uVar3 = FUN_1000b350(this_00,0x20);
  *(undefined1 *)((int)this_00 + 0x30) = uVar3;
  if (*(int *)((int)this_00 + 0x28) == 0) {
    FUN_1000b030(this_00,*(uint *)((int)this_00 + 8) | 4,'\0');
  }
  *(undefined4 *)((int)this_00 + 4) = 0;
                    // WARNING: Load size is inaccurate
  *(undefined ***)((int)this + *(int *)(*this + 4)) = std::basic_ifstream<>::vftable;
  local_4 = 2;
  FUN_10009780(puVar1);
  *puVar1 = std::basic_filebuf<>::vftable;
  *(undefined1 *)((int)this + 0x50) = 0;
  *(undefined1 *)((int)this + 0x49) = 0;
  FUN_100094a0((int)puVar1);
  *(undefined4 *)((int)this + 0x54) = 0;
  uVar2 = DAT_10199558;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x4c) = uVar2;
  ExceptionList = local_c;
  return (int *)this;
}

undefined4 * __fastcall FUN_1000c420(undefined4 *param_1)

{
  *param_1 = FtirDeviceIf::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 3) = 1;
  DMutex::DMutex((DMutex *)(param_1 + 4));
  return param_1;
}

void __fastcall FUN_1000c450(undefined4 *param_1)

{
  *param_1 = FtirDeviceIf::vftable;
  DMutex::~DMutex((DMutex *)(param_1 + 4));
  return;
}

undefined4 * __thiscall FUN_1000c460(void *this,byte param_1)

{
  FUN_1000c450((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

void __fastcall FUN_1000c480(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}

void __fastcall FUN_1000c490(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}

undefined4 __fastcall FUN_1000c4a0(undefined4 *param_1)

{
  *param_1 = 0;
  return 0;
}

undefined4 __fastcall FUN_1000c4b0(undefined4 *param_1)

{
  return *param_1;
}

void __fastcall FUN_1000c4c0(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}

void __thiscall FUN_1000c4d0(void *this,undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  
  *(undefined1 *)this = 0;
  *(undefined1 *)((int)this + 1) = 0;
  *(undefined1 *)((int)this + 2) = 0;
  *(undefined1 *)((int)this + 3) = 0;
  cVar1 = (char)((uint)param_1 >> 0x18);
  uVar2 = (undefined1)((uint)param_1 >> 8);
  if (cVar1 != '\0') {
    *(char *)this = cVar1;
    *(char *)((int)this + 3) = (char)param_1;
    *(char *)((int)this + 1) = (char)((uint)param_1 >> 0x10);
    *(undefined1 *)((int)this + 2) = uVar2;
    return;
  }
  *(char *)((int)this + 1) = (char)param_1;
  *(undefined1 *)this = uVar2;
  return;
}

void __fastcall FUN_1000c570(int param_1)

{
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  return;
}

void __fastcall FUN_1000c610(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_100180b0(*param_1);
  if (iVar1 == 0) {
    FUN_10018cd0((void *)*param_1);
    return;
  }
  return;
}

void __fastcall FUN_1000c630(int *param_1)

{
  FUN_100180e0(*param_1);
  return;
}

undefined4 __thiscall FUN_1000c640(void *this,undefined4 param_1)

{
                    // WARNING: Load size is inaccurate
  if (*this != (void *)0x0) {
    FUN_10018ca0(*this,param_1);
  }
  return 0;
}

void __thiscall FUN_1000c660(void *this,undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
                    // WARNING: Load size is inaccurate
    piVar1 = (int *)FUN_100181a0(*this,0);
    uVar2 = (**(code **)(*piVar1 + 0x70))();
    *param_1 = uVar2;
  }
  return;
}

undefined4 __thiscall FUN_1000c710(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  if (*(char *)((int)this + 0x3f8) == '\0') {
                    // WARNING: Load size is inaccurate
    FUN_10018100(*this);
                    // WARNING: Load size is inaccurate
    *(undefined4 *)((int)this + 0x3fc) = local_8;
    FUN_10018100(*this);
                    // WARNING: Load size is inaccurate
    *(undefined4 *)((int)this + 0x400) = local_8;
    FUN_10018100(*this);
                    // WARNING: Load size is inaccurate
    *(undefined4 *)((int)this + 0x404) = local_8;
    FUN_10018100(*this);
                    // WARNING: Load size is inaccurate
    *(undefined4 *)((int)this + 0x408) = local_8;
    FUN_10018100(*this);
                    // WARNING: Load size is inaccurate
    *(undefined4 *)((int)this + 0x40c) = local_8;
    FUN_10018100(*this);
                    // WARNING: Load size is inaccurate
    *(undefined4 *)((int)this + 0x410) = local_4;
    FUN_10018100(*this);
    *(undefined4 *)((int)this + 0x414) = local_4;
                    // WARNING: Load size is inaccurate
    FUN_10018100(*this);
    *(undefined4 *)((int)this + 0x418) = local_4;
                    // WARNING: Load size is inaccurate
    FUN_10018100(*this);
    *(undefined4 *)((int)this + 0x41c) = local_4;
    *(undefined1 *)((int)this + 0x3f8) = 1;
  }
  piVar2 = (int *)((int)this + 0x3fc);
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *piVar2;
    piVar2 = piVar2 + 1;
    param_1 = param_1 + 1;
  }
  return 0;
}

undefined4 __thiscall FUN_1000d140(void *this,int param_1)

{
  char cVar1;
  int *this_00;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0xffffffff;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  this_00 = FUN_10027800(&DAT_101997b0,0xffffffff);
  FUN_1002e9a0(this_00,0x1151,*(undefined4 *)(param_1 + 4));
  FUN_1002e9a0(this_00,0x1101,*(undefined4 *)(param_1 + 0xc));
  FUN_1002e9a0(this_00,0x1161,
               (*(uint *)(param_1 + 0x14) & 0xff) << 8 | *(uint *)(param_1 + 0x10) & 0xff);
  FUN_1002e9a0(this_00,0x1171,*(uint *)(param_1 + 0x18) & 0xff);
  FUN_1002e9a0(this_00,0x1181,*(uint *)(param_1 + 0x1c) & 0xff);
  FUN_1002e9a0(this_00,0x1191,*(uint *)(param_1 + 0x20) & 0xff);
                    // WARNING: Load size is inaccurate
  FUN_10018160(*this);
  (**(code **)(*this_00 + 4))();
                    // WARNING: Load size is inaccurate
  iVar3 = 10000;
  cVar1 = FUN_10018180(*this);
  while (cVar1 == '\0') {
    Sleep(100);
    iVar3 = iVar3 + -100;
    if (iVar3 < 1) break;
                    // WARNING: Load size is inaccurate
    cVar1 = FUN_10018180(*this);
  }
  FUN_10021c10();
  if (this == (void *)0x0) {
    uVar2 = 0;
  }
  FUN_1000cf20(this,(int *)0x0,1);
  return uVar2;
}

undefined4 __thiscall FUN_1000db30(void *this,int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int unaff_EBP;
  int iVar3;
  undefined1 local_4 [4];
  
  if (((param_1 != 0) && (param_1 != 1)) && (param_1 != 2)) {
    return 0xffffffff;
  }
                    // WARNING: Load size is inaccurate
  uVar2 = FUN_10018140(*this);
                    // WARNING: Load size is inaccurate
  iVar3 = 10000;
  cVar1 = FUN_10018180(*this);
  while (cVar1 == '\0') {
    Sleep(100);
    iVar3 = iVar3 + -100;
    if (iVar3 < 1) break;
                    // WARNING: Load size is inaccurate
    cVar1 = FUN_10018180(*this);
  }
  FUN_10021c10();
  if (unaff_EBP == 0) {
    uVar2 = 0;
  }
  FUN_1000c950(this,(int *)0x0,1,local_4);
  return uVar2;
}

undefined4 __thiscall FUN_1000dc00(void *this,undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  *param_1 = *(undefined4 *)((int)this + 0x7c);
  param_1[1] = *(undefined4 *)((int)this + 0x80);
  param_1[2] = *(undefined4 *)((int)this + 0x84);
  param_1[3] = *(undefined4 *)((int)this + 0x88);
  param_1[4] = *(undefined4 *)((int)this + 0x8c);
  param_1[5] = *(undefined4 *)((int)this + 0x90);
  return 0;
}

undefined4 __thiscall FUN_1000dc50(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  puVar2 = (undefined4 *)((int)this + 0x94);
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return 0;
}

undefined4 __thiscall FUN_1000dc80(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  puVar2 = (undefined4 *)((int)this + 0xb8);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return 0;
}

undefined4 __thiscall FUN_1000dcb0(void *this,undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  *param_1 = *(undefined4 *)((int)this + 0x118);
  param_1[1] = *(undefined4 *)((int)this + 0x11c);
  return 0;
}

undefined4 __fastcall FUN_1000dce0(int *param_1)

{
  undefined4 local_8;
  
  FUN_10018100(*param_1);
  FUN_10021c10();
  return local_8;
}

uint __thiscall FUN_1000dd20(void *this,undefined4 *param_1)

{
  uint uVar1;
  undefined4 local_8;
  undefined4 local_4;
  
                    // WARNING: Load size is inaccurate
  FUN_10018100(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018100(*this);
  *param_1 = local_8;
  if ((local_4 == 0xfffffffe) || (-1 < (int)local_4)) {
    uVar1 = 0;
  }
  else {
    uVar1 = local_4 & 1;
  }
  FUN_10021c10();
  return uVar1;
}

undefined4 __fastcall FUN_1000dda0(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int iVar3;
  
  uVar2 = FUN_10018140(*param_1);
  iVar3 = 10000;
  cVar1 = FUN_10018180(*param_1);
  while (cVar1 == '\0') {
    Sleep(100);
    iVar3 = iVar3 + -100;
    if (iVar3 < 1) break;
    cVar1 = FUN_10018180(*param_1);
  }
  FUN_10021c10();
  if (unaff_ESI == 0) {
    return 0;
  }
  return uVar2;
}

undefined4 __fastcall FUN_1000de40(int *param_1)

{
  undefined4 local_4;
  
  FUN_10018100(*param_1);
  return local_4;
}

void __fastcall FUN_1000de70(int *param_1)

{
  FUN_10018120(*param_1);
  return;
}

undefined4 __fastcall FUN_1000de90(int *param_1)

{
  undefined4 local_4;
  
  FUN_10018100(*param_1);
  return local_4;
}

void __fastcall FUN_1000dec0(int *param_1)

{
  FUN_10018120(*param_1);
  return;
}

undefined4 __fastcall FUN_1000dee0(int *param_1)

{
  undefined4 local_4;
  
  FUN_10018100(*param_1);
  return local_4;
}

void __fastcall FUN_1000df10(int *param_1)

{
  FUN_10018120(*param_1);
  return;
}

undefined4 __fastcall FUN_1000df30(int *param_1)

{
  undefined4 local_4;
  
  FUN_10018100(*param_1);
  return local_4;
}

void __fastcall FUN_1000df60(int *param_1)

{
  FUN_10018120(*param_1);
  return;
}

undefined4 __fastcall FUN_1000df80(int *param_1)

{
  undefined4 local_4;
  
  FUN_10018100(*param_1);
  return local_4;
}

void __fastcall FUN_1000dfb0(int *param_1)

{
  FUN_10018100(*param_1);
  return;
}

void __thiscall FUN_1000dfe0(void *this,char *param_1)

{
  char cVar1;
  
  do {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
  return;
}

undefined4 __thiscall FUN_1000e010(void *this,int *param_1)

{
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
  *(int *)((int)this + 0x5b4) = *param_1;
  *(int *)((int)this + 0x5b8) = param_1[1];
  *(int *)((int)this + 0x5bc) = param_1[2];
  *(int *)((int)this + 0x5c0) = param_1[3];
  return 0;
}

void __thiscall FUN_1000e0a0(void *this,int param_1)

{
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
  *(int *)((int)this + 0x5fc) = param_1;
  return;
}

undefined4 __thiscall FUN_1000e0d0(void *this,int *param_1)

{
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
  *(int *)((int)this + 0x5c8) = *param_1;
  *(int *)((int)this + 0x5cc) = param_1[1];
  *(int *)((int)this + 0x5d0) = param_1[2];
  *(int *)((int)this + 0x5d4) = param_1[3];
  *(int *)((int)this + 0x5d8) = param_1[4];
  return 0;
}

undefined4 __thiscall FUN_1000e180(void *this,int *param_1)

{
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
  *(int *)((int)this + 0x5e0) = *param_1;
  *(int *)((int)this + 0x5e4) = param_1[1];
  *(int *)((int)this + 0x5e8) = param_1[2];
  *(int *)((int)this + 0x5ec) = param_1[3];
  *(int *)((int)this + 0x5f0) = param_1[4];
  *(int *)((int)this + 0x5f4) = param_1[5];
  return 0;
}

undefined4 __thiscall FUN_1000e210(void *this,int *param_1)

{
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
                    // WARNING: Load size is inaccurate
  FUN_10018100(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018100(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018100(*this);
  *(int *)((int)this + 0x5e0) = *param_1;
  *(int *)((int)this + 0x5e4) = param_1[1];
  *(int *)((int)this + 0x5e8) = param_1[2];
  *(int *)((int)this + 0x5ec) = param_1[3];
  *(int *)((int)this + 0x5f0) = param_1[4];
  *(int *)((int)this + 0x5f4) = param_1[5];
  return 0;
}

undefined4 __thiscall FUN_1000e2b0(void *this,int *param_1,int *param_2,int param_3)

{
  int *this_00;
  
  this_00 = FUN_10027800(&DAT_101997b0,0xffffffff);
  FUN_1002e9a0(this_00,0x101,*param_1);
  FUN_1002e9a0(this_00,0x111,param_1[1]);
  FUN_1002e9a0(this_00,0x121,param_1[2]);
  FUN_1002e9a0(this_00,0x131,param_1[3]);
  *(int *)((int)this + 0x5b4) = *param_1;
  *(int *)((int)this + 0x5b8) = param_1[1];
  *(int *)((int)this + 0x5bc) = param_1[2];
  *(int *)((int)this + 0x5c0) = param_1[3];
  FUN_1002e9a0(this_00,0x3101,*param_2);
  FUN_1002e9a0(this_00,0x3111,param_2[1]);
  FUN_1002e9a0(this_00,0x3121,param_2[2]);
  FUN_1002e9a0(this_00,0x3131,param_2[3]);
  FUN_1002e9a0(this_00,0x3141,param_2[4]);
  *(int *)((int)this + 0x5c8) = *param_2;
  *(int *)((int)this + 0x5cc) = param_2[1];
  *(int *)((int)this + 0x5d0) = param_2[2];
  *(int *)((int)this + 0x5d4) = param_2[3];
  *(int *)((int)this + 0x5d8) = param_2[4];
  FUN_1002e9a0(this_00,0x141,param_3);
  *(int *)((int)this + 0x5fc) = param_3;
                    // WARNING: Load size is inaccurate
  FUN_10018160(*this);
  (**(code **)(*this_00 + 4))();
  return 0;
}

int __fastcall FUN_1000e4e0(int *param_1)

{
  int local_4;
  
  if ((char)param_1[0x17e] == '\0') {
    FUN_10018100(*param_1);
    param_1[0x17f] = local_4;
    *(undefined1 *)(param_1 + 0x17e) = 1;
    return local_4;
  }
  return param_1[0x17f];
}

void __fastcall FUN_1000e660(int *param_1)

{
  FUN_10018120(*param_1);
  FUN_10018120(*param_1);
  FUN_10018120(*param_1);
  return;
}

void __thiscall FUN_1000e6b0(void *this,int *param_1,int *param_2,int *param_3)

{
  if (*(char *)((int)this + 0x584) == '\0') {
                    // WARNING: Load size is inaccurate
    FUN_10018100(*this);
                    // WARNING: Load size is inaccurate
    FUN_10018100(*this);
                    // WARNING: Load size is inaccurate
    FUN_10018100(*this);
    *(undefined1 *)((int)this + 0x584) = 1;
  }
  *param_1 = *(int *)((int)this + 0x588);
  *param_2 = *(int *)((int)this + 0x58c);
  *param_3 = *(int *)((int)this + 0x590);
  return;
}

undefined4 __thiscall FUN_1000e750(void *this,int param_1,int param_2,int param_3)

{
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
  *(int *)((int)this + 0x588) = param_1;
  *(int *)((int)this + 0x58c) = param_2;
  *(int *)((int)this + 0x590) = param_3;
  return 0;
}

undefined4 __thiscall FUN_1000e7c0(void *this,byte *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)((int)this + 0x120);
  *param_1 = (byte)(uVar1 >> 0x1f);
  *param_3 = uVar1 & 0xfff;
  *param_2 = uVar1 >> 0x10 & 0xfff;
  return 0;
}

void __fastcall FUN_1000e800(int *param_1)

{
  FUN_10018120(*param_1);
  return;
}

undefined4 __fastcall FUN_1000e830(int *param_1)

{
  undefined4 local_4;
  
  FUN_10018100(*param_1);
  return local_4;
}

void __fastcall FUN_1000e860(int *param_1)

{
  FUN_10018120(*param_1);
  return;
}

void __thiscall FUN_1000e880(void *this,float *param_1)

{
  undefined4 local_4;
  
                    // WARNING: Load size is inaccurate
  FUN_10018100(*this);
  *param_1 = (float)local_4;
  return;
}

void __fastcall FUN_1000e8c0(int *param_1,undefined4 param_2)

{
  ulonglong uVar1;
  undefined4 uStack00000004;
  
  uVar1 = FUN_100362d0(param_1,param_2);
  uStack00000004 = (undefined4)uVar1;
  FUN_10018120(*param_1);
  return;
}

void __fastcall FUN_1000e8f0(int *param_1)

{
  FUN_10018100(*param_1);
  return;
}

void __fastcall FUN_1000e920(int *param_1)

{
  FUN_10018120(*param_1);
  return;
}

void __fastcall FUN_1000e940(int *param_1)

{
  FUN_10018100(*param_1);
  return;
}

void __fastcall FUN_1000e970(int *param_1)

{
  FUN_10018120(*param_1);
  *(undefined1 *)(param_1 + 0xfe) = 0;
  *(undefined1 *)(param_1 + 0x108) = 0;
  *(undefined1 *)(param_1 + 0x121) = 0;
  return;
}

void __fastcall FUN_1000e9a0(int *param_1)

{
  FUN_10018100(*param_1);
  FUN_10018100(*param_1);
  return;
}

void __thiscall FUN_1000e9f0(void *this,int param_1,int param_2)

{
  int iVar1;
  
                    // WARNING: Load size is inaccurate
  if (((param_1 != 0) && (iVar1 = FUN_10018120(*this), iVar1 == 0)) && (param_2 != 0)) {
                    // WARNING: Load size is inaccurate
    FUN_10018120(*this);
  }
  *(undefined1 *)((int)this + 0x3f8) = 0;
  *(undefined1 *)((int)this + 0x420) = 0;
  *(undefined1 *)((int)this + 0x484) = 0;
  return;
}

void __fastcall FUN_1000ea70(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10018120(*param_1);
  if (iVar1 == 0) {
    FUN_10018120(*param_1);
  }
  *(undefined1 *)(param_1 + 0xfe) = 0;
  *(undefined1 *)(param_1 + 0x108) = 0;
  *(undefined1 *)(param_1 + 0x121) = 0;
  return;
}

void __fastcall FUN_1000ead0(int *param_1)

{
  FUN_10018120(*param_1);
  *(undefined1 *)(param_1 + 0xfe) = 0;
  *(undefined1 *)(param_1 + 0x108) = 0;
  *(undefined1 *)(param_1 + 0x121) = 0;
  return;
}

undefined4 __fastcall FUN_1000eb10(int *param_1)

{
  int iVar1;
  undefined4 local_4;
  
  iVar1 = FUN_10018100(*param_1);
  if (((iVar1 == 0) && (iVar1 = local_4, local_4 != -2)) && (local_4 == 1)) {
    return 0;
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}

undefined4 __thiscall FUN_1000ebc0(void *this,int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (((param_1 == 0) || (param_1 == 1)) || (param_1 == 2)) {
                    // WARNING: Load size is inaccurate
    uVar1 = FUN_10018120(*this);
  }
  *(undefined1 *)((int)this + 0x3f8) = 0;
  *(undefined1 *)((int)this + 0x420) = 0;
  *(undefined1 *)((int)this + 0x484) = 0;
  return uVar1;
}

void __fastcall FUN_1000ec10(int *param_1)

{
  FUN_10018100(*param_1);
  return;
}

void __fastcall FUN_1000ec40(int *param_1)

{
  FUN_10018120(*param_1);
  *(undefined1 *)(param_1 + 0xfe) = 0;
  *(undefined1 *)(param_1 + 0x108) = 0;
  return;
}

void __fastcall FUN_1000ec70(int *param_1)

{
  FUN_10018100(*param_1);
  return;
}

void __fastcall FUN_1000eca0(int *param_1)

{
  FUN_10018120(*param_1);
  return;
}

undefined4 __thiscall
FUN_1000ecc0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
                    // WARNING: Load size is inaccurate
  piVar1 = (int *)FUN_100181a0(*this,0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 100))(param_1,param_2,param_3);
  }
  return 0;
}

undefined4 __thiscall
FUN_1000ecf0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
                    // WARNING: Load size is inaccurate
  piVar1 = (int *)FUN_100181a0(*this,0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x68))(param_1,param_2,param_3);
    *(undefined1 *)((int)this + 0x13c) = 0;
    *(undefined1 *)((int)this + 0x3f8) = 0;
    *(undefined1 *)((int)this + 0x420) = 0;
    *(undefined1 *)((int)this + 0x484) = 0;
    *(undefined1 *)((int)this + 0x4f0) = 0;
  }
  return 0;
}

void FUN_1000ed40(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = param_2[3];
  param_1[1] = param_2[2];
  param_1[2] = param_2[1];
  param_1[3] = *param_2;
  return;
}

undefined4 FUN_1000f710(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = 1;
  *param_2 = 0x55;
  return 0;
}

int __fastcall FUN_1000f730(int *param_1)

{
  undefined4 local_8;
  
  local_8 = FUN_10018100(*param_1);
  if (local_8 == -2) {
    local_8 = 0x32;
  }
  FUN_10018120(*param_1);
  return local_8;
}

undefined4 __fastcall FUN_1000f780(int param_1)

{
  return *(undefined4 *)(param_1 + 0x138);
}

void __fastcall FUN_1000f790(int param_1)

{
  *(undefined4 *)(param_1 + 0x138) = 0;
  return;
}

undefined4 __fastcall FUN_1000f7a0(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 != 0) {
    uVar1 = FUN_10018980(*param_1);
    return uVar1;
  }
  return 0xffffffff;
}

undefined4 __fastcall FUN_1000f7c0(int *param_1)

{
  if (*param_1 != 0) {
    FUN_100189a0(*param_1);
  }
  return 0xffffffff;
}

undefined4 __thiscall FUN_1000f7e0(void *this,int *param_1)

{
  int iVar1;
  undefined4 unaff_EDI;
  undefined4 uVar2;
  undefined4 uStack_3c;
  undefined4 *puStack_38;
  undefined4 uStack_34;
  undefined4 *puStack_30;
  undefined4 uStack_2c;
  undefined4 *puStack_28;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  void **ppvStack_10;
  void *local_4;
  
  ppvStack_10 = &local_4;
  uStack_14 = 0x5811;
  puStack_18 = (undefined1 *)0x1000f7ff;
  local_4 = this;
  iVar1 = (**(code **)(*param_1 + 0xcc))();
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x7c) = unaff_EDI;
  }
  puStack_18 = &stack0xfffffff4;
  uStack_1c = 0x6811;
  puStack_20 = (undefined1 *)0x1000f820;
  iVar1 = (**(code **)(*param_1 + 0xcc))();
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x80) = uStack_14;
  }
  puStack_20 = &stack0xfffffff4;
  uStack_24 = 0x19f4;
  puStack_28 = (undefined4 *)0x1000f844;
  iVar1 = (**(code **)(*param_1 + 0xd0))();
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x88) = uStack_14;
  }
  puStack_28 = &uStack_14;
  uStack_2c = 0x19e4;
  puStack_30 = (undefined4 *)0x1000f868;
  iVar1 = (**(code **)(*param_1 + 0xd0))();
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x84) = uStack_1c;
  }
  puStack_30 = &uStack_1c;
  uStack_34 = 0x19c4;
  puStack_38 = (undefined4 *)0x1000f88c;
  iVar1 = (**(code **)(*param_1 + 0xd0))();
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x90) = uStack_24;
  }
  puStack_38 = &uStack_24;
  uStack_3c = 0x1a04;
  iVar1 = (**(code **)(*param_1 + 0xd0))();
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x8c) = uStack_2c;
  }
  uVar2 = 0x1861;
  iVar1 = (**(code **)(*param_1 + 0xcc))(0x1861,&uStack_34);
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x120) = uStack_3c;
  }
  iVar1 = (**(code **)(*param_1 + 0xcc))(0xd821,&uStack_3c);
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x11c) = uVar2;
    *(undefined4 *)((int)this + 0x118) = 1;
    return 0;
  }
  *(undefined4 *)((int)this + 0x118) = 0;
  return 0;
}

void __fastcall FUN_1000fb90(int param_1)

{
  uint in_EAX;
  
  *(uint *)(param_1 + 0x34) = in_EAX >> 0xe & 0x3f;
  *(uint *)(param_1 + 0x30) = in_EAX >> 8 & 0x3f;
  *(uint *)(param_1 + 0x2c) = in_EAX >> 4 & 0xf;
  *(uint *)(param_1 + 0x28) = in_EAX & 0xf;
  return;
}

undefined4 __fastcall FUN_1000fbc0(int param_1)

{
  if (*(HWND *)(param_1 + 0x30) != (HWND)0x0) {
    PostMessageA(*(HWND *)(param_1 + 0x30),0x8108,0,0);
    return 0;
  }
  if (*(code **)(param_1 + 0x34) != (code *)0x0) {
    (**(code **)(param_1 + 0x34))(0x8108,0);
  }
  return 0;
}

undefined4 __fastcall FUN_1000fbf0(int param_1)

{
  if (*(HWND *)(param_1 + 0x30) != (HWND)0x0) {
    PostMessageA(*(HWND *)(param_1 + 0x30),0x8010,0,0);
    return 0;
  }
  if (*(code **)(param_1 + 0x34) != (code *)0x0) {
    (**(code **)(param_1 + 0x34))(0x8010,0);
  }
  return 0;
}

undefined4 __fastcall FUN_1000fc20(int param_1)

{
  if (*(HWND *)(param_1 + 0x30) != (HWND)0x0) {
    PostMessageA(*(HWND *)(param_1 + 0x30),0x8020,0,0);
    return 0;
  }
  if (*(code **)(param_1 + 0x34) != (code *)0x0) {
    (**(code **)(param_1 + 0x34))(0x8020,0);
  }
  return 0;
}

undefined4 __fastcall FUN_1000fc50(int param_1)

{
  if (*(HWND *)(param_1 + 0x30) != (HWND)0x0) {
    PostMessageA(*(HWND *)(param_1 + 0x30),0x8021,0,0);
    return 0;
  }
  if (*(code **)(param_1 + 0x34) != (code *)0x0) {
    (**(code **)(param_1 + 0x34))(0x8021,0);
  }
  return 0;
}

undefined4 __thiscall FUN_1000fc80(void *this,char param_1)

{
  UINT Msg;
  
  Msg = (uint)(param_1 == '\0') * 8 + 0x8030;
  if (*(HWND *)((int)this + 0x30) != (HWND)0x0) {
    PostMessageA(*(HWND *)((int)this + 0x30),Msg,0,0);
    return 0;
  }
  if (*(code **)((int)this + 0x34) != (code *)0x0) {
    (**(code **)((int)this + 0x34))(Msg,0);
  }
  return 0;
}

void __fastcall FUN_1000fcc0(int *param_1)

{
  FUN_10018120(*param_1);
  return;
}

undefined4 __thiscall FUN_1000fce0(void *this,FileCollectInfo *param_1)

{
                    // WARNING: Load size is inaccurate
  mFtirInst::SetFileCollectInfo(*this,param_1);
  return 0;
}

void __thiscall FUN_1000fd30(void *this,int param_1)

{
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
  *(int *)((int)this + 0x628) = param_1;
  return;
}

void __thiscall FUN_1000fd60(void *this,int param_1)

{
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
  *(int *)((int)this + 0x62c) = param_1;
  return;
}

undefined4 __thiscall FUN_1000fd90(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((*(char *)((int)this + 0x624) != '\0') && (param_1 != (undefined4 *)0x0)) {
    *param_1 = *(undefined4 *)((int)this + 0x630);
    uVar1 = 0;
  }
  return uVar1;
}

uint __thiscall
FUN_1000fdc0(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,
            undefined4 *param_4)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 != (undefined4 *)0x0) && (*(float *)((int)this + 0xa4) != 999.0)) {
    uVar1 = 1;
    *param_1 = *(undefined4 *)((int)this + 0xa4);
  }
  if ((param_2 != (undefined4 *)0x0) && (*(float *)((int)this + 0xa8) != 999.0)) {
    uVar1 = uVar1 | 2;
    *param_2 = *(undefined4 *)((int)this + 0xa8);
  }
  if ((param_3 != (undefined4 *)0x0) && (*(float *)((int)this + 0xac) != 999.0)) {
    uVar1 = uVar1 | 4;
    *param_3 = *(undefined4 *)((int)this + 0xac);
  }
  if ((param_4 != (undefined4 *)0x0) && (*(float *)((int)this + 0xb0) != 999.0)) {
    uVar1 = uVar1 | 8;
    *param_4 = *(undefined4 *)((int)this + 0xb0);
  }
  if (uVar1 == 0) {
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}

undefined4 __thiscall FUN_1000fe70(void *this,undefined4 *param_1)

{
  if ((param_1 != (undefined4 *)0x0) && (*(float *)((int)this + 0xb4) != 999.0)) {
    *param_1 = *(undefined4 *)((int)this + 0xb4);
    return 1;
  }
  return 0xfffffffe;
}

undefined4 __fastcall FUN_1000feb0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x428);
  if ((iVar1 != 0) || (iVar1 = *(int *)(param_1 + 0x3fc), iVar1 != 0)) {
    return CONCAT31((int3)((uint)iVar1 >> 8),iVar1 == 8);
  }
  if ((*(int *)(param_1 + 0x3c) != 0xc9) && (*(int *)(param_1 + 0x3c) != 4)) {
    return 0;
  }
  return 1;
}

uint __fastcall FUN_10010900(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  int iStack00000004;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  iStack00000004 = uVar1 - 1;
  uVar3 = FUN_100362d0(param_1,param_2);
  uVar2 = (uint)uVar3;
  if ((int)uVar1 < (int)(uint)uVar3) {
    uVar2 = uVar1;
  }
  return uVar2 & ((int)uVar2 < 0) - 1;
}

float10 __thiscall FUN_10010950(double *param_1,int param_2)

{
  return (((float10)param_1[1] - (float10)*param_1) * (float10)param_2) /
         (float10)(*(int *)(param_1 + 2) + -1) + (float10)*param_1;
}

void __fastcall FUN_100111d0(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -4) + 4) + -4 + param_1) =
       std::basic_ostream<>::vftable;
  return;
}

void __cdecl FUN_100111e0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x21);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x21);
  }
  return;
}

void __cdecl FUN_10011200(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  cVar1 = *(char *)((int)piVar2 + 0x21);
  while (cVar1 == '\0') {
    piVar2 = (int *)*piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x21);
  }
  return;
}

void __thiscall FUN_10011220(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x21) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)((int)this + 0x18) + 4)) {
    *(int *)(*(int *)((int)this + 0x18) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}

void __thiscall FUN_10011380(void *this,undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  
  *(undefined1 *)this = 0;
  *(undefined1 *)((int)this + 1) = 0;
  *(undefined1 *)((int)this + 2) = 0;
  *(undefined1 *)((int)this + 3) = 0;
  cVar1 = (char)((uint)param_1 >> 0x18);
  uVar2 = (undefined1)((uint)param_1 >> 8);
  if (cVar1 != '\0') {
    *(char *)this = cVar1;
    *(char *)((int)this + 3) = (char)param_1;
    *(char *)((int)this + 1) = (char)((uint)param_1 >> 0x10);
    *(undefined1 *)((int)this + 2) = uVar2;
    return;
  }
  *(char *)((int)this + 1) = (char)param_1;
  *(undefined1 *)this = uVar2;
  return;
}

bool __thiscall FUN_100113d0(void *this,undefined1 *param_1)

{
                    // WARNING: Load size is inaccurate
  return (bool)('\x01' - (CONCAT31(CONCAT21(CONCAT11(*this,*(undefined1 *)((int)this + 1)),
                                            *(undefined1 *)((int)this + 2)),
                                   *(undefined1 *)((int)this + 3)) <
                         CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3])));
}

undefined4 __thiscall FUN_10011af0(void *this,undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  *param_1 = *(undefined4 *)((int)this + 0x44);
  param_1[1] = *(undefined4 *)((int)this + 0x48);
  param_1[2] = *(undefined4 *)((int)this + 0x4c);
  param_1[3] = *(undefined4 *)((int)this + 0x50);
  param_1[4] = *(undefined4 *)((int)this + 0x54);
  param_1[5] = *(undefined4 *)((int)this + 0x58);
  param_1[6] = *(undefined4 *)((int)this + 0x5c);
  return 0;
}

undefined4 __thiscall FUN_10011b30(void *this,undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  *param_1 = *(undefined4 *)((int)this + 0x44);
  param_1[1] = *(undefined4 *)((int)this + 0x48);
  param_1[2] = *(undefined4 *)((int)this + 0x4c);
  param_1[3] = *(undefined4 *)((int)this + 0x50);
  param_1[4] = *(undefined4 *)((int)this + 0x54);
  param_1[5] = *(undefined4 *)((int)this + 0x58);
  param_1[6] = *(undefined4 *)((int)this + 0x5c);
  param_1[7] = *(undefined4 *)((int)this + 0x60);
  param_1[8] = *(undefined4 *)((int)this + 100);
  param_1[9] = *(undefined4 *)((int)this + 0x68);
  param_1[10] = *(undefined4 *)((int)this + 0x6c);
  param_1[0xb] = *(undefined4 *)((int)this + 0x70);
  param_1[0xc] = *(undefined4 *)((int)this + 0x74);
  param_1[0xd] = *(undefined4 *)((int)this + 0x78);
  return 0;
}

void __thiscall FUN_10011ef0(void *this,uint *param_1,uint *param_2,uint *param_3,uint *param_4)

{
  undefined4 uVar1;
  undefined4 local_4;
  
  if (*(char *)((int)this + 0x594) == '\0') {
                    // WARNING: Load size is inaccurate
    FUN_10018100(*this);
    *(undefined4 *)((int)this + 0x598) = local_4;
    *(undefined1 *)((int)this + 0x594) = 1;
  }
  uVar1 = FUN_1000feb0((int)this);
  if ((char)uVar1 != '\0') {
    *param_4 = (uint)*(byte *)((int)this + 0x59b);
    *param_1 = (uint)*(byte *)((int)this + 0x59a);
    *param_2 = (uint)*(byte *)((int)this + 0x599);
    *param_3 = *(uint *)((int)this + 0x598) & 0xff;
    return;
  }
  *param_4 = 0;
  *param_1 = (uint)*(byte *)((int)this + 0x59b);
  *param_2 = (uint)*(byte *)((int)this + 0x59a);
  *param_3 = (uint)*(byte *)((int)this + 0x599);
  return;
}

void __thiscall FUN_10011fc0(void *this,uint param_1,uint param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1000feb0((int)this);
  if ((char)uVar1 == '\0') {
    param_1 = ((param_1 << 8 | param_2) << 8 | param_3) << 8;
  }
  else {
    param_1 = ((param_4 << 8 | param_1) << 8 | param_2) << 8 | param_3;
  }
                    // WARNING: Load size is inaccurate
  FUN_10018120(*this);
  *(uint *)((int)this + 0x598) = param_1;
  return;
}

undefined4 __thiscall FUN_10012030(void *this,undefined1 *param_1,undefined1 *param_2)

{
                    // WARNING: Load size is inaccurate
  FUN_10018100(*this);
                    // WARNING: Load size is inaccurate
  FUN_10018100(*this);
  FUN_10021c10();
  FUN_10021c10();
  return 0xfffffffd;
}

undefined4 __fastcall FUN_10012860(void *param_1)

{
  undefined1 local_61;
  int local_60 [24];
  
  FUN_1000c950(param_1,local_60,1,&local_61);
  if (*(HWND *)((int)param_1 + 0x30) != (HWND)0x0) {
    PostMessageA(*(HWND *)((int)param_1 + 0x30),0x8040,0,0);
    return 0;
  }
  if (*(code **)((int)param_1 + 0x34) != (code *)0x0) {
    (**(code **)((int)param_1 + 0x34))(0x8040,0);
  }
  return 0;
}

undefined4 __fastcall FUN_100128b0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (*(char *)(param_1 + 0xc) == '\0') {
    return 0xffffffff;
  }
  uVar1 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)operator_new(0x1c);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = DMsg::vftable;
    puVar2[1] = 0xff01;
    puVar2[2] = 0;
    puVar2[3] = uVar1;
    puVar2[4] = uVar1;
    puVar2[5] = 0;
    DQueue::Post(*(DQueue **)(param_1 + 4),puVar2);
    return 0;
  }
  DQueue::Post(*(DQueue **)(param_1 + 4),(void *)0x0);
  return 0;
}

undefined4 __fastcall FUN_10012910(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (*(char *)(param_1 + 0xc) == '\0') {
    FUN_10021c10();
    return 0xffffffff;
  }
  if (*(char *)(param_1 + 0x41) != '\0') {
    FUN_10021c10();
    return 0xffffffff;
  }
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined1 *)(param_1 + 0x41) = 1;
  puVar2 = (undefined4 *)operator_new(0x1c);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = DMsg::vftable;
    puVar2[1] = 0xff04;
    puVar2[2] = 0;
    puVar2[3] = uVar1;
    puVar2[4] = uVar1;
    puVar2[5] = 0;
    DQueue::Post(*(DQueue **)(param_1 + 4),puVar2);
    return 0;
  }
  DQueue::Post(*(DQueue **)(param_1 + 4),(void *)0x0);
  return 0;
}

undefined4 __fastcall FUN_100129a0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (*(char *)(param_1 + 0xc) == '\0') {
    FUN_10021c10();
    return 0xffffffff;
  }
  if (*(char *)(param_1 + 0x41) != '\0') {
    FUN_10021c10();
    return 0xffffffff;
  }
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined1 *)(param_1 + 0x41) = 1;
  puVar2 = (undefined4 *)operator_new(0x1c);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = DMsg::vftable;
    puVar2[1] = 0xff06;
    puVar2[2] = 0;
    puVar2[3] = uVar1;
    puVar2[4] = uVar1;
    puVar2[5] = 0;
    DQueue::Post(*(DQueue **)(param_1 + 4),puVar2);
    return 0;
  }
  DQueue::Post(*(DQueue **)(param_1 + 4),(void *)0x0);
  return 0;
}

undefined4 __thiscall FUN_10012aa0(void *this,int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_50 [5];
  int local_3c [4];
  undefined4 local_2c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f508;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_1001cfa0(local_50);
  local_4 = 0;
  local_2c = 0;
  iVar1 = FUN_1000cf20(this,local_3c,1);
  if (iVar1 == 0) {
    uVar2 = FUN_1001cf50(local_50,param_1,param_2);
    local_4 = 0xffffffff;
    FUN_1001c9e0(local_50);
    ExceptionList = local_c;
    return uVar2;
  }
  local_4 = 0xffffffff;
  FUN_1001c9e0(local_50);
  ExceptionList = local_c;
  return 0xffffffff;
}

ios_base * __thiscall FUN_10012c70(void *this,byte param_1)

{
  ios_base *piVar1;
  
  piVar1 = (ios_base *)((int)this + -4);
  *(undefined ***)(*(int *)(*(int *)piVar1 + 4) + -4 + (int)this) = std::basic_ostream<>::vftable;
  *(undefined ***)this = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor((ios_base *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(piVar1);
  }
  return piVar1;
}

void __thiscall FUN_10012cb0(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x21) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)((int)this + 0x18) + 4)) {
    *(int **)(*(int *)((int)this + 0x18) + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}

void FUN_10012d00(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x21);
  while (cVar1 == '\0') {
    FUN_10012d00((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_100355b4(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x21);
  }
  return;
}

void FUN_10012d40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)operator_new(0x24);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[2] = param_3;
    puVar1[1] = param_2;
    puVar1[3] = *param_4;
    puVar1[4] = param_4[1];
    puVar1[5] = param_4[2];
    puVar1[6] = param_4[3];
    puVar1[7] = param_4[4];
    *(undefined1 *)(puVar1 + 8) = param_5;
    *(undefined1 *)((int)puVar1 + 0x21) = 0;
  }
  return;
}

void FUN_10012da0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)operator_new(0x24);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 8) = 1;
  *(undefined1 *)((int)puVar1 + 0x21) = 0;
  return;
}

void __fastcall FUN_10012ef0(undefined4 *param_1)

{
  if ((void *)param_1[3] != (void *)0x0) {
    FUN_100355b4((void *)param_1[3]);
  }
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  FUN_100355b4((void *)*param_1);
  return;
}

undefined4 * __fastcall FUN_10013760(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f738;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = (undefined4 *)operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = param_1;
  }
  *param_1 = puVar1;
  local_4 = 0;
  iVar2 = FUN_10012da0();
  param_1[6] = iVar2;
  *(undefined1 *)(iVar2 + 0x21) = 1;
  *(undefined4 *)(param_1[6] + 4) = param_1[6];
  *(undefined4 *)param_1[6] = param_1[6];
  *(undefined4 *)(param_1[6] + 8) = param_1[6];
  param_1[7] = 0;
  ExceptionList = local_c;
  return param_1;
}

void __fastcall FUN_10013fc0(undefined4 *param_1)

{
  int local_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_1004f548;
  pvStack_c = ExceptionList;
  local_4 = (void *)0x0;
  ExceptionList = &pvStack_c;
  FUN_100139d0(param_1,local_14,(undefined4 *)*param_1,*(int **)param_1[6],(undefined4 *)*param_1,
               (int *)param_1[6]);
  FUN_100355b4((void *)param_1[6]);
  param_1[6] = 0;
  param_1[7] = 0;
  FUN_100355b4((void *)*param_1);
  ExceptionList = local_4;
  return;
}

void __fastcall FUN_10014030(int param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004f56b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x54) + 4) + -0x54 + param_1) =
       std::basic_ofstream<>::vftable;
  local_4 = 0;
  FUN_1000b2d0((undefined4 *)(param_1 + -0x50));
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x54) + 4) + -4 + param_1 + -0x50) =
       std::basic_ostream<>::vftable;
  ExceptionList = local_c;
  return;
}

void __fastcall FUN_10014090(undefined4 *param_1)

{
  int aiStack_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  puStack_8 = &LAB_1004f548;
  pvStack_c = ExceptionList;
  pvStack_4 = (void *)0x0;
  ExceptionList = &pvStack_c;
  FUN_100139d0(param_1,aiStack_14,(undefined4 *)*param_1,*(int **)param_1[6],(undefined4 *)*param_1,
               (int *)param_1[6]);
  FUN_100355b4((void *)param_1[6]);
  param_1[6] = 0;
  param_1[7] = 0;
  FUN_100355b4((void *)*param_1);
  ExceptionList = pvStack_4;
  return;
}

void __fastcall FUN_100140a0(int *param_1)

{
  DQueue *this;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004f58b;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  if ((void *)param_1[2] != (void *)0x0) {
    ExceptionList = &pvStack_c;
    FUN_10015770((void *)param_1[2],(DQueue *)param_1[1]);
  }
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*param_1)(1);
  }
  this = (DQueue *)param_1[1];
  if (this != (DQueue *)0x0) {
    DQueue::~DQueue(this);
    FUN_100355b4(this);
  }
  local_4 = 0xffffffff;
  FUN_10013fc0(param_1 + 4);
  ExceptionList = pvStack_c;
  return;
}

void __fastcall FUN_10014120(int param_1)

{
  ios_base *piVar1;
  
  piVar1 = (ios_base *)(param_1 + 0x54);
  FUN_10014030((int)piVar1);
  *(undefined ***)piVar1 = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor(piVar1);
  return;
}

ios_base * __thiscall FUN_10014140(void *this,byte param_1)

{
  FUN_10014030((int)this);
  *(undefined ***)this = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor((ios_base *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4((ios_base *)((int)this + -0x54));
  }
  return (ios_base *)((int)this + -0x54);
}

int * __fastcall FUN_10014180(int *param_1)

{
  DQueue *this;
  int iVar1;
  DTaskBase *pDVar2;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f5c1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  FUN_10013760(param_1 + 4);
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)((int)param_1 + 0x41) = 0;
  param_1[0x15] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x1c] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x46] = 0;
  param_1[0x4e] = 0;
  *(undefined1 *)(param_1 + 0x4f) = 0;
  *(undefined1 *)(param_1 + 0x50) = 0;
  *(undefined1 *)((int)param_1 + 0x141) = 0;
  *(undefined1 *)((int)param_1 + 0x142) = 0;
  *(undefined1 *)((int)param_1 + 0x143) = 0;
  *(undefined1 *)(param_1 + 0x51) = 0;
  *(undefined1 *)((int)param_1 + 0x145) = 0;
  *(undefined1 *)((int)param_1 + 0x146) = 0;
  *(undefined1 *)((int)param_1 + 0x147) = 0;
  *(undefined1 *)(param_1 + 0x52) = 0;
  *(undefined1 *)((int)param_1 + 0x149) = 0;
  *(undefined1 *)((int)param_1 + 0x14a) = 0;
  *(undefined1 *)((int)param_1 + 0x14b) = 0;
  *(undefined1 *)(param_1 + 0x53) = 0;
  *(undefined1 *)((int)param_1 + 0x14d) = 0;
  *(undefined1 *)((int)param_1 + 0x14e) = 0;
  *(undefined1 *)((int)param_1 + 0x14f) = 0;
  *(undefined1 *)(param_1 + 0x97) = 0;
  *(undefined1 *)((int)param_1 + 0x25d) = 0;
  *(undefined1 *)((int)param_1 + 0x25e) = 0;
  *(undefined1 *)((int)param_1 + 0x25f) = 0;
  *(undefined1 *)(param_1 + 0x98) = 0;
  *(undefined1 *)((int)param_1 + 0x261) = 0;
  *(undefined1 *)((int)param_1 + 0x262) = 0;
  *(undefined1 *)((int)param_1 + 0x263) = 0;
  *(undefined1 *)(param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x265) = 0;
  *(undefined1 *)((int)param_1 + 0x266) = 0;
  *(undefined1 *)((int)param_1 + 0x267) = 0;
  *(undefined1 *)(param_1 + 0x9a) = 0;
  *(undefined1 *)((int)param_1 + 0x269) = 0;
  *(undefined1 *)((int)param_1 + 0x26a) = 0;
  *(undefined1 *)((int)param_1 + 0x26b) = 0;
  *(undefined1 *)(param_1 + 0xfe) = 0;
  param_1[0xff] = 0;
  *(undefined1 *)(param_1 + 0x108) = 0;
  local_4 = 0;
  param_1[0x109] = 2;
  param_1[0x10a] = 0;
  param_1[0x10b] = 0;
  param_1[0x10c] = 0;
  param_1[0x10d] = 0;
  param_1[0x10e] = 0;
  param_1[0x10f] = 0;
  param_1[0x112] = 0;
  param_1[0x110] = 0;
  param_1[0x113] = 0;
  param_1[0x111] = 0;
  param_1[0x114] = 0;
  param_1[0x116] = 0;
  param_1[0x117] = 0;
  param_1[0x118] = 0;
  param_1[0x119] = 0;
  *(undefined1 *)(param_1 + 0x121) = 0;
  param_1[299] = 0;
  param_1[300] = 0;
  param_1[0x123] = 0;
  param_1[0x12d] = 0;
  param_1[0x124] = 0;
  param_1[0x125] = 0;
  param_1[0x126] = 0;
  param_1[0x127] = 0;
  param_1[0x128] = 0;
  param_1[0x129] = 0;
  param_1[0x12a] = 0;
  param_1[0x122] = 1;
  *(undefined1 *)(param_1 + 0x12e) = 0;
  param_1[0x12f] = 1;
  param_1[0x131] = 0;
  param_1[0x132] = 0;
  param_1[0x133] = 0;
  param_1[0x134] = 0;
  *(undefined1 *)(param_1 + 0x13c) = 0;
  *(undefined1 *)((int)param_1 + 0x4f1) = 0;
  param_1[0x13d] = 0;
  param_1[0x14e] = 0;
  param_1[0x13e] = 0;
  param_1[0x13f] = 0;
  param_1[0x140] = 0;
  param_1[0x141] = 0;
  param_1[0x142] = 0;
  param_1[0x143] = 0;
  param_1[0x144] = 0;
  param_1[0x145] = 0;
  param_1[0x146] = 0;
  param_1[0x147] = 0;
  param_1[0x148] = 0;
  param_1[0x149] = 0;
  param_1[0x14a] = 0;
  param_1[0x14b] = 0;
  param_1[0x14c] = 0;
  param_1[0x14d] = 0;
  param_1[0x14f] = 0;
  param_1[0x160] = 0;
  param_1[0x150] = 0;
  param_1[0x151] = 0;
  param_1[0x152] = 0;
  param_1[0x153] = 0;
  param_1[0x154] = 0;
  param_1[0x155] = 0;
  param_1[0x156] = 0;
  param_1[0x157] = 0;
  param_1[0x158] = 0;
  param_1[0x159] = 0;
  param_1[0x15a] = 0;
  param_1[0x15b] = 0;
  param_1[0x15c] = 0;
  param_1[0x15d] = 0;
  param_1[0x15e] = 0;
  param_1[0x15f] = 0;
  *(undefined1 *)(param_1 + 0x161) = 0;
  *(undefined1 *)(param_1 + 0x165) = 0;
  *(undefined1 *)(param_1 + 0x16a) = 0;
  param_1[0x16b] = 0;
  *(undefined1 *)(param_1 + 0x16c) = 0;
  *(undefined1 *)(param_1 + 0x171) = 0;
  *(undefined1 *)(param_1 + 0x17e) = 0;
  this = (DQueue *)operator_new(0x40);
  local_4._0_1_ = 1;
  if (this == (DQueue *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DQueue::DQueue(this,8);
  }
  local_4._0_1_ = 0;
  param_1[1] = iVar1;
  pDVar2 = (DTaskBase *)operator_new(0x224);
  local_4._0_1_ = 2;
  if (pDVar2 == (DTaskBase *)0x0) {
    pDVar2 = (DTaskBase *)0x0;
  }
  else {
    pDVar2 = FUN_1001b310(pDVar2);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  *param_1 = (int)pDVar2;
  if (pDVar2 != (DTaskBase *)0x0) {
    FUN_10017fb0(pDVar2);
    *(int *)(*param_1 + 0x54) = param_1[1];
  }
  *(undefined1 *)(param_1 + 0x49) = 0;
  *(undefined1 *)(param_1 + 0x180) = 0;
  *(undefined1 *)(param_1 + 0x189) = 0;
  param_1[0x181] = 0;
  param_1[0x182] = 0;
  param_1[0x183] = 0;
  param_1[0x184] = 0;
  param_1[0x185] = 0;
  param_1[0x186] = 0;
  param_1[0x187] = 0;
  param_1[0x188] = 0;
  param_1[0x18a] = 0;
  param_1[0x18b] = 0;
  param_1[0x18c] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  ExceptionList = local_c;
  return param_1;
}

int * __thiscall FUN_100148d0(void *this,int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  void *this_00;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f627;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 != 0) {
    ExceptionList = &local_c;
    *(undefined ***)this = &PTR_10054a24;
    *(undefined ***)((int)this + 0x54) = std::basic_ios<>::vftable;
    local_4 = 0;
  }
                    // WARNING: Load size is inaccurate
  *(undefined ***)(*(int *)(*this + 4) + (int)this) = std::basic_ostream<>::vftable;
                    // WARNING: Load size is inaccurate
  this_00 = (void *)(*(int *)(*this + 4) + (int)this);
  FUN_1000b1e0(this_00);
  puVar1 = (undefined4 *)((int)this + 4);
  *(undefined4 **)((int)this_00 + 0x28) = puVar1;
  *(undefined4 *)((int)this_00 + 0x2c) = 0;
  uVar3 = FUN_1000b350(this_00,0x20);
  *(undefined1 *)((int)this_00 + 0x30) = uVar3;
  if (*(int *)((int)this_00 + 0x28) == 0) {
    FUN_1000b030(this_00,*(uint *)((int)this_00 + 8) | 4,'\0');
  }
  *(undefined4 *)((int)this_00 + 4) = 0;
                    // WARNING: Load size is inaccurate
  *(undefined ***)(*(int *)(*this + 4) + (int)this) = std::basic_ofstream<>::vftable;
  local_4 = 2;
  FUN_10009780(puVar1);
  *puVar1 = std::basic_filebuf<>::vftable;
  *(undefined1 *)((int)this + 0x4c) = 0;
  *(undefined1 *)((int)this + 0x45) = 0;
  FUN_100094a0((int)puVar1);
  *(undefined4 *)((int)this + 0x50) = 0;
  uVar2 = DAT_10199558;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x48) = uVar2;
  ExceptionList = local_c;
  return (int *)this;
}

undefined4 FUN_10014da0(undefined4 param_1)

{
  DAT_10199570 = param_1;
  return 1;
}

undefined4 * __thiscall
FUN_10014e90(void *this,_StartAddress *param_1,void *param_2,char *param_3,undefined1 param_4)

{
  uintptr_t uVar1;
  
  *(undefined1 *)((int)this + 4) = param_4;
  *(undefined ***)this = DTask::vftable;
  if (param_3 == (char *)0x0) {
    param_3 = "NoName";
  }
  _strncpy((char *)((int)this + 5),param_3,0x20);
  *(undefined1 *)((int)this + 0x24) = 0;
  uVar1 = __beginthreadex((void *)0x0,0,param_1,param_2,0,(uint *)((int)this + 0x28));
  *(uintptr_t *)((int)this + 0x2c) = uVar1;
  if (uVar1 == 0) {
    FUN_10021c10();
  }
  return (undefined4 *)this;
}

void __fastcall FUN_10014f00(undefined4 *param_1)

{
  *param_1 = DTask::vftable;
  return;
}

void __fastcall FUN_10014f10(int param_1)

{
  WaitForSingleObject(*(HANDLE *)(param_1 + 0x2c),0xffffffff);
  return;
}

undefined4 * __thiscall FUN_10014fc0(void *this,byte param_1)

{
  FUN_10014f00((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

void FUN_10015400(void)

{
  code *pcVar1;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f2b8;
  pvStack_c = ExceptionList;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  ExceptionList = &pvStack_c;
  FUN_10001a80(local_50,(undefined4 *)"deque<T> too long",0x11);
  local_4 = 0;
  FUN_10001c00(local_34,local_50);
  local_34[0] = std::length_error::vftable;
  __CxxThrowException_8(local_34,&DAT_10062230);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

void __thiscall FUN_100155e0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int unaff_ESI;
  uint uVar5;
  
  if (((*(byte *)((int)this + 0x18) & 3) == 0) &&
     (*(uint *)((int)this + 0x14) <= *(int *)((int)this + 0x1c) + 4U >> 2)) {
    FUN_10015470(this,1,unaff_ESI);
  }
  iVar3 = *(int *)((int)this + 0x18);
  if (iVar3 == 0) {
    iVar3 = *(int *)((int)this + 0x14) * 4;
  }
  uVar4 = iVar3 - 1;
  uVar5 = uVar4 >> 2;
  if (*(int *)(*(int *)((int)this + 0x10) + uVar5 * 4) == 0) {
    pvVar2 = operator_new(0x10);
    *(void **)(*(int *)((int)this + 0x10) + uVar5 * 4) = pvVar2;
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)((int)this + 0x10) + uVar5 * 4) + (uVar4 & 3) * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
  }
  *(int *)((int)this + 0x1c) = *(int *)((int)this + 0x1c) + 1;
  *(uint *)((int)this + 0x18) = uVar4;
  return;
}

void __thiscall FUN_10015660(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  uint uVar3;
  int unaff_ESI;
  uint uVar4;
  
  if (((*(int *)((int)this + 0x18) + *(int *)((int)this + 0x1c) & 3U) == 0) &&
     (*(uint *)((int)this + 0x14) <= *(int *)((int)this + 0x1c) + 4U >> 2)) {
    FUN_10015470(this,1,unaff_ESI);
  }
  uVar3 = *(int *)((int)this + 0x18) + *(int *)((int)this + 0x1c);
  uVar4 = uVar3 >> 2;
  if (*(uint *)((int)this + 0x14) <= uVar4) {
    uVar4 = uVar4 - *(uint *)((int)this + 0x14);
  }
  if (*(int *)(*(int *)((int)this + 0x10) + uVar4 * 4) == 0) {
    pvVar2 = operator_new(0x10);
    *(void **)(*(int *)((int)this + 0x10) + uVar4 * 4) = pvVar2;
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)((int)this + 0x10) + uVar4 * 4) + (uVar3 & 3) * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
  }
  *(int *)((int)this + 0x1c) = *(int *)((int)this + 0x1c) + 1;
  return;
}

void __thiscall FUN_10015770(void *this,DQueue *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = DMsg::vftable;
    puVar1[1] = 2;
    puVar1[2] = 0;
    puVar1[3] = param_1;
    puVar1[4] = param_1;
    puVar1[5] = 0;
  }
  DQueue::Post(param_1,puVar1);
  FUN_10014f10((int)this);
  CloseHandle(*(HANDLE *)((int)this + 0x2c));
  *(undefined4 *)((int)this + 0x2c) = 0;
                    // WARNING: Load size is inaccurate
  (*(code *)**this)(1);
  return;
}

undefined4 __thiscall
FUN_10015ad0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  uint3 uVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = param_2;
  local_c = param_4;
  local_14 = param_5;
  local_4 = param_3;
  local_8 = param_1;
  uVar1 = FUN_10015900(this,(byte *)&local_14);
  uVar2 = (uint3)((uint)uVar1 >> 8);
  if (((char)uVar1 != '\0') && (*(int *)((int)this + 0x14) != 0)) {
    return CONCAT31(uVar2,1);
  }
  return (uint)uVar2 << 8;
}

void __cdecl FUN_10015bd0(uint param_1,int param_2)

{
  void *pvVar1;
  undefined *puVar2;
  
  puVar2 = &DAT_101995ac;
  if (param_2 != 0) {
    puVar2 = &DAT_101995c8;
  }
  if (*(int *)(puVar2 + 0x14) == 0) {
    pvVar1 = operator_new(-(uint)((int)((ulonglong)param_1 * 8 >> 0x20) != 0) |
                          (uint)((ulonglong)param_1 * 8));
    *(uint *)(puVar2 + 0x18) = param_1;
    *(void **)(puVar2 + 0x14) = pvVar1;
  }
  return;
}

overlap smaller symbols at the same address

undefined4 __cdecl FUN_100170d0(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if (0x23 < uVar1) {
    uVar1 = 0x24;
  }
  FUN_10035ce0((undefined4 *)&DAT_100daf18,param_1,uVar1);
  _DAT_100daf18 = uVar1;
  return 0;
}

undefined4 __cdecl
FUN_10017150(double param_1,int param_2,short param_3,double param_4,double param_5,double param_6,
            double *param_7,undefined8 *param_8,double *param_9)

{
  double dVar1;
  int iVar2;
  
  if (param_2 == 0) {
    return 0xffffffff;
  }
  if (param_3 != 0) {
    param_1 = (param_5 - param_4) * param_6 + param_1;
  }
  if (param_7 != (double *)0x0) {
    *param_7 = param_1;
  }
  if (param_8 != (undefined8 *)0x0) {
    *param_8 = 0;
  }
  dVar1 = (double)param_2;
  if (param_2 < 0) {
    dVar1 = dVar1 + 4294967296.0;
  }
  dVar1 = (1.0 / dVar1) * param_1;
  iVar2 = FUN_10017100((undefined4 *)0x0,-1);
  if (0 < iVar2) {
    dVar1 = (double)(iVar2 + -1) * (dVar1 / (double)iVar2);
  }
  if (param_9 == (double *)0x0) {
    return 0;
  }
  *param_9 = dVar1;
  return 0;
}

undefined4 __cdecl FUN_10017200(int param_1,int param_2,int param_3)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  ulonglong uVar6;
  
  iVar2 = FUN_100170a0((int)(0x4000 / (longlong)param_1));
  uVar3 = iVar2 + param_3;
  if ((int)uVar3 < 0) {
    uVar3 = -uVar3;
  }
  do {
    uVar3 = uVar3 >> 1;
  } while (uVar3 != 0);
  uVar6 = FUN_100362d0(0,extraout_EDX);
  DAT_1019957c = (int)uVar6;
  lVar1 = (uVar6 & 0xffffffff) * 8;
  DAT_10199578 = operator_new(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  uVar3 = param_2 * 2;
  DAT_10199584 = operator_new(-(uint)((int)((ulonglong)uVar3 * 8 >> 0x20) != 0) |
                              (uint)((ulonglong)uVar3 * 8));
  DAT_10199588 = operator_new(-(uint)((int)((ulonglong)uVar3 * 8 >> 0x20) != 0) |
                              (uint)((ulonglong)uVar3 * 8));
  DAT_10199590 = DAT_1019957c + param_2 * 3;
  DAT_1019958c = param_2;
  DAT_10199594 = operator_new(-(uint)((int)((ulonglong)DAT_10199590 * 8 >> 0x20) != 0) |
                              (uint)((ulonglong)DAT_10199590 * 8));
  DAT_10199598 = operator_new(-(uint)((int)((ulonglong)DAT_10199590 * 8 >> 0x20) != 0) |
                              (uint)((ulonglong)DAT_10199590 * 8));
  iVar2 = FUN_100170a0(DAT_10199590);
  uVar4 = iVar2 + 1;
  if ((int)uVar4 < 0) {
    uVar4 = -uVar4;
  }
  do {
    uVar4 = uVar4 >> 1;
  } while (uVar4 != 0);
  uVar6 = FUN_100362d0(0,extraout_EDX_00);
  DAT_1019959c = (undefined4)uVar6;
  lVar1 = (uVar6 & 0xffffffff) * 8;
  DAT_101995a0 = operator_new(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  pvVar5 = operator_new(0x1c);
  if (pvVar5 == (void *)0x0) {
    DAT_101995a4 = (undefined1 *)0x0;
  }
  else {
    DAT_101995a4 = FUN_100337b0(pvVar5,DAT_10199590,0);
  }
  pvVar5 = operator_new(0x1c);
  if (pvVar5 == (void *)0x0) {
    DAT_101995a8 = (undefined1 *)0x0;
  }
  else {
    DAT_101995a8 = FUN_100337b0(pvVar5,DAT_10199590,0);
  }
  FUN_10015bd0(uVar3,0);
  FUN_10015bd0(DAT_10199590,1);
  FUN_10021c10();
  return 0;
}

overlap smaller symbols at the same address

undefined4 FUN_10017430(void)

{
  undefined1 *puVar1;
  
  if (DAT_10199578 != (void *)0x0) {
    FUN_100355b4(DAT_10199578);
  }
  DAT_10199578 = (void *)0x0;
  DAT_10199580 = 0;
  DAT_1019957c = 0;
  FUN_100355b4(DAT_10199594);
  FUN_100355b4(DAT_10199598);
  DAT_10199594 = (void *)0x0;
  DAT_10199598 = (void *)0x0;
  FUN_100355b4(DAT_10199584);
  FUN_100355b4(DAT_10199588);
  puVar1 = DAT_101995a4;
  DAT_10199584 = (void *)0x0;
  DAT_10199588 = (void *)0x0;
  DAT_1019958c = 0;
  if (DAT_101995a4 != (undefined1 *)0x0) {
    FUN_10033750(DAT_101995a4);
    FUN_100355b4(puVar1);
  }
  puVar1 = DAT_101995a8;
  DAT_101995a4 = (undefined1 *)0x0;
  if (DAT_101995a8 != (undefined1 *)0x0) {
    FUN_10033750(DAT_101995a8);
    FUN_100355b4(puVar1);
  }
  DAT_101995a8 = (undefined1 *)0x0;
  FUN_100355b4(DAT_101995a0);
  DAT_101995a0 = (void *)0x0;
  if (DAT_101995c0 != (void *)0x0) {
    FUN_100355b4(DAT_101995c0);
  }
  _DAT_101995ac = 0;
  _DAT_101995b0 = 0;
  _DAT_101995b4 = 0;
  _DAT_101995b8 = 0;
  _DAT_101995bc = 0;
  DAT_101995c0 = (void *)0x0;
  _DAT_101995c4 = 0;
  if (DAT_101995dc != (void *)0x0) {
    FUN_100355b4(DAT_101995dc);
  }
  DAT_101995dc = (void *)0x0;
  DAT_101995e0 = 0;
  _DAT_101995c8 = 0;
  _DAT_101995cc = 0;
  _DAT_101995d0 = 0;
  _DAT_101995d4 = 0;
  _DAT_101995d8 = 0;
  FUN_10021c10();
  return 0;
}

undefined4 FUN_10017c10(void)

{
  return 0;
}

undefined4 FUN_10017c20(void)

{
  return 0xffffffff;
}

DTaskBase * __thiscall FUN_10017c30(void *this,char *param_1,uchar param_2)

{
  DTaskBase::DTaskBase((DTaskBase *)this,param_1,param_2,0);
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x60) = 0xffffffff;
  *(undefined4 *)((int)this + 100) = 0xffffffff;
  *(undefined ***)this = DataCollector::vftable;
  return (DTaskBase *)this;
}

void __fastcall FUN_10017c80(DTaskBase *param_1)

{
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1004f6a8;
  pvStack_10 = ExceptionList;
  ExceptionList = &pvStack_10;
  *(undefined ***)param_1 = DataCollector::vftable;
  local_8 = 1;
  if (*(int **)(param_1 + 0x44) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x44) + 4))();
  }
  if (*(int **)(param_1 + 0x48) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x48) + 4))();
  }
  if (*(int **)(param_1 + 0x4c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x4c) + 0x10))(1);
    FUN_10017cfb();
    return;
  }
  local_8 = 0xffffffff;
  DTaskBase::~DTaskBase(param_1);
  ExceptionList = pvStack_10;
  return;
}

void FUN_10017cfb(void)

{
  int unaff_EBP;
  DTaskBase *unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  DTaskBase::~DTaskBase(unaff_ESI);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

undefined4 __fastcall FUN_10017d20(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f25b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(param_1 + 0x44) == 0) {
    ExceptionList = &local_c;
    piVar1 = FUN_10027800(&DAT_101997b0,0xffffffff);
    *(int **)(param_1 + 0x44) = piVar1;
  }
  if (*(int *)(param_1 + 0x48) == 0) {
    piVar1 = FUN_10027800(&DAT_101997b0,0xffffffff);
    *(int **)(param_1 + 0x48) = piVar1;
  }
  puVar2 = (undefined4 *)operator_new(0x100);
  local_4 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    puVar2 = FUN_1001d020(puVar2);
    *(undefined4 **)(param_1 + 0x4c) = puVar2;
    ExceptionList = local_c;
    return 0;
  }
  *(undefined4 *)(param_1 + 0x4c) = 0;
  ExceptionList = local_c;
  return 0;
}

undefined4 __thiscall FUN_10017dc0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x40) = param_1;
  return 0;
}

undefined4 FUN_10017dd0(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = 0;
  *param_2 = 0;
  return 0;
}

void __fastcall FUN_10017df0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint unaff_EBP;
  uint unaff_EDI;
  int *local_4;
  
  local_4 = param_1;
  if (param_1[0x11] != 0) {
    FUN_10022450(param_1[0x11]);
    iVar2 = (**(code **)(*(int *)param_1[0x11] + 0xe4))(0x21,&local_4);
    piVar1 = local_4;
    iVar3 = (**(code **)(*local_4 + 0xe4))(0x21,&stack0xfffffff4);
    FUN_10027470((void *)param_1[0x11],(int)piVar1);
    FUN_10027530((void *)param_1[0x11],0x21,
                 ~-(uint)(iVar3 != 0) & unaff_EDI | ~-(uint)(iVar2 != 0) & unaff_EBP);
    FUN_10022460(param_1[0x11]);
    return;
  }
  FUN_10021c10();
  return;
}

DTaskBase * __thiscall FUN_10017f40(void *this,byte param_1)

{
  FUN_10017c80((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

undefined4 __fastcall FUN_100180b0(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x4c) != 0) {
                    // WARNING: Could not recover jumptable at 0x100180c3. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar1 = (**(code **)(**(int **)(param_1 + 0x4c) + 0xc))();
    return uVar1;
  }
  FUN_10021c10();
  return 0xffffffff;
}

undefined4 __fastcall FUN_100180e0(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x4c) != 0) {
                    // WARNING: Could not recover jumptable at 0x100180f1. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar1 = (**(code **)(**(int **)(param_1 + 0x4c) + 0x14))();
    return uVar1;
  }
  return 0xffffffff;
}

undefined4 __fastcall FUN_10018100(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x4c) != 0) {
                    // WARNING: Could not recover jumptable at 0x10018111. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar1 = (**(code **)(**(int **)(param_1 + 0x4c) + 0x28))();
    return uVar1;
  }
  return 0xffffffff;
}

undefined4 __fastcall FUN_10018120(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x4c) != 0) {
                    // WARNING: Could not recover jumptable at 0x10018131. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar1 = (**(code **)(**(int **)(param_1 + 0x4c) + 0x2c))();
    return uVar1;
  }
  return 0xffffffff;
}

undefined4 __fastcall FUN_10018140(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x4c) != 0) {
                    // WARNING: Could not recover jumptable at 0x10018151. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar1 = (**(code **)(**(int **)(param_1 + 0x4c) + 0x30))();
    return uVar1;
  }
  return 0xffffffff;
}

undefined4 __fastcall FUN_10018160(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x4c) != 0) {
                    // WARNING: Could not recover jumptable at 0x10018171. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar1 = (**(code **)(**(int **)(param_1 + 0x4c) + 0x34))();
    return uVar1;
  }
  return 0xffffffff;
}

void __fastcall FUN_10018180(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x10018191. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(**(int **)(param_1 + 0x4c) + 0x38))();
  return;
}

undefined4 __thiscall FUN_100181a0(void *this,int param_1)

{
  if (0 < param_1) {
    return 0;
  }
  return *(undefined4 *)((int)this + 0x4c);
}

undefined4 __fastcall FUN_100181c0(int param_1)

{
  FUN_1000c4a0((undefined4 *)(param_1 + 0x40));
  return 0;
}

undefined4 __fastcall FUN_100181d0(int param_1)

{
  FUN_1000c4b0((undefined4 *)(param_1 + 0x40));
  return 2;
}

undefined4 __fastcall FUN_100181e0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x4c) + 8))();
  FUN_10017dc0(*(void **)(param_1 + 0x4c),*(undefined4 *)(param_1 + 4));
  return 0;
}

undefined4 __fastcall FUN_10018200(int param_1)

{
  return *(undefined4 *)(param_1 + 0x200);
}

void FUN_10018210(uint param_1)

{
  FUN_1001b4d0(param_1);
  return;
}

undefined4 __thiscall FUN_100182f0(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  int *this_00;
  
  DTaskBase::LockData((DTaskBase *)this);
  *(int *)((int)this + 0xac) = *(int *)((int)this + 0xac) + 1;
  uVar1 = *(undefined4 *)((int)this + 0xac);
  *(undefined4 *)((int)this + 0xb0) = 10;
  DTaskBase::UnlockData((DTaskBase *)this);
  this_00 = FUN_10027800(&DAT_101997b0,0xffffffff);
  FUN_1002e9a0(this_00,0x31,uVar1);
  FUN_1002e9a0(this_00,0x41,param_1);
  FUN_10018160((int)this);
  (**(code **)(*this_00 + 4))();
  return uVar1;
}

void FUN_10018360(int *param_1)

{
  void *this;
  _MEMORYSTATUS _Stack_20;
  
  if ((param_1 != (int *)0x0) &&
     (this = (void *)(**(code **)(*param_1 + 0xe8))(), this != (void *)0x0)) {
    GlobalMemoryStatus(&_Stack_20);
    FUN_10027640(this,0xdc11,_Stack_20.dwMemoryLoad);
    FUN_10027640(this,0xdc21,_Stack_20.dwTotalPhys >> 10);
    FUN_10027640(this,0xdc31,_Stack_20.dwAvailPhys >> 10);
    FUN_10027640(this,0xdc41,_Stack_20.dwTotalPageFile >> 10);
    FUN_10027640(this,0xdc51,_Stack_20.dwAvailPageFile >> 10);
    FUN_10027640(this,0xdc61,_Stack_20.dwTotalVirtual >> 10);
    FUN_10027640(this,0xdc71,_Stack_20.dwAvailVirtual >> 10);
  }
  return;
}

void __thiscall FUN_10018420(void *this,undefined4 param_1,undefined4 param_2)

{
  *(undefined4 *)((int)this + 0x210) = param_1;
  *(undefined4 *)((int)this + 0x214) = param_2;
  return;
}

void FUN_10018440(int param_1)

{
  FUN_10022a20(param_1);
  return;
}

undefined4 __thiscall FUN_10018450(void *this,undefined4 param_1)

{
  (**(code **)(**(int **)((int)this + 0x4c) + 0x60))(param_1);
  return 0;
}

DTaskBase __fastcall FUN_10018900(DTaskBase *param_1)

{
  DTaskBase DVar1;
  
  DTaskBase::LockData(param_1);
  DVar1 = param_1[0xa0];
  DTaskBase::UnlockData(param_1);
  return DVar1;
}

void __thiscall FUN_10018920(DTaskBase *param_1,DTaskBase param_2)

{
  DTaskBase::LockData(param_1);
  param_1[0xa0] = param_2;
  DTaskBase::UnlockData(param_1);
  return;
}

int * FUN_10018940(int *param_1,int *param_2,int param_3)

{
  int *piVar1;
  
  piVar1 = FUN_100215a0(param_1,param_2,param_3);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x78))(param_1);
    (**(code **)(*piVar1 + 0x78))(param_2);
  }
  return piVar1;
}

undefined4 __fastcall FUN_10018980(int param_1)

{
  FUN_10018120(param_1);
  return 0;
}

undefined4 __fastcall FUN_100189a0(int param_1)

{
  FUN_10018120(param_1);
  return 0;
}

void __cdecl FUN_100189d0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x1d);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x1d);
  }
  return;
}

void __cdecl FUN_100189f0(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  cVar1 = *(char *)((int)piVar2 + 0x1d);
  while (cVar1 == '\0') {
    piVar2 = (int *)*piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x1d);
  }
  return;
}

void __thiscall FUN_10018a10(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x1d) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)((int)this + 0x18) + 4)) {
    *(int *)(*(int *)((int)this + 0x18) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}

int __fastcall FUN_10018ae0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint unaff_EBX;
  uint unaff_ESI;
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    return -1;
  }
  FUN_100181e0(param_1);
  iVar1 = (**(code **)(**(int **)(param_1 + 0x4c) + 0xc))();
  if (iVar1 != 0) {
    return iVar1;
  }
  (**(code **)(**(int **)(param_1 + 0x4c) + 0x1c))(auStack_8,auStack_4);
  uVar2 = (**(code **)(**(int **)(param_1 + 0x4c) + 0x78))();
  *(undefined4 *)(param_1 + 0x48) = uVar2;
  switch(uVar2) {
  case 1:
  case 0xc9:
    iVar1 = 100;
    break;
  case 2:
  case 3:
    iVar1 = 10;
    break;
  default:
    goto LAB_10018b86;
  case 0x5a:
  case 100:
    iVar1 = 1000;
  }
  puVar3 = (undefined4 *)FUN_10017f60(1,iVar1);
  if (puVar3 == (undefined4 *)0x0) {
LAB_10018b86:
    *(undefined4 *)(param_1 + 0x200) = 0;
    *(undefined4 *)(param_1 + 0x204) = 0;
    *(undefined4 *)(param_1 + 0x208) = 0;
    *(undefined4 *)(param_1 + 0x20c) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x200) = *puVar3;
    *(undefined4 *)(param_1 + 0x204) = puVar3[1];
    *(undefined4 *)(param_1 + 0x208) = puVar3[2];
    *(undefined4 *)(param_1 + 0x20c) = puVar3[3];
  }
  *(uint *)(param_1 + 0x98) = unaff_ESI | unaff_EBX;
  uVar4 = FUN_1001b4c0(*(int *)(param_1 + 0x50));
  *(uint *)(param_1 + 0x9c) = uVar4;
  return 0;
}

undefined4 __thiscall FUN_10018ca0(void *this,undefined4 param_1)

{
  if (*(int *)((int)this + 0x4c) != 0) {
    (**(code **)(**(int **)((int)this + 0x4c) + 0x18))(param_1);
  }
  FUN_10018920((DTaskBase *)this,(DTaskBase)0x0);
  return 0;
}

undefined4 __fastcall FUN_10018cd0(void *param_1)

{
  FUN_100182f0(param_1,1);
  return 0;
}

void __thiscall FUN_10019020(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x1d) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)((int)this + 0x18) + 4)) {
    *(int **)(*(int *)((int)this + 0x18) + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}

void FUN_10019070(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x1d);
  while (cVar1 == '\0') {
    FUN_10019070((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_100355b4(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x1d);
  }
  return;
}

void FUN_100190b0(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  return;
}

void FUN_10019120(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)operator_new(0x20);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 7) = 1;
  *(undefined1 *)((int)puVar1 + 0x1d) = 0;
  return;
}

void FUN_10019160(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)operator_new(0x20);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[2] = param_3;
    puVar1[1] = param_2;
    puVar1[3] = *param_4;
    puVar1[4] = param_4[1];
    puVar1[5] = param_4[2];
    puVar1[6] = param_4[3];
    *(undefined1 *)(puVar1 + 7) = param_5;
    *(undefined1 *)((int)puVar1 + 0x1d) = 0;
  }
  return;
}

void __fastcall FUN_10019590(undefined4 *param_1)

{
  FUN_100190d0((int)param_1);
  FUN_100355b4((void *)*param_1);
  return;
}

undefined4 * __fastcall FUN_10019870(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f738;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = (undefined4 *)operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = param_1;
  }
  *param_1 = puVar1;
  local_4 = 0;
  iVar2 = FUN_10019120();
  param_1[6] = iVar2;
  *(undefined1 *)(iVar2 + 0x1d) = 1;
  *(undefined4 *)(param_1[6] + 4) = param_1[6];
  *(undefined4 *)param_1[6] = param_1[6];
  *(undefined4 *)(param_1[6] + 8) = param_1[6];
  param_1[7] = 0;
  ExceptionList = local_c;
  return param_1;
}

void __thiscall FUN_10019bc0(void *this,uint param_1)

{
  int iVar1;
  void *extraout_ECX;
  undefined8 uVar2;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f2b8;
  local_c = ExceptionList;
  iVar1 = *(int *)((int)this + 0x18);
  if (0x3fffffffU - iVar1 < param_1) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &local_c;
    FUN_10001a80(local_50,(undefined4 *)"list<T> too long",0x10);
    local_4 = 0;
    FUN_10001c00(local_34,local_50);
    local_34[0] = std::length_error::vftable;
    uVar2 = __CxxThrowException_8(local_34,&DAT_10062230);
    param_1 = (uint)((ulonglong)uVar2 >> 0x20);
    iVar1 = (int)uVar2;
    this = extraout_ECX;
  }
  *(uint *)((int)this + 0x18) = iVar1 + param_1;
  ExceptionList = local_c;
  return;
}

void __fastcall FUN_10019dd0(undefined4 *param_1)

{
  int local_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_1004f548;
  pvStack_c = ExceptionList;
  local_4 = (void *)0x0;
  ExceptionList = &pvStack_c;
  FUN_100198f0(param_1,local_14,(undefined4 *)*param_1,*(int **)param_1[6],(undefined4 *)*param_1,
               (int *)param_1[6]);
  FUN_100355b4((void *)param_1[6]);
  param_1[6] = 0;
  param_1[7] = 0;
  FUN_100355b4((void *)*param_1);
  ExceptionList = local_4;
  return;
}

void __fastcall FUN_10019e40(undefined4 *param_1)

{
  int aiStack_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  puStack_8 = &LAB_1004f548;
  pvStack_c = ExceptionList;
  pvStack_4 = (void *)0x0;
  ExceptionList = &pvStack_c;
  FUN_100198f0(param_1,aiStack_14,(undefined4 *)*param_1,*(int **)param_1[6],(undefined4 *)*param_1,
               (int *)param_1[6]);
  FUN_100355b4((void *)param_1[6]);
  param_1[6] = 0;
  param_1[7] = 0;
  FUN_100355b4((void *)*param_1);
  ExceptionList = pvStack_4;
  return;
}

int * __fastcall FUN_1001a4d0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *local_4;
  
  local_4 = param_1;
  piVar2 = FUN_10021af0(&DAT_101996c8);
  if (piVar2 != (int *)0x0) {
    iVar1 = param_1[0x24];
    local_4 = piVar2;
    iVar3 = FUN_100015f0(iVar1,*(undefined4 *)(iVar1 + 4),&local_4);
    FUN_10019bc0(param_1 + 0x1f,1);
    *(int *)(iVar1 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
  }
  return piVar2;
}

DTaskBase * __fastcall FUN_1001b310(DTaskBase *param_1)

{
  int *piVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f7d7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  DTaskBase::DTaskBase(param_1,"DataManager",'\0',0);
  local_4 = 0;
  *(undefined ***)param_1 = DataManager::vftable;
  FUN_1000c480((undefined4 *)(param_1 + 0x40));
  local_4._0_1_ = 1;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  FUN_10019870((undefined4 *)(param_1 + 0x5c));
  local_4._0_1_ = 2;
  FUN_100220f0((undefined4 *)(param_1 + 0x7c));
  local_4._0_1_ = 3;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  param_1[0xa0] = (DTaskBase)0x0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  param_1[0xb8] = (DTaskBase)0x0;
  *(undefined4 *)(param_1 + 0xbc) = 7;
  piVar1 = (int *)operator_new(4);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = (int)(param_1 + 0xc0);
  }
  *(int **)(param_1 + 0xc0) = piVar1;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  local_4 = CONCAT31(local_4._1_3_,4);
  param_1[0xe0] = (DTaskBase)0x0;
  param_1[0xe1] = (DTaskBase)0x1;
  FUN_1001d020((undefined4 *)(param_1 + 0xe4));
  *(undefined4 *)(param_1 + 0x1e4) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 500) = 0;
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  *(undefined4 *)(param_1 + 0x200) = 0;
  *(undefined4 *)(param_1 + 0x204) = 0;
  *(undefined4 *)(param_1 + 0x208) = 0;
  *(undefined4 *)(param_1 + 0x20c) = 0;
  *(undefined4 *)(param_1 + 0x210) = 0;
  *(undefined4 *)(param_1 + 0x214) = 0;
  param_1[0x218] = (DTaskBase)0x0;
  *(undefined4 *)(param_1 + 0x1fc) = 1;
  *(undefined4 *)(param_1 + 0x21c) = 4;
  *(undefined4 *)(param_1 + 0x220) = 4;
  ExceptionList = local_c;
  return param_1;
}

DTaskBase * __thiscall FUN_1001b4a0(void *this,byte param_1)

{
  FUN_10019e50((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

uint __fastcall FUN_1001b4c0(int param_1)

{
  return *(uint *)(param_1 + 0x38) | *(uint *)(param_1 + 0x34);
}

void FUN_1001b550(int *param_1)

{
  (**(code **)(*param_1 + 0xc))();
  return;
}

undefined4 __fastcall FUN_1001b5f0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x30);
}

undefined4 __thiscall FUN_1001bca0(void *this,int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10022730((void *)((int)this + 0x14),param_1);
  return *(undefined4 *)*puVar1;
}

void __fastcall FUN_1001bcc0(undefined4 *param_1)

{
  FUN_1001d390((int)param_1);
  FUN_100355b4((void *)*param_1);
  return;
}

void __fastcall FUN_1001c140(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004f80e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = FilterChain::vftable;
  local_4 = 2;
  FUN_1001bce0((int)param_1);
  local_4 = CONCAT31(local_4._1_3_,1);
  DMutex::~DMutex((DMutex *)(param_1 + 0xf));
  FUN_1001d390((int)(param_1 + 5));
  FUN_100355b4((void *)param_1[5]);
  FUN_10021c20(param_1);
  ExceptionList = puStack_8;
  return;
}

undefined4 * __thiscall FUN_1001c1d0(void *this,byte param_1)

{
  FUN_1001c140((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

int __thiscall FUN_1001c1f0(void *this,int param_1)

{
  uint uVar1;
  
  FUN_10015660((void *)((int)this + 0x14),&param_1);
  uVar1 = *(uint *)(param_1 + 0x1c);
  *(uint *)((int)this + 0x34) = *(uint *)((int)this + 0x34) | *(uint *)(param_1 + 0x18);
  *(uint *)((int)this + 0x38) = *(uint *)((int)this + 0x38) | uVar1;
  return *(int *)((int)this + 0x30) + -1;
}

undefined4 * __fastcall FUN_1001c8d0(undefined4 *param_1)

{
  int *piVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f80e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10021be0(param_1);
  local_4 = 0;
  *param_1 = FilterChain::vftable;
  piVar1 = (int *)operator_new(4);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = (int)(param_1 + 5);
  }
  param_1[5] = piVar1;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  local_4._0_1_ = 1;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  DMutex::DMutex((DMutex *)(param_1 + 0xf));
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_1001c220(param_1);
  ExceptionList = local_c;
  return param_1;
}

void __fastcall FUN_1001c9e0(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004f8bb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = FilterTest::vftable;
  local_4 = 0;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1);
  }
  if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[3])(1);
  }
  if ((undefined4 *)param_1[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[4])(1);
  }
  local_4 = 0xffffffff;
  DMutex::~DMutex((DMutex *)(param_1 + 1));
  ExceptionList = pvStack_c;
  return;
}

void __fastcall FUN_1001ca60(int param_1)

{
  undefined4 *puVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f8f1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = (undefined4 *)operator_new(0x108);
  local_4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_1001e4c0(puVar1);
  }
  local_4 = 0xffffffff;
  *(undefined4 **)(param_1 + 8) = puVar1;
  puVar1 = (undefined4 *)operator_new(0x48);
  local_4 = 1;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_10020f20(puVar1);
  }
  local_4 = 0xffffffff;
  *(undefined4 **)(param_1 + 0xc) = puVar1;
  puVar1 = (undefined4 *)operator_new(0x48);
  local_4 = 2;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1 = FUN_10021570(puVar1);
    *(undefined4 **)(param_1 + 0x10) = puVar1;
    ExceptionList = local_c;
    return;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  ExceptionList = local_c;
  return;
}

void FUN_1001cb30(undefined4 *param_1)

{
  param_1[1] = 4;
  param_1[2] = 4;
  *param_1 = 1;
  param_1[3] = 0x200;
  param_1[4] = 0x80;
  param_1[5] = 200;
  param_1[6] = 1;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  param_1[10] = 1;
  return;
}

int * FUN_1001cb70(void)

{
  int *this;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_1001cb30(&local_2c);
  this = FUN_10027800(&DAT_101997b0,0xffffffff);
  if (this != (int *)0x0) {
    FUN_10027530(this,0x101,local_24);
    FUN_10027530(this,0x111,local_20);
    FUN_10027530(this,0x121,local_1c);
    FUN_10027530(this,0x131,local_18);
    FUN_10027530(this,0x1151,local_2c);
    FUN_10027530(this,0x1041,local_28);
    FUN_10027530(this,0x3101,local_14);
    FUN_10027530(this,0x3111,local_10);
    FUN_10027530(this,0x3121,local_c);
    FUN_10027530(this,0x3131,local_8);
    FUN_10027530(this,0x3141,local_4);
  }
  return this;
}

undefined4 * __fastcall FUN_1001cfa0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f8bb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = FilterTest::vftable;
  DMutex::DMutex((DMutex *)(param_1 + 1));
  local_4 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  FUN_1001ca60((int)param_1);
  ExceptionList = local_c;
  return param_1;
}

undefined4 * __thiscall FUN_1001d000(void *this,byte param_1)

{
  FUN_1001c9e0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

undefined4 * __fastcall FUN_1001d020(undefined4 *param_1)

{
  FUN_1002e5d0(param_1,10000);
  *param_1 = SystemVals::vftable;
  return param_1;
}

void __fastcall FUN_1001d040(undefined4 *param_1)

{
  *param_1 = SystemVals::vftable;
  FUN_1002e680(param_1);
  return;
}

undefined4 FUN_1001d050(void)

{
  return 0x2000;
}

undefined * FUN_1001d060(void)

{
  return PTR_s_SystemVals_100db078;
}

undefined * FUN_1001d070(void)

{
  return PTR_s_SysVals_100db07c;
}

undefined4 * __thiscall FUN_1001d080(void *this,byte param_1)

{
  FUN_1001d040((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

DTaskBase * __thiscall FUN_1001d0a0(void *this,char *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f908;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  DTaskBase::DTaskBase((DTaskBase *)this,param_1,'\0',0);
  local_4 = 0;
  *(undefined ***)this = Filter::vftable;
  *(undefined4 *)((int)this + 0x40) = 0xffffffff;
  DTaskBase::StartTask((DTaskBase *)this,8);
  ExceptionList = local_c;
  return (DTaskBase *)this;
}

void __fastcall FUN_1001d100(DTaskBase *param_1)

{
  *(undefined ***)param_1 = Filter::vftable;
  DTaskBase::~DTaskBase(param_1);
  return;
}

void __fastcall FUN_1001d110(int param_1)

{
  *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
  return;
}

undefined4 __thiscall
FUN_1001d120(void *this,void *param_1,ushort param_2,undefined4 param_3,undefined4 param_4)

{
  *(uint *)((int)param_1 + 4) = (uint)param_2;
  *(undefined4 *)((int)param_1 + 8) = param_3;
  *(undefined4 *)((int)param_1 + 0x10) = *(undefined4 *)((int)param_1 + 0xc);
  *(undefined4 *)((int)param_1 + 0xc) = *(undefined4 *)((int)this + 4);
  *(void **)((int)param_1 + 0x28) = this;
  *(undefined4 *)((int)param_1 + 0x24) = param_4;
  DQueue::Post(*(DQueue **)((int)param_1 + 0x10),param_1);
  return 0;
}

undefined4 FUN_1001d160(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(1);
  }
  return 0;
}

DTaskBase * __thiscall FUN_1001d1d0(void *this,byte param_1)

{
  FUN_1001d100((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

undefined4 __thiscall
FUN_1001d1f0(void *this,ushort param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  DMsg *pDVar1;
  
  pDVar1 = (DMsg *)operator_new(0x38);
  if (pDVar1 != (DMsg *)0x0) {
    *(undefined4 *)(pDVar1 + 0x28) = 0;
    *(undefined4 *)(pDVar1 + 0x2c) = 0;
    *(undefined ***)pDVar1 = DFilterMsg::vftable;
    *(uint *)(pDVar1 + 4) = (uint)param_1;
    *(undefined4 *)(pDVar1 + 0xc) = param_3;
    *(undefined4 *)(pDVar1 + 0x18) = param_6;
    *(undefined4 *)(pDVar1 + 0x1c) = param_4;
    *(undefined4 *)(pDVar1 + 0x24) = 0;
    *(undefined4 *)(pDVar1 + 0x20) = param_5;
    *(undefined4 *)(pDVar1 + 0x30) = param_7;
    *(undefined4 *)(pDVar1 + 0x34) = param_8;
    DTaskBase::PostMsg((DTaskBase *)this,pDVar1);
  }
  return 0;
}

void __fastcall FUN_1001d260(int param_1)

{
  FUN_1001d110(param_1);
  *(undefined1 *)(param_1 + 0x68) = 1;
  return;
}

undefined4 __thiscall
FUN_1001d330(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)operator_new(0x38);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    *puVar1 = DFilterMsg::vftable;
    puVar1[7] = 0;
    puVar1[3] = *(undefined4 *)((int)this + 0x60);
    puVar1[6] = param_3;
    FUN_1001d120(this,puVar1,0x6080,param_1,param_2);
  }
  return 0;
}

void __fastcall FUN_1001d400(int param_1)

{
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  FUN_1001d390(param_1 + 0x80);
  return;
}

void __fastcall FUN_1001d420(DTaskBase *param_1)

{
  *(undefined ***)param_1 = IgramCoadder::vftable;
  FUN_1001d390((int)(param_1 + 0x80));
  FUN_100355b4(*(void **)(param_1 + 0x80));
  FUN_1001d100(param_1);
  return;
}

undefined4 * __fastcall FUN_1001d450(undefined4 *param_1)

{
  int *piVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f928;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_1001d0a0(param_1,"IgramCoadder");
  local_4 = 0;
  *param_1 = IgramCoadder::vftable;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x16] = 8;
  param_1[0x17] = 0x10;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  *(undefined1 *)(param_1 + 0x1a) = 1;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  piVar1 = (int *)operator_new(4);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = (int)(param_1 + 0x20);
  }
  param_1[0x20] = piVar1;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x2b] = 0xffffffff;
  FUN_1001d400((int)param_1);
  ExceptionList = local_c;
  return param_1;
}

DTaskBase * __thiscall FUN_1001d510(void *this,byte param_1)

{
  FUN_1001d420((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

undefined4 __thiscall FUN_1001d5e0(void *this,int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 - *(int *)((int)this + 0xa8);
  uVar2 = (int)uVar1 >> 0x1f;
  if ((0 < *(int *)((int)this + 0xa4)) &&
     (*(int *)((int)this + 0x5c) < (int)((uVar1 ^ uVar2) - uVar2))) {
    FUN_10021c10();
    return 0xffffffff;
  }
  FUN_1001d530(this,param_1);
  return 0;
}

undefined4 __thiscall FUN_1001d630(void *this,undefined4 *param_1)

{
  undefined4 *unaff_retaddr;
  undefined1 local_40 [16];
  int iStack_30;
  
  (**(code **)(*(int *)param_1[2] + 0xb8))(local_40,0);
  if (iStack_30 < (int)param_1[6]) {
    *param_1 = 0x10001;
    FUN_10021c10();
    *unaff_retaddr = 0;
    return 0xffffffff;
  }
  FUN_1001d5e0(this,iStack_30);
  *unaff_retaddr = 0;
  return 0;
}

int __thiscall FUN_1001d840(void *this,undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_EDI;
  undefined1 local_40 [8];
  int iStack_38;
  int iStack_30;
  undefined4 *puStack_8;
  undefined4 *puStack_4;
  
  (**(code **)(*(int *)param_1[2] + 0xb8))(local_40,0);
  (**(code **)(*(int *)param_1[2] + 0x2c))();
  (**(code **)(*(int *)*param_1 + 0xb8))(&stack0xffffffb8,1);
  uVar2 = iStack_30 - iStack_38 >> 0x1f;
  if (0x10 < (int)((iStack_30 - iStack_38 ^ uVar2) - uVar2)) {
    FUN_10021c10();
    *puStack_4 = 0x10007;
                    // WARNING: Load size is inaccurate
    (**(code **)(*this + 8))();
    *puStack_8 = 0;
    return -1;
  }
  iVar1 = FUN_1001d6b0(this,param_1);
  if (iVar1 == 0) {
    *puStack_4 = 0x10;
    *puStack_8 = unaff_EDI;
    return 0;
  }
  *puStack_8 = unaff_EDI;
  return iVar1;
}

undefined4 * __fastcall FUN_1001e4c0(undefined4 *param_1)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f928;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_1001d0a0(param_1,"IgramCreator");
  local_4 = 0;
  *param_1 = IgramCreator::vftable;
  param_1[0x11] = 1;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0x80000000;
  param_1[0x1d] = 0x7fffffff;
  param_1[0x1e] = 0xffffffff;
  param_1[0x1f] = 0xffffffff;
  param_1[0x20] = 0;
  param_1[0x21] = 0x1e0;
  param_1[0x22] = 0xb93;
  param_1[0x23] = 0x80000000;
  param_1[0x24] = 0x7fffffff;
  param_1[0x25] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x26) = 1;
  *(undefined1 *)((int)param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x9a) = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  *(undefined1 *)(param_1 + 0x3a) = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 2;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  pvVar1 = operator_new(0x24);
  param_1[0x27] = pvVar1;
  pvVar1 = operator_new(0x28);
  param_1[0x28] = pvVar1;
  ExceptionList = local_c;
  return param_1;
}

void __fastcall FUN_1001e5f0(DTaskBase *param_1)

{
  *(undefined ***)param_1 = IgramCreator::vftable;
  FUN_100355e9(*(void **)(param_1 + 0x48));
  FUN_100355e9(*(void **)(param_1 + 0x54));
  FUN_100355e9(*(void **)(param_1 + 0x58));
  FUN_100355e9(*(void **)(param_1 + 100));
  FUN_1001d100(param_1);
  return;
}

ulonglong FUN_1001e630(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  float10 fVar6;
  ulonglong uVar7;
  
  iVar3 = *(int *)(param_1 + param_2 * 4);
  uVar1 = iVar3 - *(int *)(param_1 + -4 + param_2 * 4);
  uVar5 = (int)uVar1 >> 0x1f;
  uVar2 = iVar3 - *(int *)(param_1 + 4 + param_2 * 4);
  iVar4 = (uVar1 ^ uVar5) - uVar5;
  uVar1 = (int)uVar2 >> 0x1f;
  iVar3 = (uVar2 ^ uVar1) - uVar1;
  fVar6 = (float10)(iVar3 + iVar4);
  if ((float10)0 < (float10)iVar4 / fVar6 - (float10)iVar3 / fVar6) {
    uVar7 = FUN_100362d0(iVar4,uVar1);
    return uVar7;
  }
  uVar7 = FUN_100362d0(iVar4,uVar1);
  return uVar7;
}

ulonglong FUN_1001e6c0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  iVar1 = *(int *)(param_1 + param_2 * 4);
  uVar2 = iVar1 - *(int *)(param_1 + -4 + param_2 * 4);
  uVar4 = (int)uVar2 >> 0x1f;
  uVar3 = iVar1 - *(int *)(param_1 + 4 + param_2 * 4);
  uVar5 = (int)uVar3 >> 0x1f;
  if ((float10)0 < (float10)(int)((uVar2 ^ uVar4) - uVar4) - (float10)(int)((uVar3 ^ uVar5) - uVar5)
     ) {
    uVar6 = FUN_100362d0(param_1,uVar5);
    return uVar6;
  }
  uVar6 = FUN_100362d0(param_1,uVar5);
  return uVar6;
}

void __thiscall FUN_1001f100(void *this,void *param_1)

{
  if (param_1 != (void *)0x0) {
    FUN_10027640(param_1,0x6811,**(undefined4 **)((int)this + 0x9c));
    FUN_10027640(param_1,0x6821,*(undefined4 *)(*(int *)((int)this + 0x9c) + 8));
    FUN_10027640(param_1,0x6831,*(undefined4 *)(*(int *)((int)this + 0x9c) + 4));
    FUN_10027640(param_1,0x6841,*(undefined4 *)(*(int *)((int)this + 0x9c) + 0xc));
    FUN_10027640(param_1,0x6851,*(undefined4 *)(*(int *)((int)this + 0x9c) + 0x10));
    FUN_10027640(param_1,0x6861,*(undefined4 *)(*(int *)((int)this + 0x9c) + 0x18));
    FUN_10027640(param_1,0x6871,*(undefined4 *)(*(int *)((int)this + 0x9c) + 0x14));
    FUN_10027640(param_1,0x6881,*(undefined4 *)(*(int *)((int)this + 0x9c) + 0x1c));
    FUN_10027640(param_1,0x5811,**(undefined4 **)((int)this + 0xa0));
    FUN_10027640(param_1,0x5821,*(undefined4 *)(*(int *)((int)this + 0xa0) + 4));
    FUN_10027640(param_1,0x5831,*(undefined4 *)(*(int *)((int)this + 0xa0) + 8));
    FUN_10027640(param_1,0x5841,*(undefined4 *)(*(int *)((int)this + 0xa0) + 0x10));
    FUN_10027640(param_1,0x5851,*(undefined4 *)(*(int *)((int)this + 0xa0) + 0xc));
    FUN_10027640(param_1,0x5861,*(undefined4 *)(*(int *)((int)this + 0xa0) + 0x14));
    FUN_100276b0((int)param_1,0x5885,*(undefined8 *)(*(int *)((int)this + 0xa0) + 0x20));
    FUN_100276b0((int)param_1,0x2815,*(undefined8 *)((int)this + 0xa8));
    FUN_10027640(param_1,0x2821,*(undefined4 *)((int)this + 0xb0));
    FUN_100276b0((int)param_1,0x2835,*(undefined8 *)((int)this + 0xb8));
    FUN_10027640(param_1,0x2841,*(undefined4 *)((int)this + 0xc0));
    FUN_100276b0((int)param_1,0x2855,*(undefined8 *)((int)this + 200));
    FUN_10027640(param_1,0x2861,*(undefined4 *)((int)this + 0xd0));
    FUN_100276b0((int)param_1,0x2875,*(undefined8 *)((int)this + 0xd8));
    FUN_10027640(param_1,0x2881,*(undefined4 *)((int)this + 0xe0));
  }
  return;
}

DTaskBase * __thiscall FUN_1001fc70(void *this,byte param_1)

{
  FUN_1001e5f0((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

undefined4 * __fastcall FUN_1001fc90(undefined4 *param_1)

{
  FUN_10020f90(param_1,"MiniSBeamCreator");
  *param_1 = MiniSBeamCreator::vftable;
  return param_1;
}

void __fastcall FUN_1001fcb0(DTaskBase *param_1)

{
  *(undefined ***)param_1 = MiniSBeamCreator::vftable;
  FUN_100208c0(param_1);
  return;
}

void FUN_1001fe70(uint param_1)

{
  FUN_10027a60(&DAT_10199818,param_1);
  return;
}

DTaskBase * __thiscall FUN_1001fe80(void *this,byte param_1)

{
  FUN_1001fcb0((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

undefined4 * __fastcall FUN_1001fea0(undefined4 *param_1)

{
  FUN_1001d0a0(param_1,"RawEncoderCreator");
  *param_1 = RawEncoderCreator::vftable;
  return param_1;
}

void __fastcall FUN_1001fec0(DTaskBase *param_1)

{
  *(undefined ***)param_1 = RawEncoderCreator::vftable;
  FUN_1001d100(param_1);
  return;
}

undefined4 FUN_1001fed0(int *param_1,uint *param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar6 = (uint *)*param_1;
  puVar5 = param_3;
  do {
    if (param_3 <= puVar6) break;
    bVar1 = *(byte *)*param_1;
    puVar5 = (uint *)(uint)bVar1;
    puVar6 = (uint *)((byte *)*param_1 + 4);
    *param_1 = (int)puVar6;
  } while ((bVar1 & 8) == 0);
  puVar6 = (uint *)*param_1;
  if (puVar6 + 4 <= param_3) {
    uVar2 = *puVar6;
    *param_1 = (int)(puVar6 + 1);
    uVar3 = puVar6[1];
    *param_1 = (int)(puVar6 + 2);
    uVar4 = puVar6[2];
    *param_1 = (int)(puVar6 + 3);
    *param_2 = (uint)(byte)((byte)uVar4 >> 4) |
               ((uint)puVar5 & 0xf0) << 8 | (uVar2 & 0xf0) << 4 | uVar3 & 0xf0;
    return 0;
  }
  return 0xffffffff;
}

DTaskBase * __thiscall FUN_10020210(void *this,byte param_1)

{
  FUN_1001fec0((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

undefined4 * __fastcall FUN_10020230(undefined4 *param_1)

{
  FUN_1001d0a0(param_1,"RawIgramCreator");
  *param_1 = RawIgramCreator::vftable;
  return param_1;
}

void __fastcall FUN_10020250(DTaskBase *param_1)

{
  *(undefined ***)param_1 = RawIgramCreator::vftable;
  FUN_1001d100(param_1);
  return;
}

undefined4 FUN_10020260(void)

{
  return 3;
}

DTaskBase * __thiscall FUN_10020410(void *this,byte param_1)

{
  FUN_10020250((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

undefined4 * __fastcall FUN_10020430(undefined4 *param_1)

{
  FUN_1001d0a0(param_1,"RawLaserCreator");
  *param_1 = RawLaserCreator::vftable;
  return param_1;
}

void __fastcall FUN_10020450(DTaskBase *param_1)

{
  *(undefined ***)param_1 = RawLaserCreator::vftable;
  FUN_1001d100(param_1);
  return;
}

undefined4 FUN_10020460(int *param_1,int *param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_4;
  if (param_3 / 2 < *param_4) {
    iVar2 = param_3 / 2;
  }
  iVar1 = iVar2;
  if (iVar2 < 1) {
    *param_4 = 0;
    return 0;
  }
  do {
    *param_2 = *param_1 >> 8;
    param_1 = param_1 + 2;
    param_2 = param_2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *param_4 = iVar2;
  return 0;
}

DTaskBase * __thiscall FUN_100205f0(void *this,byte param_1)

{
  FUN_10020450((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

float10 FUN_10020610(int param_1,uint param_2)

{
  double *pdVar1;
  uint uVar2;
  double *pdVar3;
  int iVar4;
  float10 fVar5;
  
  fVar5 = (float10)0;
  uVar2 = param_2 & 0x800001ff;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffe00) + 1;
  }
  iVar4 = 8;
  pdVar1 = (double *)(param_1 + -0xf8 + ((int)(param_2 + ((int)param_2 >> 0x1f & 0x1ffU)) >> 9) * 8)
  ;
  pdVar3 = (double *)(&DAT_100db200 + uVar2 * 0x200);
  do {
    iVar4 = iVar4 + -1;
    fVar5 = (float10)pdVar1[7] * (float10)pdVar3[6] +
            (float10)pdVar1[6] * (float10)pdVar3[5] +
            (float10)pdVar1[5] * (float10)pdVar3[4] +
            (float10)pdVar1[4] * (float10)pdVar3[3] +
            (float10)pdVar1[3] * (float10)pdVar3[2] +
            (float10)pdVar1[2] * (float10)pdVar3[1] +
            (float10)pdVar1[1] * (float10)*pdVar3 + (float10)pdVar3[-1] * (float10)*pdVar1 + fVar5;
    pdVar1 = pdVar1 + 8;
    pdVar3 = pdVar3 + 8;
  } while (iVar4 != 0);
  return fVar5;
}

float10 FUN_100206a0(int param_1,int param_2)

{
  double *pdVar1;
  int iVar2;
  double *pdVar3;
  float10 fVar4;
  
  fVar4 = (float10)0;
  iVar2 = 0x2b;
  pdVar1 = (double *)(param_1 + -0x150 + (param_2 / 0x1e0) * 8);
  pdVar3 = (double *)(&DAT_1016b950 + ((param_2 / 0x1e0) * 0x1e0 - param_2) * 0x2b0);
  do {
    iVar2 = iVar2 + -1;
    fVar4 = (float10)pdVar1[1] * (float10)*pdVar3 + (float10)pdVar3[-1] * (float10)*pdVar1 + fVar4;
    pdVar1 = pdVar1 + 2;
    pdVar3 = pdVar3 + 2;
  } while (iVar2 != 0);
  return fVar4;
}

ulonglong __thiscall FUN_10020710(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar1;
  ulonglong uVar2;
  
                    // WARNING: Load size is inaccurate
  fVar1 = (float10)(**(code **)(*this + 4))(param_1,param_2);
  if (fVar1 < (float10)0) {
    uVar2 = FUN_100362d0(extraout_ECX,extraout_EDX);
    return uVar2;
  }
  uVar2 = FUN_100362d0(extraout_ECX,extraout_EDX);
  return uVar2;
}

float10 FUN_10020750(int param_1,int param_2)

{
  double *pdVar1;
  double *pdVar2;
  int iVar3;
  float10 fVar4;
  
  fVar4 = (float10)0;
  iVar3 = 0xb;
  pdVar1 = (double *)(param_1 + -0xa8 + (param_2 / 0x1e0) * 8);
  pdVar2 = (double *)(&DAT_10194ea0 + ((param_2 / 0x1e0) * 0x1e0 - param_2) * 0x160);
  do {
    iVar3 = iVar3 + -1;
    fVar4 = (float10)pdVar1[3] * (float10)pdVar2[2] +
            (float10)pdVar1[2] * (float10)pdVar2[1] +
            (float10)pdVar1[1] * (float10)*pdVar2 + (float10)pdVar2[-1] * (float10)*pdVar1 + fVar4;
    pdVar1 = pdVar1 + 4;
    pdVar2 = pdVar2 + 4;
  } while (iVar3 != 0);
  return fVar4;
}

undefined4 * __thiscall FUN_100207d0(void *this,byte param_1)

{
  *(undefined ***)this = ResamplingFilterIf::vftable;
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

overlap smaller symbols at the same address

undefined * __cdecl FUN_100207f0(int param_1,int param_2)

{
  undefined *puVar1;
  
  if ((_DAT_101996a8 & 1) == 0) {
    _DAT_101996a8 = _DAT_101996a8 | 1;
    _DAT_10199698 = ResamplingFilter_Classic64::vftable;
    _atexit((_func_4879 *)&LAB_100504d0);
  }
  if ((_DAT_101996a8 & 2) == 0) {
    _DAT_101996a8 = _DAT_101996a8 | 2;
    _DAT_10199688 = ResamplingFilter_DTGS86::vftable;
    _atexit((_func_4879 *)&LAB_100504c0);
  }
  if ((_DAT_101996a8 & 4) == 0) {
    _DAT_101996a8 = _DAT_101996a8 | 4;
    _DAT_10199678 = ResamplingFilter_MCT44::vftable;
    _atexit((_func_4879 *)&LAB_100504b0);
  }
  if (param_1 == 0x200) {
    return &DAT_10199698;
  }
  puVar1 = &DAT_10199688;
  if (param_2 != 1) {
    puVar1 = &DAT_10199678;
  }
  return puVar1;
}

void FUN_10020890(void)

{
  if (DAT_101996b0 == 0) {
    FUN_10017200(2,0x400,2);
    FUN_10021c10();
  }
  DAT_101996b0 = DAT_101996b0 + 1;
  return;
}

void __fastcall FUN_100208c0(DTaskBase *param_1)

{
  *(undefined ***)param_1 = SBeamCreator::vftable;
  DAT_101996b0 = DAT_101996b0 + -1;
  if (DAT_101996b0 == 0) {
    FUN_10017430();
  }
  FUN_1001d100(param_1);
  return;
}

undefined4 FUN_100208e0(void)

{
  return 0x100;
}

void FUN_10020a80(uint param_1)

{
  FUN_1002c900(&DAT_10199a38,param_1);
  return;
}

undefined4 FUN_10020a90(double param_1,int param_2,int param_3,undefined8 *param_4,double *param_5)

{
  double dVar1;
  
  if (param_3 < 1) {
    return 0xffffffff;
  }
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  dVar1 = (1.0 / (double)param_3) * param_1;
  if (0 < param_2) {
    dVar1 = (double)(param_2 + -1) * (dVar1 / (double)param_2);
  }
  if (param_5 != (double *)0x0) {
    *param_5 = dVar1;
    return 0;
  }
  return 0;
}

undefined1 FUN_10020af0(float param_1,float param_2)

{
  undefined1 uVar1;
  
  uVar1 = 1;
  if ((param_1 == -2.0) || (param_2 == -2.0)) {
    uVar1 = 0;
  }
  if ((param_1 == -NAN) || (param_1 == NAN)) {
    uVar1 = 0;
  }
  if ((param_2 != -NAN) && (param_2 != NAN)) {
    return uVar1;
  }
  return 0;
}

undefined4 * __fastcall FUN_10020f20(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f928;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_1001d0a0(param_1,"SBeamCreator");
  local_4 = 0;
  *param_1 = SBeamCreator::vftable;
  param_1[0x11] = 0;
  FUN_10020890();
  ExceptionList = local_c;
  return param_1;
}

DTaskBase * __thiscall FUN_10020f70(void *this,byte param_1)

{
  FUN_100208c0((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

undefined4 * __thiscall FUN_10020f90(void *this,char *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f928;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_1001d0a0(this,param_1);
  local_4 = 0;
  *(undefined ***)this = SBeamCreator::vftable;
  *(undefined4 *)((int)this + 0x44) = 0;
  FUN_10020890();
  ExceptionList = local_c;
  return (undefined4 *)this;
}

undefined4 * __fastcall FUN_10021480(undefined4 *param_1)

{
  FUN_1001d0a0(param_1,"SpectralRejector");
  *param_1 = SpectralRejector::vftable;
  return param_1;
}

void __fastcall FUN_100214a0(DTaskBase *param_1)

{
  *(undefined ***)param_1 = SpectralRejector::vftable;
  FUN_1001d100(param_1);
  return;
}

undefined4 FUN_100214b0(void)

{
  return 0x21;
}

undefined4 FUN_100214c0(int *param_1,undefined4 *param_2)

{
  (**(code **)(*param_1 + 0x2c))();
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  return 0;
}

undefined4 __thiscall FUN_100214e0(void *this,void *param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  
  pvVar2 = param_1;
  uVar4 = 0x80000001;
  if (((param_1 == (void *)0x0) || (piVar1 = *(int **)((int)param_1 + 0x1c), piVar1 == (int *)0x0))
     || (iVar3 = (**(code **)(*piVar1 + 0x14))(), iVar3 != 0x400)) {
    FUN_10021c10();
  }
  else {
    FUN_100214c0(piVar1,&param_1);
    uVar4 = 0;
  }
  FUN_1001d120(this,pvVar2,0x6080,uVar4,*(undefined4 *)((int)pvVar2 + 0x24));
  return 0;
}

DTaskBase * __thiscall FUN_10021550(void *this,byte param_1)

{
  FUN_100214a0((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

undefined4 * __fastcall FUN_10021570(undefined4 *param_1)

{
  FUN_1001d0a0(param_1,"SpectrumCreator");
  *param_1 = SpectrumCreator::vftable;
  param_1[0x11] = 1;
  return param_1;
}

void __fastcall FUN_10021590(DTaskBase *param_1)

{
  *(undefined ***)param_1 = SpectrumCreator::vftable;
  FUN_1001d100(param_1);
  return;
}

DTaskBase * __thiscall FUN_100219c0(void *this,byte param_1)

{
  FUN_10021590((DTaskBase *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (DTaskBase *)this;
}

undefined4 * __fastcall FUN_100219e0(undefined4 *param_1)

{
  FUN_10021be0(param_1);
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  *param_1 = DataBlock::vftable;
  return param_1;
}

void __fastcall FUN_10021a10(int param_1)

{
  if (*(int **)(param_1 + 0x2c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x2c) + 4))();
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}

void __thiscall FUN_10021a40(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x14) = param_1;
  return;
}

void __thiscall FUN_10021a50(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x28) = param_1;
  return;
}

undefined4 __fastcall FUN_10021a60(int param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}

void __thiscall FUN_10021a70(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x20) = param_1;
  return;
}

undefined4 __fastcall FUN_10021a80(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}

void __thiscall FUN_10021a90(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x24) = param_1;
  return;
}

void __thiscall FUN_10021aa0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x2c) = param_1;
  return;
}

undefined4 __fastcall FUN_10021ab0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2c);
}

void __thiscall FUN_10021ac0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x30) = param_1;
  return;
}

undefined4 * __fastcall FUN_10021ad0(undefined4 *param_1)

{
  FUN_10022170(param_1,"DataBlockAllocator");
  *param_1 = DataBlockAllocator::vftable;
  param_1[0x1a] = 0;
  return param_1;
}

void __fastcall FUN_10021b70(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004f988;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = DataBlock::vftable;
  local_4 = 0;
  FUN_10021a10((int)param_1);
  local_4 = 0xffffffff;
  FUN_10021c20(param_1);
  ExceptionList = local_c;
  return;
}

undefined4 * __thiscall FUN_10021bc0(void *this,byte param_1)

{
  FUN_10021b70((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

undefined4 * __fastcall FUN_10021be0(undefined4 *param_1)

{
  *param_1 = ManagedData::vftable;
  param_1[1] = 1;
  param_1[2] = 0;
  param_1[3] = 0;
  DMutex::DMutex((DMutex *)(param_1 + 4));
  return param_1;
}

void FUN_10021c10(void)

{
  return;
}

void __fastcall FUN_10021c20(undefined4 *param_1)

{
  *param_1 = ManagedData::vftable;
  DMutex::~DMutex((DMutex *)(param_1 + 4));
  return;
}

void __fastcall FUN_10021c30(int param_1)

{
  DMutex::Lock((DMutex *)(param_1 + 0x10));
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  DMutex::Unlock((DMutex *)(param_1 + 0x10));
  return;
}

undefined4 __thiscall FUN_10021cd0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  DMutex::Lock((DMutex *)((int)this + 0x10));
  uVar1 = *(undefined4 *)((int)this + 8);
  *(undefined4 *)((int)this + 0xc) = param_2;
  *(undefined4 *)((int)this + 8) = param_1;
  DMutex::Unlock((DMutex *)((int)this + 0x10));
  return uVar1;
}

void __fastcall FUN_10021d00(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x10))(1);
  }
  return;
}

void FUN_10021d10(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0xc))();
  }
  return;
}

undefined4 * __thiscall FUN_10021d30(void *this,byte param_1)

{
  FUN_10021c20((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

undefined4 __fastcall FUN_10021d50(int param_1)

{
  undefined4 uVar1;
  
  DMutex::Lock((DMutex *)(param_1 + 100));
  uVar1 = *(undefined4 *)(param_1 + 0x40);
  DMutex::Unlock((DMutex *)(param_1 + 100));
  return uVar1;
}

void __thiscall FUN_10021d70(void *this,undefined4 param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    FUN_10035812();
    iVar1 = 0;
  }
  else {
    iVar1 = *param_2;
  }
  if (param_3 == *(int **)(iVar1 + 0x14)) {
    FUN_10035812();
  }
  if (param_3 != *(int **)((int)this + 0x14)) {
    *(int *)param_3[1] = *param_3;
    *(int *)(*param_3 + 4) = param_3[1];
    FUN_100355b4(param_3);
    *(int *)((int)this + 0x18) = *(int *)((int)this + 0x18) + -1;
  }
                    // WARNING: Load size is inaccurate
  iVar1 = *this;
  param_2[1] = param_4;
  *param_2 = iVar1;
  return;
}

void __fastcall FUN_10022040(int param_1)

{
  DMutex::Lock((DMutex *)(param_1 + 100));
  FUN_10021f00((void *)(param_1 + 0x28),(int *)&stack0x00000004);
  DMutex::Unlock((DMutex *)(param_1 + 100));
  return;
}

void __fastcall FUN_10022070(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_1004f976;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = Allocator::vftable;
  local_4 = (void *)0x1;
  *(undefined1 *)(param_1 + 1) = 0;
  DMutex::~DMutex((DMutex *)(param_1 + 0x19));
  FUN_100190d0((int)(param_1 + 10));
  FUN_100355b4((void *)param_1[10]);
  FUN_100190d0((int)(param_1 + 3));
  FUN_100355b4((void *)param_1[3]);
  ExceptionList = local_4;
  return;
}

undefined4 * __fastcall FUN_100220f0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f738;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = (undefined4 *)operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = param_1;
  }
  *param_1 = puVar1;
  local_4 = 0;
  uVar2 = FUN_100190b0();
  param_1[5] = uVar2;
  param_1[6] = 0;
  ExceptionList = local_c;
  return param_1;
}

undefined4 * __thiscall FUN_10022150(void *this,byte param_1)

{
  FUN_10022070((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

undefined4 * __thiscall FUN_10022170(void *this,char *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f976;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = Allocator::vftable;
  *(undefined1 *)((int)this + 4) = 1;
  *(undefined4 *)((int)this + 8) = 0x7fffffff;
  FUN_100220f0((undefined4 *)((int)this + 0xc));
  local_4 = 0;
  FUN_100220f0((undefined4 *)((int)this + 0x28));
  local_4 = CONCAT31(local_4._1_3_,1);
  DMutex::DMutex((DMutex *)((int)this + 100));
  if (param_1 != (char *)0x0) {
    _strncpy_s((char *)((int)this + 0x44),0x20,param_1,0x1f);
    *(undefined1 *)((int)this + 99) = 0;
  }
  ExceptionList = local_c;
  return (undefined4 *)this;
}

void __thiscall FUN_10022280(void *this,void *param_1)

{
  int iVar1;
  void *this_00;
  int iVar2;
  
  this_00 = param_1;
  if (param_1 != (void *)0x0) {
    DMutex::Lock((DMutex *)((int)this + 100));
    FUN_10021cd0(this_00,&LAB_10022260,this);
    iVar1 = *(int *)((int)this + 0x3c);
    iVar2 = FUN_100015f0(iVar1,*(undefined4 *)(iVar1 + 4),&param_1);
    FUN_10019bc0((void *)((int)this + 0x28),1);
    *(int *)(iVar1 + 4) = iVar2;
    **(int **)(iVar2 + 4) = iVar2;
    DMutex::Unlock((DMutex *)((int)this + 100));
  }
  return;
}

void __fastcall FUN_10022450(int param_1)

{
  DMutex::Lock((DMutex *)(param_1 + 0x34));
  return;
}

void __fastcall FUN_10022460(int param_1)

{
  DMutex::Unlock((DMutex *)(param_1 + 0x34));
  return;
}

undefined4 __fastcall FUN_10022470(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1c);
}

void __thiscall FUN_10022480(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x1c) = param_1;
  return;
}

undefined4 __fastcall FUN_10022490(int param_1)

{
  FUN_10022450(param_1);
  *(int *)(param_1 + 0x30) = DAT_10199734;
  DAT_10199734 = DAT_10199734 + 1;
  FUN_10022460(param_1);
  return *(undefined4 *)(param_1 + 0x30);
}

undefined4 __fastcall FUN_100224c0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_10022450(param_1);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x28) = 0xf0000001;
  return 0;
}

undefined4 __fastcall FUN_100224e0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_10022450(param_1);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x28) = 0xf0000002;
  return 0;
}

undefined4 __thiscall FUN_10022560(void *this,int param_1)

{
  *(undefined4 *)((int)this + 0x28) = 1;
  if (param_1 != -1) {
    *(int *)((int)this + 0x1c) = param_1;
  }
  FUN_10022460((int)this);
  return 0;
}

undefined4 __thiscall FUN_10022580(void *this,int param_1,undefined4 param_2)

{
  *(undefined4 *)((int)this + 0x28) = 1;
  if (param_1 != -1) {
    *(int *)((int)this + 0x1c) = param_1;
  }
  *(undefined4 *)((int)this + 0x18) = param_2;
  FUN_10022460((int)this);
  return 0;
}

undefined4 __thiscall FUN_100225b0(void *this,undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_2 == 1) {
                    // WARNING: Load size is inaccurate
    uVar1 = (**(code **)(*this + 0xa4))(param_1);
    return uVar1;
  }
  if (param_2 == 2) {
                    // WARNING: Load size is inaccurate
    uVar1 = (**(code **)(*this + 0x9c))(param_1);
    return uVar1;
  }
  if (param_2 == 3) {
                    // WARNING: Load size is inaccurate
    uVar1 = (**(code **)(*this + 0xac))(param_1);
  }
  return uVar1;
}

undefined4 __thiscall FUN_10022600(void *this,undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_2 == 1) {
                    // WARNING: Load size is inaccurate
    uVar1 = (**(code **)(*this + 0xa0))(param_1);
    return uVar1;
  }
  if (param_2 == 2) {
                    // WARNING: Load size is inaccurate
    uVar1 = (**(code **)(*this + 0x98))(param_1);
    return uVar1;
  }
  if (param_2 == 3) {
                    // WARNING: Load size is inaccurate
    uVar1 = (**(code **)(*this + 0xa8))(param_1);
  }
  return uVar1;
}

undefined1 __fastcall FUN_10022650(int param_1)

{
  return *(undefined1 *)(param_1 + 0x38);
}

void __thiscall FUN_10022660(void *this,undefined1 param_1)

{
  *(undefined1 *)((int)this + 0x38) = param_1;
  return;
}

undefined4 __fastcall FUN_10022670(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc4);
}

undefined4 __fastcall FUN_10022680(int param_1)

{
  return *(undefined4 *)(param_1 + 200);
}

undefined4 __fastcall FUN_10022690(int param_1)

{
  *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + 1;
  return 0;
}

undefined4 __fastcall FUN_100226a0(int param_1)

{
  *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + 1;
  return 0;
}

undefined4 __fastcall FUN_100226b0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x40);
}

void __thiscall FUN_100226c0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x40) = param_1;
  return;
}

void __thiscall FUN_10022730(void *this,int param_1)

{
  uint uVar1;
  int local_10;
  uint local_c;
  int local_8;
  uint local_4;
  
  uVar1 = *(uint *)((int)this + 0x18);
  if (*(int *)((int)this + 0x1c) + uVar1 < uVar1) {
    FUN_10035812();
  }
                    // WARNING: Load size is inaccurate
  local_10 = *this;
  local_c = uVar1;
  FUN_100226d0(&local_10,param_1);
  local_8 = local_10;
  local_4 = local_c;
  FUN_1001b560(&local_8);
  return;
}

undefined4 __fastcall FUN_10022790(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0xa0) == 0) {
    return 0xffffffff;
  }
  puVar1 = (undefined4 *)FUN_10022730((void *)(param_1 + 0x84),0);
                    // WARNING: Could not recover jumptable at 0x100227b1. Too many branches
                    // WARNING: Treating indirect jump as call
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x60))();
  return uVar2;
}

undefined4 __fastcall FUN_100227c0(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0xa0) == 0) {
    return 0xffffffff;
  }
  puVar1 = (undefined4 *)FUN_10022730((void *)(param_1 + 0x84),*(int *)(param_1 + 0xa0) + -1);
                    // WARNING: Could not recover jumptable at 0x100227e2. Too many branches
                    // WARNING: Treating indirect jump as call
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x60))();
  return uVar2;
}

void __thiscall FUN_100227f0(void *this,void *param_1)

{
  undefined4 uStack0000000c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004f988;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(undefined ***)this = GenericData::vftable;
  local_4 = 0;
  FUN_1001d390((int)this + 0xa4);
  FUN_100355b4(*(void **)((int)this + 0xa4));
  FUN_1001d390((int)this + 0x84);
  FUN_100355b4(*(void **)((int)this + 0x84));
  FUN_1001d390((int)this + 100);
  FUN_100355b4(*(void **)((int)this + 100));
  FUN_1001d390((int)this + 0x44);
  FUN_100355b4(*(void **)((int)this + 0x44));
  pvStack_c = (void *)0x1002287e;
  DMutex::~DMutex((DMutex *)((int)this + 0x34));
  uStack0000000c = 0xffffffff;
  pvStack_c = (void *)0x1002288d;
  FUN_10021c20((undefined4 *)this);
  ExceptionList = param_1;
  return;
}

undefined4 __fastcall FUN_100228a0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x3c);
}

void __thiscall FUN_100228b0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x3c) = param_1;
  return;
}

undefined4 __fastcall FUN_10022a20(int param_1)

{
  FUN_10022450(param_1);
  FUN_100228c0(param_1);
  FUN_10022460(param_1);
  return 0;
}

undefined4 * __fastcall FUN_10022a40(undefined4 *param_1)

{
  int *piVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f9d7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10021be0(param_1);
  local_4 = 0;
  *param_1 = GenericData::vftable;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 1;
  param_1[8] = 0;
  param_1[9] = 1;
  param_1[10] = 1;
  param_1[0xb] = 0xffffffff;
  param_1[0xc] = 0;
  DMutex::DMutex((DMutex *)(param_1 + 0xd));
  param_1[0x10] = 0xffffffff;
  local_4._0_1_ = 1;
  *(undefined1 *)(param_1 + 0xe) = 0;
  param_1[0xf] = 2;
  piVar1 = (int *)operator_new(4);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = (int)(param_1 + 0x11);
  }
  param_1[0x11] = piVar1;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  local_4._0_1_ = 2;
  piVar1 = (int *)operator_new(4);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = (int)(param_1 + 0x19);
  }
  param_1[0x19] = piVar1;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  local_4._0_1_ = 3;
  piVar1 = (int *)operator_new(4);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = (int)(param_1 + 0x21);
  }
  param_1[0x21] = piVar1;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  local_4 = CONCAT31(local_4._1_3_,4);
  piVar1 = (int *)operator_new(4);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = (int)(param_1 + 0x29);
  }
  param_1[0x29] = piVar1;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  ExceptionList = local_c;
  return param_1;
}

void * __thiscall FUN_10022b80(void *this,byte param_1)

{
  void *unaff_ESI;
  
  FUN_100227f0(this,unaff_ESI);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return this;
}

void __fastcall FUN_10022ba0(void *param_1)

{
  int extraout_ECX;
  
  FUN_10022450((int)param_1);
  *(undefined4 *)((int)param_1 + 0x2c) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x40) = 0xffffffff;
  FUN_10022480(param_1,1);
  *(undefined4 *)((int)param_1 + 0x18) = 0;
  *(undefined1 *)((int)param_1 + 0x38) = 0;
  *(undefined4 *)((int)param_1 + 0x24) = 1;
  FUN_100228c0(extraout_ECX);
  if (*(int *)((int)param_1 + 0x28) != 1) {
    *(undefined4 *)((int)param_1 + 0x28) = 1;
  }
  FUN_10022460((int)param_1);
  return;
}

undefined4 __thiscall FUN_10022bf0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvStack_4;
  
  puVar1 = param_1;
  pvStack_4 = this;
  (**(code **)*param_1)();
  pvStack_4 = (void *)FUN_1001b5f0((int)puVar1);
  FUN_10015660((void *)((int)this + 0x44),&pvStack_4);
  FUN_10015660((void *)((int)this + 0x84),&param_1);
  *(int *)((int)this + 0xc4) = *(int *)((int)this + 0xc4) + 1;
  return 0;
}

undefined4 __thiscall FUN_10022c40(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvStack_4;
  
  puVar1 = param_1;
  pvStack_4 = this;
  (**(code **)*param_1)();
  pvStack_4 = (void *)FUN_1001b5f0((int)puVar1);
  FUN_10015660((void *)((int)this + 100),&pvStack_4);
  FUN_10015660((void *)((int)this + 0xa4),&param_1);
  *(int *)((int)this + 200) = *(int *)((int)this + 200) + 1;
  return 0;
}

undefined4 * __thiscall FUN_10022c90(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f428;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int **)this = param_1;
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 0x28 + (int)param_1);
  if (iVar1 != 0) {
    FUN_1003495d((undefined4 *)(iVar1 + 4));
  }
  local_4 = 0;
  if ((*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 8) == 0) &&
     (piVar2 = *(int **)((int)param_1 + *(int *)(*param_1 + 4) + 0x2c), piVar2 != (int *)0x0)) {
    FUN_1000b7e0(piVar2);
  }
  *(bool *)((int)this + 4) = *(int *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) == 0;
  ExceptionList = local_c;
  return (undefined4 *)this;
}

void __fastcall FUN_10022d20(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1004f9f0;
  local_10 = ExceptionList;
  local_8 = 0;
  if ((*(byte *)(*(int *)(*param_1 + 4) + 0x10 + (int)param_1) & 2) != 0) {
    ExceptionList = &local_10;
    FUN_1000b7e0(param_1);
  }
  ExceptionList = local_10;
  return;
}

void __fastcall FUN_10022d70(int *param_1)

{
  int iVar1;
  bool bVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004f428;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  bVar2 = thunk_FUN_1003a9c3();
  if (!bVar2) {
    FUN_10022d20((int *)*param_1);
  }
  iVar1 = *(int *)(*(int *)(*(int *)*param_1 + 4) + 0x28 + *param_1);
  local_4 = 0xffffffff;
  if (iVar1 != 0) {
    FUN_10034966((undefined4 *)(iVar1 + 4));
  }
  ExceptionList = local_c;
  return;
}

void __thiscall FUN_10022de0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined1 local_24 [4];
  char local_20;
  undefined4 local_1c;
  void *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1004fa08;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffffd0;
  local_1c = 0;
  ExceptionList = &pvStack_10;
  local_18 = this;
  FUN_10022c90(local_24,(int *)this);
  local_8 = 0;
  if (local_20 == '\0') {
    FUN_10022e89();
    return;
  }
                    // WARNING: Load size is inaccurate
  local_8 = 1;
  (**(code **)(**(int **)(*(int *)(*this + 4) + 0x28 + (int)this) + 0x20))(param_1,param_2);
  local_8 = 0;
  FUN_10022e89();
  return;
}

undefined4 __thiscall FUN_10022ee0(void *this,void *param_1,undefined4 param_2)

{
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_20;
  
  _memset(&local_40,0,0x40);
                    // WARNING: Load size is inaccurate
  local_40 = 0x1881b4ee;
  local_3c = 1;
  local_38 = 0x40;
  uStack_34 = (**(code **)(*this + 0x14))();
                    // WARNING: Load size is inaccurate
  uStack_30 = (**(code **)(*this + 0x20))();
                    // WARNING: Load size is inaccurate
  uStack_2e = (**(code **)(*this + 0x28))();
                    // WARNING: Load size is inaccurate
  uStack_2c = (**(code **)(*this + 0x2c))();
  uStack_28 = *(undefined4 *)((int)this + 0x2c);
  uStack_20 = param_2;
  FUN_10022de0(param_1,&local_40,0x40);
  return 0;
}

void __thiscall FUN_10022ff0(void *this,void *param_1)

{
  FUN_10022f70(this,param_1,(int *)0x0);
  return;
}

undefined4 * __thiscall FUN_10023000(void *this,uint param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_1004fe48;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_10022a40((undefined4 *)this);
  *(undefined8 *)((int)this + 0xe8) = 0x7fefffffffffffff;
  *(undefined8 *)((int)this + 0xf0) = 0x10000000000000;
  *(undefined4 *)((int)this + 0x100) = 0xffffffff;
  *(undefined4 *)((int)this + 0x104) = 0xffffffff;
  *(undefined8 *)((int)this + 0xf8) = 0;
  *(undefined4 *)((int)this + 0x108) = 0xffffffff;
  lVar1 = (ulonglong)(param_1 + 2) * 8;
  local_4 = (void *)0x0;
  *(undefined ***)this = Igram::vftable;
  *(undefined4 *)((int)this + 0xcc) = 0;
  *(undefined4 *)((int)this + 0xd0) = 0;
  *(undefined4 *)((int)this + 0xd4) = 0;
  *(undefined1 *)((int)this + 0xd8) = 0;
  *(undefined4 *)((int)this + 0xdc) = 0;
  *(undefined4 *)((int)this + 0xe0) = 0;
  puVar2 = (undefined4 *)FUN_10034298(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  *(undefined4 **)((int)this + 0xcc) = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *(undefined4 **)((int)this + 0xd0) = puVar2 + 2;
    *puVar2 = 0xabcd1234;
    *(undefined4 *)(*(int *)((int)this + 0xcc) + 8 + param_1 * 8) = 0xabcd1234;
  }
  if (*(int *)((int)this + 0xd0) != 0) {
    *(uint *)((int)this + 0xe0) = param_1;
  }
  *(int *)((int)this + 0x14) = *(int *)((int)this + 0xd0);
  uVar3 = FUN_10034298(-(uint)((int)((ulonglong)param_1 * 8 >> 0x20) != 0) |
                       (uint)((ulonglong)param_1 * 8));
  *(undefined4 *)((int)this + 0xdc) = uVar3;
  ExceptionList = local_4;
  return (undefined4 *)this;
}

void __fastcall FUN_10023120(undefined4 *param_1)

{
  undefined4 uStack00000004;
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  *param_1 = Igram::vftable;
  if (*(int *)param_1[0x33] != -0x5432edcc) {
    FUN_10021c10();
  }
  if (*(int *)(param_1[0x33] + 8 + param_1[0x38] * 8) != -0x5432edcc) {
    FUN_10021c10();
  }
  FUN_100355e9((void *)param_1[0x33]);
  FUN_100355e9((void *)param_1[0x37]);
  uStack00000004 = 0xffffffff;
  FUN_100227f0(param_1,pvVar1);
  ExceptionList = (void *)0x0;
  return;
}

undefined4 FUN_100231d0(void)

{
  return 0x10;
}

undefined * FUN_100231e0(void)

{
  return PTR_s_Igram_10195138;
}

undefined * FUN_100231f0(void)

{
  return PTR_DAT_1019513c;
}

undefined4 __fastcall FUN_10023250(int param_1)

{
  return *(undefined4 *)(param_1 + 0xe0);
}

void __thiscall FUN_100232a0(void *this,int param_1)

{
  *(undefined1 *)((int)this + 0xd8) = 0;
  FUN_10022560(this,param_1);
  return;
}

void __thiscall FUN_100232b0(void *this,int param_1,undefined4 param_2)

{
  *(undefined1 *)((int)this + 0xd8) = 0;
  FUN_10022580(this,param_1,param_2);
  return;
}

undefined4 __thiscall FUN_10023340(void *this,undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  *param_1 = *(undefined4 *)((int)this + 0xdc);
  return 0;
}

void __thiscall FUN_100234f0(void *this,undefined8 *param_1,char param_2)

{
  if (param_1 != (undefined8 *)0x0) {
    FUN_10023360(this,param_2);
    *param_1 = *(undefined8 *)((int)this + 0xf8);
    *(undefined4 *)(param_1 + 1) = *(undefined4 *)((int)this + 0x108);
    param_1[2] = *(undefined8 *)((int)this + 0xf0);
    *(undefined4 *)(param_1 + 3) = *(undefined4 *)((int)this + 0x104);
    param_1[4] = *(undefined8 *)((int)this + 0xe8);
    *(undefined4 *)(param_1 + 5) = *(undefined4 *)((int)this + 0x100);
    param_1[6] = *(undefined8 *)((int)this + 0x110);
    *(int *)(param_1 + 7) = *(int *)((int)this + 0x18) - *(int *)((int)this + 0x108);
  }
  return;
}

undefined4 * __fastcall FUN_10023560(undefined4 *param_1)

{
  FUN_10022170(param_1,"IgramAllocator");
  *param_1 = IgramAllocator::vftable;
  return param_1;
}

int * __thiscall FUN_10023580(void *this,uint param_1)

{
  int *piVar1;
  uint uVar2;
  void *this_00;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_1004fdbb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar1 = FUN_10021fa0((int)this);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))();
    if (param_1 <= uVar2) goto LAB_10023604;
    FUN_10021d00(piVar1);
    FUN_10022040((int)this);
  }
  this_00 = operator_new(0x118);
  uStack_4 = 0;
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_10023000(this_00,param_1);
  }
  uStack_4 = 0xffffffff;
  FUN_10022280(this,piVar1);
  if (piVar1 == (int *)0x0) {
    ExceptionList = pvStack_c;
    return (int *)0x0;
  }
LAB_10023604:
  FUN_10022490((int)piVar1);
  ExceptionList = pvStack_c;
  return piVar1;
}

undefined4 * __thiscall FUN_10023630(void *this,byte param_1)

{
  FUN_10023120((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

void __cdecl FUN_100236e0(undefined4 param_1,undefined1 *param_2,char *param_3,uint param_4)

{
  char *pcVar1;
  byte *pbVar2;
  
  *param_2 = 0x25;
  pcVar1 = param_2 + 1;
  if ((param_4 & 0x20) != 0) {
    *pcVar1 = '+';
    pcVar1 = param_2 + 2;
  }
  if ((param_4 & 8) != 0) {
    *pcVar1 = '#';
    pcVar1 = pcVar1 + 1;
  }
  if (*param_3 == 'L') {
    *pcVar1 = 'I';
    pcVar1[1] = '6';
    pcVar1 = pcVar1 + 2;
    *pcVar1 = '4';
  }
  else {
    *pcVar1 = *param_3;
  }
  pbVar2 = (byte *)(pcVar1 + 1);
  if ((param_4 & 0xe00) == 0x400) {
    *pbVar2 = 0x6f;
    pcVar1[2] = '\0';
    return;
  }
  if ((param_4 & 0xe00) != 0x800) {
    *pbVar2 = param_3[1];
    pcVar1[2] = '\0';
    return;
  }
  *pbVar2 = ~((char)param_4 * '\b') & 0x20U | 0x58;
  pcVar1[2] = '\0';
  return;
}

void __fastcall FUN_10023770(int param_1)

{
  FUN_100355e9(*(void **)(param_1 + 8));
  FUN_100355e9(*(void **)(param_1 + 0x10));
  FUN_100355e9(*(void **)(param_1 + 0x14));
  return;
}

void __cdecl FUN_100237a0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = pcVar2 + (1 - (int)(param_1 + 1));
  pcVar3 = (char *)FUN_10034298((uint)pcVar2);
  for (; pcVar2 != (char *)0x0; pcVar2 = pcVar2 + -1) {
    *pcVar3 = *param_1;
    pcVar3 = pcVar3 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

void __thiscall FUN_100237e0(void *this,undefined4 param_1,char param_2)

{
  char cVar1;
  lconv *plVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined1 *puVar8;
  _Cvtvec *unaff_EBX;
  _Cvtvec *unaff_ESI;
  _Cvtvec *unaff_EDI;
  char *pcVar9;
  undefined1 *puVar10;
  _Cvtvec *in_stack_ffffffe0;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1004fa20;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  plVar2 = _localeconv();
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  local_8 = 0;
  __Getcvt(unaff_EDI);
  pcVar9 = plVar2->grouping;
  pcVar3 = pcVar9;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = pcVar3 + (1 - (int)(pcVar9 + 1));
  pcVar4 = (char *)FUN_10034298((uint)pcVar3);
  pcVar7 = pcVar4;
  for (; pcVar3 != (char *)0x0; pcVar3 = pcVar3 + -1) {
    *pcVar7 = *pcVar9;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  *(char **)((int)this + 8) = pcVar4;
  __Getcvt(unaff_ESI);
  pcVar9 = "false";
  pcVar3 = "false";
  do {
    pcVar7 = pcVar3;
    pcVar3 = pcVar7 + 1;
  } while (*pcVar7 != '\0');
  pcVar7 = pcVar7 + -0x10055473;
  pcVar4 = (char *)FUN_10034298((uint)pcVar7);
  pcVar3 = pcVar4;
  for (; pcVar7 != (char *)0x0; pcVar7 = pcVar7 + -1) {
    *pcVar3 = *pcVar9;
    pcVar3 = pcVar3 + 1;
    pcVar9 = pcVar9 + 1;
  }
  *(char **)((int)this + 0x10) = pcVar4;
  __Getcvt(unaff_EBX);
  puVar10 = &DAT_1005547c;
  pcVar3 = "true";
  do {
    pcVar9 = pcVar3;
    pcVar3 = pcVar9 + 1;
  } while (*pcVar9 != '\0');
  pcVar9 = pcVar9 + -0x1005547b;
  puVar5 = (undefined1 *)FUN_10034298((uint)pcVar9);
  puVar8 = puVar5;
  for (; pcVar9 != (char *)0x0; pcVar9 = pcVar9 + -1) {
    *puVar8 = *puVar10;
    puVar8 = puVar8 + 1;
    puVar10 = puVar10 + 1;
  }
  *(undefined1 **)((int)this + 0x14) = puVar5;
  local_8 = 0xffffffff;
  __Getcvt(in_stack_ffffffe0);
  *(char *)((int)this + 0xc) = *plVar2->decimal_point;
  __Getcvt(in_stack_ffffffe0);
  *(char *)((int)this + 0xd) = *plVar2->thousands_sep;
  if (param_2 != '\0') {
    __Getcvt(in_stack_ffffffe0);
    uVar6 = FUN_100237a0("");
    *(undefined4 *)((int)this + 8) = uVar6;
    __Getcvt(in_stack_ffffffe0);
    *(undefined1 *)((int)this + 0xc) = 0x2e;
    __Getcvt(in_stack_ffffffe0);
    *(undefined1 *)((int)this + 0xd) = 0x2c;
  }
  ExceptionList = local_10;
  return;
}

undefined4 * __thiscall FUN_10023ad0(void *this,undefined4 param_1,undefined4 param_2,char param_3)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004fa38;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)((int)this + 4) = param_2;
  local_4 = 0;
  *(undefined ***)this = std::numpunct<char>::vftable;
  FUN_100237e0(this,param_1,param_3);
  ExceptionList = local_c;
  return (undefined4 *)this;
}

undefined1 __fastcall FUN_10023b30(int param_1)

{
  return *(undefined1 *)(param_1 + 0xc);
}

undefined1 __fastcall FUN_10023b40(int param_1)

{
  return *(undefined1 *)(param_1 + 0xd);
}

undefined4 * __thiscall FUN_10023b50(void *this)

{
  byte in_stack_00000010;
  
  *(undefined ***)this = std::numpunct<char>::vftable;
  FUN_100355e9(*(void **)((int)this + 8));
  FUN_100355e9(*(void **)((int)this + 0x10));
  FUN_100355e9(*(void **)((int)this + 0x14));
  *(undefined ***)this = std::locale::facet::vftable;
  if ((in_stack_00000010 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

undefined4 __thiscall FUN_10023ba0(void *this,undefined4 param_1)

{
                    // WARNING: Load size is inaccurate
  (**(code **)(*this + 0x10))(param_1);
  return param_1;
}

undefined4 __thiscall FUN_10023bc0(void *this,undefined4 param_1)

{
                    // WARNING: Load size is inaccurate
  (**(code **)(*this + 0x14))(param_1);
  return param_1;
}

undefined4 __thiscall FUN_10023ce0(void *this,undefined4 param_1)

{
                    // WARNING: Load size is inaccurate
  (**(code **)(*this + 0xc))(param_1);
  return param_1;
}

void * __thiscall FUN_10023d00(void *this,void *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = *(char **)((int)this + 8);
  *(undefined4 *)((int)param_1 + 0x18) = 0xf;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  *(undefined1 *)((int)param_1 + 4) = 0;
  pcVar3 = pcVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_10001a80(param_1,(undefined4 *)pcVar2,(int)pcVar3 - (int)(pcVar2 + 1));
  return param_1;
}

void * __thiscall FUN_10023d50(void *this,void *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = *(char **)((int)this + 0x10);
  *(undefined4 *)((int)param_1 + 0x18) = 0xf;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  *(undefined1 *)((int)param_1 + 4) = 0;
  pcVar3 = pcVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_10001a80(param_1,(undefined4 *)pcVar2,(int)pcVar3 - (int)(pcVar2 + 1));
  return param_1;
}

void * __thiscall FUN_10023da0(void *this,void *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = *(char **)((int)this + 0x14);
  *(undefined4 *)((int)param_1 + 0x18) = 0xf;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  *(undefined1 *)((int)param_1 + 4) = 0;
  pcVar3 = pcVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_10001a80(param_1,(undefined4 *)pcVar2,(int)pcVar3 - (int)(pcVar2 + 1));
  return param_1;
}

undefined4 * __thiscall
FUN_10024d70(void *this,undefined4 *param_1,undefined4 param_2,int *param_3,void *param_4,
            byte param_5,undefined4 param_6)

{
  char *_Format;
  uint uVar1;
  undefined1 local_48 [8];
  char ****local_40 [16];
  
  _Format = (char *)FUN_100236e0(this,local_48,"ld",*(uint *)((int)param_4 + 0x10));
  uVar1 = _sprintf_s((char *)local_40,0x40,_Format,param_6);
  FUN_10024ac0(this,param_1,param_2,param_3,param_4,param_5,local_40,uVar1);
  return param_1;
}

undefined4 * __thiscall
FUN_10024de0(void *this,undefined4 *param_1,undefined4 param_2,int *param_3,void *param_4,
            byte param_5,undefined4 param_6)

{
  char *_Format;
  uint uVar1;
  undefined1 local_48 [8];
  char ****local_40 [16];
  
  _Format = (char *)FUN_100236e0(this,local_48,"lu",*(uint *)((int)param_4 + 0x10));
  uVar1 = _sprintf_s((char *)local_40,0x40,_Format,param_6);
  FUN_10024ac0(this,param_1,param_2,param_3,param_4,param_5,local_40,uVar1);
  return param_1;
}

undefined4 * __thiscall
FUN_10024e50(void *this,undefined4 *param_1,undefined4 param_2,int *param_3,void *param_4,
            byte param_5,undefined4 param_6,undefined4 param_7)

{
  char *_Format;
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char ****local_40 [16];
  
  uVar2 = param_6;
  uVar3 = param_7;
  _Format = (char *)FUN_100236e0(this,(undefined1 *)&param_6,"Ld",*(uint *)((int)param_4 + 0x10));
  uVar1 = _sprintf_s((char *)local_40,0x40,_Format,uVar2,uVar3);
  FUN_10024ac0(this,param_1,param_2,param_3,param_4,param_5,local_40,uVar1);
  return param_1;
}

undefined4 * __thiscall
FUN_10024ec0(void *this,undefined4 *param_1,undefined4 param_2,int *param_3,void *param_4,
            byte param_5,undefined4 param_6,undefined4 param_7)

{
  char *_Format;
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char ****local_40 [16];
  
  uVar2 = param_6;
  uVar3 = param_7;
  _Format = (char *)FUN_100236e0(this,(undefined1 *)&param_6,"Lu",*(uint *)((int)param_4 + 0x10));
  uVar1 = _sprintf_s((char *)local_40,0x40,_Format,uVar2,uVar3);
  FUN_10024ac0(this,param_1,param_2,param_3,param_4,param_5,local_40,uVar1);
  return param_1;
}

undefined4 * __thiscall
FUN_100252a0(void *this,undefined4 *param_1,undefined4 param_2,int *param_3,void *param_4,
            byte param_5,undefined4 param_6)

{
  uint uVar1;
  char ****local_40 [16];
  
  uVar1 = _sprintf_s((char *)local_40,0x40,"%p",param_6);
  FUN_10024ac0(this,param_1,param_2,param_3,param_4,param_5,local_40,uVar1);
  return param_1;
}

void __thiscall FUN_100256b0(void *this,undefined1 param_1)

{
  int *piVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined1 local_24 [4];
  char local_20;
  undefined4 local_1c;
  void *local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1004fbb8;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xffffffd0;
  local_1c = 0;
  ExceptionList = &pvStack_10;
  local_18 = this;
  FUN_10022c90(local_24,(int *)this);
  local_8 = 0;
  if (local_20 == '\0') {
    FUN_10025777();
    return;
  }
                    // WARNING: Load size is inaccurate
  piVar1 = *(int **)(*(int *)(*this + 4) + 0x28 + (int)this);
  local_8 = 1;
  if ((*(int *)piVar1[9] == 0) || (piVar2 = (int *)piVar1[0xd], *piVar2 < 1)) {
    (**(code **)(*piVar1 + 4))(param_1);
  }
  else {
    *piVar2 = *piVar2 + -1;
    puVar3 = *(undefined1 **)piVar1[9];
    *(undefined1 **)piVar1[9] = puVar3 + 1;
    *puVar3 = param_1;
  }
  local_8 = 0;
  FUN_10025777();
  return;
}

int __thiscall FUN_10025860(void *this,int *param_1)

{
  FUN_10022ee0(this,param_1,0);
  FUN_10022de0(param_1,*(undefined4 *)((int)this + 0xd0),*(int *)((int)this + 0x18) * 8);
  return -(uint)((*(byte *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) & 6) != 0);
}

void __thiscall FUN_10025b90(void *this,undefined4 param_1)

{
  *(undefined4 *)this = 1;
  *(undefined4 *)((int)this + 8) = param_1;
  return;
}

void __thiscall FUN_10025bb0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 8) = param_1;
  *(undefined4 *)this = 4;
  return;
}

void __thiscall FUN_10025bd0(void *this,undefined8 param_1)

{
  *(undefined8 *)((int)this + 8) = param_1;
  *(undefined4 *)this = 5;
  return;
}

undefined4 * __thiscall FUN_10025c60(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  
  switch(*param_1) {
  case 1:
    *(undefined4 *)((int)this + 8) = param_1[2];
    *(undefined4 *)this = 1;
    return (undefined4 *)this;
  default:
    *(undefined4 *)this = 0;
    return (undefined4 *)this;
  case 4:
    uVar1 = param_1[2];
    *(undefined4 *)this = 4;
    *(undefined4 *)((int)this + 8) = uVar1;
    return (undefined4 *)this;
  case 5:
    uVar2 = *(undefined8 *)(param_1 + 2);
    *(undefined4 *)this = 5;
    *(undefined8 *)((int)this + 8) = uVar2;
    return (undefined4 *)this;
  case 6:
    pcVar4 = (char *)param_1[2];
    pcVar5 = pcVar4 + 1;
  }
  do {
    cVar3 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar3 != '\0');
  pcVar4 = pcVar4 + (1 - (int)pcVar5);
  if (0x100 < (int)pcVar4) {
    pcVar4 = (char *)0x100;
  }
  pcVar5 = (char *)FUN_10034298((uint)pcVar4);
  *(char **)((int)this + 8) = pcVar5;
  if (pcVar5 != (char *)0x0) {
    _strncpy(pcVar5,(char *)param_1[2],(size_t)pcVar4);
    pcVar4[*(int *)((int)this + 8) + -1] = '\0';
  }
  *(undefined4 *)this = 6;
  return (undefined4 *)this;
}

void __fastcall FUN_10025d30(int *param_1)

{
  if (*param_1 == 6) {
    FUN_100355e9((void *)param_1[2]);
  }
  return;
}

undefined4 __thiscall FUN_10025d40(void *this,int *param_1)

{
                    // WARNING: Load size is inaccurate
  if (*this != 1) {
    return 0xfffffffd;
  }
  *param_1 = *(int *)((int)this + 8);
  return 0;
}

undefined4 __thiscall FUN_10025d60(void *this,int *param_1)

{
                    // WARNING: Load size is inaccurate
  if (*this != 4) {
    return 0xfffffffd;
  }
  *param_1 = *(int *)((int)this + 8);
  return 0;
}

undefined4 __thiscall FUN_10025d80(void *this,undefined8 *param_1)

{
                    // WARNING: Load size is inaccurate
  if (*this != 5) {
    return 0xfffffffd;
  }
  *param_1 = *(undefined8 *)((int)this + 8);
  return 0;
}

undefined4 __thiscall FUN_10025da0(void *this,int *param_1)

{
                    // WARNING: Load size is inaccurate
  if (*this != 6) {
    return 0xfffffffd;
  }
  *param_1 = *(int *)((int)this + 8);
  return 0;
}

void __thiscall FUN_10025dc0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 8) = param_1;
  *(undefined4 *)this = 1;
  return;
}

void __thiscall FUN_10025dd0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = 4;
  *(undefined4 *)((int)this + 8) = param_1;
  return;
}

void __thiscall FUN_10025de0(void *this,undefined8 param_1)

{
  *(undefined4 *)this = 5;
  *(undefined8 *)((int)this + 8) = param_1;
  return;
}

void __fastcall FUN_10025e60(int param_1)

{
  FUN_10025d30((int *)(param_1 + 8));
  return;
}

void __cdecl FUN_10025e70(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x29);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x29);
  }
  return;
}

void __cdecl FUN_10025e90(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  cVar1 = *(char *)((int)piVar2 + 0x29);
  while (cVar1 == '\0') {
    piVar2 = (int *)*piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x29);
  }
  return;
}

void __thiscall FUN_10025eb0(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x29) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)((int)this + 0x18) + 4)) {
    *(int *)(*(int *)((int)this + 0x18) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}

void __thiscall FUN_10026010(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x29) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)((int)this + 0x18) + 4)) {
    *(int **)(*(int *)((int)this + 0x18) + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}

undefined4 * __cdecl FUN_10026060(undefined4 *param_1,undefined4 param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004fbd8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *param_1 = param_2;
  FUN_10025c60(param_1 + 2,(undefined4 *)&stack0x0000000c);
  FUN_10025d30((int *)&stack0x0000000c);
  ExceptionList = local_c;
  return param_1;
}

undefined4 *
FUN_100260c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1004fc01;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)operator_new(0x30);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[4] = *param_4;
    FUN_10025c60(puVar1 + 6,param_4 + 2);
    *(undefined1 *)(puVar1 + 10) = param_5;
    *(undefined1 *)((int)puVar1 + 0x29) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}

void FUN_10026160(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)operator_new(0x30);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 10) = 1;
  *(undefined1 *)((int)puVar1 + 0x29) = 0;
  return;
}

void __fastcall FUN_100261a0(int param_1)

{
  void *this;
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined8 local_58;
  int local_4c;
  int *local_48;
  int local_44;
  
  local_48 = *(int **)(param_1 + 4);
  local_44 = **(int **)(param_1 + 0x1c);
  local_4c = param_1;
LAB_100261d4:
  piVar1 = local_48;
  iVar3 = *(int *)(local_4c + 0x1c);
  if ((local_48 == (int *)0x0) || (local_48 != *(int **)(local_4c + 4))) {
    FUN_10035812();
  }
  if (local_44 == iVar3) {
    return;
  }
  if (piVar1 == (int *)0x0) {
    FUN_10035812();
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar1;
  }
  if (local_44 == *(int *)(iVar3 + 0x18)) {
    FUN_10035812();
  }
  if (piVar1 == (int *)0x0) {
    FUN_10035812();
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar1;
  }
  iVar2 = local_44;
  if (local_44 == *(int *)(iVar3 + 0x18)) {
    FUN_10035812();
  }
  this = (void *)(iVar2 + 0x18);
  switch(*(undefined4 *)(iVar2 + 0x18)) {
  case 1:
    local_58 = CONCAT44(local_58._4_4_,0xfffffffe);
    FUN_10025d40(this,(int *)&local_58);
    break;
  default:
    goto switchD_1002623a_caseD_2;
  case 4:
    local_58 = CONCAT44(local_58._4_4_,0xc0000000);
    FUN_10025d60(this,(int *)&local_58);
    goto LAB_10026281;
  case 5:
    local_58 = 0xc000000000000000;
    FUN_10025d80(this,&local_58);
LAB_10026281:
    FUN_10021c10();
    FUN_10025f10((int *)&local_48);
    goto LAB_100261d4;
  case 6:
    local_58 = CONCAT44(local_58._4_4_,"Error");
    FUN_10025da0(this,(int *)&local_58);
  }
  FUN_10021c10();
switchD_1002623a_caseD_2:
  FUN_10025f10((int *)&local_48);
  goto LAB_100261d4;
}

void FUN_100263c0(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x29);
  while (cVar1 == '\0') {
    FUN_100263c0((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_10025d30(param_1 + 6);
    FUN_100355b4(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x29);
  }
  return;
}

undefined4 __fastcall FUN_10026470(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10026400(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    return *puVar1;
  }
  return 0xfffffffe;
}

undefined4 __thiscall FUN_10026490(void *this,undefined4 param_1,int *param_2)

{
  void *this_00;
  undefined4 uVar1;
  
  this_00 = (void *)FUN_10026400((int)this);
  if (this_00 != (void *)0x0) {
    uVar1 = FUN_10025d40(this_00,param_2);
    return uVar1;
  }
  return 0xfffffffe;
}

undefined4 __thiscall FUN_100264c0(void *this,undefined4 param_1,int *param_2)

{
  void *this_00;
  undefined4 uVar1;
  
  this_00 = (void *)FUN_10026400((int)this);
  if (this_00 != (void *)0x0) {
    uVar1 = FUN_10025d60(this_00,param_2);
    return uVar1;
  }
  return 0xfffffffe;
}

undefined4 __thiscall FUN_100264f0(void *this,undefined4 param_1,undefined8 *param_2)

{
  void *this_00;
  undefined4 uVar1;
  
  this_00 = (void *)FUN_10026400((int)this);
  if (this_00 != (void *)0x0) {
    uVar1 = FUN_10025d80(this_00,param_2);
    return uVar1;
  }
  return 0xfffffffe;
}

undefined4 __thiscall FUN_10026520(void *this,undefined4 param_1,int *param_2)

{
  void *this_00;
  undefined4 uVar1;
  
  this_00 = (void *)FUN_10026400((int)this);
  if (this_00 != (void *)0x0) {
    uVar1 = FUN_10025da0(this_00,param_2);
    return uVar1;
  }
  return 0xfffffffe;
}

void __fastcall FUN_10026550(undefined4 *param_1)

{
  FUN_100355b4((void *)*param_1);
  return;
}

void __fastcall FUN_10026560(int param_1)

{
  FUN_100263c0(*(int **)(*(int *)(param_1 + 0x1c) + 4));
  *(int *)(*(int *)(param_1 + 0x1c) + 4) = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)*(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(int *)(*(int *)(param_1 + 0x1c) + 8) = *(int *)(param_1 + 0x1c);
  return;
}

undefined4 * __fastcall FUN_10026b40(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004f738;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = (undefined4 *)operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = param_1;
  }
  *param_1 = puVar1;
  local_4 = 0;
  iVar2 = FUN_10026160();
  param_1[6] = iVar2;
  *(undefined1 *)(iVar2 + 0x29) = 1;
  *(undefined4 *)(param_1[6] + 4) = param_1[6];
  *(undefined4 *)param_1[6] = param_1[6];
  *(undefined4 *)(param_1[6] + 8) = param_1[6];
  param_1[7] = 0;
  ExceptionList = local_c;
  return param_1;
}

void __thiscall FUN_10026ca0(void *this,undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined1 auStack_60 [4];
  undefined4 uStack_5c;
  int local_48 [3];
  uint local_3c [2];
  int local_34 [4];
  undefined4 local_24 [2];
  int local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fc20;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10025b90(auStack_60,param_2);
  puVar1 = FUN_10026060(local_24,param_1);
  local_3c[0] = *puVar1;
  local_4 = 0;
  FUN_10025c60(local_34,puVar1 + 2);
  local_4 = CONCAT31(local_4._1_3_,1);
  uStack_5c = 0x10026d12;
  FUN_10026780((void *)((int)this + 4),local_48,local_3c);
  FUN_10025d30(local_34);
  FUN_10025d30(local_1c);
  ExceptionList = local_c;
  return;
}

void __thiscall FUN_10026d40(void *this,undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined1 auStack_60 [4];
  undefined4 uStack_5c;
  int local_48 [3];
  uint local_3c [2];
  int local_34 [4];
  undefined4 local_24 [2];
  int local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fc20;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10025bb0(auStack_60,param_2);
  puVar1 = FUN_10026060(local_24,param_1);
  local_3c[0] = *puVar1;
  local_4 = 0;
  FUN_10025c60(local_34,puVar1 + 2);
  local_4 = CONCAT31(local_4._1_3_,1);
  uStack_5c = 0x10026db5;
  FUN_10026780((void *)((int)this + 4),local_48,local_3c);
  FUN_10025d30(local_34);
  FUN_10025d30(local_1c);
  ExceptionList = local_c;
  return;
}

void __thiscall FUN_10026de0(int param_1,undefined4 param_2,undefined8 param_3)

{
  uint *puVar1;
  undefined1 auStack_60 [4];
  undefined4 uStack_5c;
  int local_48 [3];
  uint local_3c [2];
  int local_34 [4];
  undefined4 local_24 [2];
  int local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fc20;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10025bd0(auStack_60,param_3);
  puVar1 = FUN_10026060(local_24,param_2);
  local_3c[0] = *puVar1;
  local_4 = 0;
  FUN_10025c60(local_34,puVar1 + 2);
  local_4 = CONCAT31(local_4._1_3_,1);
  uStack_5c = 0x10026e57;
  FUN_10026780((void *)(param_1 + 4),local_48,local_3c);
  FUN_10025d30(local_34);
  FUN_10025d30(local_1c);
  ExceptionList = local_c;
  return;
}

void __thiscall FUN_10026e80(void *this,undefined4 param_1,char *param_2)

{
  uint *puVar1;
  undefined1 auStack_60 [4];
  undefined4 uStack_5c;
  int local_48 [3];
  uint local_3c [2];
  int local_34 [4];
  undefined4 local_24 [2];
  int local_1c [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fc20;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10025bf0(auStack_60,param_2);
  puVar1 = FUN_10026060(local_24,param_1);
  local_3c[0] = *puVar1;
  local_4 = 0;
  FUN_10025c60(local_34,puVar1 + 2);
  local_4 = CONCAT31(local_4._1_3_,1);
  uStack_5c = 0x10026ef2;
  FUN_10026780((void *)((int)this + 4),local_48,local_3c);
  FUN_10025d30(local_34);
  FUN_10025d30(local_1c);
  ExceptionList = local_c;
  return;
}

undefined4 __thiscall FUN_10026f20(void *this,undefined4 param_1,undefined4 param_2)

{
  void *this_00;
  
  this_00 = (void *)FUN_10026400((int)this);
  if (this_00 != (void *)0x0) {
    FUN_10025dc0(this_00,param_2);
    return 0;
  }
  FUN_10026ca0(this,param_1,param_2);
  return 0;
}

undefined4 __thiscall FUN_10026f60(void *this,undefined4 param_1,undefined4 param_2)

{
  void *this_00;
  
  this_00 = (void *)FUN_10026400((int)this);
  if (this_00 != (void *)0x0) {
    FUN_10025dd0(this_00,param_2);
    return 0;
  }
  FUN_10026d40(this,param_1,param_2);
  return 0;
}

undefined4 __thiscall FUN_10026fa0(int param_1,undefined4 param_2,undefined8 param_3)

{
  void *this;
  
  this = (void *)FUN_10026400(param_1);
  if (this != (void *)0x0) {
    FUN_10025de0(this,param_3);
    return 0;
  }
  FUN_10026de0(param_1,param_2,param_3);
  return 0;
}

undefined4 __thiscall FUN_10026fe0(void *this,undefined4 param_1,char *param_2)

{
  void *this_00;
  
  this_00 = (void *)FUN_10026400((int)this);
  if (this_00 != (void *)0x0) {
    FUN_10025df0(this_00,param_2);
    return 0;
  }
  FUN_10026e80(this,param_1,param_2);
  return 0;
}

void __fastcall FUN_100272f0(undefined4 *param_1)

{
  int local_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_1004f548;
  pvStack_c = ExceptionList;
  local_4 = (void *)0x0;
  ExceptionList = &pvStack_c;
  FUN_10026bc0(param_1,local_14,(undefined4 *)*param_1,*(int **)param_1[6],(undefined4 *)*param_1,
               (int *)param_1[6]);
  FUN_100355b4((void *)param_1[6]);
  param_1[6] = 0;
  param_1[7] = 0;
  FUN_100355b4((void *)*param_1);
  ExceptionList = local_4;
  return;
}

void __fastcall FUN_10027360(undefined4 *param_1)

{
  int aiStack_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  puStack_8 = &LAB_1004f548;
  pvStack_c = ExceptionList;
  pvStack_4 = (void *)0x0;
  ExceptionList = &pvStack_c;
  FUN_10026bc0(param_1,aiStack_14,(undefined4 *)*param_1,*(int **)param_1[6],(undefined4 *)*param_1,
               (int *)param_1[6]);
  FUN_100355b4((void *)param_1[6]);
  param_1[6] = 0;
  param_1[7] = 0;
  FUN_100355b4((void *)*param_1);
  ExceptionList = pvStack_4;
  return;
}

void __fastcall FUN_10027370(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004fc3b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = KeyValList::vftable;
  local_4 = 0;
  FUN_100263c0(*(int **)(param_1[7] + 4));
  *(undefined4 *)(param_1[7] + 4) = param_1[7];
  param_1[8] = 0;
  *(undefined4 *)param_1[7] = param_1[7];
  *(undefined4 *)(param_1[7] + 8) = param_1[7];
  local_4 = 0xffffffff;
  FUN_100272f0(param_1 + 1);
  ExceptionList = local_c;
  return;
}

undefined4 * __fastcall FUN_100273f0(undefined4 *param_1)

{
  *param_1 = KeyValList::vftable;
  FUN_10026b40(param_1 + 1);
  return param_1;
}

undefined4 * __thiscall FUN_10027420(void *this,byte param_1)

{
  FUN_10027370((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

undefined4 * __thiscall FUN_10027440(void *this,uint param_1)

{
  FUN_1002e5d0(this,param_1);
  *(undefined ***)this = MetaVals::vftable;
  return (undefined4 *)this;
}

void __fastcall FUN_10027460(undefined4 *param_1)

{
  *param_1 = MetaVals::vftable;
  FUN_1002e680(param_1);
  return;
}

int * __thiscall FUN_10027470(void *this,int param_1)

{
  FUN_10022450((int)this);
                    // WARNING: Load size is inaccurate
  (**(code **)(*this + 0xc))();
  FUN_10027020((void *)((int)this + 0xd0),param_1 + 0xd0);
  FUN_10022460((int)this);
  return (int *)this;
}

void __thiscall FUN_100274b0(void *this,int param_1)

{
  FUN_10022450((int)this);
  FUN_100271a0((void *)((int)this + 0xd0),param_1 + 0xd0);
  FUN_10022460((int)this);
  return;
}

undefined4 FUN_100274e0(void)

{
  return 0x4000;
}

undefined * FUN_100274f0(void)

{
  return PTR_s_MetaVals_10195234;
}

undefined * FUN_10027500(void)

{
  return PTR_DAT_10195238;
}

int __fastcall FUN_10027510(int *param_1)

{
  int iVar1;
  int *local_4;
  
  iVar1 = 0x11;
  local_4 = param_1;
  (**(code **)(*param_1 + 0xe4))(0x11,&local_4);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return iVar1;
}

undefined4 __thiscall FUN_10027530(void *this,uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((~((byte)(param_1 >> 0xb) & 1) & 1) == 0) {
    return 0xfffffffc;
  }
  *(undefined1 *)((int)this + 0xfc) = 1;
  uVar1 = FUN_10026f20((void *)((int)this + 0xd0),param_1,param_2);
  return uVar1;
}

undefined4 __thiscall FUN_10027570(void *this,uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((~((byte)(param_1 >> 0xb) & 1) & 1) == 0) {
    return 0xfffffffc;
  }
  *(undefined1 *)((int)this + 0xfc) = 1;
  uVar1 = FUN_10026f60((void *)((int)this + 0xd0),param_1,param_2);
  return uVar1;
}

undefined4 __thiscall FUN_100275b0(void *this,uint param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((~((byte)(param_1 >> 0xb) & 1) & 1) == 0) {
    return 0xfffffffc;
  }
  uVar1 = FUN_10026490((void *)((int)this + 0xd0),param_1,param_2);
  return uVar1;
}

undefined4 __thiscall FUN_100275e0(void *this,uint param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((~((byte)(param_1 >> 0xb) & 1) & 1) == 0) {
    return 0xfffffffc;
  }
  uVar1 = FUN_100264c0((void *)((int)this + 0xd0),param_1,param_2);
  return uVar1;
}

undefined4 __thiscall FUN_10027610(void *this,uint param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  
  if ((~((byte)(param_1 >> 0xb) & 1) & 1) == 0) {
    return 0xfffffffc;
  }
  uVar1 = FUN_100264f0((void *)((int)this + 0xd0),param_1,param_2);
  return uVar1;
}

undefined4 __thiscall FUN_10027640(void *this,uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (-1 < (char)(param_1 >> 4)) {
    return 0xfffffffc;
  }
  *(undefined1 *)((int)this + 0xfc) = 1;
  uVar1 = FUN_10026f20((void *)((int)this + 0xd0),param_1,param_2);
  return uVar1;
}

undefined4 __thiscall FUN_10027670(void *this,uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (-1 < (char)(param_1 >> 4)) {
    return 0xfffffffc;
  }
  *(undefined1 *)((int)this + 0xfc) = 1;
  uVar1 = FUN_10026f60((void *)((int)this + 0xd0),param_1,param_2);
  return uVar1;
}

undefined4 __thiscall FUN_100276b0(int param_1,uint param_2,undefined8 param_3)

{
  undefined4 uVar1;
  
  if (-1 < (char)(param_2 >> 4)) {
    return 0xfffffffc;
  }
  *(undefined1 *)(param_1 + 0xfc) = 1;
  uVar1 = FUN_10026fa0(param_1 + 0xd0,param_2,param_3);
  return uVar1;
}

undefined4 __thiscall FUN_100276f0(void *this,uint param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (-1 < (char)(param_1 >> 4)) {
    return 0xfffffffc;
  }
  uVar1 = FUN_10026490((void *)((int)this + 0xd0),param_1,param_2);
  return uVar1;
}

undefined4 __thiscall FUN_10027720(void *this,uint param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (-1 < (char)(param_1 >> 4)) {
    return 0xfffffffc;
  }
  uVar1 = FUN_100264c0((void *)((int)this + 0xd0),param_1,param_2);
  return uVar1;
}

undefined4 __thiscall FUN_10027750(void *this,uint param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  
  if (-1 < (char)(param_1 >> 4)) {
    return 0xfffffffc;
  }
  uVar1 = FUN_100264f0((void *)((int)this + 0xd0),param_1,param_2);
  return uVar1;
}

undefined4 __cdecl FUN_10027780(undefined4 param_1)

{
  switch(param_1) {
  case 1:
    return 0x4000;
  case 2:
    return 0x2000;
  default:
    return 0x1000;
  case 8:
    return 0x800;
  case 0x10:
    return 0x400;
  }
}

undefined4 * __thiscall FUN_100278c0(void *this,byte param_1)

{
  FUN_10027460((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

int __fastcall FUN_100278e0(int *param_1)

{
  int **ppiVar1;
  int *local_4;
  
  local_4 = param_1;
  FUN_10022450((int)param_1);
  ppiVar1 = &local_4;
  (**(code **)(*param_1 + 0xe4))(0x11);
  if ((int)ppiVar1 < 0) {
    ppiVar1 = (int **)0x0;
  }
  FUN_10027530(param_1,0x11,(int)ppiVar1 + 1);
  FUN_10022460((int)param_1);
  return (int)ppiVar1 + 1;
}

undefined4 * __thiscall FUN_10027930(void *this,uint param_1)

{
  int iVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fc58;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_1002c6a0((undefined4 *)this);
  local_4 = 0;
  *(undefined ***)this = MiniSBeam::vftable;
  iVar1 = FUN_10034298(-(uint)((int)((ulonglong)param_1 * 8 >> 0x20) != 0) |
                       (uint)((ulonglong)param_1 * 8));
  *(int *)((int)this + 0xcc) = iVar1;
  *(int *)((int)this + 0x14) = iVar1;
  if (iVar1 != 0) {
    *(uint *)((int)this + 0xd0) = param_1;
  }
  ExceptionList = puStack_8;
  return (undefined4 *)this;
}

void __thiscall FUN_100279b0(void *this,undefined4 param_1,void *param_2)

{
  *(undefined ***)this = MiniSBeam::vftable;
  FUN_1002c6d0(this,param_1,param_2);
  return;
}

undefined4 FUN_100279c0(void)

{
  return 0x200;
}

undefined * FUN_100279d0(void)

{
  return PTR_s_MiniSBeam_10195278;
}

undefined * FUN_100279e0(void)

{
  return PTR_s_MiniSbm_1019527c;
}

void __fastcall thunk_FUN_1002c760(void *param_1)

{
  FUN_10022ba0(param_1);
  *(undefined8 *)((int)param_1 + 0xd8) = 0;
  *(undefined8 *)((int)param_1 + 0xe0) = 0;
  return;
}

undefined4 __fastcall FUN_10027a00(int param_1)

{
  return *(undefined4 *)(param_1 + 0xd0);
}

undefined4 * __fastcall FUN_10027a40(undefined4 *param_1)

{
  FUN_10022170(param_1,"MiniSBeamAllocator");
  *param_1 = MiniSBeamAllocator::vftable;
  return param_1;
}

int * __thiscall FUN_10027a60(void *this,uint param_1)

{
  int *piVar1;
  uint uVar2;
  void *this_00;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_1004fdbb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar1 = FUN_10021fa0((int)this);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))();
    if (param_1 <= uVar2) goto LAB_10027ae4;
    FUN_10021d00(piVar1);
    FUN_10022040((int)this);
  }
  this_00 = operator_new(0xe8);
  uStack_4 = 0;
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_10027930(this_00,param_1);
  }
  uStack_4 = 0xffffffff;
  FUN_10022280(this,piVar1);
  if (piVar1 == (int *)0x0) {
    ExceptionList = pvStack_c;
    return (int *)0x0;
  }
LAB_10027ae4:
  FUN_10022490((int)piVar1);
  ExceptionList = pvStack_c;
  return piVar1;
}

void * __thiscall FUN_10027b10(void *this,undefined4 param_1,undefined4 param_2,byte param_3)

{
  undefined4 unaff_ESI;
  void *unaff_retaddr;
  
  FUN_100279b0(this,unaff_ESI,unaff_retaddr);
  if ((param_3 & 1) != 0) {
    FUN_100355b4(this);
  }
  return this;
}

undefined4 * __thiscall FUN_10027b30(void *this,int param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fe48;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_10022a40((undefined4 *)this);
  lVar1 = (ulonglong)(param_1 + 2) * 4;
  local_4 = 0;
  *(undefined ***)this = RawEncoder::vftable;
  *(undefined4 *)((int)this + 0xcc) = 0;
  *(undefined4 *)((int)this + 0xd0) = 0;
  *(undefined4 *)((int)this + 0xd4) = 0;
  *(undefined4 *)((int)this + 0xd8) = 0;
  puVar2 = (undefined4 *)FUN_10034298(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  *(undefined4 **)((int)this + 0xcc) = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *(undefined4 **)((int)this + 0xd0) = puVar2 + 1;
    *puVar2 = 0xabcd1234;
    *(undefined4 *)(*(int *)((int)this + 0xcc) + 4 + param_1 * 4) = 0xabcd1234;
  }
  *(int *)((int)this + 0x14) = *(int *)((int)this + 0xd0);
  if (*(int *)((int)this + 0xd0) != 0) {
    *(int *)((int)this + 0xd4) = param_1;
  }
  ExceptionList = puStack_8;
  return (undefined4 *)this;
}

void __thiscall FUN_10027bf0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0xd8) = param_1;
  return;
}

void __fastcall FUN_10027c00(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004fe48;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = RawEncoder::vftable;
  local_4 = 0;
  puVar1 = param_1;
  if (*(int *)param_1[0x33] != -0x5432edcc) {
    FUN_10021c10();
  }
  if (*(int *)(param_1[0x33] + 4 + param_1[0x35] * 4) != -0x5432edcc) {
    FUN_10021c10();
  }
  FUN_100355e9((void *)param_1[0x33]);
  FUN_100227f0(param_1,puVar1);
  ExceptionList = puStack_8;
  return;
}

undefined * FUN_10027ca0(void)

{
  return PTR_s_Encoder_101952d4;
}

undefined * FUN_10027cb0(void)

{
  return PTR_DAT_101952d8;
}

undefined4 FUN_10027cc0(void)

{
  return 4;
}

undefined4 __fastcall FUN_10027cd0(int param_1)

{
  return *(undefined4 *)(param_1 + 0xd4);
}

undefined4 * __fastcall FUN_10027d30(undefined4 *param_1)

{
  FUN_10022170(param_1,"RawEncoderAllocator");
  *param_1 = RawEncoderAllocator::vftable;
  return param_1;
}

int * __thiscall FUN_10027d50(void *this,uint param_1)

{
  int *piVar1;
  uint uVar2;
  void *this_00;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_1004fdbb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar1 = FUN_10021fa0((int)this);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))();
    if (param_1 <= uVar2) goto LAB_10027dd4;
    FUN_10021d00(piVar1);
    FUN_10022040((int)this);
  }
  this_00 = operator_new(0xdc);
  uStack_4 = 0;
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_10027b30(this_00,param_1);
  }
  uStack_4 = 0xffffffff;
  FUN_10022280(this,piVar1);
  if (piVar1 == (int *)0x0) {
    ExceptionList = pvStack_c;
    return (int *)0x0;
  }
LAB_10027dd4:
  FUN_10022490((int)piVar1);
  ExceptionList = pvStack_c;
  return piVar1;
}

undefined4 * __thiscall FUN_10027e00(void *this,byte param_1)

{
  FUN_10027c00((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

int __thiscall FUN_10027e20(void *this,int *param_1)

{
  FUN_10022ee0(this,param_1,0);
  FUN_10022de0(param_1,*(undefined4 *)((int)this + 0xd0),*(int *)((int)this + 0x18) * 4);
  return -(uint)((*(byte *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) & 6) != 0);
}

undefined4 * __thiscall FUN_10028040(void *this,uint param_1)

{
  int iVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fe48;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_10022a40((undefined4 *)this);
  local_4 = 0;
  *(undefined ***)this = RawHwData::vftable;
  *(undefined4 *)((int)this + 0xcc) = 0;
  *(undefined4 *)((int)this + 0xd0) = 0;
  *(undefined4 *)((int)this + 0xd4) = 0;
  *(undefined4 *)((int)this + 0xd8) = 1;
  iVar1 = FUN_10034298(-(uint)((int)((ulonglong)param_1 * 4 >> 0x20) != 0) |
                       (uint)((ulonglong)param_1 * 4));
  *(int *)((int)this + 0xcc) = iVar1;
  *(int *)((int)this + 0x14) = iVar1;
  if (iVar1 != 0) {
    *(uint *)((int)this + 0xd0) = param_1;
  }
  ExceptionList = puStack_8;
  return (undefined4 *)this;
}

void __thiscall FUN_100280e0(void *this,undefined4 param_1,void *param_2)

{
  *(undefined ***)this = RawHwData::vftable;
  FUN_100355e9(*(void **)((int)this + 0xcc));
  FUN_100227f0(this,param_2);
  return;
}

undefined * FUN_10028100(void)

{
  return PTR_s_RawHwData_10195320;
}

undefined * FUN_10028110(void)

{
  return PTR_DAT_10195324;
}

undefined4 __thiscall FUN_10028150(void *this,undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)((int)this + 0xd0);
  if (param_2 < *(int *)((int)this + 0xd0)) {
    iVar3 = param_2;
  }
  puVar1 = *(undefined4 **)((int)this + 0xcc);
  for (iVar2 = iVar3; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  *(int *)((int)this + 0x18) = iVar3;
  return 0;
}

void __thiscall FUN_10028190(void *this,undefined4 param_1,undefined4 param_2)

{
  *(undefined4 *)((int)this + 0xd4) = param_1;
  *(undefined4 *)((int)this + 0xd8) = param_2;
  return;
}

undefined4 * __fastcall FUN_100281b0(undefined4 *param_1)

{
  FUN_10022170(param_1,"RawHwDataAllocator");
  *param_1 = RawHwDataAllocator::vftable;
  return param_1;
}

void * __thiscall FUN_10028280(void *this,byte param_1)

{
  undefined4 unaff_ESI;
  void *unaff_retaddr;
  
  FUN_100280e0(this,unaff_ESI,unaff_retaddr);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return this;
}

int __thiscall FUN_100282a0(void *this,int param_1)

{
  int iVar1;
  int extraout_ECX;
  
  iVar1 = FUN_1002f550((int)this);
  return *(int *)(*(int *)(extraout_ECX + 0xcc) + (iVar1 + param_1 * 2) * 4) >> 8;
}

int __thiscall FUN_100282c0(void *this,int param_1)

{
  int iVar1;
  int extraout_ECX;
  
  iVar1 = FUN_10027cd0((int)this);
  return *(int *)(*(int *)(extraout_ECX + 0xcc) + (iVar1 + param_1 * 2) * 4) >> 8;
}

float10 FUN_1002b910(void)

{
  LARGE_INTEGER LStack_10;
  LARGE_INTEGER local_8;
  
  QueryPerformanceCounter(&local_8);
  Sleep(100);
  QueryPerformanceCounter(&LStack_10);
  return (float10)(float)(((float10)CONCAT44(LStack_10.s.HighPart,LStack_10.s.LowPart) -
                          (float10)(longlong)local_8) / (float10)100.0);
}

undefined4 * __thiscall FUN_1002b950(void *this,uint param_1)

{
  int iVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fe48;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_10022a40((undefined4 *)this);
  local_4 = 0;
  *(undefined ***)this = RawIgram::vftable;
  *(undefined4 *)((int)this + 0xcc) = 0;
  *(undefined4 *)((int)this + 0xd0) = 0;
  iVar1 = FUN_10034298(-(uint)((int)((ulonglong)param_1 * 4 >> 0x20) != 0) |
                       (uint)((ulonglong)param_1 * 4));
  *(int *)((int)this + 0xcc) = iVar1;
  *(int *)((int)this + 0x14) = iVar1;
  if (iVar1 != 0) {
    *(uint *)((int)this + 0xd0) = param_1;
  }
  ExceptionList = puStack_8;
  return (undefined4 *)this;
}

void __thiscall FUN_1002b9e0(void *this,undefined4 param_1,void *param_2)

{
  *(undefined ***)this = RawIgram::vftable;
  FUN_100355e9(*(void **)((int)this + 0xcc));
  FUN_100227f0(this,param_2);
  return;
}

undefined4 FUN_1002ba00(void)

{
  return 2;
}

undefined * FUN_1002ba10(void)

{
  return PTR_s_RawIgram_101953c4;
}

undefined * FUN_1002ba20(void)

{
  return PTR_s_RawIgm_101953c8;
}

undefined4 * __fastcall FUN_1002baa0(undefined4 *param_1)

{
  FUN_10022170(param_1,"RawIgramAllocator");
  *param_1 = RawIgramAllocator::vftable;
  return param_1;
}

int * __thiscall FUN_1002bac0(void *this,uint param_1)

{
  int *piVar1;
  uint uVar2;
  void *this_00;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_1004fdbb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar1 = FUN_10021fa0((int)this);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))();
    if (param_1 <= uVar2) goto LAB_1002bb44;
    FUN_10021d00(piVar1);
    FUN_10022040((int)this);
  }
  this_00 = operator_new(0xd4);
  uStack_4 = 0;
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_1002b950(this_00,param_1);
  }
  uStack_4 = 0xffffffff;
  FUN_10022280(this,piVar1);
  if (piVar1 == (int *)0x0) {
    ExceptionList = pvStack_c;
    return (int *)0x0;
  }
LAB_1002bb44:
  FUN_10022490((int)piVar1);
  ExceptionList = pvStack_c;
  return piVar1;
}

void * __thiscall FUN_1002bb70(void *this,byte param_1)

{
  undefined4 unaff_ESI;
  void *unaff_retaddr;
  
  FUN_1002b9e0(this,unaff_ESI,unaff_retaddr);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return this;
}

int __thiscall FUN_1002bd70(void *this,int *param_1)

{
  FUN_10022ee0(this,param_1,0);
  FUN_10022de0(param_1,*(undefined4 *)((int)this + 0xcc),*(int *)((int)this + 0x18) * 4);
  return -(uint)((*(byte *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) & 6) != 0);
}

undefined4 * __thiscall FUN_1002c0f0(void *this,int param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fe48;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_10022a40((undefined4 *)this);
  lVar1 = (ulonglong)(param_1 + 2) * 4;
  local_4 = 0;
  *(undefined ***)this = RawLaser::vftable;
  *(undefined4 *)((int)this + 0xcc) = 0;
  *(undefined4 *)((int)this + 0xd0) = 0;
  *(undefined4 *)((int)this + 0xd4) = 0;
  puVar2 = (undefined4 *)FUN_10034298(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  *(undefined4 **)((int)this + 0xcc) = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *(undefined4 **)((int)this + 0xd0) = puVar2 + 1;
    *puVar2 = 0xabcd1234;
    *(undefined4 *)(*(int *)((int)this + 0xcc) + 4 + param_1 * 4) = 0xabcd1234;
  }
  *(int *)((int)this + 0x14) = *(int *)((int)this + 0xd0);
  if (*(int *)((int)this + 0xd0) != 0) {
    *(int *)((int)this + 0xd4) = param_1;
  }
  ExceptionList = puStack_8;
  return (undefined4 *)this;
}

void __fastcall FUN_1002c1b0(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004fe48;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = RawLaser::vftable;
  local_4 = 0;
  puVar1 = param_1;
  if (*(int *)param_1[0x33] != -0x5432edcc) {
    FUN_10021c10();
  }
  if (*(int *)(param_1[0x33] + 4 + param_1[0x35] * 4) != -0x5432edcc) {
    FUN_10021c10();
  }
  FUN_100355e9((void *)param_1[0x33]);
  FUN_100227f0(param_1,puVar1);
  ExceptionList = puStack_8;
  return;
}

undefined * FUN_1002c250(void)

{
  return PTR_s_Laser_10195408;
}

undefined * FUN_1002c260(void)

{
  return PTR_DAT_1019540c;
}

undefined4 * __fastcall FUN_1002c2a0(undefined4 *param_1)

{
  FUN_10022170(param_1,"RawLaserAllocator");
  *param_1 = RawLaserAllocator::vftable;
  return param_1;
}

int * __thiscall FUN_1002c2c0(void *this,uint param_1)

{
  int *piVar1;
  uint uVar2;
  void *this_00;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_1004fdbb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar1 = FUN_10021fa0((int)this);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))();
    if (param_1 <= uVar2) goto LAB_1002c344;
    FUN_10021d00(piVar1);
    FUN_10022040((int)this);
  }
  this_00 = operator_new(0xf0);
  uStack_4 = 0;
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_1002c0f0(this_00,param_1);
  }
  uStack_4 = 0xffffffff;
  FUN_10022280(this,piVar1);
  if (piVar1 == (int *)0x0) {
    ExceptionList = pvStack_c;
    return (int *)0x0;
  }
LAB_1002c344:
  FUN_10022490((int)piVar1);
  ExceptionList = pvStack_c;
  return piVar1;
}

undefined4 * __thiscall FUN_1002c370(void *this,byte param_1)

{
  FUN_1002c1b0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

undefined4 * __thiscall FUN_1002c600(void *this,uint param_1)

{
  int iVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fe48;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_10022a40((undefined4 *)this);
  *(undefined8 *)((int)this + 0xd8) = 0;
  *(undefined8 *)((int)this + 0xe0) = 0;
  local_4 = 0;
  *(undefined ***)this = SBeam::vftable;
  *(undefined4 *)((int)this + 0xcc) = 0;
  *(undefined4 *)((int)this + 0xd0) = 0;
  iVar1 = FUN_10034298(-(uint)((int)((ulonglong)param_1 * 8 >> 0x20) != 0) |
                       (uint)((ulonglong)param_1 * 8));
  *(int *)((int)this + 0xcc) = iVar1;
  *(int *)((int)this + 0x14) = iVar1;
  if (iVar1 != 0) {
    *(uint *)((int)this + 0xd0) = param_1;
  }
  ExceptionList = puStack_8;
  return (undefined4 *)this;
}

undefined4 * __fastcall FUN_1002c6a0(undefined4 *param_1)

{
  FUN_10022a40(param_1);
  *(undefined8 *)(param_1 + 0x36) = 0;
  param_1[0x33] = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  param_1[0x34] = 0;
  *param_1 = SBeam::vftable;
  return param_1;
}

void __thiscall FUN_1002c6d0(void *this,undefined4 param_1,void *param_2)

{
  *(undefined ***)this = SBeam::vftable;
  FUN_100355e9(*(void **)((int)this + 0xcc));
  FUN_100227f0(this,param_2);
  return;
}

undefined * FUN_1002c6f0(void)

{
  return PTR_s_SBeam_1019544c;
}

undefined * FUN_1002c700(void)

{
  return PTR_DAT_10195450;
}

void __fastcall FUN_1002c760(void *param_1)

{
  FUN_10022ba0(param_1);
  *(undefined8 *)((int)param_1 + 0xd8) = 0;
  *(undefined8 *)((int)param_1 + 0xe0) = 0;
  return;
}

undefined4 FUN_1002c780(void)

{
  return 8;
}

void __thiscall FUN_1002c790(void *this,undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *(undefined8 *)((int)this + 0xd8);
  *param_2 = *(undefined8 *)((int)this + 0xe0);
  return;
}

uint __fastcall FUN_1002c7b0(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar3 = FUN_100362d0(param_1,param_2);
  uVar2 = (uint)uVar3;
  if (uVar1 <= uVar2) {
    uVar2 = uVar1 - 1;
  }
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  return uVar2;
}

float10 __fastcall FUN_1002c810(int *param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 in_stack_00000000;
  int iStack_10;
  int *local_4;
  
  local_4 = param_1;
  (**(code **)(*param_1 + 0x40))();
  iVar2 = (**(code **)(*param_1 + 0xc4))();
  iStack_10 = (int)((ulonglong)in_stack_00000000 >> 0x20);
  uVar1 = *(undefined8 *)(iStack_10 + iVar2 * 8);
  local_4 = (int *)((ulonglong)uVar1 >> 0x20);
  (**(code **)(*param_1 + 0x54))(0xffffffff);
  return (float10)(double)CONCAT44((int)uVar1,&local_4);
}

float10 __fastcall FUN_1002c860(int *param_1)

{
  double dVar1;
  int iVar2;
  int iVar3;
  undefined8 in_stack_00000000;
  int iStack_20;
  undefined4 uStack_1c;
  undefined1 local_c [4];
  undefined8 local_8;
  
  local_8 = 0;
  (**(code **)(*param_1 + 0x40))(local_c);
  iStack_20 = (int)in_stack_00000000;
  uStack_1c = (undefined4)((ulonglong)in_stack_00000000 >> 0x20);
  iVar2 = (**(code **)(*param_1 + 0xc4))();
  iVar3 = (**(code **)(*param_1 + 0xc4))(in_stack_00000000);
  dVar1 = *(double *)(iStack_20 + iVar3 * 8);
  if (dVar1 != 0.0) {
    uStack_1c = SUB84(*(double *)(iStack_20 + iVar2 * 8) / dVar1,0);
  }
  (**(code **)(*param_1 + 0x54))(0xffffffff);
  return (float10)(double)CONCAT44(uStack_1c,iStack_20);
}

undefined4 * __fastcall FUN_1002c8e0(undefined4 *param_1)

{
  FUN_10022170(param_1,"SBeamAllocator");
  *param_1 = SBeamAllocator::vftable;
  return param_1;
}

int * __thiscall FUN_1002c900(void *this,uint param_1)

{
  int *piVar1;
  uint uVar2;
  void *this_00;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_1004fdbb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar1 = FUN_10021fa0((int)this);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))();
    if (param_1 <= uVar2) goto LAB_1002c984;
    FUN_10021d00(piVar1);
    FUN_10022040((int)this);
  }
  this_00 = operator_new(0xe8);
  uStack_4 = 0;
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_1002c600(this_00,param_1);
  }
  uStack_4 = 0xffffffff;
  FUN_10022280(this,piVar1);
  if (piVar1 == (int *)0x0) {
    ExceptionList = pvStack_c;
    return (int *)0x0;
  }
LAB_1002c984:
  FUN_10022490((int)piVar1);
  ExceptionList = pvStack_c;
  return piVar1;
}

void * __thiscall FUN_1002c9b0(void *this,byte param_1)

{
  undefined4 unaff_ESI;
  void *unaff_retaddr;
  
  FUN_1002c6d0(this,unaff_ESI,unaff_retaddr);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return this;
}

undefined4 * __thiscall FUN_1002cf30(void *this,int param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fe48;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_10022a40((undefined4 *)this);
  lVar1 = (ulonglong)(param_1 + 2) * 4;
  local_4 = 0;
  *(undefined ***)this = ScanInfo::vftable;
  *(undefined4 *)((int)this + 0xcc) = 0;
  *(undefined4 *)((int)this + 0xd0) = 0;
  *(undefined4 *)((int)this + 0xd4) = 0;
  *(undefined4 *)((int)this + 0xd8) = 0;
  *(undefined4 *)((int)this + 0xdc) = 0;
  *(undefined4 *)((int)this + 0xe0) = 0;
  *(undefined4 *)((int)this + 0xe4) = 1;
  puVar2 = (undefined4 *)FUN_10034298(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  *(undefined4 **)((int)this + 0xcc) = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *(undefined4 **)((int)this + 0xd0) = puVar2 + 1;
    *puVar2 = 0xabcd1234;
    *(undefined4 *)(*(int *)((int)this + 0xcc) + 4 + param_1 * 4) = 0xabcd1234;
  }
  *(int *)((int)this + 0x14) = *(int *)((int)this + 0xd0);
  if (*(int *)((int)this + 0xd0) != 0) {
    *(int *)((int)this + 0xd4) = param_1;
  }
  ExceptionList = puStack_8;
  return (undefined4 *)this;
}

void __fastcall FUN_1002d000(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004fe48;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = ScanInfo::vftable;
  local_4 = 0;
  puVar1 = param_1;
  if (*(int *)param_1[0x33] != -0x5432edcc) {
    FUN_10021c10();
  }
  if (*(int *)(param_1[0x33] + 4 + param_1[0x35] * 4) != -0x5432edcc) {
    FUN_10021c10();
  }
  FUN_100355e9((void *)param_1[0x33]);
  FUN_100227f0(param_1,puVar1);
  ExceptionList = puStack_8;
  return;
}

undefined4 FUN_1002d0a0(void)

{
  return 0x8000;
}

undefined * FUN_1002d0b0(void)

{
  return PTR_s_ScanInfo_10195478;
}

undefined * FUN_1002d0c0(void)

{
  return PTR_s_SInf_1019547c;
}

undefined1 FUN_1002d0d0(void)

{
  return 1;
}

void __fastcall FUN_1002d0e0(void *param_1)

{
  FUN_10022ba0(param_1);
  *(undefined4 *)((int)param_1 + 0xd8) = 0;
  *(undefined4 *)((int)param_1 + 0xdc) = 0;
  if (*(int **)((int)param_1 + 0xe0) != (int *)0x0) {
    (**(code **)(**(int **)((int)param_1 + 0xe0) + 4))();
  }
  *(undefined4 *)((int)param_1 + 0xe0) = 0;
  return;
}

undefined4 __fastcall FUN_1002d120(int param_1)

{
  undefined4 uVar1;
  undefined4 local_4;
  
  uVar1 = 0;
  local_4 = 0;
  if (*(int *)(param_1 + 0xe0) != 0) {
    uVar1 = 0x901;
    (**(code **)(**(int **)(param_1 + 0xe0) + 0xf0))(0x901,&local_4);
  }
  return uVar1;
}

undefined4 __fastcall FUN_1002d150(int param_1)

{
  undefined4 uVar1;
  undefined4 local_4;
  
  uVar1 = 0;
  local_4 = 0;
  if (*(int *)(param_1 + 0xe0) != 0) {
    uVar1 = 0x821;
    (**(code **)(**(int **)(param_1 + 0xe0) + 0xf0))(0x821,&local_4);
  }
  return uVar1;
}

undefined4 __fastcall FUN_1002d180(int param_1)

{
  undefined4 uVar1;
  int local_4;
  
  uVar1 = 0x31;
  local_4 = param_1;
  (**(code **)(**(int **)(param_1 + 0xe0) + 0xe4))(0x31,&local_4);
  return uVar1;
}

undefined4 __fastcall FUN_1002d1a0(int param_1)

{
  undefined4 uVar1;
  int local_4;
  
  uVar1 = 0x41;
  local_4 = param_1;
  (**(code **)(**(int **)(param_1 + 0xe0) + 0xe4))(0x41,&local_4);
  return uVar1;
}

undefined4 __fastcall FUN_1002d1c0(int param_1)

{
  undefined4 uVar1;
  int local_4;
  
  uVar1 = 0x51;
  local_4 = param_1;
  (**(code **)(**(int **)(param_1 + 0xe0) + 0xe4))(0x51,&local_4);
  return uVar1;
}

void FUN_1002d1e0(void)

{
  return;
}

void __thiscall FUN_1002d1f0(void *this,int *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 unaff_ESI;
  
  piVar1 = param_1;
  if ((param_1 != (int *)0x0) && (*(int *)((int)this + 0xe0) != 0)) {
    (**(code **)(**(int **)((int)this + 0xe0) + 0xf0))(0x901,&param_1);
    *piVar1 = (int)param_1;
  }
  piVar1 = param_2;
  if ((param_2 != (int *)0x0) && (*(int *)((int)this + 0xe0) != 0)) {
    (**(code **)(**(int **)((int)this + 0xe0) + 0xf0))(0x911,&param_1);
    *piVar1 = (int)param_1;
  }
  puVar2 = param_3;
  if ((param_3 != (undefined4 *)0x0) && (*(int *)((int)this + 0xe0) != 0)) {
    (**(code **)(**(int **)((int)this + 0xe0) + 0xe4))(0x141,&param_1);
    *puVar2 = unaff_ESI;
  }
  return;
}

undefined4 __fastcall FUN_1002d290(int param_1)

{
  double dVar1;
  int iVar2;
  undefined4 uVar3;
  uint unaff_ESI;
  int *unaff_retaddr;
  undefined8 *puStack_14;
  undefined8 local_8;
  
  local_8 = 0;
  puStack_14 = &local_8;
  iVar2 = (**(code **)(**(int **)(param_1 + 0xe0) + 0xd4))(0x2815);
  if ((iVar2 == 0) &&
     (iVar2 = (**(code **)(**(int **)(param_1 + 0xe0) + 0xcc))(0x2821,&puStack_14), iVar2 == 0)) {
    dVar1 = ABS((double)(ulonglong)unaff_ESI);
    uVar3 = 0;
  }
  else {
    dVar1 = (double)(ulonglong)unaff_ESI;
    uVar3 = 0xffffffff;
  }
  if (local_8._4_4_ != (double *)0x0) {
    *local_8._4_4_ = dVar1;
  }
  if (unaff_retaddr != (int *)0x0) {
    *unaff_retaddr = (int)puStack_14;
  }
  return uVar3;
}

int __fastcall FUN_1002d320(int param_1)

{
  int iVar1;
  uint3 uVar2;
  int local_4;
  
  local_4 = param_1;
  iVar1 = (**(code **)(**(int **)(param_1 + 0xe0) + 0xcc))(0x5811,&local_4);
  uVar2 = (uint3)((uint)iVar1 >> 8);
  if (iVar1 != 0) {
    return (uint)uVar2 << 8;
  }
  return CONCAT31(uVar2,1);
}

undefined4 __fastcall FUN_1002d350(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_4;
  
  uVar2 = 0;
  local_4 = param_1;
  iVar1 = (**(code **)(**(int **)(param_1 + 0xe0) + 0xd0))(0x1984);
  if (iVar1 != 0) {
    uVar2 = 0xffffffff;
  }
  if (local_4 != 0) {
    *(int **)local_4 = &local_4;
  }
  return uVar2;
}

undefined4 __fastcall FUN_1002d390(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_EDI;
  undefined4 uVar3;
  int local_8;
  undefined4 *puStack_4;
  
  piVar2 = &local_8;
  uVar3 = 0;
  iVar1 = (**(code **)(**(int **)(param_1 + 0xe0) + 0xd0))(0x3924);
  if ((iVar1 != 0) &&
     (iVar1 = (**(code **)(**(int **)(param_1 + 0xe0) + 0xd0))(0x3154,&stack0xfffffff0), iVar1 != 0)
     ) {
    uVar3 = 0xffffffff;
  }
  if (puStack_4 != (undefined4 *)0x0) {
    *puStack_4 = unaff_EDI;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0xe0) + 0xcc))(0x31a1,&stack0xfffffff4);
  if (iVar1 != 0) {
    piVar2 = (int *)0x0;
  }
  if (local_8 != 0) {
    *(bool *)local_8 = piVar2 == (int *)0x0;
  }
  return uVar3;
}

undefined1 * __fastcall FUN_1002d850(int param_1)

{
  int iVar1;
  int local_4;
  
  local_4 = param_1;
  iVar1 = (**(code **)(**(int **)(param_1 + 0xe0) + 0xf0))(0x831);
  if (iVar1 == 0) {
    return (undefined1 *)&local_4;
  }
  FUN_10021c10();
  return (undefined1 *)0x1;
}

undefined1 * __fastcall FUN_1002d890(int param_1)

{
  int iVar1;
  int local_4;
  
  local_4 = param_1;
  iVar1 = (**(code **)(**(int **)(param_1 + 0xe0) + 0xf0))(0x8a1);
  if (iVar1 == 0) {
    return (undefined1 *)&local_4;
  }
  FID_conflict__wprintf("Warning: ScanInfo did not have a valid DataState\n");
  return (undefined1 *)0x20000000;
}

void __thiscall FUN_1002d8d0(void *this,undefined4 param_1)

{
  FUN_10027640(*(void **)((int)this + 0xe0),0x8a1,param_1);
  *(undefined4 *)((int)this + 0x1c) = param_1;
  return;
}

undefined1 * __fastcall FUN_1002d900(int param_1)

{
  int iVar1;
  int local_4;
  
  local_4 = param_1;
  iVar1 = (**(code **)(**(int **)(param_1 + 0xe0) + 0xf0))(0x8b1);
  if (iVar1 == 0) {
    return (undefined1 *)&local_4;
  }
  FID_conflict__wprintf("Warning: ScanInfo did not have a valid DataStateDetails\n");
  return (undefined1 *)0x0;
}

void __thiscall FUN_1002d940(void *this,undefined4 param_1)

{
  FUN_10027640(*(void **)((int)this + 0xe0),0x8b1,param_1);
  *(undefined4 *)((int)this + 0x20) = param_1;
  return;
}

undefined4 * __fastcall FUN_1002d970(undefined4 *param_1)

{
  FUN_10022170(param_1,"ScanInfoAllocator");
  *param_1 = ScanInfoAllocator::vftable;
  return param_1;
}

int * __thiscall FUN_1002d990(void *this,uint param_1)

{
  int *piVar1;
  uint uVar2;
  void *this_00;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_1004fdbb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar1 = FUN_10021fa0((int)this);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))();
    if (param_1 <= uVar2) goto LAB_1002da14;
    FUN_10021d00(piVar1);
    FUN_10022040((int)this);
  }
  this_00 = operator_new(0xe8);
  uStack_4 = 0;
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_1002cf30(this_00,param_1);
  }
  uStack_4 = 0xffffffff;
  FUN_10022280(this,piVar1);
  if (piVar1 == (int *)0x0) {
    ExceptionList = pvStack_c;
    return (int *)0x0;
  }
LAB_1002da14:
  FUN_10022490((int)piVar1);
  ExceptionList = pvStack_c;
  return piVar1;
}

undefined4 * __thiscall FUN_1002da40(void *this,byte param_1)

{
  FUN_1002d000((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

undefined4 __fastcall FUN_1002da60(int param_1)

{
  return *(undefined4 *)(param_1 + 0x60);
}

undefined4 __fastcall FUN_1002da70(int param_1)

{
  return *(undefined4 *)(param_1 + 0x80);
}

undefined4 __thiscall FUN_1002da80(void *this,uint param_1)

{
  undefined4 *puVar1;
  
  if (*(uint *)((int)this + 0xa0) <= param_1) {
    return 0;
  }
  puVar1 = (undefined4 *)FUN_10022730((void *)((int)this + 0x84),param_1);
  return *puVar1;
}

undefined4 __thiscall FUN_1002dab0(void *this,uint param_1)

{
  undefined4 *puVar1;
  
  if (*(uint *)((int)this + 0xc0) <= param_1) {
    return 0;
  }
  puVar1 = (undefined4 *)FUN_10022730((void *)((int)this + 0xa4),param_1);
  return *puVar1;
}

undefined4 __thiscall FUN_1002dae0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvStack_4;
  
  puVar1 = param_1;
  pvStack_4 = this;
  (**(code **)*param_1)();
  pvStack_4 = (void *)FUN_1001b5f0((int)puVar1);
  FUN_10015660((void *)((int)this + 0x44),&pvStack_4);
  FUN_10015660((void *)((int)this + 0x84),&param_1);
  return 0;
}

undefined4 __thiscall FUN_1002db30(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvStack_4;
  
  puVar1 = param_1;
  pvStack_4 = this;
  (**(code **)*param_1)();
  pvStack_4 = (void *)FUN_1001b5f0((int)puVar1);
  FUN_10015660((void *)((int)this + 100),&pvStack_4);
  FUN_10015660((void *)((int)this + 0xa4),&param_1);
  return 0;
}

undefined4 * __thiscall FUN_1002de10(void *this,uint param_1)

{
  int iVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fe48;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_10022a40((undefined4 *)this);
  local_4 = 0;
  *(undefined ***)this = Spectrum::vftable;
  *(undefined4 *)((int)this + 0xcc) = 0;
  *(undefined4 *)((int)this + 0xd0) = 0;
  *(undefined4 *)((int)this + 0xe8) = 1;
  iVar1 = FUN_10034298(-(uint)((int)((ulonglong)param_1 * 8 >> 0x20) != 0) |
                       (uint)((ulonglong)param_1 * 8));
  *(int *)((int)this + 0xcc) = iVar1;
  *(int *)((int)this + 0x14) = iVar1;
  if (iVar1 != 0) {
    *(uint *)((int)this + 0xd0) = param_1;
  }
  ExceptionList = puStack_8;
  return (undefined4 *)this;
}

void __thiscall FUN_1002deb0(void *this,undefined4 param_1,void *param_2)

{
  *(undefined ***)this = Spectrum::vftable;
  FUN_100355e9(*(void **)((int)this + 0xcc));
  FUN_100227f0(this,param_2);
  return;
}

undefined4 FUN_1002ded0(void)

{
  return 0x400;
}

undefined * FUN_1002dee0(void)

{
  return PTR_s_Spectrum_101954bc;
}

undefined * FUN_1002def0(void)

{
  return PTR_DAT_101954c0;
}

void __fastcall thunk_FUN_10022ba0(void *param_1)

{
  int extraout_ECX;
  
  FUN_10022450((int)param_1);
  *(undefined4 *)((int)param_1 + 0x2c) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x40) = 0xffffffff;
  FUN_10022480(param_1,1);
  *(undefined4 *)((int)param_1 + 0x18) = 0;
  *(undefined1 *)((int)param_1 + 0x38) = 0;
  *(undefined4 *)((int)param_1 + 0x24) = 1;
  FUN_100228c0(extraout_ECX);
  if (*(int *)((int)param_1 + 0x28) != 1) {
    *(undefined4 *)((int)param_1 + 0x28) = 1;
  }
  FUN_10022460((int)param_1);
  return;
}

void __thiscall FUN_1002df10(void *this,undefined8 param_1,undefined8 param_2)

{
  *(undefined8 *)((int)this + 0xd8) = param_1;
  *(undefined8 *)((int)this + 0xe0) = param_2;
  return;
}

void __thiscall FUN_1002df30(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0xe8) = param_1;
  return;
}

float10 __thiscall FUN_1002df40(int param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = *(int *)(param_1 + 0x18) + -1;
  fVar2 = (float10)iVar1;
  if (iVar1 < 0) {
    fVar2 = fVar2 + (float10)4294967296.0;
  }
  return (((float10)*(double *)(param_1 + 0xe0) - (float10)*(double *)(param_1 + 0xd8)) *
         (float10)param_2) / fVar2 + (float10)*(double *)(param_1 + 0xd8);
}

float10 __fastcall FUN_1002df70(int *param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 in_stack_00000000;
  int iStack_10;
  int *local_4;
  
  local_4 = param_1;
  (**(code **)(*param_1 + 0x40))();
  iVar2 = (**(code **)(*param_1 + 0xbc))();
  iStack_10 = (int)((ulonglong)in_stack_00000000 >> 0x20);
  uVar1 = *(undefined8 *)(iStack_10 + iVar2 * 8);
  local_4 = (int *)((ulonglong)uVar1 >> 0x20);
  (**(code **)(*param_1 + 0x54))(0xffffffff);
  return (float10)(double)CONCAT44((int)uVar1,&local_4);
}

float10 __fastcall FUN_1002dfc0(int *param_1)

{
  double dVar1;
  int iVar2;
  int iVar3;
  undefined8 in_stack_00000000;
  int iStack_20;
  undefined4 uStack_1c;
  undefined1 local_c [4];
  undefined8 local_8;
  
  local_8 = 0;
  (**(code **)(*param_1 + 0x40))(local_c);
  iStack_20 = (int)in_stack_00000000;
  uStack_1c = (undefined4)((ulonglong)in_stack_00000000 >> 0x20);
  iVar2 = (**(code **)(*param_1 + 0xbc))();
  iVar3 = (**(code **)(*param_1 + 0xbc))(in_stack_00000000);
  dVar1 = *(double *)(iStack_20 + iVar3 * 8);
  if (dVar1 != 0.0) {
    uStack_1c = SUB84(*(double *)(iStack_20 + iVar2 * 8) / dVar1,0);
  }
  (**(code **)(*param_1 + 0x54))(0xffffffff);
  return (float10)(double)CONCAT44(uStack_1c,iStack_20);
}

undefined4 * __fastcall FUN_1002e040(undefined4 *param_1)

{
  FUN_10022170(param_1,"SpectrumAllocator");
  *param_1 = SpectrumAllocator::vftable;
  return param_1;
}

int * __thiscall FUN_1002e060(void *this,uint param_1)

{
  int *piVar1;
  uint uVar2;
  void *this_00;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_1004fdbb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar1 = FUN_10021fa0((int)this);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))();
    if (param_1 <= uVar2) goto LAB_1002e0e4;
    FUN_10021d00(piVar1);
    FUN_10022040((int)this);
  }
  this_00 = operator_new(0xf0);
  uStack_4 = 0;
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_1002de10(this_00,param_1);
  }
  uStack_4 = 0xffffffff;
  FUN_10022280(this,piVar1);
  if (piVar1 == (int *)0x0) {
    ExceptionList = pvStack_c;
    return (int *)0x0;
  }
LAB_1002e0e4:
  FUN_10022490((int)piVar1);
  ExceptionList = pvStack_c;
  return piVar1;
}

void * __thiscall FUN_1002e110(void *this,byte param_1)

{
  undefined4 unaff_ESI;
  void *unaff_retaddr;
  
  FUN_1002deb0(this,unaff_ESI,unaff_retaddr);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return this;
}

int __thiscall FUN_1002e1c0(void *this,int *param_1)

{
  FUN_10022ee0(this,param_1,0);
  FUN_10022de0(param_1,*(undefined4 *)((int)this + 0xcc),*(int *)((int)this + 0x18) * 8);
  return -(uint)((*(byte *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) & 6) != 0);
}

undefined4 * __thiscall FUN_1002e5d0(void *this,uint param_1)

{
  int iVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fe14;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_10022a40((undefined4 *)this);
  local_4 = 0;
  *(undefined ***)this = ValList::vftable;
  DMutex::DMutex((DMutex *)((int)this + 0xcc));
  local_4._0_1_ = 1;
  FUN_100273f0((undefined4 *)((int)this + 0xd0));
  local_4 = CONCAT31(local_4._1_3_,2);
  *(undefined4 *)((int)this + 0xf4) = 0;
  *(undefined4 *)((int)this + 0xf8) = 0;
  *(undefined1 *)((int)this + 0xfc) = 1;
  *(undefined1 *)((int)this + 0xfd) = 1;
  iVar1 = FUN_10034298(param_1);
  *(int *)((int)this + 0xf4) = iVar1;
  *(int *)((int)this + 0x14) = iVar1;
  if (iVar1 != 0) {
    *(uint *)((int)this + 0xf8) = param_1;
  }
  ExceptionList = puStack_8;
  return (undefined4 *)this;
}

void __fastcall FUN_1002e680(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004fe36;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = ValList::vftable;
  local_4 = 1;
  puVar1 = param_1;
  FUN_100355e9((void *)param_1[0x3d]);
  FUN_10027370(param_1 + 0x34);
  DMutex::~DMutex((DMutex *)(param_1 + 0x33));
  FUN_100227f0(param_1,puVar1);
  ExceptionList = puStack_8;
  return;
}

void __fastcall FUN_1002e700(void *param_1)

{
  FUN_10022450((int)param_1);
  FUN_10026560((int)param_1 + 0xd0);
  *(undefined1 *)((int)param_1 + 0xfc) = 1;
  FUN_10022ba0(param_1);
  FUN_10022460((int)param_1);
  return;
}

undefined4 FUN_1002e730(void)

{
  return 1;
}

undefined4 __fastcall FUN_1002e740(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}

undefined4 __fastcall FUN_1002e750(int param_1)

{
  return *(undefined4 *)(param_1 + 0xf8);
}

void FUN_1002e790(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = param_2[7];
  param_1[1] = param_2[6];
  param_1[2] = param_2[5];
  param_1[3] = param_2[4];
  param_1[4] = param_2[3];
  param_1[5] = param_2[2];
  param_1[6] = param_2[1];
  param_1[7] = *param_2;
  return;
}

undefined4 __cdecl FUN_1002e7d0(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 7;
  uVar1 = 0;
  if ((uVar2 == 1) || (uVar2 == 4)) {
    uVar1 = 4;
  }
  else if (uVar2 == 5) {
    return 8;
  }
  return uVar1;
}

void __fastcall FUN_1002e990(int param_1)

{
  FUN_10026470(param_1 + 0xd0);
  return;
}

void __thiscall FUN_1002e9a0(void *this,undefined4 param_1,undefined4 param_2)

{
  *(undefined1 *)((int)this + 0xfc) = 1;
  FUN_10026f20((void *)((int)this + 0xd0),param_1,param_2);
  return;
}

void __thiscall FUN_1002e9c0(void *this,undefined4 param_1,undefined4 param_2)

{
  *(undefined1 *)((int)this + 0xfc) = 1;
  FUN_10026f60((void *)((int)this + 0xd0),param_1,param_2);
  return;
}

void __thiscall FUN_1002e9f0(int param_1,undefined4 param_2,undefined8 param_3)

{
  *(undefined1 *)(param_1 + 0xfc) = 1;
  FUN_10026fa0(param_1 + 0xd0,param_2,param_3);
  return;
}

void __thiscall FUN_1002ea20(void *this,undefined4 param_1,char *param_2)

{
  *(undefined1 *)((int)this + 0xfc) = 1;
  FUN_10026fe0((void *)((int)this + 0xd0),param_1,param_2);
  return;
}

void __thiscall FUN_1002ea40(void *this,undefined4 param_1,int *param_2)

{
  FUN_10026490((void *)((int)this + 0xd0),param_1,param_2);
  return;
}

void __thiscall FUN_1002ea50(void *this,undefined4 param_1,int *param_2)

{
  FUN_100264c0((void *)((int)this + 0xd0),param_1,param_2);
  return;
}

void __thiscall FUN_1002ea60(void *this,undefined4 param_1,undefined8 *param_2)

{
  FUN_100264f0((void *)((int)this + 0xd0),param_1,param_2);
  return;
}

void __thiscall FUN_1002ea70(void *this,undefined4 param_1,int *param_2)

{
  FUN_10026520((void *)((int)this + 0xd0),param_1,param_2);
  return;
}

void __cdecl FUN_1002ea80(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = param_2[3];
  param_1[1] = param_2[2];
  param_1[2] = param_2[1];
  param_1[3] = *param_2;
  return;
}

void __cdecl FUN_1002eab0(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = param_2[7];
  param_1[1] = param_2[6];
  param_1[2] = param_2[5];
  param_1[3] = param_2[4];
  param_1[4] = param_2[3];
  param_1[5] = param_2[2];
  param_1[6] = param_2[1];
  param_1[7] = *param_2;
  return;
}

undefined4 __thiscall FUN_1002eca0(void *this,uint param_1,char *param_2)

{
  undefined8 local_8;
  
  switch(param_1 & 7) {
  case 1:
    FUN_1002ea80((undefined1 *)&param_2,param_2);
    FUN_1002e9a0(this,param_1,param_2);
    return 0;
  default:
    return 0xfffffffe;
  case 4:
    FUN_1002ea80((undefined1 *)&param_2,param_2);
    FUN_1002e9c0(this,param_1,param_2);
    return 0;
  case 5:
    FUN_1002eab0((undefined1 *)&local_8,param_2);
    FUN_1002e9f0((int)this,param_1,local_8);
    return 0;
  case 6:
    FUN_1002ea20(this,param_1,param_2);
    return 0;
  }
}

undefined4 __thiscall FUN_1002ed80(void *this,uint param_1,char *param_2)

{
  switch(param_1 & 7) {
  case 1:
    FUN_1002e9a0(this,param_1,*(undefined4 *)param_2);
    return 0;
  default:
    return 0xfffffffe;
  case 4:
    FUN_1002e9c0(this,param_1,*(undefined4 *)param_2);
    return 0;
  case 5:
    FUN_1002e9f0((int)this,param_1,*(undefined8 *)param_2);
    return 0;
  case 6:
    FUN_1002ea20(this,param_1,param_2);
    return 0;
  }
}

void __fastcall FUN_1002ee10(int param_1)

{
  FUN_100261a0(param_1 + 0xd0);
  return;
}

undefined4 __cdecl FUN_1002ee20(uint param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  switch(param_1 & 7) {
  case 1:
    FUN_1002ea80((undefined1 *)param_2,(undefined1 *)param_3);
    return 0;
  default:
    return 0xfffffffe;
  case 4:
    FUN_1002ea80((undefined1 *)param_2,(undefined1 *)param_3);
    return 0;
  case 5:
    FUN_1002eab0((undefined1 *)param_2,(undefined1 *)param_3);
    return 0;
  case 6:
    FUN_10035ce0(param_2,param_3,param_4);
    return 0;
  }
}

undefined4 * __thiscall FUN_1002eec0(void *this,byte param_1)

{
  FUN_1002e680((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

void __fastcall FUN_1002eee0(void *param_1)

{
  FUN_10022450((int)param_1);
  FUN_10026560((int)param_1 + 0xd0);
  FUN_1002e800(param_1,*(char **)((int)param_1 + 0xf4),*(int *)((int)param_1 + 0x18));
  FUN_10022460((int)param_1);
  return;
}

void __thiscall FUN_1002ef10(void *this,char *param_1,int param_2)

{
  FUN_10022450((int)this);
  FUN_10026560((int)this + 0xd0);
  FUN_1002e800(this,param_1,param_2);
  *(undefined1 *)((int)this + 0xfc) = 1;
  FUN_10022460((int)this);
  return;
}

undefined4 __thiscall FUN_1002ef50(void *this,int param_1)

{
  FUN_10022560(this,param_1);
  FUN_1002eee0(this);
  return 0;
}

undefined4 __thiscall FUN_1002ef70(void *this,int param_1,undefined4 param_2)

{
  FUN_10022580(this,param_1,param_2);
  if (*(char *)((int)this + 0xfd) != '\0') {
    FUN_1002eee0(this);
  }
  return 0;
}

undefined4 * __thiscall FUN_1002f390(void *this,uint param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_1004fe48;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_10022a40((undefined4 *)this);
  lVar1 = (ulonglong)(param_1 + 2) * 4;
  local_4 = (void *)0x0;
  *(undefined ***)this = VelCurve::vftable;
  *(undefined4 *)((int)this + 0xcc) = 0;
  *(undefined4 *)((int)this + 0xd0) = 0;
  *(undefined4 *)((int)this + 0xd4) = 0;
  *(undefined4 *)((int)this + 0xd8) = 0;
  puVar2 = (undefined4 *)FUN_10034298(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  *(undefined4 **)((int)this + 0xcc) = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *(undefined4 **)((int)this + 0xd0) = puVar2 + 1;
    *puVar2 = 0xabcd1234;
    *(undefined4 *)(*(int *)((int)this + 0xcc) + 4 + param_1 * 4) = 0xabcd1234;
  }
  if (*(int *)((int)this + 0xd0) != 0) {
    *(uint *)((int)this + 0xd8) = param_1;
  }
  *(int *)((int)this + 0x14) = *(int *)((int)this + 0xd0);
  uVar3 = FUN_10034298(-(uint)((int)((ulonglong)param_1 * 4 >> 0x20) != 0) |
                       (uint)((ulonglong)param_1 * 4));
  *(undefined4 *)((int)this + 0xd4) = uVar3;
  ExceptionList = local_4;
  return (undefined4 *)this;
}

void __fastcall FUN_1002f470(undefined4 *param_1)

{
  undefined4 uStack00000004;
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  *param_1 = VelCurve::vftable;
  if (*(int *)param_1[0x33] != -0x5432edcc) {
    FUN_10021c10();
  }
  if (*(int *)(param_1[0x33] + 4 + param_1[0x36] * 4) != -0x5432edcc) {
    FUN_10021c10();
  }
  FUN_100355e9((void *)param_1[0x33]);
  FUN_100355e9((void *)param_1[0x35]);
  uStack00000004 = 0xffffffff;
  FUN_100227f0(param_1,pvVar1);
  ExceptionList = (void *)0x0;
  return;
}

undefined4 FUN_1002f520(void)

{
  return 0x40;
}

undefined * FUN_1002f530(void)

{
  return PTR_s_VelCurve_10195504;
}

undefined * FUN_1002f540(void)

{
  return PTR_DAT_10195508;
}

undefined4 __fastcall FUN_1002f550(int param_1)

{
  return *(undefined4 *)(param_1 + 0xd8);
}

undefined4 * __fastcall FUN_1002f740(undefined4 *param_1)

{
  FUN_10022170(param_1,"VelCurveAllocator");
  *param_1 = VelCurveAllocator::vftable;
  return param_1;
}

int * __thiscall FUN_1002f760(void *this,uint param_1)

{
  int *piVar1;
  uint uVar2;
  void *this_00;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_1004fdbb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar1 = FUN_10021fa0((int)this);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x30))();
    if (param_1 <= uVar2) goto LAB_1002f7e4;
    FUN_10021d00(piVar1);
    FUN_10022040((int)this);
  }
  this_00 = operator_new(0x138);
  uStack_4 = 0;
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_1002f390(this_00,param_1);
  }
  uStack_4 = 0xffffffff;
  FUN_10022280(this,piVar1);
  if (piVar1 == (int *)0x0) {
    ExceptionList = pvStack_c;
    return (int *)0x0;
  }
LAB_1002f7e4:
  FUN_10022490((int)piVar1);
  ExceptionList = pvStack_c;
  return piVar1;
}

undefined4 * __thiscall FUN_1002f810(void *this,byte param_1)

{
  FUN_1002f470((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

void __fastcall FUN_1002fac0(int param_1)

{
  long lVar1;
  
  lVar1 = DMutex::Lock((DMutex *)(param_1 + 0x184));
  if (lVar1 != 0) {
    OutputDebugStringA("Error: BtCom::Lock() Failed\n");
  }
  return;
}

void __fastcall FUN_1002fae0(int param_1)

{
  DMutex::Unlock((DMutex *)(param_1 + 0x184));
  return;
}

void __fastcall FUN_1002fb00(int param_1)

{
  OutputDebugStringA("BtCom::InitData()");
  *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x104) = 0x2580;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x114) = 1;
  *(undefined1 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined1 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 20000;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  if (*(void **)(param_1 + 0x158) != (void *)0x0) {
    FUN_100355e9(*(void **)(param_1 + 0x158));
  }
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x16c) = 0;
  *(undefined4 *)(param_1 + 0x170) = 0;
  *(undefined1 *)(param_1 + 0x175) = 0;
  *(undefined4 *)(param_1 + 0x178) = 0;
  *(undefined4 *)(param_1 + 0x17c) = 0;
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined1 *)(param_1 + 0x174) = 1;
  return;
}

void FUN_1002fc00(undefined4 *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = param_1;
  puVar1 = (undefined1 *)((int)param_1 + 3);
  puVar2 = (undefined1 *)((int)param_1 + 2);
  puVar3 = (undefined1 *)((int)param_1 + 1);
  param_1 = (undefined4 *)
            CONCAT13(*(undefined1 *)puVar4,CONCAT12(*puVar3,CONCAT11(*puVar2,*puVar1)));
  *puVar4 = param_1;
  return;
}

void FUN_1002fc30(HANDLE param_1,DWORD param_2)

{
  _DCB local_1c;
  
  local_1c.BaudRate = 0;
  local_1c._8_4_ = 0;
  local_1c.wReserved = 0;
  local_1c.XonLim = 0;
  local_1c.XoffLim = 0;
  local_1c.ByteSize = '\0';
  local_1c.Parity = '\0';
  local_1c.StopBits = '\0';
  local_1c.XonChar = '\0';
  local_1c.XoffChar = '\0';
  local_1c.ErrorChar = '\0';
  local_1c.EofChar = '\0';
  local_1c.EvtChar = '\0';
  local_1c.wReserved1 = 0;
  local_1c.DCBlength = 0x1c;
  GetCommState(param_1,&local_1c);
  local_1c._8_4_ = local_1c._8_4_ & 0xffffe495 | 0x6014;
  local_1c.BaudRate = param_2;
  local_1c.ByteSize = 8;
  local_1c._20_4_ = local_1c._20_4_ & 0xffffff00;
  local_1c.Parity = '\0';
  SetCommState(param_1,&local_1c);
  return;
}

void FUN_1002fcb0(HANDLE param_1)

{
  BOOL BVar1;
  _COMMTIMEOUTS local_14;
  
  local_14.ReadTotalTimeoutMultiplier = 10;
  local_14.WriteTotalTimeoutMultiplier = 10;
  local_14.ReadIntervalTimeout = 0;
  local_14.ReadTotalTimeoutConstant = 10000;
  local_14.WriteTotalTimeoutConstant = 5000;
  BVar1 = SetCommTimeouts(param_1,&local_14);
  if (BVar1 == 0) {
    GetLastError();
  }
  return;
}

undefined4 __fastcall FUN_10030110(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10c);
}

int __thiscall
FUN_10030310(void *this,undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,undefined4 param_6)

{
  int iVar1;
  uint extraout_EDX;
  undefined4 *unaff_ESI;
  undefined4 unaff_EDI;
  uint uVar2;
  
  uVar2 = (uint)CONCAT11(param_1,0xb7);
  FUN_10031570(param_3);
  FUN_10031570(param_5);
  uVar2 = uVar2 & 0xffffff;
  FUN_10031570(param_6);
  iVar1 = FUN_10030190(this,(undefined4 *)&stack0xfffffff0,0x10,param_2,extraout_EDX,param_4,param_5
                       ,unaff_EDI,unaff_ESI,uVar2);
  if (iVar1 != 0) {
    OutputDebugStringA("  SendMsg(): Failed");
  }
  return iVar1;
}

int __thiscall
FUN_100304d0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  int iVar1;
  
  if ((*(int *)((int)this + 0x114) == 3) && (*(int *)((int)this + 0x108) != -1)) {
    iVar1 = FUN_10030310(this,1,param_1,param_2,param_3,param_4,0);
    return iVar1;
  }
  OutputDebugStringA("BtCom::SendMsg(): Cannot be safe");
  return -1;
}

void __fastcall FUN_10030a30(int param_1)

{
  *(undefined4 *)(param_1 + 0x114) = 2;
  if (*(int *)(param_1 + 0x10c) == 1) {
    OutputDebugStringA("DealWithLossOfConnection()");
    *(undefined4 *)(param_1 + 0x10c) = 2;
    FUN_1002fd90(param_1);
    FUN_1002ff60(param_1);
    CloseHandle(*(HANDLE *)(param_1 + 0x108));
    *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x114) = 1;
  }
  return;
}

void __thiscall FUN_10030a90(void *this,undefined1 param_1)

{
  *(undefined1 *)((int)this + 0x118) = param_1;
  FUN_10030a30((int)this);
  *(undefined1 *)((int)this + 0x174) = 1;
  return;
}

undefined4 * __fastcall FUN_10030c10(undefined4 *param_1)

{
  *param_1 = BtCom::vftable;
  param_1[0x56] = 0;
  DMutex::DMutex((DMutex *)(param_1 + 0x61));
  FUN_1002fb00((int)param_1);
  return param_1;
}

void __fastcall FUN_10030c40(undefined4 *param_1)

{
  *param_1 = BtCom::vftable;
  FUN_1002ffd0((DWORD)param_1);
  DMutex::~DMutex((DMutex *)(param_1 + 0x61));
  return;
}

undefined4 * __thiscall FUN_10030ca0(void *this,byte param_1)

{
  FUN_10030c40((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

void __fastcall FUN_10031190(undefined4 *param_1)

{
  *param_1 = mInstBt::vftable;
  param_1[1] = 0;
  return;
}

undefined4 __thiscall FUN_100311d0(void *this,undefined1 param_1)

{
  if (*(void **)((int)this + 4) != (void *)0x0) {
    FUN_10030a90(*(void **)((int)this + 4),param_1);
  }
  return 0;
}

undefined4 __fastcall FUN_100311f0(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    uVar1 = FUN_10030110(*(int *)(param_1 + 4));
    return uVar1;
  }
  return 2;
}

int __thiscall FUN_10031210(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(void **)((int)this + 4) == (void *)0x0) {
    return -1;
  }
  iVar1 = FUN_100304d0(*(void **)((int)this + 4),param_1,param_2,0,(undefined4 *)0x0);
  return iVar1;
}

int __thiscall
FUN_10031240(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  int iVar1;
  
  if (*(void **)((int)this + 4) == (void *)0x0) {
    return -1;
  }
  iVar1 = FUN_100304d0(*(void **)((int)this + 4),param_1,param_2,param_3,param_4);
  return iVar1;
}

int __thiscall FUN_10031260(void *this,uint param_1,uint *param_2)

{
  int iVar1;
  
  if (*(void **)((int)this + 4) == (void *)0x0) {
    return -1;
  }
  iVar1 = FUN_100303a0(*(void **)((int)this + 4),param_1,&param_1,0,(undefined4 *)0x0);
  *param_2 = ~-(uint)(iVar1 != 0) & param_1;
  return iVar1;
}

void __fastcall FUN_100312a0(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_1002fac0(*(int *)(param_1 + 4));
    return;
  }
  return;
}

void __fastcall FUN_100312b0(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_1002fae0(*(int *)(param_1 + 4));
    return;
  }
  return;
}

void __fastcall FUN_100312c0(undefined4 *param_1)

{
  *param_1 = mInstBt::vftable;
  FUN_100311a0((int)param_1);
  return;
}

undefined4 * __thiscall FUN_10031390(void *this,byte param_1)

{
  FUN_100312c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

void __fastcall FUN_100313b0(undefined1 *param_1)

{
  *param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

undefined1 * __fastcall FUN_100313c0(undefined1 *param_1)

{
  HANDLE pvVar1;
  
  *param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  pvVar1 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)0x0);
  *(HANDLE *)(param_1 + 0x20) = pvVar1;
  return param_1;
}

void __fastcall FUN_100313f0(int param_1)

{
  if (*(HANDLE *)(param_1 + 0x20) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}

undefined4 __fastcall FUN_10031410(int param_1)

{
  DWORD DVar1;
  
  DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x20),2000);
  if (DVar1 == 0) {
    return 0;
  }
  return 0xffffffff;
}

undefined4 __fastcall FUN_10031430(int param_1)

{
  ReleaseMutex(*(HANDLE *)(param_1 + 0x20));
  return 0;
}

undefined4 __thiscall
FUN_10031440(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_10031410((int)this);
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 4) = param_1;
    *(undefined4 *)((int)this + 8) = param_2;
    *(undefined1 *)this = 1;
    *(undefined4 *)((int)this + 0xc) = param_3;
    *(undefined4 *)((int)this + 0x10) = param_4;
    *(undefined4 *)((int)this + 0x14) = 0;
    *(undefined4 *)((int)this + 0x18) = 0;
    FUN_10031430((int)this);
    return 0;
  }
  return 0xffffffff;
}

void __fastcall FUN_10031490(int param_1)

{
  long lVar1;
  
  lVar1 = DMutex::Lock((DMutex *)(param_1 + 0x224));
  if (lVar1 != 0) {
    OutputDebugStringA("Warning: NetCom::Lock() Failed\n");
  }
  return;
}

void __fastcall FUN_100314b0(int param_1)

{
  DMutex::Unlock((DMutex *)(param_1 + 0x224));
  return;
}

void __fastcall FUN_100314c0(int param_1)

{
  *(undefined4 *)(param_1 + 0x5c) = 1;
  return;
}

void __fastcall FUN_100314d0(undefined4 *param_1)

{
  undefined1 uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  if ((void *)param_1[4] != (void *)0x0) {
    FUN_100355e9((void *)param_1[4]);
  }
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x19] = 0;
  param_1[0x20] = 1;
  *(undefined1 *)(param_1 + 0x21) = 0;
  param_1[0x1c] = 0;
  param_1[0x1e] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  uVar1 = FUN_100314c0((int)param_1);
  *(undefined1 *)((int)param_1 + 0x61) = 0;
  *(undefined1 *)((int)param_1 + 0x62) = 0;
  *(undefined1 *)(param_1 + 0x18) = uVar1;
  return;
}

undefined4 __fastcall FUN_10031560(int param_1)

{
  return *(undefined4 *)(param_1 + 100);
}

undefined4 FUN_10031570(undefined4 param_1)

{
  undefined4 local_4;
  
  local_4 = CONCAT13((char)param_1,
                     CONCAT12((char)((uint)param_1 >> 8),CONCAT11(param_1._2_1_,param_1._3_1_)));
  return local_4;
}

void FUN_10031c60(undefined1 param_1,undefined4 param_2,uint param_3,undefined4 param_4,
                 undefined4 *param_5,undefined4 param_6)

{
  void *this;
  undefined4 *unaff_ESI;
  undefined4 unaff_EDI;
  uint uVar1;
  
  uVar1 = (uint)CONCAT11(param_1,0xb7);
  FUN_10031570(param_3);
  FUN_10031570(param_5);
  uVar1 = uVar1 & 0xffffff;
  FUN_10031570(param_6);
  FUN_10031b70(this,(undefined4 *)&stack0xfffffff0,0x10,param_2,param_3,param_4,param_5,unaff_EDI,
               unaff_ESI,uVar1);
  return;
}

undefined4 __thiscall
FUN_10031cd0(void *this,undefined4 param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (*(int *)((int)this + 100) == 1) {
    uVar1 = FUN_10031c60(1,param_1,param_2,param_3,param_4,0);
  }
  return uVar1;
}

void __thiscall FUN_100322b0(void *this,undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  if (*(char *)((int)this + 0x28) != '\0') {
    *param_1 = 10;
    *param_2 = *(undefined4 *)((int)this + 0x70);
    *param_3 = *(int *)((int)this + 0x38) + *(int *)((int)this + 0x30);
    return;
  }
  if (*(char *)((int)this + 0xc) != '\0') {
    *param_1 = 0x14;
    *param_2 = *(undefined4 *)((int)this + 0x78);
    *param_3 = *(int *)((int)this + 0x18);
    return;
  }
  *param_1 = 1;
  *param_2 = 0;
  *param_3 = 0;
  return;
}

undefined4 * __fastcall FUN_10032320(undefined4 *param_1)

{
  int iVar1;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fe99;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  FUN_100313b0((undefined1 *)(param_1 + 3));
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  FUN_100313c0((undefined1 *)(param_1 + 10));
  local_4 = 0;
  param_1[0x15] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0xffffffff;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x86] = 0;
  param_1[0x87] = 0xffffffff;
  param_1[0x88] = 0;
  DMutex::DMutex((DMutex *)(param_1 + 0x89));
  local_4 = CONCAT31(local_4._1_3_,1);
  iVar1 = Ordinal_115(0x202,param_1 + 0x22);
  if (iVar1 != 0) {
    FUN_10021c10();
  }
  FUN_100314d0(param_1);
  ExceptionList = unaff_ESI;
  return param_1;
}

undefined4 __fastcall FUN_10032400(undefined4 *param_1)

{
  FUN_10021c10();
  FUN_10031a10(param_1);
  FUN_10031d00((int)param_1);
  FUN_100321e0((int)param_1);
  FUN_10032240((int)param_1);
  param_1[0x19] = 0;
  return 0xffffffff;
}

void __thiscall FUN_10032520(void *this,undefined1 param_1)

{
  *(undefined1 *)((int)this + 0x84) = param_1;
  FUN_10032470((undefined4 *)this);
  *(undefined1 *)((int)this + 0x60) = 1;
  return;
}

void __fastcall FUN_10032580(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_1004fe99;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  if (param_1[0x86] != 0) {
    ExceptionList = &pvStack_c;
    freeaddrinfo(param_1[0x86]);
  }
  param_1[0x86] = 0;
  FUN_10032400(param_1);
  if (param_1[0x87] != -1) {
    Ordinal_3(param_1[0x87]);
  }
  param_1[0x87] = 0xffffffff;
  Ordinal_116();
  if ((void *)param_1[0x1a] != (void *)0x0) {
    FUN_100355e9((void *)param_1[0x1a]);
  }
  local_4 = local_4 & 0xffffff00;
  DMutex::~DMutex((DMutex *)(param_1 + 0x89));
  FUN_100313f0((int)(param_1 + 10));
  ExceptionList = pvStack_c;
  return;
}

int __thiscall
FUN_100328b0(void *this,undefined4 param_1,char *param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  char *pcVar2;
  char *_Dest;
  int iVar3;
  
  if (*(void **)((int)this + 0x68) != (void *)0x0) {
    FUN_100355e9(*(void **)((int)this + 0x68));
  }
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  _Dest = (char *)FUN_10034298((uint)(pcVar2 + (1 - (int)(param_2 + 1))));
  *(char **)((int)this + 0x68) = _Dest;
  _strncpy(_Dest,param_2,(size_t)(pcVar2 + (1 - (int)(param_2 + 1))));
  *(int *)((int)this + 0x6c) = param_4;
  iVar3 = FUN_100323e0((int)this);
  if (iVar3 == 0) {
    FUN_10032630((int *)this);
    FUN_10032690(this);
    FUN_10032850(this);
    FUN_10032540(this);
    FUN_10032070(this);
  }
  return iVar3;
}

void __fastcall FUN_10033750(undefined1 *param_1)

{
  *(undefined4 *)(param_1 + 0x14) = 0;
  if (*(void **)(param_1 + 4) != (void *)0x0) {
    FUN_100355b4(*(void **)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

char __fastcall FUN_10033780(char *param_1)

{
  if (*param_1 != '\0') {
    FUN_10033240(*(void **)(param_1 + 4),(double *)*(void **)(param_1 + 4),*(int *)(param_1 + 0xc),1
                 ,'\0');
    param_1[1] = '\x01';
  }
  return *param_1;
}

undefined1 * __thiscall FUN_100337b0(void *this,undefined4 param_1,undefined4 param_2)

{
  longlong lVar1;
  void *pvVar2;
  undefined4 extraout_ECX;
  uint uVar3;
  undefined4 extraout_EDX;
  ulonglong uVar4;
  
  *(undefined4 *)((int)this + 0x14) = param_1;
  *(undefined1 *)this = 0;
  *(undefined1 *)((int)this + 1) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x18) = param_2;
  FUN_10038030();
  uVar4 = FUN_100362d0(extraout_ECX,extraout_EDX);
  uVar3 = (uint)uVar4;
  if ((int)uVar3 < 0) {
    uVar3 = -uVar3;
  }
  do {
    uVar3 = uVar3 >> 1;
  } while (uVar3 != 0);
  uVar4 = FUN_100362d0(0,(int)(uVar4 >> 0x20));
  lVar1 = (uVar4 & 0xffffffff) * 8;
  pvVar2 = operator_new(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  *(void **)((int)this + 4) = pvVar2;
  *(int *)((int)this + 8) = (int)uVar4 * 8;
  *(undefined4 *)((int)this + 0xc) = 0;
  return (undefined1 *)this;
}

void __fastcall FUN_10033a20(undefined4 *param_1)

{
  *param_1 = DLSSplineCalc::vftable;
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  return;
}

void __fastcall FUN_10033a40(undefined4 *param_1)

{
  *param_1 = DLSSplineCalc::vftable;
  return;
}

void FUN_10033c6a(void)

{
  int unaff_EBP;
  
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

void __fastcall FUN_10033d70(int param_1)

{
  if (*(void **)(param_1 + 0x10) != (void *)0x0) {
    FUN_100355b4(*(void **)(param_1 + 0x10));
  }
  if (*(void **)(param_1 + 0x28) != (void *)0x0) {
    FUN_100355b4(*(void **)(param_1 + 0x28));
  }
  if (*(void **)(param_1 + 0x2c) != (void *)0x0) {
    FUN_100355b4(*(void **)(param_1 + 0x2c));
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

undefined4 * __thiscall FUN_10033fc0(void *this,byte param_1)

{
  FUN_10033a40((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

undefined4 * __thiscall
FUN_10033fe0(void *this,undefined8 param_1,undefined8 param_2,undefined4 *param_3,uint param_4)

{
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1004fef8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_10033a20((undefined4 *)this);
  *(undefined8 *)((int)this + 0x18) = param_1;
  *(undefined8 *)((int)this + 0x20) = param_2;
  local_4 = 0;
  *(undefined ***)this = DLSdSplineCalc::vftable;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  FUN_10033dc0(this,param_4,'\0');
  uVar1 = FUN_10033e40(this,param_3,param_4);
  *(char *)((int)this + 4) = (char)uVar1;
  *(undefined1 *)((int)this + 0xc) = 1;
  ExceptionList = local_c;
  return (undefined4 *)this;
}

void __fastcall FUN_10034060(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1004fef8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = DLSdSplineCalc::vftable;
  local_4 = 0;
  FUN_10033d70((int)param_1);
  FUN_10033a40(param_1);
  ExceptionList = local_c;
  return;
}

undefined4 * __thiscall FUN_100340b0(void *this,byte param_1)

{
  FUN_10034060((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (undefined4 *)this;
}

void FUN_10034298(uint param_1)

{
  operator_new(param_1);
  return;
}

EH_prolog3

void FUN_100342a3(void)

{
  code *pcVar1;
  undefined1 local_54 [40];
  undefined1 local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x100342af;
  FUN_10001d30(local_2c,"string too long");
  local_8 = 0;
  FUN_10001c60(local_54,local_2c);
  __CxxThrowException_8(local_54,&DAT_10062230);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

EH_prolog3

void FUN_100342db(void)

{
  code *pcVar1;
  undefined1 local_54 [40];
  undefined1 local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x100342e7;
  FUN_10001d30(local_2c,"invalid string position");
  local_8 = 0;
  FUN_10001c80(local_54,local_2c);
  __CxxThrowException_8(local_54,&DAT_10062288);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

void __fastcall FUN_10034502(int *param_1)

{
  if (*param_1 < 4) {
    __Mtxunlock((_Rmtx *)(&DAT_10199be0 + *param_1 * 0x18));
  }
  return;
}

undefined4 FUN_100345b6(void)

{
  return DAT_10199c48;
}

void __fastcall FUN_10034946(undefined4 *param_1)

{
  FUN_10035185((LPCRITICAL_SECTION)*param_1);
  FUN_100355b4((void *)*param_1);
  return;
}

void __fastcall FUN_1003495d(undefined4 *param_1)

{
  __Mtxlock((_Rmtx *)*param_1);
  return;
}

void __fastcall FUN_10034966(undefined4 *param_1)

{
  __Mtxunlock((_Rmtx *)*param_1);
  return;
}

bool thunk_FUN_1003a9c3(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return p_Var1->_ProcessingThrow != 0;
}

void __cdecl FUN_10034bb1(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}

void __cdecl FUN_10034bc1(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = FUN_10034bb1;
  param_1[1] = param_2;
  return;
}

void __cdecl FUN_1003516a(byte *param_1,undefined4 *param_2,int param_3,int *param_4)

{
  FUN_10035101(param_1,param_2,param_3,param_4);
  return;
}

void __cdecl FUN_10035185(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return;
}

void __fastcall FUN_1003532d(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = std::exception::vftable;
  return;
}

char * __fastcall FUN_10035421(int param_1)

{
  char *pcVar1;
  
  pcVar1 = *(char **)(param_1 + 4);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = "Unknown exception";
  }
  return pcVar1;
}

exception * __thiscall FUN_1003544c(void *this,exception *param_1)

{
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_cast::vftable;
  return (exception *)this;
}

exception * __thiscall FUN_10035492(void *this,exception *param_1)

{
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_typeid::vftable;
  return (exception *)this;
}

undefined4 * __thiscall FUN_100354cc(void *this,exception *param_1)

{
  FUN_10035492(this,param_1);
  *(undefined ***)this = std::__non_rtti_object::vftable;
  return (undefined4 *)this;
}

exception * __thiscall FUN_100354f4(void *this,byte param_1)

{
  exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (exception *)this;
}

exception * __thiscall FUN_10035515(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_cast::vftable;
  exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (exception *)this;
}

exception * __thiscall FUN_1003553c(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_typeid::vftable;
  exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (exception *)this;
}

void FUN_100355b4(void *param_1)

{
  _free(param_1);
  return;
}

void FUN_100355e9(void *param_1)

{
  FUN_100355b4(param_1);
  return;
}

void FUN_1003569d(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}

void __cdecl FUN_100356b5(undefined4 param_1)

{
  DAT_10199df8 = param_1;
  return;
}

void FUN_10035812(void)

{
  __invalid_parameter((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  return;
}

void FUN_100360e1(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = FUN_1003cd25();
  __unlock_file2(1,ppuVar1 + 8);
  return;
}

void FUN_1003622b(void)

{
  FUN_1003dd30();
  return;
}

void FUN_10036248(void)

{
  return;
}

void FUN_100365ea(void)

{
  FUN_1003ed58(4);
  return;
}

void FUN_1003671e(void)

{
  FILE *unaff_ESI;
  
  __unlock_file(unaff_ESI);
  return;
}

void FUN_1003682a(void)

{
  FILE *unaff_ESI;
  
  __unlock_file(unaff_ESI);
  return;
}

void FUN_1003698b(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 0xc));
  return;
}

void FUN_10036ae7(void)

{
  int unaff_ESI;
  
  __unlock_file2(unaff_ESI,*(void **)(DAT_1019aa10 + unaff_ESI * 4));
  return;
}

void FUN_10036b16(void)

{
  FUN_1003ed58(1);
  return;
}

void FUN_10036b68(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 8));
  return;
}

void FUN_10036c6f(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 8));
  return;
}

void FUN_10036e53(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 0x14));
  return;
}

void FUN_10036fd0(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 8));
  return;
}

void FUN_1003710a(void)

{
  FILE *unaff_ESI;
  
  __unlock_file(unaff_ESI);
  return;
}

int __fastcall FUN_100374b6(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)param_1 - *(int *)(*(int *)(*param_1 + -4) + 4);
  iVar1 = *(int *)(*(int *)(*param_1 + -4) + 8);
  if (iVar1 != 0) {
    iVar2 = iVar2 - *(int *)((int)param_1 - iVar1);
  }
  return iVar2;
}

void FUN_10037bb0(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  float10 in_ST1;
  
  if ((DAT_1019a8d0 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_10042030();
    return;
  }
  FUN_10037c0d(SUB84((double)in_ST1,0),(uint)((ulonglong)(double)in_ST1 >> 0x20),
               SUB84((double)in_ST0,0),(uint)((ulonglong)(double)in_ST0 >> 0x20));
  return;
}

overlap smaller symbols at the same address

void FUN_10037dd2(void)

{
  float10 in_ST0;
  
  if (ROUND(in_ST0) == in_ST0) {
    return;
  }
  return;
}

void __fastcall FUN_10037e40(void *param_1)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  double dVar1;
  
  if ((DAT_1019a8d0 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_10043310(param_1);
    return;
  }
  dVar1 = (double)in_ST0;
  FUN_10043058(SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20));
  FUN_10037e98(SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20));
  return;
}

void FUN_10037f30(void)

{
  float10 in_ST0;
  double dVar1;
  
  dVar1 = (double)in_ST0;
  FUN_10043058(SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20));
  FUN_10037f4d(SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20));
  return;
}

void FUN_10038030(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  double dVar1;
  
  if ((DAT_1019a8d0 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_100434c0();
    return;
  }
  dVar1 = (double)in_ST0;
  FUN_10043058(SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20));
  FUN_10038088(SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20));
  return;
}

void __fastcall FUN_100386e0(void *param_1)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  double dVar1;
  
  if ((DAT_1019a8d0 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_10043d80(param_1);
    return;
  }
  dVar1 = (double)in_ST0;
  FUN_10043058(SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20));
  FUN_10038738(SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20));
  return;
}

void FUN_1003965e(void)

{
  FUN_1003ed58(0xc);
  return;
}

void FUN_1003976a(void)

{
  FUN_1003ed58(0xd);
  return;
}

void FUN_10039776(void)

{
  FUN_1003ed58(0xc);
  return;
}

void FUN_1003a34e(void)

{
  FUN_1003ed58(0xc);
  return;
}

void FUN_1003a35a(void)

{
  FUN_1003ed58(0xc);
  return;
}

void FUN_1003a38b(void)

{
  int unaff_ESI;
  
  *(uint *)(unaff_ESI + 0x70) = *(uint *)(unaff_ESI + 0x70) & 0xffffffef;
  return;
}

void FUN_1003a44c(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 8));
  return;
}

exception * __thiscall FUN_1003a750(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_exception::vftable;
  exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    FUN_100355b4(this);
  }
  return (exception *)this;
}

void FUN_1003a8e5(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if (0 < p_Var1->_ProcessingThrow) {
    p_Var1 = __getptd();
    p_Var1->_ProcessingThrow = p_Var1->_ProcessingThrow + -1;
  }
  return;
}

bool FUN_1003a9c3(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  return p_Var1->_ProcessingThrow != 0;
}

EH_prolog3

void FUN_1003aa51(void *param_1)

{
  code *pcVar1;
  _ptiddata p_Var2;
  
  p_Var2 = __getptd();
  if (p_Var2->_curexcspec != (void *)0x0) {
    _inconsistency();
  }
  FUN_1003c81b();
  terminate();
  p_Var2 = __getptd();
  p_Var2->_curexcspec = param_1;
  __CxxThrowException_8(0,(byte *)0x0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

exception * __thiscall FUN_1003b2f0(void *this,exception *param_1)

{
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_exception::vftable;
  return (exception *)this;
}

void __cdecl FUN_1003b783(byte *param_1,undefined4 *param_2)

{
  FUN_1003b664(param_1,param_2,(localeinfo_struct *)0x0);
  return;
}

void FUN_1003bc5b(void)

{
  FUN_1003ed58(4);
  return;
}

void FUN_1003bd95(void)

{
  FUN_1003ed58(0xe);
  return;
}

undefined4 FUN_1003c11c(void)

{
  return DAT_10195a28;
}

void FUN_1003c285(void)

{
  FUN_1003ed58(0xd);
  return;
}

void FUN_1003c28e(void)

{
  FUN_1003ed58(0xc);
  return;
}

void FUN_1003c444(void)

{
  FUN_1003ed58(0xd);
  return;
}

void FUN_1003c450(void)

{
  FUN_1003ed58(0xc);
  return;
}

void __cdecl FUN_1003c7d3(undefined4 param_1)

{
  DAT_1019a174 = param_1;
  return;
}

void FUN_1003c81b(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if ((code *)p_Var1->_unexpected != (code *)0x0) {
    (*(code *)p_Var1->_unexpected)();
  }
  terminate();
  return;
}

overlap smaller symbols at the same address

void FUN_1003ca6c(void)

{
  _DAT_1019ba28 = 0;
  return;
}

void __cdecl FUN_1003ca74(undefined4 param_1)

{
  DAT_1019a17c = param_1;
  return;
}

void __cdecl FUN_1003cafc(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uVar16;
  
  uVar16 = param_3 >> 7;
  do {
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    uVar3 = param_2[3];
    uVar4 = param_2[4];
    uVar5 = param_2[5];
    uVar6 = param_2[6];
    uVar7 = param_2[7];
    uVar8 = param_2[8];
    uVar9 = param_2[9];
    uVar10 = param_2[10];
    uVar11 = param_2[0xb];
    uVar12 = param_2[0xc];
    uVar13 = param_2[0xd];
    uVar14 = param_2[0xe];
    uVar15 = param_2[0xf];
    *param_1 = *param_2;
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    param_1[3] = uVar3;
    param_1[4] = uVar4;
    param_1[5] = uVar5;
    param_1[6] = uVar6;
    param_1[7] = uVar7;
    param_1[8] = uVar8;
    param_1[9] = uVar9;
    param_1[10] = uVar10;
    param_1[0xb] = uVar11;
    param_1[0xc] = uVar12;
    param_1[0xd] = uVar13;
    param_1[0xe] = uVar14;
    param_1[0xf] = uVar15;
    uVar1 = param_2[0x11];
    uVar2 = param_2[0x12];
    uVar3 = param_2[0x13];
    uVar4 = param_2[0x14];
    uVar5 = param_2[0x15];
    uVar6 = param_2[0x16];
    uVar7 = param_2[0x17];
    uVar8 = param_2[0x18];
    uVar9 = param_2[0x19];
    uVar10 = param_2[0x1a];
    uVar11 = param_2[0x1b];
    uVar12 = param_2[0x1c];
    uVar13 = param_2[0x1d];
    uVar14 = param_2[0x1e];
    uVar15 = param_2[0x1f];
    param_1[0x10] = param_2[0x10];
    param_1[0x11] = uVar1;
    param_1[0x12] = uVar2;
    param_1[0x13] = uVar3;
    param_1[0x14] = uVar4;
    param_1[0x15] = uVar5;
    param_1[0x16] = uVar6;
    param_1[0x17] = uVar7;
    param_1[0x18] = uVar8;
    param_1[0x19] = uVar9;
    param_1[0x1a] = uVar10;
    param_1[0x1b] = uVar11;
    param_1[0x1c] = uVar12;
    param_1[0x1d] = uVar13;
    param_1[0x1e] = uVar14;
    param_1[0x1f] = uVar15;
    param_2 = param_2 + 0x20;
    param_1 = param_1 + 0x20;
    uVar16 = uVar16 - 1;
  } while (uVar16 != 0);
  return;
}

EH_epilog3

undefined4 FUN_1003cc66(void)

{
  return 1;
}

undefined ** FUN_1003cd25(void)

{
  return &PTR_DAT_10195a30;
}

void FUN_1003dc82(void)

{
  FUN_1003ed58(4);
  return;
}

void FUN_1003dd27(void)

{
  __lock(8);
  return;
}

void FUN_1003dd30(void)

{
  FUN_1003ed58(8);
  return;
}

void FUN_1003df16(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + 0x10) != 0) {
    FUN_1003ed58(8);
  }
  return;
}

void __cdecl FUN_1003ed58(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_10195ce8)[param_1 * 2]);
  return;
}

void FUN_1003ee29(void)

{
  FUN_1003ed58(10);
  return;
}

void FUN_100406da(void)

{
  int unaff_EBP;
  
  __unlock_fhandle(*(int *)(unaff_EBP + 8));
  return;
}

void FUN_100407bb(void)

{
  int unaff_EBP;
  
  __unlock_fhandle(*(int *)(unaff_EBP + 8));
  return;
}

void FUN_10040b82(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 8));
  return;
}

void FUN_10040cd3(void)

{
  int unaff_EBP;
  
  __unlock_fhandle(*(int *)(unaff_EBP + 8));
  return;
}

void FUN_10040f5b(void)

{
  int unaff_EBP;
  
  __unlock_file(*(FILE **)(unaff_EBP + 8));
  return;
}

void FUN_100410c4(void)

{
  int unaff_EBP;
  
  __unlock_fhandle(*(int *)(unaff_EBP + 8));
  return;
}

void FUN_1004138f(void)

{
  FUN_1003ed58(0xd);
  return;
}

void FUN_1004175a(void)

{
  FUN_1003ed58(0xd);
  return;
}

void FUN_10042030(void)

{
  float10 in_ST0;
  float10 in_ST1;
  
  FUN_10042049((double)in_ST1,SUB84((double)in_ST0,0),(uint)((ulonglong)(double)in_ST0 >> 0x20));
  return;
}

float10 __fastcall
FUN_10042f70(undefined4 param_1,int param_2,undefined2 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  float10 in_ST0;
  int local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  undefined4 local_10;
  double dStack_c;
  
  local_14 = param_7;
  local_10 = param_8;
  dStack_c = (double)in_ST0;
  uStack_1c = param_5;
  uStack_18 = param_6;
  uStack_20 = param_1;
  __87except(param_2,&local_24,&param_3);
  return (float10)dStack_c;
}

FUN_10042fd0(void)

{
  float10 in_ST0;
  float10 fVar1;
  undefined1 auVar2 [10];
  
  fVar1 = (float10)f2xm1(-(ROUND(in_ST0) - in_ST0));
  auVar2 = (undefined1  [10])fscale((float10)1 + fVar1,ROUND(in_ST0));
  return auVar2;
}

void FUN_10042fe5(void)

{
  return;
}

undefined4 FUN_10042ffc(void)

{
  uint in_EAX;
  
  if ((in_EAX & 0x80000) != 0) {
    return 7;
  }
  return 1;
}

uint __cdecl FUN_10043058(undefined4 param_1,uint param_2)

{
  if ((param_2 & 0x7ff00000) != 0x7ff00000) {
    return param_2 & 0x7ff00000;
  }
  return param_2;
}

void FUN_1004306e(void)

{
  return;
}

void __fastcall
FUN_100430b9(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  ushort in_FPUStatusWord;
  float10 in_ST0;
  ushort unaff_retaddr;
  uint uStack_4;
  
  uStack_4 = (uint)((ulonglong)(double)in_ST0 >> 0x20);
  if (((ulonglong)(double)in_ST0 & 0x7ff0000000000000) == 0) {
    fscale(in_ST0,(float10)1536.0);
  }
  else if ((uStack_4 & 0x7ff00000) == 0x7ff00000) {
    fscale(in_ST0,(float10)-1536.0);
  }
  else if (((unaff_retaddr == 0x27f) || ((unaff_retaddr & 0x20) != 0)) ||
          ((in_FPUStatusWord & 0x20) == 0)) {
    return;
  }
  if (param_2 == 0x1d) {
    FUN_10042f70(param_1,0x1d,unaff_retaddr,param_3,param_4,param_5,param_6,param_7);
    return;
  }
  __startOneArgErrorHandling(param_1,param_2,unaff_retaddr,param_3,param_4,param_5);
  return;
}

void __fastcall FUN_10043310(void *param_1)

{
  float10 in_ST0;
  
  FUN_1004332e(param_1,SUB84((double)in_ST0,0));
  return;
}

float10 __thiscall FUN_1004332e(void *param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  float10 extraout_ST0;
  double in_XMM0_Qa;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  
  uVar1 = (ushort)((ulonglong)in_XMM0_Qa >> 0x30);
  uVar2 = (uVar1 & 0x7fff) + 0xcfd0;
  if (uVar2 < 0x10c6) {
    dVar9 = (in_XMM0_Qa * 10.185916357881302 + 6755399441055744.0) - 6755399441055744.0;
    iVar3 = ((int)ROUND(in_XMM0_Qa * 10.185916357881302) + 0x1c7610U & 0x3f) * 0x20;
    dVar10 = dVar9 * 3.798187816439979e-12;
    dVar4 = in_XMM0_Qa - dVar9 * 0.09817477042088285;
    dVar14 = in_XMM0_Qa - dVar9 * 0.09817477042088285;
    dVar15 = dVar14 - dVar10;
    dVar5 = dVar4 - dVar10;
    dVar7 = dVar4 - dVar9 * 3.798187816439979e-12;
    dVar6 = dVar5 * dVar5;
    dVar8 = dVar7 * dVar7;
    dVar11 = *(double *)(&DAT_1005d560 + iVar3) + *(double *)(&DAT_1005d578 + iVar3);
    dVar12 = *(double *)(&DAT_1005d578 + iVar3) * dVar15;
    dVar16 = dVar15 * *(double *)(&DAT_1005d560 + iVar3);
    dVar13 = dVar12 + *(double *)(&DAT_1005d568 + iVar3);
    dVar17 = dVar16 + dVar13;
    return (float10)(dVar17 + (dVar9 * 1.2639164054974691e-22 - ((dVar14 - dVar15) - dVar10)) *
                              (*(double *)(&DAT_1005d568 + iVar3) * dVar15 - dVar11) +
                              *(double *)(&DAT_1005d570 + iVar3) +
                              (*(double *)(&DAT_1005d568 + iVar3) - dVar13) + dVar12 +
                              (dVar13 - dVar17) + dVar16 +
                              (dVar6 * 0.008333333333333333 + -0.16666666666666666 +
                              (dVar4 * 2.7557319223985893e-06 * dVar5 + -0.0001984126984126984) *
                              dVar6 * dVar6) * dVar11 * dVar15 * dVar6 +
                              (dVar8 * 0.041666666666666664 + -0.5 +
                              (dVar4 * 2.48015873015873e-05 * dVar7 + -0.001388888888888889) *
                              dVar8 * dVar8) * *(double *)(&DAT_1005d568 + iVar3) * dVar8);
  }
  if ((short)uVar2 < 0x10c6) {
    return (float10)(1.0 - (double)((ulonglong)in_XMM0_Qa & 0xffffffffffff |
                                   (ulonglong)(uVar1 & 0x7fff) << 0x30));
  }
  FUN_10037e8f(param_1,param_2);
  return extraout_ST0;
}

void FUN_100434c0(void)

{
  float10 in_ST0;
  
  FUN_100434de((double)in_ST0);
  return;
}

void __fastcall FUN_10043d80(void *param_1)

{
  float10 in_ST0;
  
  FUN_10043d9e(param_1,SUB84((double)in_ST0,0));
  return;
}

void FUN_10044574(void)

{
  FUN_1003ed58(4);
  return;
}

void FUN_100446da(void)

{
  FUN_1003ed58(4);
  return;
}

void FUN_10044987(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) != 0) {
    FUN_1003ed58(0);
  }
  return;
}

undefined4 FUN_1004554f(void)

{
  return 0;
}

void FUN_100478e3(void)

{
  FUN_1003ed58(1);
  return;
}

void FUN_100479c2(int param_1)

{
  __local_unwind4(*(uint **)(param_1 + 0x28),*(int *)(param_1 + 0x18),*(uint *)(param_1 + 0x1c));
  return;
}

void FUN_10048080(void)

{
  code *in_EAX;
  
  (*in_EAX)();
  return;
}

overlap smaller symbols at the same address

void __cdecl FUN_10048edf(undefined4 param_1)

{
  _DAT_1019a804 = param_1;
  return;
}

overlap smaller symbols at the same address

void __cdecl FUN_10048eee(undefined4 param_1)

{
  _DAT_1019a808 = param_1;
  return;
}

void FUN_10049b19(void)

{
  int unaff_EBP;
  
  __unlock_fhandle(*(int *)(unaff_EBP + 8));
  return;
}

void FUN_10049cb7(void)

{
  int unaff_EBP;
  
  __unlock_fhandle(*(int *)(unaff_EBP + 8));
  return;
}

void FUN_1004a100(void)

{
  FUN_1003ed58(10);
  return;
}

void FUN_1004a203(void)

{
  FUN_1003ed58(10);
  return;
}

void FUN_1004a2c1(void)

{
  FUN_1003ed58(0xb);
  return;
}

overlap smaller symbols at the same address

void FUN_1004ab6d(void)

{
  return;
}

void FUN_10050350(void)

{
  FUN_10002a50((undefined4 *)&DAT_10196de0);
  return;
}

void FUN_10050360(void)

{
  FUN_10009c40(0x100dab18);
  return;
}

overlap smaller symbols at the same address

void FUN_10050370(void)

{
  if (0xf < DAT_100dae28) {
    FUN_100355b4(DAT_100dae14);
  }
  DAT_100dae28 = 0xf;
  _DAT_100dae24 = 0;
  DAT_100dae14 = (void *)((uint)DAT_100dae14 & 0xffffff00);
  return;
}

overlap smaller symbols at the same address

void FUN_100503a0(void)

{
  if (0xf < DAT_100dae44) {
    FUN_100355b4(DAT_100dae30);
  }
  DAT_100dae44 = 0xf;
  _DAT_100dae40 = 0;
  DAT_100dae30 = (void *)((uint)DAT_100dae30 & 0xffffff00);
  return;
}

overlap smaller symbols at the same address

void FUN_100503d0(void)

{
  if (0xf < DAT_100dae60) {
    FUN_100355b4(DAT_100dae4c);
  }
  DAT_100dae60 = 0xf;
  _DAT_100dae5c = 0;
  DAT_100dae4c = (void *)((uint)DAT_100dae4c & 0xffffff00);
  return;
}

overlap smaller symbols at the same address

void FUN_10050400(void)

{
  if (DAT_101995c0 != (void *)0x0) {
    FUN_100355b4(DAT_101995c0);
  }
  DAT_101995c0 = (void *)0x0;
  _DAT_101995c4 = 0;
  _DAT_101995ac = 0;
  _DAT_101995b0 = 0;
  _DAT_101995b4 = 0;
  _DAT_101995b8 = 0;
  _DAT_101995bc = 0;
  return;
}

overlap smaller symbols at the same address

void FUN_10050450(void)

{
  if (DAT_101995dc != (void *)0x0) {
    FUN_100355b4(DAT_101995dc);
  }
  DAT_101995dc = (void *)0x0;
  DAT_101995e0 = 0;
  _DAT_101995c8 = 0;
  _DAT_101995cc = 0;
  _DAT_101995d0 = 0;
  _DAT_101995d4 = 0;
  _DAT_101995d8 = 0;
  return;
}

void FUN_100504a0(void)

{
  FUN_10022070((undefined4 *)&DAT_101995f0);
  return;
}

void FUN_100504e0(void)

{
  DMutex::~DMutex((DMutex *)&DAT_101996bc);
  return;
}

void FUN_100504f0(void)

{
  FUN_10022070((undefined4 *)&DAT_101996c8);
  return;
}

void FUN_10050500(void)

{
  FUN_10022070((undefined4 *)&DAT_10199740);
  return;
}

void FUN_10050510(void)

{
  FUN_10022070((undefined4 *)&DAT_101997b0);
  return;
}

void FUN_10050520(void)

{
  FUN_10022070((undefined4 *)&DAT_10199818);
  return;
}

void FUN_10050530(void)

{
  FUN_10022070((undefined4 *)&DAT_10199880);
  return;
}

void FUN_10050540(void)

{
  FUN_10022070((undefined4 *)&DAT_101998f0);
  return;
}

void FUN_10050550(void)

{
  DMutex::~DMutex((DMutex *)&DAT_10199964);
  return;
}

void FUN_10050560(void)

{
  FUN_10022070((undefined4 *)&DAT_10199968);
  return;
}

void FUN_10050570(void)

{
  FUN_10022070((undefined4 *)&DAT_101999d0);
  return;
}

void FUN_10050580(void)

{
  FUN_10022070((undefined4 *)&DAT_10199a38);
  return;
}

void FUN_10050590(void)

{
  FUN_10022070((undefined4 *)&DAT_10199aa0);
  return;
}

void FUN_100505a0(void)

{
  FUN_10022070((undefined4 *)&DAT_10199b08);
  return;
}

void FUN_100505b0(void)

{
  FUN_10022070((undefined4 *)&DAT_10199b70);
  return;
}

void FUN_100505ba(void)

{
  FUN_100344b1();
  return;
}

void FUN_100505c4(void)

{
  FUN_10008bc0((uint *)&DAT_10199c64);
  return;
}

void FUN_100505ce(void)

{
  FUN_100344b1();
  return;
}

void FUN_100505d8(void)

{
  thunk_FUN_100351f5();
  return;
}