# AI - functions for working with AI

## AI_TurnToWP

Turns an NPC to a specific waypoint in the world.

```dae
func void AI_TurnToWP(var C_NPC npc, var string wp) {};
```

- `npc` - NPC
- `wp` - name of waypoint in the game world

## AI_TurnToVob

Turns an NPC to a specific freepoint or vob in the world. It works similarly to `AI_TurnToWP`.

```dae
func void AI_TurnToVob(var C_NPC npc, var string vob) {};
```

- `npc` - NPC
- `vob` - name of freepoint or vob in the game world
