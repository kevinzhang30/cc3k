# ChamberCrawler3000 (CC3K)
ChamberCrawler3000 (CC3K) is a game inspired by the classic video game *Rogue* https://en.wikipedia.org/wiki/Rogue_(video_game). The player navigates through a series of chambers across five dungeon floors, defeating enemies, collecting treasure, and using potions, all displayed in an ASCII-rendered game world. The goal is to reach the fifth floor while surviving enemy attacks and enhancing your character's abilities through various items and potions.

## Features
- **Playable Races:** Choose between several character races including Shade, Drow, Vampire, Troll, and Goblin, each with unique stats and abilities.
- **Enemies:** Face off against a variety of enemies such as Humans, Dwarves, Elves, Orcs, Dragons, and more. Some enemies have unique abilities, like Elves attacking twice and Orcs dealing more damage to Goblins.
- **Potions & Treasure:** Discover hidden potions with beneficial or harmful effects, as well as various gold piles scattered throughout the dungeon.
- **Turn-Based Combat:** Engage enemies with attack commands, with combat calculated based on attack and defense values.
- **ASCII Display:** The game world is rendered in an ASCII format with color-coded elements for easier navigation.

## Installation
1. Clone the repository:
   ```bash
   git clone <repository_url>
   ```
2. Compile the game using the provided `Makefile`:
   ```bash
   make
   ```
3. Run the game:
   ```bash
   ./cc3k
   ```

## Controls
- **Movement:** Use commands like `no`, `so`, `ea`, `we`, `ne`, `nw`, `se`, `sw` to move the character.
- **Interact:** Use `u <direction>` to use potions, `a <direction>` to attack enemies.
- **Race Selection:** Select your character's race at the beginning of the game (`s`, `d`, `v`, `g`, `t`).
- **Other Commands:** 
  - `f`: Freeze enemy movement.
  - `r`: Restart the game.
  - `q`: Quit the game.

## Command-Line Options
- Optionally, load a custom floor layout by specifying a file:
  ```bash
  ./cc3k <layout_file>
  ```

## Future Enhancements (DLC)
The project is designed to support downloadable content, allowing for additional features and challenges such as:
- Smarter AI enemies.
- New character races or enemy types.
- More complex dungeon layouts.
