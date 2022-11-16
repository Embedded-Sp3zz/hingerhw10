# cube.py

def cb(num):
  return pow(num,3)

for x in range(20):
  if (x % 2) == 0:
    print(x)
  else:
    print(cb(x))
