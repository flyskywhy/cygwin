(* $Id: gtkBin.ml,v 1.20 2003/12/10 10:49:57 oandrieu Exp $ *)

open Gaux
open Gtk
open Tags
open GtkBinProps
open GtkBase

external _gtkbin_init : unit -> unit = "ml_gtkbin_init"
let () = _gtkbin_init ()

module Alignment = Alignment

module EventBox = EventBox

module Frame = Frame

module AspectFrame = AspectFrame

module HandleBox = HandleBox

module Viewport = Viewport

module ScrolledWindow = ScrolledWindow

(* module Invisible = Invisible *)

module Expander = Expander
