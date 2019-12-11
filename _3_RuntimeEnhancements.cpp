
// --------------------------------------------------------------------------------
/// <summary>
/// _1_Introduction.cpp
/// </summary>
/// <created>ʆϒʅ,06.12.2019</created>
/// <changed>ʆϒʅ,12.12.2019</changed>
// --------------------------------------------------------------------------------

#include "pch.h"
#include "Console.h"


#define Tab '\t'
#define Nline '\n'


void _03_01_LanguageRuntimeEnhancements ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "-------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ language runtime enhancements:
    // after the introduction of enhancements of modern C++ to its usability,
    // the improvements concerning runtime comes on the row
    // and the whole of all the concepts that extends it comes in the following.
    ColourCouter ( "~~~~~ Language runtime enhancements:\n", F_bWHITE );
    ColourCouter ( "Language runtime represents all the features that effectively affect the performance of a program.\n\n", F_YELLOW );



    //ColourCouter ( "\n", F_bYELLOW );
    //ColourCouter ( "\n", F_bCYAN );
    //! - in addition:
  }
  catch (const std::exception&)
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
    // concept by need to introduce functions without names, supported by many scenarios,
    // in them their presence is now almost a standard in modern programming languages.
    // the feature typically encapsulates a few lines, invoked or passed to algorithms or asynchronous methods.
    ColourCouter ( "----- Lambada expressions:\n", F_bWHITE );
    ColourCouter ( "Lambada expressions wrap the concepts of anonymous functions.\n\n", F_YELLOW );

    //! --- basics
    // note syntax:
    //           [capture-clause] (parameter-list) mutable exception-specification trailing-return-type { lambada-body }
    //! example: [=]              ()               mutable throw()                 -> int               { lambada-body }

    //! capture clause
    // capture clause, also known as lambada introducer,
    // introduces by value '=' or by reference '&' accessed variables of surrounding scope,
    // while legal to be kept empty and capture nothing, can contain capture-defaults [=] and [&] specifications
    // to indicate how to access any outside variables and in what form, and even these can be mixed and introduced together.
    // a capture containing ellipsis indicate a pack expansion,
    // and probably 'this' pointer need to be passed to a lambada within a class member function,
    // of which the *this form copies entire outside scope usable in parallelism and asynchronous operations.
    // note the practice of passing local variables by reference is lifetime dependent,
    // thus prone to runtime access violation errors.
    // note that from C++14, capture clause can initialize new not in outside scope declared variables,
    // introduced through any arbitrary expression and typed through deduction there of,
    // making even move-only variables (such as std::unique_ptr) capture-able.

    //! parameter list
    // optional parameter list specification, additionally known as lambada declarator,
    // resembles parameter list of a function,
    // thus giving the possibility to introduce input parameters even generic ones,
    // when the type of the parameter is deducted using 'auto' keyword.
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

    ColourCouter ( "Each lambada expression contains a number of specification, some of which are optional.\n\n", F_YELLOW );
    std::vector<int> test ( 5, 0 );

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

    auto number = std::make_unique<int> ( 5 );
    auto sum = [=, count = std::move ( number )] // an anonymous function which captures by expression
    {
      int temp { 0 };
      for (auto i = 0; i < *count; i++)
      {
        temp += test [i];
      }
      return temp;
    };
    std::cout << "The sum of elements is:" << Tab << sum () << Nline << Nline;
  }
  catch (const std::exception&)
  {

  }
}
