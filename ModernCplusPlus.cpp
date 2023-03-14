
// --------------------------------------------------------------------------------
/// <summary>
/// ............................::Nerd snow sayings!::............................
/// nerd Snow's sayings!
/// Learning C++
/// Programming needs patience and practical practice.
/// Programming in a way, that no nerdy dog in the future is able to compile it, is to be avoided!
/// I was almost a good nerd and emptied my Recycle Bin regularly at the night! :) So be a lamb (^.^) and stay a good nerd!
/// In the source code encountered in mind foreseen as future todos can be seen as such tasks that encourage the nerd community... :|
/// ModernCplusPlus.cpp
/// ModernCplusPlus
/// created by Mehrdad Soleimanimajd on 27.11.2019
/// </summary>
/// <created>ʆϒʅ, 27.11.2019</created>
/// <changed>ʆϒʅ, 14.03.2023</changed>
// --------------------------------------------------------------------------------

#include "pch.h"
#ifdef _WIN32
#include "Console.h"
#elifdef __APPLE__
#include "Terminal.h"
#define CHOOSE "Pick"
#endif
#include "_1_Introduction.h"
#include "_2_UsabilityEnhancements.h"
#include "_3_RuntimeEnhancements.h"


#define Tab '\t'
#define Nline '\n'


int main ()
{
  try
  {
#pragma region Console
    // font
#ifdef _WIN32
    COORD fontS { 15,15 };
    ConsoleFont ( L"Lucida Sans Typewriter" );
    ConsoleFontSize ( fontS );
    ConsoleFontColour ( F_WHITE );
    // screen
    COORD leftANDtop { 15,15 };
    COORD widthANDheight { 90,40 };
    COLORREF backColour { RGB ( 50,50,50 ) };
    ConsoleScreenPosition ( leftANDtop );
    ConsoleScreenSize ( widthANDheight );
    ConsoleScreenColour ( backColour );
#endif

    //// cursor
    //ConsoleCursorState ( false );

    //// codec
    //UINT consoleOutputCPstorage;
    //consoleOutputCPstorage = GetConsoleOutputCP ();
    //SetConsoleOutputCP ( CP_UTF8 );

    //// back to default codec
    //SetConsoleOutputCP ( consoleOutputCPstorage );
#pragma endregion

    //! ...................................:: References ::...................................
    // https://changkun.de/modern-cpp/en-us/00-preface/index.html
    // http://www.cplusplus.com/doc/
    // https://stackoverflow.com/
    // http://de.cppreference.com/
    // https://docs.microsoft.com/
    // https://www.ibm.com/support/knowledgecenter/en/
    // https://www.tutorialspoint.com/cplusplus/
    // C++ reference: http://www.cplusplus.com/reference/
    ColourCouter ( " -------------------------------------------------", F_bRED, false );
    ColourCouter ( "-------------------------------------------------\n", F_bRED, false );
    ColourCouter ( "References:\n", F_bPURPLE, false );
    ColourCouter ( "https://changkun.de/modern-cpp/en-us/00-preface/index.html\n", F_YELLOW, true );
    ColourCouter ( "http://www.cplusplus.com/doc/\n", F_YELLOW, true );
    ColourCouter ( "https://stackoverflow.com/\n", F_YELLOW, true );
    ColourCouter ( "http://de.cppreference.com/\n", F_YELLOW, true );
    ColourCouter ( "https://docs.microsoft.com/\n", F_YELLOW, true );
    ColourCouter ( "https://www.ibm.com/support/knowledgecenter/en/\n", F_YELLOW, true );
    ColourCouter ( "https://www.tutorialspoint.com/cplusplus/\n", F_YELLOW, true );
    ColourCouter ( "C++ reference: http://www.cplusplus.com/reference/\n", F_YELLOW, true );
    ColourCouter ( " -------------------------------------------------", F_bRED, false );
    ColourCouter ( "-------------------------------------------------\n", F_bRED, false );
    //! ...............................:: nerd Snow's sayings! ::...............................
    ColourCouter ( "Nerd snow's sayings!\n", F_bPURPLE, false );
    ColourCouter ( "Programming needs patience and practical practice.\n", F_YELLOW, true );
    ColourCouter ( "Programming in a way, that no nerdy dog in the future is able to compile it, is to be avoided!\n", F_YELLOW, true );
    ColourCouter ( "I was almost a good nerd and emptied my Recycle Bin regularly at the night! :) So be a lamb (^.^) and stay a good nerd!\n", F_YELLOW, true );
    ColourCouter ( "In the source code encountered in mind foreseen as future todos can be seen as such tasks that encourage the nerd community... :|\n", F_YELLOW, true );
    ColourCouter ( " -------------------------------------------------", F_bRED, false );
    ColourCouter ( "-------------------------------------------------\n\n", F_bRED, false );

    ColourCouter ( " +++++++++++++++++++++++++++++++++++++++++++++++++", F_bRED, false );
    ColourCouter ( "+++++++++++++++++++++++++++++++++++++++++++++++++\n", F_bRED, false );
    ColourCouter ( ".:: Introduction ::.\n", F_CYAN, false );

    _01_01_Introduction ();

    //! .................................:: LANGUAGE USABILITY ENHANCEMENTS ::.................................
    ColourCouter ( " +++++++++++++++++++++++++++++++++++++++++++++++++", F_bRED, false );
    ColourCouter ( "+++++++++++++++++++++++++++++++++++++++++++++++++\n", F_bRED, false );
    ColourCouter ( ".:: LANGUAGE USABILITY ENHANCEMENTS ::.\n", F_CYAN, false );

    // Todo menu to choose chapters
    // which usecase for a programmer is questionable!
    //char input { 'n' };
    //std::cout << "Proceed to introduction? Please enter -Y- for yes and -N- for no." << Tab;
    //std::cin >> input;
    //std::cout << Nline;
    //if (input == 'y' || input == 'Y')
    //{
    //}
    ////else

    _02_01_LanguageUsabilityEnhancements ();
    _02_02_Constants ();
    _02_03_VariablesAndInitialization ();
    _02_04_TypeInference ();
    _02_05_ControlFlow ();
    _02_06_Templates ();
    _02_07_ObjectOriented ();

    //! .................................:: LANGUAGE RUNTIME ENHANCEMENTS ::.................................
    ColourCouter ( " +++++++++++++++++++++++++++++++++++++++++++++++++", F_bRED, false );
    ColourCouter ( "+++++++++++++++++++++++++++++++++++++++++++++++++\n", F_bRED, false );
    ColourCouter ( ".:: LANGUAGE RUNTIME ENHANCEMENTS ::.\n", F_CYAN, false );

    _03_01_LanguageRuntimeEnhancements ();
    _03_02_LambadaExpressions ();
    _03_03_FunctionObjectWrapper ();
    _03_04_RValueReference ();

    ColourCouter ( " +++++++++++++++++++++++++++++++++++++++++++++++++", F_bRED, false );
    ColourCouter ( "+++++++++++++++++++++++++++++++++++++++++++++++++\n", F_bRED, false );
  }
  catch (const std::exception&)
  {

  }

  // preventing the instant closing of console window, so the result could be seen
  // not a good practice anyhow with a lot discussion in the internet
  // alternatives:
  // Ctrl+F5 is, which compile without debugging
  // putting a break point at the end of the function main
  system ( "PAUSE" ); // system dependent
  std::cin.get (); // alternative and portable
  // for advanced programmer: your program should be able to handle it itself

  //return 0;
  return EXIT_SUCCESS; // see the tutorials > functions section > the return value of main
}
