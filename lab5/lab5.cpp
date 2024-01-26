//
//  main.cpp
//  lab5
//
//  Created by Patricia Antlitz on 3/27/23.
//
// Patricia Antlitz - Recorder - Patty recorded all names and roles, and was responsible for writing comments.
// Matt Catanzano - Manager - Matt separated the team by roles, was in charge of having the source code on his machine and upload the assignment on blackboard.
// Jacky Chiu - Presenter - Jacky made sure the team was on the same page and all questions were answered before we started coding
// Dylan LeDrew - Reflector - Dylan is responsible for answering the TA, Professor Lin, or the class with any questions they might have about the code.
//
//

#include <iostream>
using namespace std;

//requirement, write a class named COmplexNUmber
class ComplexNumber{
    
public:
    //default contructor
    ComplexNumber():realNumber(0), iNumber(0){}
    //values contructor
    ComplexNumber(double first, double second):realNumber(first), iNumber(second){}
    
    //create modifiers and accessors
    void setNum(double num)
    {
        iNumber = num;
    }
    
    void setRealNum(double num)
    {
        realNumber = num;
    }
    
    double getNum(void) const
    {
        return iNumber;
    }
    
    double getRealNum(void) const
    {
        return realNumber;
    }
    //output operator friend function
    friend ostream& operator<<(ostream& output, const ComplexNumber &obj);
    //operator overload
    ComplexNumber operator/(const ComplexNumber& rOp);
    ComplexNumber operator*(const ComplexNumber& rOp);
    ComplexNumber operator+(const ComplexNumber& rOp);
    ComplexNumber operator-(const ComplexNumber& rOp);
    ComplexNumber operator!();
    
private:
    //private data
    double realNumber;
    double iNumber;
};

ostream& operator<<(ostream& output, const ComplexNumber &obj);

int main(int argc, const char* argv[])
{
    //the main function was setup following the lab's requirements
    int i = 0;
    
    ComplexNumber c1;
    ComplexNumber c2(1, 2);
    ComplexNumber c3(3, 4);
    ComplexNumber c4;
    ComplexNumber c5;

    cout << "Value of c1 (default constructor):" << endl;
    cout << "c1.Re() == " << c1.getRealNum() << " c1.Im() == " << c1.getNum() << endl;
    
    cout << "Value of c2 (value constructor):" << endl;
    cout << "c2.Re() == " << c2.getRealNum() << " c2.Im() == " << c2.getNum() << endl;
    cout << endl;

    cout << "c2 + c3 (" << c2 << " + " << c3 << ") == " << (c2 + c3);
    cout << endl;
    cout << "c2 - c3 (" << c2 << " - " << c3 << ") == " << (c2 - c3);
    cout << endl;
    cout << "c2 * c3 (" << c2 << " * " << c3 << ") == " << (c2 * c3);
    cout << endl;
    cout << "c2 / c3 (" << c2 << " / " << c3 << ") == " << (c2 / c3);
    cout << endl;
    cout << "(c2 / c3) + (c2 * c3) == " << (c2 / c3) + (c2 * c3);
    cout << endl;
    cout << "Conjugate of c2 (" << c2 << ") == " << (!c2);
    cout << endl;
    cout << endl;
    
    cout << "Vector output using indexed for - loop:" << endl;
    
    for (i = 0; i < 10; i++)
    {
        int r = i * 2;
        ComplexNumber c5(i, r);
        cout << c5 << endl;
    }
    cout << endl << "Vector output using an iterator in for - loop:" << endl;
    
    for (i = 0; i < 10; i++)
    {
        ComplexNumber c6(1, 2);
        cout << c5 << endl;
        c5 = c5 + c6;
    }
    return 0;
}
//output/print
ostream& operator<<(ostream& output, const ComplexNumber &obj)
{
    output << obj.getRealNum() << " + " << obj.getNum() << " i ";
    return output;
}
//division
ComplexNumber ComplexNumber::operator/(const ComplexNumber& rOp)
{
    double reasonNum = (realNumber * rOp.realNumber + iNumber * rOp.iNumber) / (rOp.realNumber * rOp.realNumber + rOp.iNumber * rOp.iNumber);
    
    double imaginaryNum = (iNumber * rOp.realNumber - realNumber * rOp.iNumber) / (rOp.realNumber * rOp.realNumber + rOp.iNumber * rOp.iNumber);
    
    return ComplexNumber(reasonNum, imaginaryNum);
}
//multiplication
ComplexNumber ComplexNumber::operator*(const ComplexNumber& rOp)
{
    double reasonNum = (realNumber * rOp.realNumber - iNumber * rOp.iNumber);
    double imaginaryNum = (realNumber * rOp.iNumber + iNumber * rOp.realNumber);
    
    return ComplexNumber(reasonNum, imaginaryNum);
}
//addition
ComplexNumber ComplexNumber::operator+(const ComplexNumber& rOp)
{
    double reasonNum = realNumber + rOp.realNumber;
    double imaginaryNum = iNumber + rOp.iNumber;
    
    return ComplexNumber(reasonNum, imaginaryNum);
}
//subtraction
ComplexNumber ComplexNumber::operator-(const ComplexNumber& rOp)
{
    double reasonNum = realNumber - rOp.realNumber;
    double imaginaryNum = iNumber - rOp.iNumber;
    
    return ComplexNumber(reasonNum, imaginaryNum);
}

ComplexNumber ComplexNumber::operator!()
{
    double imaginaryNum = -(iNumber);
    
    return ComplexNumber(realNumber, imaginaryNum);
}
