# ViewportWidget Plugin (UE4.27.2)
![Preview](https://github.com/user-attachments/assets/ea08b8f1-f365-41ae-8f5d-283fae8421f0)
插件实现：
- 在UMG上渲染一个独立的3D视口
- 视口内容为自定义蓝图对象
- 可自定义相机、灯光
- 解决天光、后期与场景渲染一致性问题
- 解决背景与Widget透明混合问题（需改动引擎源码）
  
说明文档：https://zhuanlan.zhihu.com/p/1966930044652852570

**插件用法**：在UMG编辑界面拖入viewport widget这个控件，然后在属性"Entries"设置用于渲染在viewport上的Actor引用


:star:以下为Viewport widget上的效果与实际场景渲染的对比图：

**天光(SkyLight)**：
![Preview](https://pic3.zhimg.com/80/v2-6127c9be665edbca71253fe917d64226_1440w.webp)

**后期(Postprocess)**：
![Preview](https://pica.zhimg.com/80/v2-f8cbc05f7be8d46e54f8fae8025aee86_1440w.webp)

**优化-背景透明(PropagateAlpha)**：
![Preview](https://github.com/user-attachments/assets/eafe04e2-323f-4661-a2a7-af4bead55b3e)  
<img width="1303" height="630" alt="image" src="https://github.com/user-attachments/assets/aa3bd89e-cc77-491a-9b7d-50b979285d91" />
 - 文档：[UE4后处理中的PropagateAlpha - 在Tonemap中保留Alpha](https://zhuanlan.zhihu.com/p/1999223344109728919)
 - Diff(Engine):[sitonmoon/ViewportWidget@ba4f0a8](https://github.com/sitonmoon/ViewportWidget/commit/ba4f0a85282e8ff12143f7a1b916c81377e6581c)
 - Diff(Plugin):[sitonmoon/ViewportWidget@39ea517](https://github.com/sitonmoon/ViewportWidget/commit/39ea517d6b7beb66cbfea99c6b592da670bf3d55)
