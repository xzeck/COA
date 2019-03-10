# IEEE 754 Double Precision Converter

### 1. Aim 

The goal of the project is to make a working IEEE 754 converter, which allows the user to enter a positive or negative Integer or a floating point value and to get its equivalent in IEEE 754 format. 
	
Additionally the program aims to displaying the parts that make up the IEEE 754 format, _i.e_ Sign, Exponent, Mantisa. 

### 2. What is IEEE 754?

IEEE 754 is a technical standards used to represent floating point arithmetic which was established back in 1985 by **Institute of Electrical and Electronic Engineers**.

A standard IEEE 754 format consists of 
* Sign : __Single__ bit which  represents the sign of the given number. __0__ means its a __positive__ number and __1__ means its a __negative__ number. 
* Exponent : Consists of __11 bits__  which  gives shows the power by which the number is to be raised. For double precision format its 1023 + _< offset >_ 
* Fraction :  __52 bits__ consists of the rest of the numbers except the _1_ in the obtained decimal. 

### Use

IEEE 754 is the standard method used for representing floating-point arithmetic in computers. This system has been revised thrice and the current system that is being used is _IEEE 754-2008_ 

