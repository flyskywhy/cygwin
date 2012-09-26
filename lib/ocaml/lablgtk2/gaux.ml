(* $Id: gaux.ml,v 1.1 2000/05/26 03:53:20 garrigue Exp $ *)

(* Option handling *)

let may ~f x =
  match x with None -> ()
  | Some x -> let _ = f x in ()

let may_map ~f x =
  match x with None -> None
  | Some x -> Some (f x)

let default x ~opt =
  match opt with None -> x | Some y -> y

let may_default f x ~opt =
  match opt with None -> f x | Some y -> y
