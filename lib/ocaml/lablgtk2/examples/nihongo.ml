(* $Id: nihongo.ml,v 1.25 2004/11/17 10:51:47 garrigue Exp $ *)

(* これを実行する前にLC_ALL=ja_JP.EUCなどと指定しなければならない *)

open GMain

let window = GWindow.window ()
let box = GPack.vbox ~packing: window#add ()
let text = GText.view ~packing: box#add ()
let button = GButton.button ~label: "終了" ~packing: box#add ()
let label = GMisc.label ~text:"これには影響しない" ~packing: box#add ()

let _ =
  window#connect#destroy ~callback:Main.quit;
  text#buffer#insert "こんにちは";
  text#misc#set_size_chars ~width:20 ~height:5 ();
  let style = button#misc#style#copy in
  button#misc#set_style style;
  style#set_bg [`NORMAL,`NAME "green"; `PRELIGHT,`NAME "red"];
  button#connect#clicked ~callback:Main.quit

let _ =
  window#show ();
  Main.main ()
