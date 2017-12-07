#include<iostream>
#include<stack>



int calculation(int operand1, int operand2, char operation) {
   switch (operation) {
      case '+': return operand2 + operand1;
      case '-': return operand2 - operand1;
      case '*': return operand2 * operand1;
      case '/': return operand2 / operand1;
      default : return 0;
   }
}

int PostfixCalculation(std::string postfix, int size) {
   std::stack<int> stakingStack;
   int i = 0;
   int digitCheck=0, operandCheck =0; //to catch the error from the user
   char ch;
   int result;
   while (i < size) {
      ch = postfix[i];
      if (isdigit(ch)) {
         stakingStack.push(ch -'0');
         digitCheck++;
      }
      else {
        int operand1 = stakingStack.top();
         stakingStack.pop();
         int operand2 = stakingStack.top();
         stakingStack.pop();
         result = calculation(operand1, operand2, ch);
         stakingStack.push(result);
         operandCheck++;
      }
      i++;
   }
    if(operandCheck==0){
        std::cout << "No operands provided.\nPlease enter an operand to evaluate your expression.\n";
    }
    else if((digitCheck-operandCheck)!=1){ //for proper expression the difference has to be 1
        std::cout << "Not enough operands.\nPlease retype your expression.\n";
    }
    else{
        return result;
    }
}


int main() {

   std::string postfixInput;
   std::cout << "Welcome to the world of programming!\n\n";
   std::cout << "Would you be kind to type a postfix expression for me to evaluate?\n";
   std::cout << "Type here and press enter (or enter q to quit): ";
   getline(std::cin, postfixInput);
   while(postfixInput!="q"){
       int result = PostfixCalculation(postfixInput, postfixInput.length());
       std::cout << "The result of your input is "<< result << "\n";
       std::cout << std::endl;
       std::cout << "Maybe one more postfix expression? ";
       getline(std::cin, postfixInput);
   }
   return 0;
}
