***in exam multiple choice questions: match the anomaly to the definition (you will get data with one of three anomalies)
text questions: translate a control flow diagram to test sequence***
## Static testing & Compilers

Modern compilers are useful static analysis tools that can detect defects such as:
-  Syntax errors
-  Correct data type usage
-  Undeclared variables
-  Unreachable code
-  Variables that are used before they are set. 
-  Conditions that are constant.
-  Out-of-bounds addressing
-  Function and interface typing

This is assisted by ***data flow analysis and control flow analysis***.

## Data Flow Analysis

Concerned with **how data is used** on the different paths through the code.
There are 3 different usage states for each data variable.
-  **Undefined (u)** The data has no defined value.
-  **Defined (d)** The data is assigned a value.
-  **Referenced (r)** The data is used.

Data flow analysis **cannot detect errors**
But **it can identify anomalies** which may be high risk features:
-  **ur-anomaly** - An undefined data item is read on a program path.
-  **du-anomaly** - A data item that has been assigned a value becomes undefined without being used.
-  **dd-anomaly** - A data item that has been assigned a value is assigned another value without being used in the meantime 

### Example

```java
1 class Exchange {
2	public static void main(String[] args) {
3		int Help, Min=2, Max=4;
4		if (Min > Max)
5		{
6			Max = Help;
7			Max = Min;
8				Help = Min;
9		}
10	}
}
```

ur-anomaly In line 6 Help is used before it is assigned a value.
dd-anomaly in line 7 Max is assigned a value without using the value it was assigned in lines 6.
du-anomaly in line 8 Help is assigned a value, but is then never used within the scope of Exchange. 