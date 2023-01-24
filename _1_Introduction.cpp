
// --------------------------------------------------------------------------------
/// <summary>
/// _1_Introduction.cpp
/// ModernCplusPlus
/// created by Mehrdad Solimanimajd on 27.11.2019
/// </summary>
/// <created>ʆϒʅ, 27.11.2019</created>
/// <changed>ʆϒʅ, 23.01.2023</changed>
// --------------------------------------------------------------------------------

#include "pch.h"
#ifdef _WIN32
#include "Console.h"
#elifdef __APPLE__
#include "Terminal.h"
#endif


void _01_01_Introduction ()
{
  try
  {
    ColourCouter ( " -------------------------------------------------", F_bRED );
    ColourCouter ( "-------------------------------------------------\n\n", F_bRED );

    //! ####################################################################
    //! ~~~~~ modern C++ language:
    // C++ 11 version has been accumulated in a span stretched over a decade,
    // of which the 14 and 17 versions is an important complement,
    // and the most recent version (20) open the doors of modernization to this decent language.
    // with vitality infused language through all these new features,
    // it introduces an old long lasting cross-platform development tool anew.
    // introduced enhancement in usability, manipulation of complex template types through auto keyword,
    // improvements to language runtime, template parameters verification on the compile-time,
    // emergence of Lambada expressions as the gate to anonymous functions,
    // a feature already commonplace in modern programming language such as Python/Swift and
    // solving the long criticized temporary objects efficiency by introducing the rvalue references
    // are just some to mention.
    // C++ community has been promoting an important development direction from 17th version forward,
    // mentioning structured binding as an example,
    // the correction of programming paradigm in C++ language is the intention
    // to further upholding C++ as a better language for system programming and library development,
    // the extended library to concurrent programming std::thread at the language level
    // for no dependence on underlying system and full regular expression support through std::regex
    // are some of which.
    // well as an advancement freak and at this introduction end, technology stops at no hurdle,
    // with this in mind, the development promotion and a more vibrant future of this
    // old novel language is encouraged by acceptance of new things added to it.
    // in conclusion of all this,
    // having a compiler with the ability to support the most recent feature is self-explanatory.
    // to be noted, a C++ programmer doesn't need to learn all of these new features all at 
    // once as part of the language and through the provided index,
    // each can be learnt upon the urgency the use of it dictates.
    // while the following claims to stay brief and exact and comprehensible,
    // provides some dark magic of C++ to be learnt for every interested programmer,
    // and if the interest in advanced C++ is there, this dark magic is limited and unsuitable.
    // with every advancement in the concepts of each programming language, some deprecations follow,
    // for every feature the compilers flag, this fact in mind,
    // most of these deprecations are permanently reserve to support backward compatibility.
    // additionally the following writing doesn't concern itself to introduce them,
    // and when interested, the research is due.
    ColourCouter ( "~~~~~ Modern C++ language:\n", F_bPURPLE );
    ColourCouter ( "The constant evolution of the C++ language over the years, make the use of a compiler with "
                   "support for the most recent feature self-explanatory.\n\n", F_YELLOW );

    //! ####################################################################
    //! ----- C++ compilers:
    // rewriting the code in high-level language to machine language happens with the help of special 
    // programs called compilers, interpreters or assemblers based on the type of the high level language.
    // C++ language is designed to be a compiled language, therefore its code generally get translated 
    // into machine language, which results to a highly efficient program.
    // for this purpose, a set of tools, known as development toolchain, are needed,
    // whose core are a compiler and its linker.
    ColourCouter ( "----- C++ Compilers:\n", F_bPURPLE );
    ColourCouter ( "The compilers job are to rewrite the code in higher level language into machine language, "
                   "which have been built into various programming applications\n\n", F_YELLOW );

    //! ####################################################################
    //! ----- console programs:
    // the fact of easy interaction, simple implementation and identical behaviour of console programs 
    // across all platforms make them very useful to learn the basics of a programming language.
    // the programmer's decision to use a particular tool defines the way,
    // in which a console program get compiled.
    ColourCouter ( "----- Console programs:\n", F_bPURPLE );
    ColourCouter ( "They are programs that use characters to communicate with user and their environment "
                   "i.e. printer, keyboard etc.\n\n", F_YELLOW );

    //! ####################################################################
    //! ----- IDE:
    // generally several development tools get integrated in an IDE,
    // which includes a text editor and tools to compile the program directly.
    // some free IDE's:
    // ---------------------------------------------
    // IDE                      Platform
    // ---------------------------------------------
    // Code::blocks             Windows/Linux/MacOS
    // ---------------------------------------------
    // Visual Studio Express    Windows
    // ---------------------------------------------
    // Dev-C++                  Windows
    // ---------------------------------------------
    ColourCouter ( "----- IDE:\n", F_bPURPLE );
    ColourCouter ( "The easiest way for a beginner is to use an Integrated Development "
                   "Environment (IDE).\n\n", F_YELLOW );

    //! - in addition:
    // if there is a Linux or Mac environment with development features at disposal,
    // including the C++11 flags in the command for the compiler, any code could be compilable.
    // ----------------------------------------------------------------------------------------------------------
    // IDE          Platform                    Command
    // ----------------------------------------------------------------------------------------------------------
    // GCC          Linux, among others...      g++ -std=c++0x example.cpp -o example_program
    // ----------------------------------------------------------------------------------------------------------
    // Clang        OS X, among others...       clang++ -std=c++2a -stdlib=libc++ example.cpp -o example_program
    // ----------------------------------------------------------------------------------------------------------
  }
  catch (const std::exception&)
  {

  }
}
