
// --------------------------------------------------------------------------------
/// <summary>
/// _1_Introduction.cpp
/// </summary>
/// <created>ʆϒʅ,27.11.2019</created>
/// <changed>ʆϒʅ,28.11.2019</changed>
// --------------------------------------------------------------------------------

#include "pch.h"
#include "Console.h"


#define Tab '\t'
#define Nline '\n'


void _02_01_LanguageUsabilityEnhancements ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "-------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ language usability enhancements:
    // the very same procedure of bringing an algorithm while using the concepts of a programming language,
    // such as declaration, definition of variables, constants, etc. program flow control, object-oriented paradigms,
    // implemented abstracts with the use of templates, concluding this sentence and using other words,
    // whatever occurred before the runtime at the coding or compiling stages is known as language usability,
    // which summarizes the language behaviour at these stages.

    ColourCouter ( "~~~~~ Language usability enhancements:\n", F_bWHITE );
    ColourCouter ( "Language usability wraps the way in which a language represents the algorithm on a program.\n\n", F_YELLOW );
  }
  catch (const std::exception&)
  {

  }
}


constexpr int len_function_constexpr ( const int& n )
{
  // starting from C++ 14, internal use of simple statements like local variables, loops and branches

  // to nerds, from time to time have fun setting functions at eternal recursivity! :)
  if (n < 3)
    return len_function_constexpr ( n + 1 );
  else if (n > 3)
    return len_function_constexpr ( n - 1 );
  else
    return n;
}
void _02_02_Constants ()
{
  try
  {
    //! ####################################################################
    //! ----- constants:

    //! nullptr
    // considering 0 and NULL, which is defined as 0 or ((void*)0) in different compilers, while traditional C++ treats them the same,
    // they result to counter-intuitive code when putting overload feature into practice.
    // in this scenario, nullptr concept appears to replace NULL, whenever defining a pointer,
    // of which the type is nullptr_t, can implicitly be converted to any pointer of different types
    // and is equally or unequally comparable to them.

    //! constexpr
    // as a compiler encounters constant expressions like 1+2, 3*4, to increase the performance of the program,
    // the procedure of direct optimization is thought to embed them into result at compile time.
    // with this feature compilation of a lot of illegal expression becomes possible, on the other hand using constexpr,
    // it is possible to explicitly declare the functions or constructors as compile time constant expressions.
    // the constexpr keyword supports the recursivity feature of a function.

    ColourCouter ( "----- Constants:\n", F_bWHITE );
    ColourCouter ( "Use nullptr keyword to solve the confusion when using overloads.\n", F_YELLOW );
    ColourCouter ( "Use constexpr to explicitly define elaborated language concepts as constant expressions.\n\n", F_YELLOW );

#define len_define 3
    const int len { len_define - 3 + 3 }; // legal for mast compilers
    constexpr int len_constexpr { 0 + 1 + 2 };
    std::string arrayOfString_1 [len] { "" };
    std::string arrayOfString_2 [len_constexpr] { "" };
    std::string arrayOfString_3 [len_function_constexpr ( 0 )] { "" };

    arrayOfString_1 [0] = "First storage place of array one!\n";
    arrayOfString_2 [0] = "First storage place of array two!\n";
    arrayOfString_3 [0] = "First storage place of array three!\n";

    std::cout << arrayOfString_1 [0] << arrayOfString_2 [0] << arrayOfString_3 [0] << Nline;
  }
  catch (const std::exception&)
  {

  }
}


void _02_03_VariablesAndInitialization ()
{
  try
  {
    //! ####################################################################
    //! ----- variables and initialization:
    ColourCouter ( "----- Variables and initialization:\n", F_bWHITE );

    //! if-switch
    // traditional C++ lacks the support for declarations within the if and switch statements,
    // for which C++ 17 provides the needed concepts to eliminate this limitation.
    ColourCouter ( "Declarations within the control statements if and switch are possible.\n\n", F_YELLOW );
    std::vector<char> container = { '|', ':', ')' };
    if (
      std::vector<char>::iterator entity = std::find ( container.begin (), container.end (), ':' );
      entity != container.end ()
      )
    {
      std::cout << *entity << *(entity - 1) << Nline << Nline;
    }

    //! initializer list
    // to declare and initialize an object of a class using uniform initialization method,
    // C++ binds the concepts of initialization list to the type and wraps it under std::initializer_list container.
    // note that this method is additionally usable with normal functions.
    ColourCouter ( "It is possible to use initializer lists when instantiating an object.\n\n", F_YELLOW );
    class SomeType
    {
    public:
      std::vector<char> container;
      std::string character;
      SomeType ( std::initializer_list<char> input )
      {
        for (std::initializer_list<char>::iterator entity = input.begin (); entity != input.end (); entity++)
        {
          if (*entity == ':')
            character = *entity;
          else
            container.push_back ( *entity );
        }
      }
    };
    SomeType theObject { '|', ':', ')' };
    for (short i = 0; i < theObject.container.size (); i++)
    {
      std::cout << theObject.character << theObject.container [i] << Tab;
    }
    std::cout << Nline << Nline;

    //! structured binding
    // to enclose multiple type bound together and wrapped as a container, C++ provides std::tuple,
    // consumable as function parameters and while its usefulness is clear, the procedure in C++ 11/14 are troublesome:
    //-- there is no simple direct way to define and get the elements from tuple itself
    //-- despite unpack feasibility through std::tie, the developer must be very clear about number of objects and their types.
    // C++ 17 builds upon this container to bring about the possibility to leverage its power.
    ColourCouter ( "To introduce different objects bound together as an entity.\n\n", F_YELLOW );
    auto [a, b, c] = std::tuple<int, float, char> ( std::make_tuple ( 1, .2f, 'c' ) );
    std::cout << a << Tab << b << Tab << c << Tab << Nline << Nline;
  }
  catch (const std::exception&)
  {

  }
}


void _02_04_TypeInference ()
{
  try
  {
    //! ####################################################################
    //! ~~~~~ type inference:
    // 
    ColourCouter ( "~~~~~ Type inference:\n", F_bWHITE );
    ColourCouter ( ".\n\n", F_YELLOW );



    //ColourCouter ( "\n", F_bYELLOW );
    //ColourCouter ( "\n", F_bCYAN );
    //! - in addition:
  }
  catch (const std::exception&)
  {

  }
}
