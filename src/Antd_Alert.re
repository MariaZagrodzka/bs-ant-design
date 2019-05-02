/*
 afterClose	Called when close animation is finished	() => void	-
 banner	Whether to show as banner	boolean	false
 closable	Whether Alert can be closed	boolean	-
 closeText	Close text to show	string|ReactNode	-
 description	Additional content of Alert	string|ReactNode	-
 iconType	Icon type, effective when showIcon is true	string	-
 message	Content of Alert	string|ReactNode	-
 showIcon	Whether to show icon	boolean	false, in banner mode default is true
 type	Type of Alert styles, options: success, info, warning, error	string	info, in banner mode default is warning
 onClose	Callback when Alert is closed	(e: MouseEvent) => void	-
    */
[%bs.raw {|require("antd/lib/alert/style")|}];

[@bs.deriving jsConverter]
type alertType = [ | `success | `info | `warning | `error];

module Internal = {
  [@bs.module] [@react.component]
  external make:
    (
      ~afterClose: unit => unit=?,
      ~banner: bool=?,
      ~closable: bool=?,
      ~closeText: React.element=?,
      ~description: React.element=?,
      ~iconType: string=?,
      ~message: React.element=?,
      ~showIcon: bool=?,
      ~_type: option(string)=?,
      ~onClose: ReactEvent.Mouse.t => unit=?,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?
    ) =>
    React.element =
    "antd/lib/alert";
};

[@react.component]
let make =
    (
      ~afterClose: unit => unit=?,
      ~banner: bool=?,
      ~closable: bool=?,
      ~closeText: React.element=?,
      ~description: React.element=?,
      ~iconType: string=?,
      ~message: React.element=?,
      ~showIcon: bool=?,
      ~_type: option(alertType)=?,
      ~onClose: ReactEvent.Mouse.t => unit=?,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
    ) =>
  <Internal
    afterClose
    banner
    closable
    closeText
    description
    iconType
    message
    showIcon
    _type={Js.Option.map((. b) => alertTypeToJs(b), _type)}
    onClose
    id
    className
    style
  />;