(* $Id: gtkRange.ml,v 1.11 2003/08/15 11:08:43 garrigue Exp $ *)

open Gaux
open Gtk
open Tags
open GtkRangeProps
open GtkBase

external _gtkrange_init : unit -> unit = "ml_gtkrange_init"
let () = _gtkrange_init ()

module ProgressBar = ProgressBar

module Range = Range

module Scale = Scale

module Scrollbar = Scrollbar

module Ruler = Ruler
