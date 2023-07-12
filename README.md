# Asset Helper Plugin

## Installation

1. Clone or download the Asset Helper Plugin repository
2. Copy the plugin folder to your Unreal Engine project's `Plugins` directory.

# Duplicate Texture Detection

The Asset Helper Plugin is a powerful tool that allows you to detect duplicated textures in your Unreal Engine project. This plugin supports Unreal Python scripting, making it easy to automate the process of identifying duplicate textures.

### Example Python Script

To demonstrate the usage of the plugin, here's an example Python script located in the `PyScripts` folder of the plugin repository:

```python
import unreal

def get_texture_checksum(texture_asset):
    return unreal.AssetHelperFunctionLibrary.calculate_texture_crc(texture_asset)

asset_reg = unreal.AssetRegistryHelpers.get_asset_registry()

record = {} # map for cache checksum
 
# filter for Texture2D type
filter = unreal.ARFilter(class_names=['Texture2D'], recursive_paths=True,
                         package_paths=['/Game/'])

assets = asset_reg.get_assets(filter)

with unreal.ScopedSlowTask(len(assets), "Processing Textures") as slow_task:
    slow_task.make_dialog(True)
    for asset in assets:
        if slow_task.should_cancel():  # True if the user has pressed Cancel in the UI
            break

        slow_task.enter_progress_frame(1)

        texture = asset.get_asset()
        
        hashNum = get_texture_checksum(texture) # Calculate hash from checksum

        if hashNum not in record: # Lookup in map then cache it
            record[hashNum] = asset
        else:
            print(f'Duplicate found. {asset.package_name} is the same as {record[hashNum].package_name}')