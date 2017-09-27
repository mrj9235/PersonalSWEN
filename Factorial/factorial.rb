# factorial(n) is defined as n*n-1*n-2..1 for n > 0
# factorial(n) is 1 for n=0
# Let's raise an exception if factorial is negative
# Let's raise an exception if factorial is anything but an integer

def factorial(n)
  if(n < 0)
    raise ArgumentError
  end

  if(n.is_a? String)
    raise ArgumentError
  end
 
  tot = 1
  while n > 1
    tot *= n
    n -= 1
  end

  return tot
end
