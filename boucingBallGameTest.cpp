1. // BCX Bounce by Kevin Diggins
adopted from Charles Petzold
2. // BCX generated C code modified for
the free Dev-C++ system
3. // from   http://www.bloodshed.net/
4. // or     http://sourceforge.net/
projects/dev-cpp/
5. // (actually Dev-C++ is the IDE for
the GNU GCC/G++ compiler)
6. // a Dev-C++ tested Windows
//Application by  vegaseat  21nov2004 7. 8. #include <windows.h> 9. 10. #define Show ( Window) RedrawWindow
//( Window, 0 , 0 ,0 ); ShowWindow
//( Window, SW_SHOW ); 11. 12. #define AppName "BouncingBall1"
13. //#define Caption "Bouncing Ball ..." 14. 15. char BCX_STR [ 1024 * 1024 ]; 16. 17. static int BCX_GetDiaUnit ;
18. static int BCX_cxBaseUnit ;
19. static int BCX_cyBaseUnit ;
20. static int BCX_ScaleX ;
21. static int BCX_ScaleY ;
22. static HANDLE Form1 ; 23. 24. double MIN ( double, double);
25. double MAX ( double, double); 26. 27. int WINAPI WinMain ( HINSTANCE ,
HINSTANCE , LPSTR , int);
28. void FormLoad ( HANDLE);
29. LRESULT CALLBACK WndProc (HWND ,
UINT , WPARAM , LPARAM ); 30.31. 32. double MAX ( double a , double b )
33. {
34. if ( a > b )
35. {
36. return a ;
37. }
38. return b ;
39. } 40.41. 42. double MIN ( double a , double b )
43. {
44. if ( a < b )
45. {
46. return a ;
47. }
48. return b ;
49. } 50.51. 52. // standard main for Windows GUI
53. int WINAPI WinMain ( HINSTANCE hInst ,
HINSTANCE hPrev , LPSTR CmdLine, int
CmdShow)
54. {
55. static WNDCLASS Wc;
56. memset (& Wc, 0 ,sizeof ( Wc));
57. static MSG Msg;
58. memset (& Msg, 0, sizeof (Msg )); 59. 60. Wc. style =CS_HREDRAW | CS_VREDRAW ;
61. Wc. lpfnWndProc= WndProc;
62. Wc. cbClsExtra= 0 ;
63. Wc. cbWndExtra= 0 ;
64. Wc. hInstance =hInst ;
65. Wc. hIcon =LoadIcon
( NULL , IDI_WINLOGO );
66. Wc. hCursor= LoadCursor
( NULL , IDC_ARROW );
67. Wc. hbrBackground=
( HBRUSH) GetStockObject( WHITE_BRUSH );
68. Wc. lpszMenuName = NULL ;
69. Wc. lpszClassName= AppName;
70. RegisterClass(& Wc);
71. FormLoad (hInst );
72. // 50ms here, lower value gives
higher speed
73. SetTimer ((HWND ) Form1 ,1 , 50 ,NULL );
74. // ye olde event message loop
75. while( GetMessage(& Msg, NULL , 0 ,0 ))
76. {
77. if (! IsWindow ((HWND ) Form1 )||!
IsDialogMessage (( HWND )Form1 ,& Msg))
78. {
79. TranslateMessage(& Msg);
80. DispatchMessage (&Msg);
81. }
82. }
83. return Msg. wParam;
84. } 85.86. 87. // create the form and show it
(somewhat older style)
88. void FormLoad (HANDLE hInst )
89. {
90. // get the scale factors
91. BCX_GetDiaUnit = GetDialogBaseUnits
();
92. BCX_cxBaseUnit = LOWORD
( BCX_GetDiaUnit );
93. BCX_cyBaseUnit = HIWORD
( BCX_GetDiaUnit );
94. BCX_ScaleX = BCX_cxBaseUnit / 4;
95. BCX_ScaleY = BCX_cyBaseUnit / 8;
96. // now the form
97. Form1 = CreateWindow ( AppName, Caption,
98. DS_MODALFRAME | WS_POPUP |
WS_CAPTION |WS_SYSMENU ,
99. 10 *BCX_ScaleX , 20* BCX_ScaleY , 250* BCX_ScaleX ,175 *BCX_ScaleY , NULL ,
100. ( HMENU )NULL ,
( HINSTANCE )hInst , NULL );
101. Show ((HWND ) Form1 );
102. } 103.104. 105. // event message handler
106. LRESULT CALLBACK WndProc (HWND hWnd ,
UINT Msg, WPARAM wParam , LPARAM
lParam )
107. {
108. static HANDLE  hBitmap ;
109. static HBRUSH  hBrush ;
110. static HDC  hdc ;
111. static HDC  hdcMem ;
112. static int cxClient ;
113. static int cyClient ;
114. static int xCenter ;
115. static int yCenter ;
116. static int cxTotal ;
117. static int cyTotal ;
118. static int cxRadius ;
119. static int cyRadius ;
120. static int cxMove ;
121. static int cyMove ;
122. static int xPixel ;
123. static int yPixel ;
124. static int nScale ;
125.
126. while( 1 )
127. {
128. if ( Msg == WM_CREATE )
129. {
130. hdc = GetDC ( hWnd );
131. xPixel = GetDeviceCaps
( hdc, ASPECTX);
132. yPixel = GetDeviceCaps
( hdc, ASPECTY);
133. ReleaseDC( hWnd , hdc);
134. return 0 ;
135. break;
136. }
137. // draw the ball
138. if ( Msg == WM_SIZE )
139. {
140. xCenter = ( cxClient = LOWORD
( lParam))/ 2;
141. yCenter = ( cyClient = HIWORD
( lParam))/ 2;
142. nScale = ( int) MIN
( cxClient * xPixel, cyClient * yPixel)/ 16;
143. cxRadius = nScale / xPixel;
144. cyRadius = nScale / yPixel;
145. cxMove = ( int) MAX
( 1 , cxRadius/ 4 );
146. cyMove = ( int) MAX
( 1 , cyRadius/ 4 );
147. cxTotal = 2 *( cxRadius + cxMove );
148. cyTotal = 2 *( cyRadius + cyMove );
149. if ( hBitmap)
150. {
151. DeleteObject ( hBitmap);
152. }
153. hdc = GetDC ( hWnd );
154. hdcMem = CreateCompatibleDC
( hdc);
155. hBitmap =
CreateCompatibleBitmap
( hdc, cxTotal, cyTotal);
156. ReleaseDC( hWnd , hdc);
157. SelectObject( hdcMem ,hBitmap);
158. Rectangle( hdcMem,- 1 ,- 1 , cxTotal
+ 1 , cyTotal+1 );
159. hBrush = CreateHatchBrush
( HS_DIAGCROSS , 0);
160. SelectObject( hdcMem ,hBrush );
161. SetBkColor( hdcMem, RGB
( 0 , 127, 255));
162. Ellipse
( hdcMem, cxMove ,cyMove , cxTotal-
cxMove ,cyTotal- cyMove );
163. DeleteDC( hdcMem );
164. DeleteObject( hBrush );
165. return 0 ;
166. break;
167. }
168. // move the ball
169. if ( Msg == WM_TIMER )
170. {
171. if (!hBitmap)
172. {
173. break ;
174. }
175. hdc = GetDC ( hWnd );
176. hdcMem = CreateCompatibleDC
( hdc);
177. SelectObject( hdcMem ,hBitmap);
178. BitBlt( hdc, xCenter-
cxTotal/ 2 , yCenter-
cyTotal/ 2 , cxTotal, cyTotal,hdcMem , 0, 0 , SRCCOPY);
179. ReleaseDC( hWnd , hdc);
180. DeleteDC( hdcMem );
181. xCenter += cxMove ;
182. yCenter += cyMove ;
183. if ( xCenter
+ cxRadius >=cxClient || xCenter-
cxRadius <= 0)
184. {
185. cxMove = - cxMove;
186. }
187. if ( yCenter+ cyRadius >=
cyClient || yCenter - cyRadius <= 0 )
188. {
189. cyMove = - cyMove;
190. }
191. return 0 ;
192. break;
193. }
194. // clean up and exit program
195. if ( Msg == WM_DESTROY )
196. {
197. if ( hBitmap)
198. {
199. DeleteObject ( hBitmap);
200. }
201. KillTimer(( HWND )Form1 , 1 );
202. PostQuitMessage (0 );
203. return 0 ;
204. }
205. break ;
206. }
207. return DefWindowProc( hWnd , Msg,
wParam , lParam );
