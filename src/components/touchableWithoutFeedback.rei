module type Component = {
  let make:
    (
      ~accessible: bool=?,
      ~accessibilityLabel: string=?,
      ~accessibilityComponentType: [
                                     | `none
                                     | `button
                                     | `radiobutton_checked
                                     | `radiobutton_unchecked
                                   ]
                                     =?,
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
      ~delayLongPress: int=?,
      ~delayPressIn: int=?,
      ~delayPressOut: int=?,
      ~disabled: bool=?,
      ~hitSlop: Types.insets=?,
      ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
      ~onLongPress: unit => unit=?,
      ~onPress: unit => unit=?,
      ~onPressIn: unit => unit=?,
      ~onPressOut: unit => unit=?,
      ~pressRetentionOffset: Types.insets=?,
      ~style: Style.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

module CreateComponent: (Impl: View.Impl) => Component;

include Component;
