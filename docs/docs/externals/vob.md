# VOB - functions for object manipulation

## Vob_Rotate

```dae
func void Vob_Rotate(var string vobName, var C_Position vobPosition) {};
```

- `vobName`
- `vobPosition`

## Vob_MoveTo

```dae
func void Vob_MoveTo(var string vobName, var string pointName) {};
```

- `vobName`
- `pointName`

## Vob_SetOnFloor

Sticks a vob with a specific name to the ground.

```dae
func void Vob_SetOnFloor(var string vobName) {};
```

- `vobName`

```dae title="Example usage"
Vob_SetOnFloor("CHEST_LOBART");
```

## Vob_SetVisual

Sets the visual of a specific vob in the game world.

```dae
func void Vob_SetVisual(var string vobName, var string visualName) {};
```

- `vobName`
- `visualName`

```dae title="Example usage"
Vob_SetVisual("CHEST_LOBART", "CHESTBIG_OCCHESTLARGELOCKED.MDS");
```
