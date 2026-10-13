from Crypto.Cipher import AES
ciphertext = bytes.fromhex("4b0d83daa4c29be7882623c3beb0ae5feb3ddfdc71bc4bf6ced1c416547a9419")
def do_rand(x):
  if x == 0:
      x = 123459876
  hi = x // 127773
  lo = x % 127773
  x = 16807 * lo - 2836 * hi
  if x < 0:
      x += 0x7fffffff
  return x, x % 0x80000000

state = 0
key = bytearray()
for _ in range(16):
  state, r = do_rand(state)
  key.append(r % 256)
flag = AES.new(key, AES.MODE_CBC, bytes(16)).decrypt(ciphertext)
print (flag)
