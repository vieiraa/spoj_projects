class Hash
    @@hash_table = Array.new(101, "empty")
    @@size = 0

    def hash_key(s)
        pos = 0

        (0...s.to_s.size).each do |i|
            pos += s[i].to_s.ord * (i+1)
        end

        pos *= 19

        return pos % 101
    end

    def find(s)
        if @@size == 0 then
            return -1
        end

        pos = hash_key(s.to_s)
        aux = pos

        for i in 1..20 do
            if s == @@hash_table[pos] then
                return pos
            end

            pos = ((aux + i*i + 23*i) % 101)
        end

        return -1
    end

    def clear
        for i in 0..100 do
            @@hash_table[i] = "empty"
        end

        @@size = 0
    end

    def insert(s)
        if @@size > 100 or find(s.to_s) > 0 then
            return 0
        end

        pos = hash_key(s)
        aux = pos

        for i in 1..20 do
            if @@hash_table[pos] == "empty" then
                @@hash_table[pos] = s
                @@size = @@size + 1

                return 1
            end

            pos = ((aux + i*i + 23*i) % 101)
        end

        return 0
    end

    def remove(s)
        if @@size == 0 then
            return 0
        end

        pos = find(s.to_s)
        # print "pos = #{pos}\n"

        if pos < 0 then
            return 0
        end

        @@hash_table[pos] = "empty"
        @@size = @@size - 1

        return 1
    end

    def show
        print "\n#{@@size}"

        for i in 0..100 do
            if @@hash_table[i] != "empty" then
                print "\n#{i}:#{@@hash_table[i]}"
            end
        end
    end
end

h = Hash.new

t = gets.chomp.to_i

(0...t).each do
    n = gets.chomp.to_i

    (0...n).each do
        op = gets.chomp
        key = op[4, op.size]

        if op[0] == "A" then
            if !(key == "") then
                h.insert(key)
            end

        else
            if !(key == "") then
                h.remove(key)
            end
        end
    end

    h.show
    h.clear
end
