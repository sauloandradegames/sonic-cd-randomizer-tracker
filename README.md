# SONIC CD RANDOMIZER TRACKER

A tracker for Sonic CD Randomizer. Previously developed on C++, now ported for Angular.

In my opinion, "Segments" mode is the most interesting of all Randomizer modes available, offering a good challenge and an easy to track progress. Most of the modes falls on being hard to track player progress. In a race context, it's hard to say who is winning the race. Worst case scenario, it's possible to a player reaches the end of the randomizer by time travveling straight to the creadits, spoiling all fun of the randomizer.

## What is Segments Mode?

In this Randomizer Mode, game sets seven zones (or **segments**) with eight stages plus a Boss stage. The 8 first stages can be any Act 1 or Act 2 with their respective Time Zones (`Past`, `Present`, `Good Future` or `Bad Future`). Bosses can be any Act 3 Good Future or Bad Future. In the end, the player can face 7 of 14 possible bosses.

Beating a stage leads the player to the next stage in the segment. The segment boss can be accessed by finishing the 8 stages in order (referenced here as the segment **Main Route**). It's the safer route, because it's guaranteed to reach the end of the segment, but it is the slowest route as well. As an alternative, the player can perform a **Time Travel** (by activating a `Past` or `Future` sign). Time Travel leads the player to another stage in the current segment. In one hand, the player can advance faster through the segment, skipping stages in the process. On the other hand, the player can be teleported to the same stage or, in the worst case scenario, go back through the segment. Time Travel never leads the player straight to the segment boss.

Each segment is linked to one of the seven **Time Stones**. By beating the segment Special Stage and retrieving the Time Stone, the player guarantees Good Future in the segment (Bad Future stages cannot be converted into Good Future stages by this way). By this way, the player can access an alternate boss fight at the end of the segment.

## How the tracker works?

The program asks the user to input how the stage was beaten (by Signpost, by Past Time Travel or Future Time Travel), followed by the stage and act reached, followed by Time Zone reached.

The Tracker tries to create a "map" of the current segment, informing all stages visited by the player and telling which stages can be accessed from the current position by reaching the end of the stage or by time travel.

The tracker also can integrate with OBS for those who want to show information progress on stream.

## Current state of this project

Tracker is functional, but needs polishment
- Input is done by mnemonics ("abbreviations" for each function). This input isn't the best input for an average user.
- Because the program runs on a Linux terminal (and don't having a "traditional" executable), this program is very hard to interact.
- It's not possible to correct wrong inputs in the tracker. If the user enters wrong, that's it.
- OBS integration needs to be redone. I envisioned a wrong logic for this tracker, considering the player won't repeat bosses. This statement is incorrect (for example, the player can fight Tidal Tempest Bad Future boss and, after that, fight Tidal Tempest Good Future boss)
- Tracker cannot build the segment, only list stages in the order the player visit them, not in the current order of the randomizer seed. This is the biggest challenge for me when programming this tracker.
- My final goal is to build a tracker with a graphical interface, easier to interact and easier to understand.
- Right now, Randomizer have an option to generate a graphical *spoiler log*. My wish is to mount a tracker with a graphical visualization who can build the segment as the player fills in with information.

## Requirements

This project was generated with [Angular CLI](https://github.com/angular/angular-cli) version 16.1.5.

### Development server

Run `ng serve` for a dev server. Navigate to `http://localhost:4200/`. The application will automatically reload if you change any of the source files.

### Code scaffolding

Run `ng generate component component-name` to generate a new component. You can also use `ng generate directive|pipe|service|class|guard|interface|enum|module`.

### Build

Run `ng build` to build the project. The build artifacts will be stored in the `dist/` directory.

### Running unit tests

Run `ng test` to execute the unit tests via [Karma](https://karma-runner.github.io).

### Running end-to-end tests

Run `ng e2e` to execute the end-to-end tests via a platform of your choice. To use this command, you need to first add a package that implements end-to-end testing capabilities.

### Further help

To get more help on the Angular CLI use `ng help` or go check out the [Angular CLI Overview and Command Reference](https://angular.io/cli) page.
