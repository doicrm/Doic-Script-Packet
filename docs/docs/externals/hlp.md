# HLP - help functions

## Hlp_GetItem

Finds an item object by its instance name.

```dae
func C_Item Hlp_GetItem(var int itemInstance) {};
```

- `itemInstance` - instance name of the item
- `return` - link to item object

## Hlp_IsValidVob

Checks if vob is in the game world.

```dae
func int Hlp_IsValidVob(var instance object) {};
```

- `object` - any instance
- `return` - `TRUE` or `FALSE`
