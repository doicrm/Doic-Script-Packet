# Menu functions

## Menu_SetItemText

Sets value of specified menu item.

```dae
func void Menu_SetItemText(var string menuItemName, var string value) {};
```

- `menuItemName`
- `value` - text value to set

```dae title="Example usage"
Menu_SetItemText("MENU_ITEM_PLAYERGUILD", "Necromancer");
```

## Menu_GetItemText

Returns value of text on first line (`0` by default) of specific menu item.

```dae
func string Menu_GetItemText(var string menuItemName) {};
```

- `menuItemName`
- `return` - text value of menu item

```dae title="Example usage"
var string playerGuild;
playerGuild = Menu_GetItemText("MENU_ITEM_PLAYERGUILD");

if (Hlp_StrCmp(playerGuild, "Necromancer"))
{
    //...
};
```
