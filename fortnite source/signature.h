#pragma once
//Gworld : 48 89 05 ? ? ? ? 0F 28 D7
//FName : 48 8D 0D B0 0F 74 0A or 48 8D 1D 00 00 00 00 48 8B 07 48 8B A8
//DecryptAnsi (V1) : 48 89 5C 24 ? 57 48 83 EC 20 44 0F B7 01 48 8B FA 49 C1 E8 06
//Getnamebyindex : 48 89 5C 24 ? 48 89 6C 24 ? 56 57 41 54 41 56 41 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 8B 19 48 8B F2
//GObject : 48 8B 05 ? ? ? ? 48 8B 0C C8 48 8B 04 D1

void get_prank_lol()
{

}

//DecryptAnsi (V2) : 48 89 5C 24 ? 57 48 83 EC 20 44 0F B7 01 48 8B FA 48 8D 51 04



//
//__int64 __fastcall sub_140D99820(_BYTE* a1, __int64* a2, __int64* a3)
//{
//    __int64 result; // rax
//    __int64 v7; // rbx
//    __int64 v8; // rcx
//    __int64 v9; // rax
//    __int64 v10; // rax
//    __int64 v11; // rbx
//    __int64 v12; // r15
//    __int64 v13; // rcx
//    char v14; // r12
//    __int64 v15; // rdx
//    __int64 v16; // r8
//    __int64 v17; // rax
//    __int64 v18; // rdx
//    __int64 v19; // rbx
//    __int64 v20; // rdi
//    char v21; // [rsp+28h] [rbp-81h]
//    __int64 v22; // [rsp+30h] [rbp-79h] BYREF
//    unsigned int v23; // [rsp+38h] [rbp-71h]
//    __int64 v24[2]; // [rsp+40h] [rbp-69h] BYREF
//    __int64 v25[2]; // [rsp+50h] [rbp-59h] BYREF
//    __int64 v26[3]; // [rsp+60h] [rbp-49h] BYREF
//    __int64 v27[3]; // [rsp+78h] [rbp-31h] BYREF
//    __int128 v28; // [rsp+90h] [rbp-19h] BYREF
//    __int128 v29; // [rsp+A0h] [rbp-9h] BYREF
//    char v30[32]; // [rsp+C0h] [rbp+17h] BYREF
//    int v31; // [rsp+110h] [rbp+67h] BYREF
//
//    if (a1[418]
//        || (result = sub_140D70D00(*a2), (_BYTE)result)
//        && ((result = ((__int64(__fastcall*)(__int64))sub_140D70944)(*a2), !(_BYTE)result) || byte_14EC73FF9))
//    {
//        v7 = a2[1];
//        if (v7)
//        {
//            _InterlockedIncrement((volatile signed __int32*)(v7 + 8));
//            if ((unsigned int)((__int64(__fastcall*)(__int64, __int64, __int64))unk_14477E61C)(v7 + 8, 1i64, 4i64) == 1)
//            {
//                (**(void(__fastcall***)(__int64))v7)(v7);
//                sub_140DB7CD4(v7);
//            }
//        }
//        v8 = *a3;
//        v24[0] = *a2;
//        v9 = a2[1];
//        v24[1] = v9;
//        if (v9)
//            _InterlockedIncrement((volatile signed __int32*)(v9 + 8));
//        v10 = sub_1411D8C4C(v8, v24);
//        v11 = *a2;
//        v12 = v10;
//        v13 = 0i64;
//        v14 = *(_BYTE*)(*a2 + 0x18D);
//        v28 = xmmword_14BD42E80;
//        v29 = xmmword_14BD42E80;
//        do
//        {
//            *(float*)((char*)&v29 + v13 + 16) = *(float*)((char*)&xmmword_14BD42E80 + v13) * 0.60000002;
//            v13 += 4i64;
//        } while (v13 < 16);
//        (*(void(__fastcall**)(_BYTE*))(*(_QWORD*)a1 + 96i64))(a1);
//        v21 = v14;
//        v31 = sub_1411D9790(v11, v15, v16, v12, &v28, v21);
//        v26[0] = (__int64)a2;
//        v26[2] = (__int64)&v31;
//        v26[1] = v12;
//        v25[1] = (__int64)v26;
//        v25[0] = (__int64)&unk_140D9A114;
//        sub_140D99CBC(a1, v25);
//        v27[0] = (__int64)a2;
//        v27[2] = (__int64)&v31;
//        v27[1] = v12;
//        v17 = ((__int64(__fastcall*)(char*, __int64*))sub_140D9A634)(v30, v27);
//        sub_140D99CBC(a1, v17);
//        v18 = *a2;
//        v22 = 0i64;
//        sub_140D9A5CC(&v22, *(_QWORD*)(v18 + 1608), *(unsigned int*)(v18 + 1616));
//        if ((int)v23 > 0)
//        {
//            v19 = v22;
//            v20 = v23;
//            do
//            {
//                sub_140D99820(a1, (__int64*)v19, a3);
//                v19 += 16i64;
//                --v20;
//            } while (v20);
//        }
//        result = sub_140D9A4C0(&v22);
//    }
//    return result;
//}



//48 89 5C 24 ? 57 48 83 EC 20 44 0F B7 01 48 8B FA 49 C1 E8 06 48 8D 51 04 48 8B D9 4D 03 C0 48 8B CF E8 - DA
//48 83 EC 28 80 3D ? ? ? ? ? 74 0C 48 8D 05 ? ? ? ? 48 83 C4 28 C3 48 8D 0D ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ? EB E6 - FNAME
//