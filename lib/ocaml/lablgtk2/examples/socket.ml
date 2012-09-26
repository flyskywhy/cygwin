(* $Id: socket.ml,v 1.4 2004/01/13 05:49:52 garrigue Exp $ *)

open GMain

let main () =
  let w = GWindow.window ~title:"Socket example" () in
  w#connect#destroy ~callback:Main.quit;
  let vbox = GPack.vbox ~packing:w#add () in
  let label = GMisc.label ~packing:vbox#pack () in
  w#show ();
  let socket = GWindow.socket ~packing:vbox#add ~height:40 () in
  label#set_text ("XID to plug into this socket: 0x" ^ 
                  Int32.format "%x" socket#xwindow);
  Main.main ()

let _ = main ()
