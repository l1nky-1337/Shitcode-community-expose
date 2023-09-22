#ifndef DECRYPTANSI_HPP
#define DECRYPTANSI_HPP
//48 89 05 ? ? ? ? 0F 28 D7 - GWORLD : STAT_UGameEngine_Tick_TickWorldTravel
//
//48 89 5C 24 ? 57 48 83 EC 20 44 0F B7 01 48 8B FA 49 C1 E8 06 48 8D 51 ? 48 8B D9 4D 03 C0 48 8B CF E8 - DA
//48 83 EC 28 80 3D ? ? ? ? ? 74 0C 48 8D 05 ? ? ? ? 48 83 C4 28 C3 48 8D 0D ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ? 48 83 C4 28 C3 - FNAME
uintptr_t Gworld = 0xEE9ED98;
uintptr_t FNameOffset = 0xeb03740;
static std::string DecryptAnsi(int Name)
{
        uint32_t COffset = (uint32_t)((int)(Name) >> 16);
        uint16_t NOffset = (uint16_t)Name;

        uint64_t NPC = ctx->read_physical_memory<uint64_t>(DriverVar::module + FNameOffset + (8 * COffset) + 16) + (unsigned int)(2 * NOffset);
        uint16_t Entry = ctx->read_physical_memory<uint16_t>(NPC);

        int Lenght = Entry >> 6;
        char buffer[4096];
        if ((uint32_t)Lenght)
        {
            for (int x = 0; x < Lenght; ++x)
            {
                buffer[x] = ctx->read_physical_memory<char>(NPC + 2 + x);
            }

   
           

            char* v2 = buffer; // rdi
            int v4 = Lenght; // ebx
            __int64 result; // rax
            int v6; // er8
            unsigned int v7; // ecx
            char v8; // dl

            result = ctx->read_physical_memory<int>(DriverVar::module + 0xeb03740) >> 5;
            v6 = 0;
            if (v4)
            {
                do
                {
                    v7 = *v2++;
                    v8 = result ^ (16 * v7) ^ (result ^ (v7 >> 4)) & 0xF;
                    result = (unsigned int)(result + 8 * v6++);
                    *(v2 - 1) = v8;
                } while (v6 < v4);
            }
            buffer[Lenght] = '\0';
            return std::string(buffer);
        }
        else
        {
            return "Error Decrypt Ansi";
        }
}

static std::string GetNameByIndex(int Name)
{
    uint32_t COffset = (uint32_t)((int)(Name) >> 16);
    uint16_t NOffset = (uint16_t)Name;

    uint64_t NPC = ctx->read_physical_memory<uint64_t>(DriverVar::module + FNameOffset + (8 * COffset) + 16) + (unsigned int)(2 * NOffset);
    if (ctx->read_physical_memory<uint16_t>(NPC) < 64)
    {
        auto a1 = ctx->read_physical_memory<_QWORD>(NPC + 2);
        return DecryptAnsi(a1);
    }
    else
    {
        return DecryptAnsi(Name);
    }
}



#endif