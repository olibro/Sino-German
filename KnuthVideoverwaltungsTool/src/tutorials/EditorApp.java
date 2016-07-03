package fx.editor;

import java.io.File;
import java.util.HashMap;
import java.util.Map;

import fx.editor.Tool;
import fx.editor.shapes.container.IShapeManager;
import fx.editor.shapes.container.ShapeManager;
import fx.editor.shapes.geom2d.Point;
import fx.editor.shapes.geom2d.shapes.Rectangle;
import fx.editor.shapes.geom2d.shapes.Shape;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.RadioButton;
import javafx.scene.control.SeparatorMenuItem;
import javafx.scene.control.ToggleGroup;
import javafx.scene.control.ToolBar;
import javafx.scene.control.Tooltip;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCombination;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.FileChooser;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;

public class EditorApp extends Application {
    private Controller controller;
    private Canvas drawingCanvas;
    private Label statusLabel;
    private ShapeRenderer shapeRenderer= new ShapeRenderer();
    private IShapeManager shapeManager;
    private Stage primaryStage;
    
    public static void main(String[] args) {
        Application.launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        this.primaryStage = primaryStage;
        shapeManager = new ShapeManager();
        controller = new Controller(this, shapeManager);

        ToolBar toolbar = createToolBar();
        HBox statusBar = createStatusBar();
        Pane drawingCanvasPane = createDrawingCanvasPane();
        GridPane actionPane = createActionPane();
        VBox colorPane = createColorPane();
        
        BorderPane borderPane = new BorderPane();
        borderPane.setTop(toolbar);
        borderPane.setLeft(actionPane);
        borderPane.setRight(colorPane);
        borderPane.setCenter(drawingCanvasPane);
        borderPane.setBottom(statusBar);
        
        MenuBar menuBar = createMenuBar();
        VBox top = new VBox();
        top.getChildren().addAll(menuBar,borderPane);
        Scene scene = new Scene(top, 800, 600);  
        primaryStage.setScene(scene);
        primaryStage.setTitle("Shape Editor");
        scene.getWindow().setOnCloseRequest(new EventHandler<WindowEvent>() {
            @Override
            public void handle(WindowEvent evt) {
                controller.closeApplication();     
            }
        });
        primaryStage.show();   
        
    }

    
    private MenuBar createMenuBar() {
        // create file menu with submenues and menu items
        MenuItem fileMenuItem = new MenuItem("File");  
        fileMenuItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent arg0) {
                controller.openFile();     
            }
            
        });
        MenuItem urlMenuItem = new MenuItem("URL");
        Menu openMenu = new Menu("Open");
        openMenu.getItems().addAll(fileMenuItem,urlMenuItem);

        // menu item with Shortcut <Ctrl> s
        MenuItem saveMenuItem = new MenuItem("Save");
        saveMenuItem.setAccelerator(KeyCombination.keyCombination("Ctrl+S"));
        saveMenuItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent evt) {
                controller.save();     
            }
        });

        MenuItem saveAsMenuItem = new MenuItem("Save as ...");
        saveAsMenuItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent evt) {
                controller.saveAs();     
            }
        });

        MenuItem exitMenuItem = new MenuItem("Exit");
        exitMenuItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent evt) {
                controller.closeApplication();     
            }
        });
        
        Menu fileMenu = new Menu("File");
        fileMenu.getItems().addAll(openMenu,saveMenuItem, saveAsMenuItem, new SeparatorMenuItem(),exitMenuItem);
        Menu editMenu = new Menu("Edit");
        Menu helpMenu = new Menu("Help");
        
        MenuBar menuBar = new MenuBar();
        menuBar.getMenus().addAll(fileMenu, editMenu, helpMenu );
        return menuBar;
    }
    
    private ToolBar createToolBar() {
        Button openButton = createToolBarButton("open");
        Button saveButton = createToolBarButton("save");
        Button newButton = createToolBarButton("new");
        ToolBar toolbar = new ToolBar(newButton,openButton,saveButton); 
        openButton.setOnAction(evt -> controller.openFile());
        saveButton.setOnAction(evt -> controller.save());
        newButton.setOnAction(evt -> controller.displayErrorMessage("not yet implemented"));
        return toolbar;
    }
    
    private Button createToolBarButton(String commandName) {
        Image icon = new Image(getClass().getResourceAsStream("/fx/editor/resources/" + commandName + ".gif"));
        Button button = new Button();
        button.setGraphic(new ImageView(icon));
        return button;
    }
    
    private HBox createStatusBar() {
        HBox statusbar = new HBox();
        statusLabel = new Label();
        statusbar.getChildren().add(statusLabel);
        return statusbar;
    }
    
    private GridPane createActionPane() {
        GridPane gridPane = new GridPane();
        gridPane.setAlignment(Pos.TOP_LEFT);
        gridPane.setHgap(10);
        gridPane.setVgap(10);
        gridPane.setStyle("-fx-background-color: #F9F9F9;");
        gridPane.setPadding(new Insets(5, 5, 5, 5));
        
        Button addRectangleButton = new Button();
        Image icon = new Image(getClass().getResourceAsStream("/fx/editor/resources/rectangle.gif"));
        addRectangleButton.setStyle("-fx-background-color: #FFFFFF;");
        addRectangleButton.setGraphic(new ImageView(icon));   
        addRectangleButton.setTooltip(new Tooltip("Add rectangle"));
        gridPane.add(addRectangleButton, 0, 0);
        addRectangleButton.setOnAction(new EventHandler<ActionEvent>() {
            Tool addRectangleTool = new AddRectangleTool(controller);
            @Override
            public void handle(ActionEvent evt) {
                controller.setTool(addRectangleTool);   
            }   
        });
        
        Button addCircleButton = new Button();
        icon = new Image(getClass().getResourceAsStream("/fx/editor/resources/circle.gif"));
        addCircleButton.setGraphic(new ImageView(icon));
        addCircleButton.setStyle("-fx-background-color: #FFFFFF;");
        addCircleButton.setTooltip(new Tooltip("Add circle"));
        addCircleButton.setOnAction(new EventHandler<ActionEvent>() {
            Tool addCircleTool = new AddCircleTool(controller);
            @Override
            public void handle(ActionEvent evt) {
                controller.setTool(addCircleTool);   
            } 
        });
        gridPane.add(addCircleButton, 1, 0);
        
        EventHandler<ActionEvent> notYetImplementedHandler = new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent evt) {
                controller.setTool(null);   
                controller.displayStatusText("Tool not yet implemented"); 
            }     
        };
           
        Button moveButton = new Button();
        icon = new Image(getClass().getResourceAsStream("/fx/editor/resources/move.gif"));
        moveButton.setGraphic(new ImageView(icon));
        moveButton.setStyle("-fx-background-color: #FFFFFF;");
        moveButton.setTooltip(new Tooltip("Move Shape"));
        moveButton.setOnAction(notYetImplementedHandler);
        gridPane.add(moveButton, 0, 1);
        
        Button resizeButton = new Button();
        icon = new Image(getClass().getResourceAsStream("/fx/editor/resources/resize.gif"));
        resizeButton.setGraphic(new ImageView(icon));
        resizeButton.setStyle("-fx-background-color: #FFFFFF;");
        resizeButton.setTooltip(new Tooltip("Resize Shape"));
        resizeButton.setOnAction(notYetImplementedHandler);
        gridPane.add(resizeButton, 1, 1);
        
        Button clearButton = new Button();
        icon = new Image(getClass().getResourceAsStream("/fx/editor/resources/clear.gif"));
        clearButton.setGraphic(new ImageView(icon));
        clearButton.setStyle("-fx-background-color: #FFFFFF;");
        clearButton.setTooltip(new Tooltip("Clear"));
        clearButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent evt) {
                controller.clear(); 
            }     
        });
        gridPane.add(clearButton, 0, 2);
        return gridPane;
    }
    
    private enum DrawingColorItem {
        red(Color.RED), blue(Color.BLUE), green(Color.GREEN), yellow(Color.YELLOW);
        
        public final Color color;

        private DrawingColorItem(Color color) {
            this.color = color;
        }
    }
    
    private VBox createColorPane() {
        VBox colorSelectionBox = new VBox();
        colorSelectionBox.setStyle("-fx-background-color: #F9F9F9;");
        colorSelectionBox.setSpacing(10);
        colorSelectionBox.setPadding(new Insets(5, 5, 5, 5));
        Label colorLabel = new Label("Drawing Color");
        colorLabel.setFont(Font.font("Arial", FontWeight.BOLD, 14));
        colorSelectionBox.getChildren().add(colorLabel);

        // define a CheckboxGroup for bundling all color checkboxes
        final ToggleGroup toggleGroup = new ToggleGroup();

        // create radio buttons within the group and add them to the panel
        for (DrawingColorItem drawingColorItem : DrawingColorItem.values()) {
            final Color color = drawingColorItem.color;
            // decide which of the radio buttons should checked
            boolean checked = color.equals(Controller.DEFAULT_DRAWING_COLOR);

            RadioButton radioButton = new RadioButton(drawingColorItem.toString());
            colorSelectionBox.getChildren().add(radioButton);
            radioButton.setToggleGroup(toggleGroup);
            radioButton.setSelected(checked);
            radioButton.setStyle("-fx-text-fill: #" + color.toString().substring(2, 8) + ";");
            radioButton.setOnAction(new EventHandler<ActionEvent> () {
                @Override
                public void handle(ActionEvent evt) {
                    controller.changeDrawingColor(color);                   
                }        
            });
        }

        Label bgLabel = new Label("Background");
        bgLabel.setFont(Font.font("Arial", FontWeight.BOLD, 14));
        colorSelectionBox.getChildren().add(bgLabel);

        // define a map for all background colors
        // just create a new entry in this map to add a new color
        final Map<String, Color> colorTable = new HashMap<String, Color>();
        colorTable.put("white", Color.WHITE);
        colorTable.put("gray", Color.GRAY);
        colorTable.put("black", Color.BLACK);
        
        final ComboBox<String> comboBox = new ComboBox<String>();
        colorSelectionBox.getChildren().add(comboBox);
        comboBox.getItems().addAll(colorTable.keySet());

        // listen for item events
        comboBox.setOnAction(new EventHandler<ActionEvent> () {
            @Override
            public void handle(ActionEvent event) {
                controller.changeBackgroundColor((Color) colorTable.get(comboBox.getValue()));      
            }
        });
        return colorSelectionBox;
    }

    private Pane createDrawingCanvasPane() {
        drawingCanvas = new Canvas(300,300);
        
        Pane drawingCanvasPane = new Pane();
        drawingCanvasPane.setPrefSize(2000, 2000);
        drawingCanvasPane.getChildren().add(drawingCanvas);
        drawingCanvas.widthProperty().bind(drawingCanvasPane.widthProperty());
        drawingCanvas.heightProperty().bind(drawingCanvasPane.heightProperty());
        
        
        drawingCanvas.setOnMousePressed(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent evt) {
                System.out.println(evt);
                Tool tool = controller.getTool();
                if (tool == null)
                    return;
                tool.mousePressed(evt.getX(), evt.getY());
                
            }   
        });
        drawingCanvas.setOnMouseDragged(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent evt) {
                System.out.println(evt);
                Tool tool = controller.getTool();
                if (tool == null)
                    return;
                tool.mouseDragged(evt.getX(), evt.getY());
                
            }   
        });
        drawingCanvas.setOnMouseReleased(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent evt) {
                System.out.println(evt);
                Tool tool = controller.getTool();
                if (tool == null)
                    return;
                tool.mouseReleased(evt.getX(), evt.getY());
                
            }   
        });
        return drawingCanvasPane;
    }

    public File showFileDialog(String title, boolean open) {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle(title);
        String currentDir = System.getProperty("user.dir") + File.separator;
        File file = new File(currentDir);
        fileChooser.setInitialDirectory(file);
        return open ? fileChooser.showOpenDialog(null) : fileChooser.showSaveDialog(null);
    }

    public void displayStatusText(String msg) {
        statusLabel.setText(msg);
        
    }

    public void popupMsgWindow(String msg) {
        Stage stage = new Stage();
        HBox hBox = new HBox();
        Label label = new Label(msg);
        hBox.getChildren().add(label);
        hBox.setPadding(new Insets(25, 25, 25, 25));
        stage.setScene(new Scene(hBox));
        stage.setTitle("My modal window");
        stage.initModality(Modality.WINDOW_MODAL);
        stage.initOwner(primaryStage.getScene().getWindow());
        stage.show();   
    }

    public void draw(Shape shape) {
        repaintDrawingCanvas();
        shapeRenderer.render(shape, drawingCanvas.getGraphicsContext2D());
        
    }

    public void repaintDrawingCanvas() {
        GraphicsContext gc = drawingCanvas.getGraphicsContext2D();
        gc.setFill(controller.getBackgroundColor());
        gc.fillRect(0, 0, drawingCanvas.getWidth(), drawingCanvas.getHeight());
        for (Shape shape: shapeManager.getAll()) {
            shapeRenderer.render(shape, gc);
        }  
    }
}
