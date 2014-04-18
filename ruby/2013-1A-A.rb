

file_content_array = IO.readlines('tiny.in')

T = file_content_array[0].to_i

for i in 1..T
	line_split = file_content_array[i].split(' ');
	r = line_split[0].to_i
	t = line_split[1].to_i

	puts "CASE #{i}: r=#{r} t=#{t}"

	

	puts "CASE #{i}: #{black_rings}"
end

