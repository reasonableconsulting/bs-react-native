module type ActivityIndicatorComponent = {
  let make:
    (
      ~animating: bool=?,
      ~color: Style.color=?,
      ~size: [ | `large | `small | `exact(int)]=?,
      ~hidesWhenStopped: bool=?,
      ~accessibilityLabel: ReasonReact.reactElement=?,
      ~accessible: bool=?,
      ~hitSlop: Types.insets=?,
      ~onAccessibilityTap: unit => unit=?,
      ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
      ~onMagicTap: unit => unit=?,
      ~responderHandlers: Types.touchResponderHandlers=?,
      ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
      ~removeClippedSubviews: bool=?,
      ~style: Style.t=?,
      ~testID: string=?,
      ~accessibilityComponentType: [
                                     | `none
                                     | `button
                                     | `radiobutton_checked
                                     | `radiobutton_unchecked
                                   ]
                                     =?,
      ~accessibilityLiveRegion: [ | `none | `polite | `assertive]=?,
      ~collapsable: bool=?,
      ~importantForAccessibility: [ | `auto | `yes | `no | `noHideDescendants]
                                    =?,
      ~needsOffscreenAlphaCompositing: bool=?,
      ~renderToHardwareTextureAndroid: bool=?,
      ~accessibilityTraits: list(
                              [
                                | `none
                                | `button
                                | `link
                                | `header
                                | `search
                                | `image
                                | `selected
                                | `plays
                                | `key
                                | `text
                                | `summary
                                | `disabled
                                | `frequentUpdates
                                | `startsMedia
                                | `adjustable
                                | `allowsDirectInteraction
                                | `pageTurn
                              ],
                            )
                              =?,
      ~accessibilityViewIsModal: bool=?,
      ~shouldRasterizeIOS: bool=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

module CreateComponent = (Impl: View.Impl) : ActivityIndicatorComponent => {
  [@bs.module "react-native"] [@bs.scope "Platform"]
  external _os: string = "OS";
  let encodeSize = size =>
    switch (size) {
    | `small => Encode.string("small")
    | `large => Encode.string("large")
    | `exact(x) =>
      switch (_os) {
      | "ios" =>
        Js.Console.warn(
          "Passing 'exact' to the size prop of activityIndicator is supported only on Android. Because you only provided the 'exact' size, we defaulted it to the small size on iOS",
        );
        Encode.string("small");
      | _ => Encode.int(x)
      }
    };

  let make =
      (
        ~animating=?,
        ~color=?,
        ~size=?,
        ~hidesWhenStopped=?,
        ~accessibilityLabel=?,
        ~accessible=?,
        ~hitSlop=?,
        ~onAccessibilityTap=?,
        ~onLayout=?,
        ~onMagicTap=?,
        ~responderHandlers=?,
        ~pointerEvents=?,
        ~removeClippedSubviews=?,
        ~style=?,
        ~testID=?,
        ~accessibilityComponentType=?,
        ~accessibilityLiveRegion=?,
        ~collapsable=?,
        ~importantForAccessibility=?,
        ~needsOffscreenAlphaCompositing=?,
        ~renderToHardwareTextureAndroid=?,
        ~accessibilityTraits=?,
        ~accessibilityViewIsModal=?,
        ~shouldRasterizeIOS=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=Impl.view,
      ~props=
        Props.extendView(
          {
            "animating": animating,
            "color": color,
            "size": UtilsRN.option_map(encodeSize, size),
            "hidesWhenStopped": hidesWhenStopped,
          },
          ~accessibilityLabel?,
          ~accessible?,
          ~hitSlop?,
          ~onAccessibilityTap?,
          ~onLayout?,
          ~onMagicTap?,
          ~responderHandlers?,
          ~pointerEvents?,
          ~removeClippedSubviews?,
          ~style?,
          ~testID?,
          ~accessibilityComponentType?,
          ~accessibilityLiveRegion?,
          ~collapsable?,
          ~importantForAccessibility?,
          ~needsOffscreenAlphaCompositing?,
          ~renderToHardwareTextureAndroid?,
          ~accessibilityTraits?,
          ~accessibilityViewIsModal?,
          ~shouldRasterizeIOS?,
        ),
    );
};

include CreateComponent({
  [@bs.module "react-native"]
  external view: ReasonReact.reactClass = "ActivityIndicator";
});
