# WLD - world manipulation functions

## Wld_InsertVob

```dae
func void Wld_InsertVob(var string vobName, var string pointName) {};
```

- `vobName`
- `pointName`

```dae title="Example usage"
Wld_InsertVob("SECRET_CHEST", "WP_START");
```

## Wld_InsertMob

```dae
func void Wld_InsertMob(var string vobName, var string pointName) {};
```

- `vobName`
- `pointName`

```dae title="Example usage"
Wld_InsertMob("SIGNPOST", "WP_START");
```

## Wld_InsertMobInter

```dae
func void Wld_InsertMobInter(var string vobName, var string pointName) {};
```

- `vobName`
- `pointName`

```dae title="Example usage"
Wld_InsertMobInter("EDDA_CAULDRON", "WP_START");
```

## Wld_InsertMobContainer

```dae
func void Wld_InsertMobContainer(var string vobName, var string pointName) {};
```

- `vobName`
- `pointName`

```dae title="Example usage"
Wld_InsertMobContainer("CAVALORN_CHEST", "WP_START");
```

## Wld_InsertMobFire

```dae
func void Wld_InsertMobFire(var string vobName, var string pointName) {};
```

- `vobName`
- `pointName`

```dae title="Example usage"
Wld_InsertMobFire("CAVALORN_CAMPFIRE", "WP_START");
```

## Wld_InsertMobDoor

```dae
func void Wld_InsertMobDoor(var string vobName, var string pointName) {};
```

- `vobName`
- `pointName`

```dae title="Example usage"
Wld_InsertMobDoor("BOSPER_HOUSE_DOOR", "NW_CITY_BOSPER_HOUSE_ENTRANCE");
```

## Wld_InsertMobBed

```dae
func void Wld_InsertMobBed(var string vobName, var string pointName) {};
```

- `vobName`
- `pointName`

```dae title="Example usage"
Wld_InsertMobDoor("BOSPER_BED", "NW_CITY_BOSPER_HOUSE_BED");
```

## Wld_InsertVobPos

```dae
func void Wld_InsertVobPos(var string vobName, var C_Position vobPosition) {};
```

- `vobName`
- `vobPosition`

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(0, 0, 0);
Wld_InsertVobPos("SECRET_CHEST", pos);
```

## Wld_InsertMobPos

```dae
func void Wld_InsertMobPos(var string vobName, var C_Position vobPosition) {};
```

- `vobName`
- `vobPosition`

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(23120, 1400, 16795);
Wld_InsertMobPos("SIGNPOST", pos);
```

## Wld_InsertMobInterPos

```dae
func void Wld_InsertMobInterPos(var string vobName, var C_Position vobPosition) {};
```

- `vobName`
- `vobPosition`

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(16795, 1400, 23120);
Wld_InsertMobInterPos("EDDA_CAULDRON", pos);
```

## Wld_InsertMobContainerPos

```dae
func void Wld_InsertMobContainerPos(var string vobName, var C_Position vobPosition) {};
```

- `vobName`
- `vobPosition`

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(16795, 23120, 1400);
Wld_InsertMobContainerPos("CAVALORN_CHEST", pos);
```

## Wld_InsertMobFirePos

```dae
func void Wld_InsertMobFirePos(var string vobName, var C_Position vobPosition) {};
```

- `vobName`
- `vobPosition`

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(16795, 23120, 1400);
Wld_InsertMobFirePos("CAVALORN_CAMPFIRE", pos);
```

## Wld_InsertMobDoorPos

```dae
func void Wld_InsertMobDoorPos(var string vobName, var C_Position vobPosition) {};
```

- `vobName`
- `vobPosition`

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(1400, 16795, 23120);
Wld_InsertMobDoorPos("BOSPER_HOUSE_DOOR", pos);
```

## Wld_InsertMobBedPos

```dae
func void Wld_InsertMobBedPos(var string vobName, var C_Position vobPosition) {};
```

- `vobName`
- `vobPosition`

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(1400, 16795, 23120);
Wld_InsertMobBedPos("BOSPER_BED", pos);
```

## Wld_RemoveVob

Removes a specific vob from the game world.

```dae
func int Wld_RemoveVob(var string vobName) {};
```

- `vobName`
- `return` - `TRUE` if the vob has been correctly removed, `FALSE` otherwise

```dae
if (Wld_RemoveVob("CHEST_LOBART"))
{
    Print("Vob successfully removed");
};
```

## Wld_GetPos

Returns an object representing a set of points or angles.

```dae
func C_Position Wld_GetPos(var int posX, var int posY, vart int posZ) {};
```

- `posX` - point or angle in X axis
- `posY` - point or angle in Y axis
- `posZ` - point or angle in Z axis
- `return` - C_Position

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(0, 180, 0);
```

## Wld_GetPlayerPortalRoom

Returns name of portal room where the player currently is.

```dae
func string Wld_GetPlayerPortalRoom() {};
```

- `return` - name of player's portal room

```dae title="Example usage"
var string playerPortalRoom;
playerPortalRoom = Wld_GetPlayerPortalRoom();

if (Hlp_StrCmp(playerPortalRoom, "hütte2"))
{
    //...
};
```
