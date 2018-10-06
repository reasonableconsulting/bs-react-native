module type Component = {
  let setHidden:
    (bool, ~animation: [ | `fade | `none | `slide]=?, unit) => unit;

  let setBarStyle:
    ([ | `darkContent | `default | `lightContent], ~animated: bool=?, unit) =>
    unit;

  let setNetworkActivityIndicatorVisible: bool => unit;

  let setBackgroundColor: (string, ~animated: bool=?, unit) => unit;

  let setTranslucent: bool => unit;

  let make:
    (
      ~animated: bool=?,
      ~barStyle: [ | `darkContent | `default | `lightContent]=?,
      ~hidden: bool=?,
      ~backgroundColor: string=?,
      ~translucent: bool=?,
      ~networkActivityIndicatorVisible: bool=?,
      ~showHideTransition: [ | `fade | `none | `slide]=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

module CreateComponent = (Impl: View.Impl) : Component => {
  [@bs.scope "StatusBar"] [@bs.module "react-native"]
  external _setHidden: (bool, Js.Undefined.t(string)) => unit = "setHidden";

  let setHidden = (hidden, ~animation=?, ()) =>
    _setHidden(
      hidden,
      Js.Undefined.fromOption(
        UtilsRN.option_map(
          x =>
            switch (x) {
            | `none => "none"
            | `fade => "fade"
            | `slide => "slide"
            },
          animation,
        ),
      ),
    );

  [@bs.scope "StatusBar"] [@bs.module "react-native"]
  external _setBarStyle: (string, Js.Undefined.t(bool)) => unit =
    "setBarStyle";

  let setBarStyle = (style, ~animated=?, ()) =>
    _setBarStyle(
      switch (style) {
      | `default => "default"
      | `lightContent => "light-content"
      | `darkContent => "dark-content"
      },
      Js.Undefined.fromOption(animated),
    );

  [@bs.scope "StatusBar"] [@bs.module "react-native"]
  external _setNetworkActivityIndicatorVisible: bool => unit =
    "setNetworkActivityIndicatorVisible";

  let setNetworkActivityIndicatorVisible = visible =>
    _setNetworkActivityIndicatorVisible(visible);

  [@bs.scope "StatusBar"] [@bs.module "react-native"]
  external _setBackgroundColor: (string, Js.Undefined.t(bool)) => unit =
    "setBackgroundColor";

  let setBackgroundColor = (color, ~animated=?, ()) =>
    _setBackgroundColor(color, Js.Undefined.fromOption(animated));

  [@bs.scope "StatusBar"] [@bs.module "react-native"]
  external _setTranslucent: bool => unit = "setTranslucent";

  let setTranslucent = translucent => _setTranslucent(translucent);

  let make =
      (
        ~animated=?,
        ~barStyle=?,
        ~hidden=?,
        ~backgroundColor=?,
        ~translucent=?,
        ~networkActivityIndicatorVisible=?,
        ~showHideTransition=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=Impl.view,
      ~props={
        "animated": animated,
        "barStyle":
          UtilsRN.option_map(
            x =>
              switch (x) {
              | `default => "default"
              | `lightContent => "light-content"
              | `darkContent => "dark-content"
              },
            barStyle,
          ),
        "backgroundColor": backgroundColor,
        "hidden": hidden,
        "translucent": translucent,
        "networkActivityIndicatorVisible": networkActivityIndicatorVisible,
        "showHideTransition":
          UtilsRN.option_map(
            x =>
              switch (x) {
              | `none => "none"
              | `fade => "fade"
              | `slide => "slide"
              },
            showHideTransition,
          ),
      },
    );
};

include CreateComponent({
  [@bs.module "react-native"]
  external view: ReasonReact.reactClass = "StatusBar";
});
