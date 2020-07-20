Midterm Notes:
	##L1##
	1. identifiers(all user-defined variable names) cannot start with number, case sensitive. 
	2. 1 byte = 8 bits. float = 4 byte, double = 8 byte = double float.
	3. A 32-Bit Floating Point Value Has Three Components: sign bit, exponent(location of decimal point), mantissa(significant digits) 
	4. "\n" new line, as well as endl;
	5. Source Code(.cpp) ->(preprocessor)-> Object files(.o) ->(linker)-> Executable(a.out)
	6. (一些忽略的小点, magic formula) getline(cin, x);*(reads a texualline ending with newline, consuming the newline character  itself)* cin.ignore(<times of repeat>, '<until char to ignore>'); cin.get(<array>, <until index>); cout.setf(ios::showpoint); cout.setf(ios::fixed); cout.precision(<number>)  
	7. *在worksheet1* getline要读一个newline, 如果有了个'\n'或者按了回车来输入，有newline了，那么getline就会停止输入。 
	8. cin 的叠加：cin >> >> >> (values read are separated  by whitespace)

	##L2## 
	1. static_cast<type>(object)  convert double to int.
	2. Precedence Rules.
	3. 
