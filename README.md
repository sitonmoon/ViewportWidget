# ViewportWidget Plugin (UE4.27.2)
![Preview](https://github.com/user-attachments/assets/ea08b8f1-f365-41ae-8f5d-283fae8421f0)
插件实现了在UMG上渲染一个独立的视口，视口渲染内容、相机、灯光可自定义，并解决多个问题实现与场景实际渲染效果一致。
说明文档：https://zhuanlan.zhihu.com/p/1966930044652852570

**插件用法**：在UMG编辑界面拖入viewport widget这个控件，然后在属性"Entries"设置用于渲染在viewport上的Actor引用


以下为Viewport widget上的效果与实际场景渲染的对比图：

**天光(SkyLight)**：
![Preview](https://pic3.zhimg.com/80/v2-6127c9be665edbca71253fe917d64226_1440w.webp)

**后期(Postprocess)**：
![Preview](https://pica.zhimg.com/80/v2-f8cbc05f7be8d46e54f8fae8025aee86_1440w.webp)
