import sys

# from jsonlibconfig import encoder
# from jsonlibconfig import decoder

from typing import Union

from fastapi import FastAPI, Request
from pydantic import BaseModel
# from
# import decoder
# from jsonlibconfig import encoder
# from jsonlibconfig import decoder

import subprocess
import os
import json
app = FastAPI()

class Item(BaseModel):
    data: str

# load config from file
# baseConfig = decoder.decode_file("baseConfig.json")



def loadBaseConfig():
    # os.system(["cat data.json | jsonlibconfig --pretty > dataFormat.json"])
    bash_command = "cat baseConfig.cfg | jsonlibconfig --target json --pretty > baseConfigFormatedJson.json"
    try:
        subprocess.run(bash_command, shell=True, check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error running Bash command: {e}")

    with open('baseConfigFormatedJson.json', 'r') as file:
        jsonBaseConfig = json.load(file)

    print("//////////////////////")
    print(jsonBaseConfig)
    print("//////////////////////")
    # try:
    #     subprocess.run(bash_command, shell=True, check=True)
    # except subprocess.CalledProcessError as e:
    #     print(f"Error running Bash command: {e}")
    # return {"status": "success"}
    return jsonBaseConfig

def cleanArgs(object):
    size = len(object["args"])
    object["args"] = object["args"][-4:]
    object["args"] = object["args"][:-1]
    return object


def merge_two_dicts(x, y):
    z = x.copy()   # start with x's keys and values
    z.update(y)    # modifies z with y's keys and values & returns None
    return z

def formatJson(datas):
    datas = json.loads(datas)
    allObjects = []
    for data in datas:
        if data["object"]:
            if "userData" in data["object"]:
                print(data["object"])
                buf = data["object"]["userData"].get("name", "default")
                if buf == "default":
                    continue
                object = {
                    # "objects" : {
                        "primitive": data["object"]["userData"].get("name", "default"),
                        "type": data["object"].get("type", "default"),
                        "material": data["object"]["userData"].get("material", "default"),
                        "args": data["object"].get("matrix", "default")
                    # }
                }
                object = cleanArgs(object)
                # print("////////////////////////////////////////////////////")
                # print(object)
                # print("////////////////////////////////////////////////////")
                allObjects.append(object)
    allObjects = {
        "objects": allObjects
    }
    base_config = loadBaseConfig()
    print("////////////////////////////////////////////////////")
    print(allObjects)
    print("////////////////////////////////////////////////////")
    allObjects = merge_two_dicts(base_config, allObjects)
    return allObjects


@app.get("/")
def read_root():
    return {"Hello": "World"}

@app.post("/save")
def save(data : Item):
    # libConfig = encoder.decode(data.data)
    allObjects = json.dumps(formatJson(data.data))
    with open("data.json", "w") as f:
        f.write(allObjects)
    # os.system(["cat data.json | jsonlibconfig --pretty > dataFormat.json"])
    bash_command = "cat data.json | jsonlibconfig --pretty > dataFormat.cfg"
    try:
        subprocess.run(bash_command, shell=True, check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error running Bash command: {e}")
    return {"status": "success"}