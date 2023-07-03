
// ===========================================================================
/// <summary>
/// _1_Introduction.cpp
/// ModernCplusPlus
/// created by Mehrdad Soleimanimajd on 06.12.2019
/// </summary>
/// <created>ʆϒʅ, 06.12.2019</created>
/// <changed>ʆϒʅ, 03.07.2023</changed>
// ===========================================================================

#include "pch.h"
#ifdef _WIN32
#include "Console.h"
#else ifdef __APPLE__
#include "Terminal.h"
#endif


#define Tab '\t'
#define Nline '\n'


void _03_01_LanguageRuntimeEnhancements ()
{
    try
    {
        ColourCouter (" -------------------------------------------------", F_bRED, false);
        ColourCouter ("-------------------------------------------------\n\n", F_bRED, false);

        //! ####################################################################
        //! ~~~~~ language runtime enhancements:
        // after the introduction of enhancements of modern C++ to its usability,
        // the improvements concerning runtime are next
        // and all the concepts that extends it is in the following summarized.
        ColourCouter ("~~~~~ Language runtime enhancements:\n", F_bPURPLE, false);
        ColourCouter ("Language runtime represents all the features that effectively affect the performance of a program.\n\n", F_bYELLOW, true);
    } catch (const std::exception&)
    {

    }
}


void _03_02_LambadaExpressions ()
{
    try
    {
        //! ####################################################################
        //! ----- lambada expressions:
        // in modern C++ provided gate to anonymous function objects (closures), a very important feature,
        // is a concept to introduce functions without names and is supported by many scenarios,
        // there their presence is now almost a standard in modern programming languages.
        // the feature typically encapsulates a few lines, invoked or passed to algorithms or asynchronous methods.
        ColourCouter ("----- Lambada expressions:\n", F_bPURPLE, false);
        ColourCouter ("Lambada expressions wrap the concepts of anonymous functions.\n\n", F_bYELLOW, true);

        //! --- basics
        // note syntax:
        //           [capture-clause] (parameter-list) mutable exception-specification trailing-return-type { lambada-body }
        //! example: [=]              ()               mutable throw()                 -> int               { lambada-body }

        //! capture clause
        // capture clause, also known as lambada introducer, in simple form is utilized by
        // value '=' or by reference '&' to access variables of surrounding scope.
        // while legal to be kept empty and capture nothing, can also contain capture-defaults [=] and [&] specifications
        // to indicate how to access any outside variables and in what form, and even these can be mixed and introduced together.
        // a capture containing ellipsis indicate a pack expansion,
        // and obviously 'this' pointer need to be passed to a lambada within a class member function,
        // of which the *this form copies entire outside scope usable in parallelism and asynchronous operations.
        // note the practice of passing local variables by reference is lifetime dependent,
        // thus prone to runtime access violation errors.
        // note that from C++14, capture clause can initialize new not in outside scope declared variables,
        // introduced through any arbitrary expression and typed through deduction there of,
        // making even move-only variables (such as std::unique_ptr) capture-able.

        //! parameter list
        // optional parameter list specification, additionally known as lambada declarator,
        // resembles parameter list of a function, thus the possibility is provided to introduce input parameters
        // to the extend of generic ones and deduction of their types by using 'auto' keyword.
        // note that empty parenthesis can be omitted,
        // if lambada expression doesn't contain exception-specification, trailing-return-type or mutable

        //! mutable
        // optional mutable specification enables the modification to variables captured by value,
        // which in normal cases are captured as const-by-value, thus being able to modify them within the sphere of expression.

        //! exception specification
        // optional exception specification can be used to prevent lambada expression throwing exceptions,
        // when the keyword noexcept is introduced, which results to compiler warnings, if lambada expression indeed throws.

        //! return type
        // optional trailing-return-type specification resembles the return type of a function.
        // while return type of a lambada expression is deduced automatically,
        // the 'auto' keyword is needed, when specifying trailing-return-type,
        // which needs to be preceded by expression's parameter list

        ColourCouter ("Each lambada expression contains a number of specification, some of which are optional.\n\n", F_bYELLOW, true);
        std::vector<int> test (5, 0);

        for (auto& element : test)
        {
            element = [&] { return element + 1; }(); // an anonymous function on place which captures by value
        }
        for (const auto element : test)
        {
            std::cout << element << Tab;
        }

        std::cout << Nline;

        [&] // an anonymous function creating an anonymous function on each iteration
            {
                for (auto i = 0; i < test.size (); i++)
                {
                    [&] { test [i] += i * 2; }();
                }
            }();
            for (const auto element : test)
            {
                std::cout << element << Tab;
            }

            std::cout << Nline << Nline;

            auto number = std::make_unique<int> (5);
            auto sum = [=, count = std::move (number)](auto calc) // an anonymous function which captures by expression and note that the exclusive pointer is first transferred to rvalue.
                // additionally pay attention to the use of generic parameter
                {
                    auto [sum, sign] = std::tuple<int, std::string> (std::make_tuple (0, "For result enable calculation!"));
                    for (auto i = 0; i < *count; i++)
                    {
                        sum += test [i];
                    }
                    if (calc)
                    {
                        if (sum % 2 == 0)
                            sign = "even";
                        else
                            sign = "odd";
                    }
                    return std::make_tuple (sum, sign);
                };
            auto [tempA, tempB] = std::tuple<int, std::string> (sum (0));
            std::cout << "The sum of elements is:" << Tab << tempA << Tab << "which is " << tempB << Nline << Nline;
    } catch (const std::exception&)
    {

    }
}


