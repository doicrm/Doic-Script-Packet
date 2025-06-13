# NPC - character functions

## Npc_IsInRoutineName

Checks if NPC is in specified routine.

```dae
func int Npc_IsInRoutineName(var C_NPC npc, var string routine) {};
```

- `npc` - NPC
- `routine` - name of routine to check
- `return` - `TRUE` if NPC is in routine, `FALSE` otherwise

```dae title="Example usage"
if (Npc_IsInRoutineName(self, "Start"))
{
    //...
};
```

## Npc_EquipItem

```dae
func void Npc_EquipItem(var C_NPC npc, var int itemInstance) {};
```

- `npc` - NPC
- `itemInstance` - instance name of the item

```dae title="Example usage"
Npc_EquipItem(self, ItLsTorch);
```
