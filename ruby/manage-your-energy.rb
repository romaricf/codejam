def readIntLine()
	return STDIN.readline.split(' ').map! { |x| x.to_i }
end
def readFloatLine()
	return STDIN.readline.split(' ').map! { |x| x.to_f }
end
def readStrLine()
	return STDIN.readline.chomp.split(' ')
end


def solve()
	e, r, n = readIntLine()
	v = readIntLine()
	gain = 0
	maxIdx = (0..(n - 1)).to_a
	maxIdx.sort! { |a, b|
		v[a] <=> v[b]
	}

	while maxIdx.length > 0
		idx = maxIdx.pop()
		before = idx - 1
		after = idx + 1

		#puts "idx" + idx.to_s
		while after < n && v[after] != -1
			after += 1
		end

		while before >= 0 && v[before] != -1
			before -= 1
		end
		
		energy = (before == -1) ? e : [(idx - before) * r, e].min
		remain = after == n ? 0 : [e - (after - idx) * r, 0].max
		spend = [energy - remain, 0].max

		#puts "gain" + (spend * v[idx]).to_s
		gain += spend * v[idx]
		v[idx] = -1
	end
	return gain



=begin
	v.sort!
	totalE = e + [r, e].min * (n - 1)
	gain = 0
	currentE = totalE
	while v.length > 0
		spent = [currentE, e].min
		currentE -= spent
		gain += v.pop() * spent
	end
	return gain
=end
end

STDIN.gets.to_i.times do |i|
	print "Case #", i + 1 , ": "
	puts solve()
end
