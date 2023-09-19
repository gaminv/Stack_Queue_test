#include <iostream>
#include <string>
#include "StackArray.h"
#include "QueueArray.h"
#include "StackOverflow.h"
#include "StackUnderflow.h"
#include "WrongStackSize.h"

bool checkBalanceBrackets(const std::string& text, const int maxDeep);

int main()
{
    try {
        // создание очереди с максимальным размером 5
        Queue<int>* queue = new QueueArray<int>(5);
        queue->enQueue(1);
        queue->enQueue(2);
        queue->enQueue(3);
        queue->enQueue(4);
        queue->enQueue(5);
        // Раскомментирование следующей строки вызовет исключение, поскольку очередь уже заполнена.
        //queue->enQueue(6);

   // Удаление из очереди всех элементов в очереди
        while (!queue->isEmpty()) {
            std::cout << queue->deQueue() << " ";
        }

        // создание стека с максимальным размером 5
        Stack<int>* stack = new StackArray<int>(5);
        stack->push(1);
        stack->push(2);
        stack->push(3);
        stack->push(4);
        stack->push(5);

        // Раскомментирование следующей строки вызовет исключение, потому что стек уже заполнен
        //stack->push(6);

        // Извлечение всех элементов в стеке
        while (!stack->isEmpty()) {
            std::cout << stack->pop() << " ";
        }

        // Проверка наличия сбалансированных скобок в строке
        std::string str1 = "(([]))";
        std::string str2 = "([)])";
        bool res1 = checkBalanceBrackets(str1, 3);
        bool res2 = checkBalanceBrackets(str2, 3);
        std::cout << std::boolalpha << res1 << " " << res2 << std::endl;

        delete queue;
        delete stack;

    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

bool checkBalanceBrackets(const std::string& text, const int maxDeep)
{
    Stack<char>* temp = new StackArray<char>(text.size());

    int roundCount = 0;
    int squareCount = 0;
    int curlyCount = 0;
    for (int i = 0; i < text.size(); i++)
    {
        char siqn = text[i];
        switch (siqn)
        {
        case '(':
            if (roundCount + squareCount + curlyCount >= maxDeep)
                return false;
            roundCount++;
            temp->push(siqn);
            break;
        case ')':
            if (roundCount == 0 or temp->pop() != '(')
                return false;
            roundCount--;
            break;
        case '[':
            if (roundCount + squareCount + curlyCount >= maxDeep)
                return false;
            squareCount++;
            temp->push(siqn);
            break;
        case ']':
            if (squareCount == 0 or temp->pop() != '[')
                return false;
            squareCount--;
            break;
        case '{':
            if (roundCount + squareCount + curlyCount >= maxDeep)
                return false;
            curlyCount++;
            temp->push(siqn);
            break;
        case '}':
            if (curlyCount == 0 or temp->pop() != '{')
                return false;
            curlyCount--;
            break;
        }
    }

    bool result = temp->isEmpty() and roundCount == 0 and squareCount == 0 and curlyCount == 0;
    delete temp;
    return result;
}