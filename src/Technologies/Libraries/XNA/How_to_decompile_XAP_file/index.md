---
title: How to decompile XAP file
breadcrumb:
- label: Technologies
  href: Technologies/index.html
- label: Libraries
  href: Technologies/Libraries/index.html
- label: XNA
  href: Technologies/Libraries/XNA/index.html
subpages:
- label: Go Up
  href: Technologies/Libraries/XNA/index.html
---

Decompiling an [XAP](Article_does_not_yet_exist_or_link_is_broken/index.html) file (a [Windows Phone](Article_does_not_yet_exist_or_link_is_broken/index.html) app package) into C# code and rebuilding it into a new XAP is a multi-step process.

## Steps

### Step 1: Extract the Contents of the XAP File

1. **Rename the XAP file**:
  - Change the `.xap` file extension to `.zip`.
  - Extract the ZIP file using any archive tool (e.g., WinRAR, 7-Zip).
2. **Analyze the Contents**:
  - Look for the `DLL` files in the `Bin` or `App` folders. These contain the compiled C# code.
  - Other assets, such as `XAML`, images, and configuration files, will also be extracted.

---

### Step 2: Decompile the DLL Files

1. **Use a Decompiler**:
  - Tools like ILSpy, dnSpy, or Telerik JustDecompile can be used to decompile `.dll` files to readable C# code.
2. **Steps for Decompilation**:
  - Open the `.dll` file in the decompiler.
  - Explore the namespaces, classes, and methods to understand the code structure.
  - Export the decompiled code to a Visual Studio project (most decompilers have this feature).
3. **Analyze Decompiled Code**:
  - Review the decompiled code for errors or incomplete segments caused by obfuscation.
  - Manually reconstruct missing parts if necessary.

---

### Step 3: Modify the Decompiled Code (Optional)

1. Open the exported Visual Studio project.
2. Make any necessary changes to the code.
  - Fix errors caused by obfuscation or incompatible constructs.
  - Modify functionality, if required.

---

### Step 4: Rebuild the XAP File

1. **Create a New Windows Phone Project**:
  - In Visual Studio, create a new Windows Phone project of the same version (e.g., Windows Phone 8.0, 8.1).
  - Use the same name and namespace as the original project (if possible).
2. **Add Decompiled Code and Assets**:
  - Add the decompiled code and assets (images, XAML files, etc.) to the project.
  - Ensure the `AppManifest.xaml` file matches the original app's configuration.
3. **Fix Dependencies**:
  - Reference required libraries (.dll) that were part of the original app or are available in the Windows Phone SDK.
4. **Build the Project**:
  - Set the project to build as a Windows Phone app.
  - Compile the project in Visual Studio to generate a new XAP file.

---

### Step 5: Test the New XAP File

1. Deploy the new XAP to a Windows Phone emulator or device.
  - Use tools like the Windows Phone Application Deployment tool (available in the Windows Phone SDK).
2. Test for functionality and stability.

---

### Additional Notes

- **Legal Considerations**: Decompiling and modifying software without explicit permission may violate copyright or licensing agreements.
- **Obfuscation**: If the original XAP was obfuscated, the decompiled code may not be fully readable or functional, requiring significant effort to reconstruct.
- **Re-signing the App**: The new XAP must be signed with a valid certificate for deployment.

## How to reuse .xnb files

1. Extract and place them into the rebuilt project’s `Content` folder.
2. Match the original folder structure and paths.
3. Set them to `Content` build action in the IDE.
4. Optionally edit them by decompiling and recompiling using the XNA or MonoGame Pipeline tools.

## How to extract wav files from xnb files

- [https://forums.terraria.org/index.php?threads/textract-extract-terrarias-images-sound-effects-and-music.937/](https://forums.terraria.org/index.php?threads/textract-extract-terrarias-images-sound-effects-and-music.937/)
- [https://github.com/Antag99/TExtract](https://github.com/Antag99/TExtract)
