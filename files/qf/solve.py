from pwn import *
import pefile

pe = pefile.PE("main.exe")
#print("ImageBase: " + hex(pe.OPTIONAL_HEADER.ImageBase))
rva = 0x416210 - pe.OPTIONAL_HEADER.ImageBase
data = pe.get_data(rva, 24)

flag_bytes = []
for byte in data:
    i = byte ^ 0x5a
    if i == 0x20:
        i = 0x5f
    flag_bytes.append(i)

flag = bytes(flag_bytes)
print(flag.decode())