using ptr = void (int); // function pointer
void caller (ptr toCall) { toCall (2); }

int aFunction (int input) { return input + 1; }

int theFunction (int a, int b, int c) { return a + b + c; }
void _03_03_FunctionObjectWrapper ()
{
    try
    {
        //! ####################################################################
        //! ----- function object wrapper: 
        // modern C++ language is able to encapsulate function objects to enhance runtime capabilities.
        ColourCouter ("----- Function object wrapper:\n", F_bPURPLE, false);
        ColourCouter ("C++ standard features to safely wrap function objects.\n\n", F_bYELLOW, true);

        //! --- introduction
        // since a lambada expression (an object of class type known as closure type) is essentially
        // similar to a function object type (known as closure object),
        // when one is introduced with empty capture list, it is convertible to a function pointer.
        // note that the type of objects that can be called is collectively called callable type.
        ColourCouter ("In C++ language, it is possible to unsafely convert a closure type.\n\n", F_bYELLOW, true);
        auto closure = [](int input) { std::cout << input + 1 << Tab; };
        closure (2);
        caller (closure); // unsafe call using function pointer
        std::cout << Nline << Nline;

        //! --- std::function
        // to safely wrap the concepts of callable objects, overcoming the limits of previous approach,
        // and in the same time being able to store, copy and call target entities there of,
        // modern C++ introduces the generic, polymorphic function wrapper as a standardised container,
        // which seamlessly handles functions and function pointers as objects.
        // note the ease that the container offers while putting the drawbacks aside.
        ColourCouter ("Standard modern C++ container to wrap callable objects is function facility.\n\n", F_bYELLOW, true);
        std::function<int (int)> testOne = aFunction; // taking one int parameter and returning an int
        std::function<int (int)> testTwo = [&](int input) { return input + 1; };
        std::cout << testOne (2) << Tab << testTwo (2) << Nline << Nline;

        //! --- std::bind and std::placeholder
        // modern C++ offers the possibility to bind some parameters of a function in an expression
        // combined of bind function and placeholder namespace introduced under standard C++ library.
        // the result of the expression is then a callable safely wrapped object.
        // placeholder namespace provides the needed functionality with which some parameters can be passed later on.
        // note that the complex output type of bind function is circumvented using the 'auto' keyword.
        ColourCouter ("In modern C++, the parameters of callable objects can be wrapped and bound together in an arbitrary manner.\n\n", F_bYELLOW, true);
        auto boundParameters = std::bind (theFunction, std::placeholders::_1, 3, 3);
        std::cout << boundParameters (3) << Nline << Nline;
    } catch (const std::exception&)
    {

    }
}


void _03_04_RValueReference ()
{
    try
    {
        //! ####################################################################
        //! ----- : rvalue reference
         // 
        ColourCouter ("----- rvalue reference:\n", F_bPURPLE, false);
        ColourCouter (".\n\n", F_bYELLOW, true);




        //ColourCouter ( "\n", F_bYELLOW );
        //ColourCouter ( "\n", F_bCYAN );
        //! - in addition:

    } catch (const std::exception&)
    {

    }
}
