const { app, BrowserWindow, ipcRenderer, ipcMain, dialog } = require('electron');
// const THREE = require('three');
// const fs = require('fs')
// const path = require('path')

app.on('ready', () => {
    const win = new BrowserWindow({
        width: 1920,
        height: 1080,
        webPreferences: {
            nodeIntegration: true,
            contexIntegration: true
        }
    });

    win.loadFile('index.html');
    // win.webContents.openDevTools();
    win.webContents.executeJavaScript('require("./component.js")');
});

//////////////

//////////////

app.whenReady().then(() => {
    // createWindow()

    app.on('activate', () => {
        if (BrowserWindow.getAllWindows().length === 0) {
            createWindow()
        }
    })
})

app.on("window-all-closed", () => {
    if (process.platform !== "darwin") {
        app.quit();
    }
});