# Slash
# Slash - Unreal Engine 5 Action RPG System

![UE5](https://img.shields.io/badge/Unreal_Engine-5.x-white?logo=unrealengine&logoColor=white&color=0E1128)
![C++](https://img.shields.io/badge/C++-17/20-blue?logo=cplusplus)
![License](https://img.shields.io/badge/License-MIT-green)

## 📝 项目简介 | Project Overview
“Slash” 是一个基于 “Unreal Engine 5” 开发的第三人称动作 RPG 项目。本项目核心逻辑完全由 “C++” 编写，重点展示了底层角色控制、状态机架构、以及虚幻引擎高级特性的结合应用。

“Slash” is a 3rd-person Action RPG project built with “Unreal Engine 5”. The core logic is implemented in “C++”, focusing on character control systems, state machine architecture, and the integration of advanced UE5 features.

---

## 🚀 技术要点 | Key Technical Features

### 1. 角色与战斗系统 (Character & Combat)
*   C++ Base Classes: 建立了健壮的 Base Character 类层次结构，利用继承和多态实现敌我通用的属性逻辑。
*   State Machine: 使用 C++ 枚举和状态机管理角色的非对称状态（Idle, Attacking, Equipped, etc.）。
*   Combat Mechanics: 实现了基于蒙太奇（Anim Montage）的攻击序列、武器装备系统以及精确的碰撞检测。

### 2. 环境与渲染 (Environment & Rendering)
*   RVT (Runtime Virtual Texture): 配置并实现了运行时虚拟纹理，优化了地表地形与静态网格体（岩石/植被）的混合效果。
*   World Partition: 使用虚幻 5 的世界分区系统处理大场景加载与管理。

### 3. 系统架构 (System Architecture)
*   Component-Based Design: 逻辑高度组件化（Attribute Component, Combat Component），增强代码复用性。
*   Enhanced Input: 深度集成虚幻 5 的增强输入系统（Enhanced Input System）。
*   IK & Physics: 集成了动画动力学（IK）和物理资产，确保动作的自然与打击感的反馈。

---

## 🛠️ 开发环境 | Development Stack
*   Engine: Unreal Engine 5.x
*   IDE: Visual Studio 2022
*   Language: C++
*   Version Control: Git

---

## 📦 如何运行 | How to Run
> Note: 由于版权和存储空间限制，本项目仓库主要包含 Source 代码 和 Config 配置。美术资产（Content 文件夹下的模型和贴图）未全部包含。
> Due to copyright and storage limits, this repo primarily contains Source code and Configs. Asset files (.uasset) are partially excluded.

1. Clone 仓库到本地。
2. 右键点击 `Slash.uproject` 选择 `Generate Visual Studio project files`。
3. 打开 `.sln` 文件，在 Visual Studio 中选择 `Development Editor` 配置进行编译（Build）。
4. 运行项目。

---

## ⚖️ 声明与致谢 | Disclaimer & Credits
*   本项目是我在学习 “Stephen Ulibarri” 的课程过程中编写的教育练习项目。
*   代码归属： 逻辑实现由本人完成，架构遵循教学设计。
*   资产归属： 美术资产（如角色模型、场景资源）来源于虚幻商城及课程配套资源，仅供学习展示，严禁商用。

---