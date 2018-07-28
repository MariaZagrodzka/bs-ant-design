open Antd_Helpers;

module IconName = Antd_IconName;

[@bs.module] external reactClass : ReasonReact.reactClass = "antd/lib/button";

[%bs.raw {|require("antd/lib/button/style")|}];

[@bs.deriving jsConverter]
type buttonType = [ | `primary | `ghost | `dashed | `danger];

[@bs.deriving jsConverter]
type buttonShape = [ | `circle' | [@bs.as "circle-outline"] `circleOutline];

[@bs.deriving jsConverter]
type buttonSize = [ | `small | `default | `large];

module LoadingProps = {
  type delay = {. "delay": int};
  type t =
    | Bool(bool)
    | Delay(delay);
  type js;
  external ofBool : bool => js = "%identity";
  external ofDelay : delay => js = "%identity";
  let toJs: t => js =
    fun
    | Bool(a) => a |> from_bool |> ofBool
    | Delay(a) => a |> ofDelay;
};

[@bs.obj]
external makeProps :
  (
    ~_type: string=?,
    ~htmlType: string=?,
    ~icon: IconName.t=?,
    ~shape: string=?,
    ~size: string=?,
    ~onClick: ReactEventRe.Mouse.t => unit=?,
    ~onMouseUp: ReactEventRe.Mouse.t => unit=?,
    ~onMouseDown: ReactEventRe.Mouse.t => unit=?,
    ~tabIndex: int=?,
    ~loading: LoadingProps.js=?,
    ~disabled: bool=?,
    ~ghost: bool=?,
    ~target: string=?,
    ~href: string=?,
    ~download: string=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~_type=?,
      ~htmlType=?,
      ~icon=?,
      ~shape=?,
      ~size=?,
      ~onClick=?,
      ~onMouseUp=?,
      ~onMouseDown=?,
      ~tabIndex=?,
      ~loading: option(LoadingProps.t)=?,
      ~disabled=?,
      ~ghost=?,
      ~target=?,
      ~href=?,
      ~download=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~_type=?Js.Option.map((. b) => buttonTypeToJs(b), _type),
        ~htmlType?,
        ~icon?,
        ~shape=?Js.Option.map((. b) => buttonShapeToJs(b), shape),
        ~size=?Js.Option.map((. b) => buttonSizeToJs(b), size),
        ~onClick?,
        ~onMouseUp?,
        ~onMouseDown?,
        ~tabIndex?,
        ~loading=?Js.Option.map((. b) => LoadingProps.toJs(b), loading),
        ~disabled=?Js.Option.map((. b) => from_bool(b), disabled),
        ~ghost=?Js.Option.map((. b) => from_bool(b), ghost),
        ~target?,
        ~href?,
        ~download?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );