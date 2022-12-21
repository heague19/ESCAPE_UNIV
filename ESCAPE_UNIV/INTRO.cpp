#include "INTRO.h"

INTRO::INTRO()
{

}
void INTROPrint(int color)
{
	BoxUI INTRO(72, 36, 2, 1);
	SelectCursorColor(DARK_SKY);
	
	INTRO.ConstructorBox();
	InitCursorColor();
	
	
	//INTRO.Print("\n                                                                         \n              .,,,,,     ,,-,     .,,-,,         ,,~,,       .,-,,       ,,,,,                 \n             =#@@@@@   .$@@@#    =@@@@@@#,     .$@@@@@$     ~@@@@@$,    $@@@@@,                \n            ;@@@@@@@   @@@@@#   =@@@@@@@@@!    =@@@@@@@=   ~@@@@@@@#  .@@@@@@@,                \n            @@@@@@@@  ;@@@@@#  #@@@@@@@@@@@.  ,@@@@@@@@@. .@@@@@@@@@# ~@@@@@@@,                \n            @@@@@$$$  ;@@@@$; -@@@@@!;$@@@@#  #@@@#;@@@@, .@@@@;$@@@# !@@@@#$$,                \n            @@@@,     ;@@@@.  *@@@@,   *@@@@~ #@@@= =@@@- .@@@* *@@@# =@@@!                    \n            @@@@#$$~  ;@@@@~  @@@@;     @@$;, #@@@* *@@@- .@@@*=@@@@# =@@@@$$$                 \n            @@@@@@@;  ~@@@@=  @@@@~     ,.    #@@@$-*@@@- .@@@*#@@@@* =@@@@@@@                 \n            @@@@@@@;   @@@@@. @@@@~     @@@@: #@@@@**@@@- .@@@*#@@@=  =@@@@@@@                 \n            @@@#:::,   .@@@@: @@@@$    :@@@@~ #@@@@**@@@- .@@@*#@=;.  =@@@*:::                 \n            @@@#---- ,-~@@@@! ~@@@@=---@@@@@. #@@@@**@@@- .@@@*       =@@@;---                 \n            @@@@@@@@ =@@@@@@- .@@@@@@@@@@@@!  #@@@=,*@@@- .@@@*       ~@@@@@@@,                \n            *@@@@@@@ =@@@@@$   ;@@@@@@@@@@$   #@@@* *@@@- .@@@*       -@@@@@@@,                \n             @@@@@@@ =@@@@@-    :@@@@@@@@@.   #@@@* *@@@- .@@@*        $@@@@@@,                \n              ~;;;;; -@@@!,      .:#@@@*:     :;;;~ ~;;;,  ;;;~         ,:;;;;,                \n                                                                                                                                                                                      \n                                                                                               \n                         ~~~~ .~~~~     ~~:~~    .~~~~.~~~~.  ~~~~-                            \n                         @@@@,-@@@@   .@@@@@@=   -@@@#.@@@@;  @@@@~                            \n                         @@@@,-@@@@  .@@@@@@@@*  -@@@# *@@@@ *@@@#.                            \n                         @@@@,-@@@@  ;@@@@@@@@@  -@@@# -@@@@-#@@@*                             \n                         @@@@,-@@@@  !@@@#!@@@@- -@@@#  #@@@@@@@@,                             \n                         @@@@,-@@@@  $@@@- @@@@: -@@@#  !@@@@@@@$                              \n                         @@@@,-@@@@  $@@@- @@@@: -@@@#   @@@@@@@~                              \n                         @@@@,-@@@@  $@@@- @@@@: -@@@#   !@@@@@@.                              \n                         @@@@,-@@@@  $@@@- @@@@: -@@@#   ~@@@@@*                               \n                         @@@@,-@@@@  $@@@- @@@@: -@@@#    @@@@@.                               \n                         @@@@!!@@@@  $@@@- @@@@: -@@@#    ,@@@*                                \n                         @@@@@@@@@$  $@@@- @@@@: -@@@#     #@@~                                \n                         :@@@@@@@@~  $@@@- @@@@: -@@@#     =@@                                 \n                          =@@@@@@=   $@@@- @@@@: -@@@#      @~                                 \n                           ~@@@$-    -:::. ~:::,  :::~      !.                                 \n                                                                                               \n                                                                                             ");
	INTRO.Print("                                                                                                \n               .,,,,,     ,,-.     .,,-,,         ,,~,,       .,-,,       ,,,,,                 \n              =#@@@@@   .$@@@#    =@@@@@@#,     .$@@@@@$     ~@@@@@$,    $@@@@@,                \n             ;@@@@@@@   @@@@@#   *@@@@@@@@@;    =@@@@@@@=   :@@@@@@@$  .@@@@@@@,                \n             @@@@@@@@  ;@@@@@#  #@@@@@@@@@@@.  -@@@@@@@@@. .@@@@@@@@@# ~@@@@@@@,\n             @@@@@$$$  ;@@@@$; -@@@@@!;$@@@@#  #@@@#;@@@@, .@@@@;$@@@# *@@@@#$$,\n             @@@@,     ;@@@@.  *@@@@,   *@@@@~ #@@@* $@@@- .@@@* *@@@# $@@@!\n             @@@@#$$~  ;@@@@-  @@@@;     @@=;, #@@@! =@@@- .@@@*=@@@@# $@@@@$$$\n             @@@@@@@;  ~@@@@=  @@@@~     ,.    #@@@=,=@@@- .@@@*@@@@@* $@@@@@@@\n             @@@@@@@;   @@@@@  @@@@~     @@@@: #@@@@*=@@@- .@@@*@@@@=  $@@@@@@@\n             @@@#:::,   .@@@@~ @@@@$    :@@@@~ #@@@@*=@@@- .@@@*@@=;.  $@@@*:::\n             @@@#---- ,-~@@@@; ~@@@@$---@@@@@. #@@@@*=@@@- .@@@*       =@@@;---                 \n             @@@@@@@@ $@@@@@@, .@@@@@@@@@@@@!  #@@@=,=@@@- .@@@*       ~@@@@@@@,                \n             =@@@@@@@ $@@@@@$   ;@@@@@@@@@@$   #@@@! =@@@- .@@@*       -@@@@@@@,                \n              @@@@@@@ $@@@@@,    ;@@@@@@@@@.   #@@@! =@@@- .@@@*        #@@@@@@,                \n               ~;;;;; ~@@@!.      .:#@@@*:     :;;;~ ~;;;,  ;;;~         -:;;;;.                \n                                                                                                \n\n                                                                                                \n      ~~~~. ~~~~     ~~:~~     ~~~~ ~~~~,  -~~~~   .~,         .~::~  ~~~,  ~~~~ .~~~~          \n      @@@@~ #@@@,   $@@@@@@.   @@@@,@@@@@  @@@@*   -@!         @@@@@ .@@@*  @@@@.-@@@@          \n      @@@@~ #@@@,  =@@@@@@@$   @@@@,~@@@@.,@@@@,   !@~       .@@@@@@ .@@@*  @@@@.-@@@@          \n      @@@@~ #@@@, :@@@@@@@@@-  @@@@,,@@@@=#@@@$    @@.       -@@@@@@ .@@@*  @@@@.-@@@@          \n      @@@@~ #@@@, ;@@@@:@@@@;  @@@@, #@@@$@@@@:    @@        *@@@@=: .@@@*  @@@@.-@@@@          \n      @@@@~ #@@@, ;@@@* @@@@;  @@@@,  @@@@@@@@.   :@!        =@@@@   .@@@*  @@@@.-@@@@          \n      @@@@~ #@@@, ;@@@; @@@@!  @@@@,  =@@@@@@;    =@-        ~@@@@.  .@@@*  @@@@.-@@@@          \n      @@@@~ #@@@, ;@@@; @@@@!  @@@@,  ;@@@@@@,    =@.        -@@@@=  .@@@*  @@@@.-@@@@          \n      @@@@~ #@@@, ;@@@; @@@@!  @@@@,   @@@@@#    .@$          $@@@@. .@@@*  @@@@.-@@@@          \n      @@@@~ #@@@, ;@@@; @@@@!  @@@@,   :@@@@-    .@=          .@@@@- .@@@*  @@@@.-@@@@          \n      @@@@*;@@@@. ;@@@; @@@@!  @@@@,   .@@@#     ~@!        -:;@@@@--;@@@*  @@@@;!@@@@          \n      ;@@@@@@@@@  ;@@@; @@@@!  @@@@,    =@@!     @@,        =@@@@@@,!@@@@!  @@@@@@@@@!          \n      -@@@@@@@@!  ;@@@; @@@@!  @@@@,    ~@@,     @@         =@@@@@$ !@@@@-  !@@@@@@@@-          \n       =@@@@@@=   ;@@@; @@@@!  @@@@,     @$     -@=         =@@@@#, !@@@$   .$@@@@@@*           \n         -@@@@~    ,:::- -:::-  ~:::.     :,     ;@:         ,@@@:.  !@@~      :@@@=-            \n                                       ");

	InitCursorColor();

	SelectCursorColor(YELLOW);
	BoxUI INTRO_MENU(19, 34, 106, 2);
	INTRO_MENU.ConstructorBox();
	InitCursorColor();


	BoxUI START(17, 5, 108, 3); //스타트 박스 변수 선언
	START.ConstructorBox();
	START.Print("\n\n\               시작");

	BoxUI RANK(17, 5, 108, 16); //랭크 박스 변수 선언
	RANK.ConstructorBox();
	RANK.Print("\n\n\             랭크 보기");

	BoxUI EXIT(17, 5, 108, 29);
	EXIT.ConstructorBox();
	EXIT.Print("\n\n\             종료하기");
	INTRO::Iflag = true;
}
bool INTRO::Iflag = false;