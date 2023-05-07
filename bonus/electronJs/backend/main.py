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

def loadBaseConfig():
    # os.system(["cat data.json | jsonlibconfig --pretty > dataFormat.json"])
    bash_command = "cat baseConfig.cfg | jsonlibconfig --target json --pretty > baseConfigFormatedJson.json"
    try:
        subprocess.run(bash_command, shell=True, check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error running Bash command: {e}")

    with open('baseConfigFormatedJson.json', 'r') as file:
        jsonBaseConfig = json.load(file)

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


def getCoord(data):
    # data["userData"]["matrix"] = data["userData"]["matrix"][-4:]
    data["object"]["matrix"] = data["object"]["matrix"][-4:]
    # remove the last element
    data["object"]["matrix"] = data["object"]["matrix"][:-1]
    # print(data["matrix"])
        # round every element to float exemple: 2.0
        # cast it to float in this format 2.0
    data["object"]["matrix"] = [float("{:.2f}".format(x)) for x in data["object"]["matrix"]]
    return data



def formatJson(datas):
    datas = json.loads(datas)
    allObjects = []
    material = {
        "type": "Flat",
        "args": {
            "color": {
                "r": 120,
                "g": 0,
                "b": 100
            },
            "properties": {
                "reflectivity": 0.5,
                "shininess": 0.5
            }
        }
    }
    for data in datas:
        if data["object"]:
            if "userData" in data["object"]:
                print(data["object"])
                buf = data["object"]["userData"].get("name", "default")
                if buf == "default":
                    continue
                data = getCoord(data)
                print("/////////////////////////////////////")
                print(data["object"]["matrix"])
                print("/////////////////////////////////////")
                object = {
                    "primitive" : {
                        "type": buf,
                        "args": {
                            "x": data["object"]["matrix"][0],
                            "y": data["object"]["matrix"][1],
                            "z": data["object"]["matrix"][2],
                            "radius": 10.0
                        }
                    },
                    "material": material
                }
                # object = cleanArgs(object)
                allObjects.append(object)
    allObjects = {
        "objects": {

            "pathObjects": "./src/plugins/",
            "pathMaterial": "./src/plugins/",
            "objects": allObjects
        }
    }
    base_config = loadBaseConfig()
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