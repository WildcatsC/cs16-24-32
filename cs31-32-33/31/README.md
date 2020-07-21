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
	2. Precedence Rules. (Arithmetic Operators Have Higher Precendence Than Relational Operators)
	3. do-while最后记得加分号，而且是后检验 注意**do-while loop will always execute at least once** 
	4. 不能 int i, j = 0;
	5. cout.setf( ios::boolalpha );   // to show bools as “true” or “false”

##L3##
	1. pass by ref 会动原来的值，pass by value 不会
	2. overload function 不能只搞不同返回类型而全同的参数。
	3. switch没break的话就会执行下一个case
	4. **Function Prototype** 

##L4##
	1. defualt parameter 只需要写一次。例如在function propotype里面。
	2. <cmath>  floor, ceil, fabs, sqrt	
	3. <cctype>   isdigit, isupper, islower
	4. <cassert>  assert(); Add "#define" line before #include line: Turns OFF all assertions throughout program 
	5. <cstdlib> exit();
	6. PostFixand Prefix ++, -- Operators **precedence rules** 
	7. An enumeration is a distinct type: include several explicitly named constants ("enumerators")
	8. returning more than one value from your function, you’ll need to use reference parameters 来直接改动原来的ref
	9. array[size] 以后，如果中间有被赋值的，那其他没赋值的都变成0
	10. array[]的话必须要有{}来直接initialize
	11. array as parameter Very Similar To “Pass By Reference”: address of array[0] is passed
	12. C++ allows any number of indexes (dimensions)
	
