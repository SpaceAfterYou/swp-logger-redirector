[![Stand With Ukraine](https://raw.githubusercontent.com/vshymanskyy/StandWithUkraine/main/banner-direct-single.svg)](https://stand-with-ukraine.pp.ua)

# SoulWorker Plugin: Logger Redirector

## What the...

This is an example of a plugin for the [plugin loader](https://github.com/SoulWorkerResearch/swp-loader). It can also be useful when developing your own plugins. Its task is to redirect the game logs to spdlog

![image](https://user-images.githubusercontent.com/10461884/230788524-25814644-efe9-4cfc-a48e-ea07f343b527.png)

## How to

First of all, after the first launch of the game with the loader, in the folder with the game there will be a file: `configs/loader.json`.

```jsonc
{
  // ...

  // An optional step. This will enable the terminal.
  // Without it, the output will only go to a file in the logs folder.
  // With this both to the terminal and to the file.
  "use_console": true, 

  // Logging level.
  "level": "trace"

  // ...
}
```

> [The available logging levels can be found in the source code of spdlog](https://github.com/gabime/spdlog/blob/v1.x/include/spdlog/common.h#L244)

- Unpack the latest available archive from the [release](../../releases) page into your game folder. Replace the files if necessary
- Also, you need to install the [plugin loader](https://github.com/SoulWorkerResearch/swp-launcher)
- Now you can run the game using steam

## For Developers

- [vcpkg](https://vcpkg.io/) is needed for dependency management. If you don't want to fuck with it (GLHF), you can install dependencies yourself. They are listed in the `vcpkg.json` file under the `dependencies` property

[Your place is here](https://github.com/SoulWorkerResearch/swp-sdk)

## [Well cum 👌 to discord](http://discord.gg/SequFJP)

[![Discord](https://img.shields.io/discord/606442027873206292?style=flat-square)](http://discord.gg/SequFJP)
