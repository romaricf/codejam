def check(r, t, k)
  (2 * k * r + (2 * k - 1) * k) <= t
end

gets.to_i.times do |test_count|
  r, t = gets.split.map(&:to_i)

  low = 0 
  high = 10 ** 20
  while low < high
    middle = low + high + 1 >> 1
    if check(r, t, middle)
      low = middle
    else
      high = middle - 1
    end
  end
  puts "Case \##{test_count + 1}: #{low}"
end
