#pragma once

static std::string RealGetNameFromFName(int key)
{
    uint32_t ChunkOffset = (uint32_t)((int)(key) >> 16);
    uint16_t NameOffset = (uint16_t)key;

    uint64_t NamePoolChunk = read<uint64_t>(globals::imagebase + 0xe145cc0 + (8 * ChunkOffset) + 16) + (unsigned int)(4 * NameOffset); //((ChunkOffset + 2) * 8) ERROR_NAME_SIZE_EXCEEDED
    uint16_t nameEntry = read<uint16_t>(NamePoolChunk);

    int nameLength = nameEntry >> 6;
    char buff[1024];
    if ((uint32_t)nameLength)
    {
        for (int x = 0; x < nameLength; ++x)
        {
            buff[x] = read<char>(NamePoolChunk + 4 + x);
        }
        char* v2 = buff; // rdi
        __int64 result; // rax
        unsigned int v5 = nameLength; // ecx
        __int64 v6; // r8
        char v7; // cl
        unsigned int v8; // eax

        result = 22i64;
        if (v5)
        {
            v6 = v5;
            do
            {
                v7 = *v2++;
                v8 = result + 45297;
                *(v2 - 1) = v8 + ~v7;
                result = (v8 << 8) | (v8 >> 8);
                --v6;
            } while (v6);
        }

        buff[nameLength] = '\0';
        return std::string(buff);
    }
    else
    {
        return "";
    }
}

static std::string GetNameFromFName(int key)
{
    uint32_t ChunkOffset = (uint32_t)((int)(key) >> 16);
    uint16_t NameOffset = (uint16_t)key;

    uint64_t NamePoolChunk = read<uint64_t>(globals::imagebase + 0xe145cc0 + (8 * ChunkOffset) + 16) + (unsigned int)(4 * NameOffset); //((ChunkOffset + 2) * 8) ERROR_NAME_SIZE_EXCEEDED
    if (read<uint16_t>(NamePoolChunk) < 64)
    {
        auto a1 = read<DWORD>(NamePoolChunk + 4);
        return RealGetNameFromFName(a1);
    }
    else
    {
        return RealGetNameFromFName(key);
    }
}

